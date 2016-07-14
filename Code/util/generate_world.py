from framework import Vector
from framework.database.model.static_actor import Road, StrongPoint
from framework.database.util.reset import reset
from world import WorldGenerator, Node

reset()

wg = WorldGenerator()

for node in wg.generate_nodes():
    strong_point = StrongPoint(node.location, node.level)
    strong_point.save()


created_nodes = StrongPoint.read()
nodes = []
for node in created_nodes:
    nodes.append(Node(node._rid, Vector(node.oRecordData['location_x'], node.oRecordData['location_y']), node.oRecordData['level']))

for edge in wg.generate_edges(nodes):
    road = Road(edge.start_node_id, edge.end_node_id)
    road.save()
