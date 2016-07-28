from framework import Vector
from framework.database.core.session import Session
from framework.database.model import Road, Strongpoint
from framework.database.util.reset import reset as reset_db
from framework.world import WorldGenerator, Node

reset_db()

wg = WorldGenerator()

session = Session()

for node in wg.generate_nodes():
    session.add(Strongpoint(node.location, node.level))

session.commit()

created_strongpoints = session.query(Strongpoint)
nodes = []
for strongpoint in created_strongpoints:
    nodes.append(Node(strongpoint.id, Vector(strongpoint.location_x, strongpoint.location_y), strongpoint.level))

for edge in wg.generate_edges(nodes):
    session.add(Road(edge.start_node_id, edge.end_node_id))

session.commit()
