from framework import Vector
from framework.database.model import Road, Strongpoint
from framework.database.util.reset import reset
from framework.world import WorldGenerator, Node

reset()

wg = WorldGenerator()

for node in wg.generate_nodes():
    strong_point = Strongpoint(node.location, node.level)
    strong_point.save()


created_nodes = Strongpoint.read()
nodes = []
for node in created_nodes:
    nodes.append(Node(node.rid, Vector(node.x, node.y), node.level))

for edge in wg.generate_edges(nodes):
    road = Road(edge.start_node_id, edge.end_node_id)
    road.save()
