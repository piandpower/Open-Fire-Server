from typing import Iterable
from .static_actor import Node, Edge

NODE_SPACING = 10.0
ID_UNKNOWN = 'ID_INKNOWN'


class WorldGenerator:
    nodes = []
    edges = []

    def generate(self):
        self.nodes = self.__generate_nodes()
        self.edges = self.__generate_edges(self.nodes)

    @staticmethod
    def __generate_nodes():
        nodes = []
        for x in range(10):
            for y in range(10):
                nodes.append(Node(ID_UNKNOWN, x * NODE_SPACING, y * NODE_SPACING))

        return nodes

    @classmethod
    def __generate_edges(cls, nodes: Iterable[Node]):
        edges = []
        for start_node in nodes:
            for end_node in nodes:
                if start_node.node_id != end_node.node_id and cls.__has_edge(start_node, end_node):
                    edges.append(Edge(start_node.node_id, end_node.node_id))

        return edges

    @staticmethod
    def __has_edge(start_node: Node, end_node: Node):
        node_spacing = NODE_SPACING * 1.1
        dist_x = start_node.x - end_node.x
        dist_y = start_node.y - end_node.y
        if node_spacing * node_spacing > ((dist_x * dist_x) + (dist_y * dist_y)):
            return False

        return True
