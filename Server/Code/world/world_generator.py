from typing import Iterable
from random import uniform
from .static_actor import Node, Edge

MIN_NODE_RANGE = 100.0
SQ_MIN_NODE_RANGE = MIN_NODE_RANGE * MIN_NODE_RANGE
MAX_EDGE_RANGE = 300.0
ID_UNKNOWN = 'ID_INKNOWN'


class WorldGenerator:
    nodes = []
    edges = []

    def generate(self):
        self.nodes = self.__generate_nodes()
        self.edges = self.__generate_edges(self.nodes)

    @classmethod
    def __generate_nodes(cls):
        nodes = []
        for _ in range(10000):
            node = cls.__generate_random_node()
            if not cls.__is_overlap(node.x, node.y, nodes):
                nodes.append(node)

        return nodes

    @staticmethod
    def __generate_random_node():
        return Node(ID_UNKNOWN, uniform(0.0, 500.0), uniform(0.0, 500.0))

    @staticmethod
    def __is_overlap(pos_x, pos_y, nodes: Iterable[Node]):
        for node in nodes:
            dist_x = pos_x - node.x
            dist_y = pos_y - node.y
            sq_dist = (dist_x * dist_x) + (dist_y * dist_y)
            if sq_dist <= SQ_MIN_NODE_RANGE:
                return True

        return False

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
        dist_x = start_node.x - end_node.x
        dist_y = start_node.y - end_node.y
        if MAX_EDGE_RANGE * MAX_EDGE_RANGE > ((dist_x * dist_x) + (dist_y * dist_y)):
            return False

        return True
