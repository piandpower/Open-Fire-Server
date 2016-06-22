from framework import Vector
from model import StrongPointModel, StrongPointEdgeModel
from world import WorldGenerator, Node

wg = WorldGenerator()

for node in wg.generate_nodes():
    StrongPointModel.create(node.location.x, node.location.y, node.level)

created_nodes = StrongPointModel.read()
nodes = []
for node in created_nodes:
    nodes.append(Node(node.id, Vector(node.location_x, node.location_y), node.level))

for edge in wg.generate_edges(nodes):
    StrongPointEdgeModel.create(edge.start_node_id, edge.end_node_id)
