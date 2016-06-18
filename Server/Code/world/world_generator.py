from typing import Iterable
from random import uniform
from .static_actor import Node, Edge

MIN_NODE_RANGE = 100.0
SQ_MIN_NODE_RANGE = MIN_NODE_RANGE * MIN_NODE_RANGE
MAX_EDGE_RANGE = 150.0
SQ_MAX_EDGE_RANGE = MAX_EDGE_RANGE * MAX_EDGE_RANGE


class WorldGenerator:
    @classmethod
    def generate_nodes(cls):
        node_id = 1
        nodes = []
        for _ in range(10000):
            node = cls.__generate_random_node(node_id)
            if not cls.__is_overlap(node.location_x, node.location_y, nodes):
                nodes.append(node)
                node_id += 1

        return nodes

    @classmethod
    def generate_edges(cls, nodes: Iterable[Node]):
        edges = []
        for start_node in nodes:
            for end_node in nodes:
                if start_node.node_id != end_node.node_id and cls.__has_edge(start_node, end_node):
                    edges.append(Edge(start_node.node_id, end_node.node_id))

        return edges

    @staticmethod
    def __generate_random_node(node_id):
        return Node(node_id, uniform(0.0, 500.0), uniform(0.0, 500.0))

    @staticmethod
    def __is_overlap(location_x, location_y, nodes: Iterable[Node]):
        for node in nodes:
            dist_x = location_x - node.location_x
            dist_y = location_y - node.location_y
            sq_dist = (dist_x * dist_x) + (dist_y * dist_y)
            if sq_dist <= SQ_MIN_NODE_RANGE:
                return True

        return False

    @staticmethod
    def __has_edge(start_node: Node, end_node: Node):
        dist_x = start_node.location_x - end_node.location_x
        dist_y = start_node.location_y - end_node.location_y
        if SQ_MAX_EDGE_RANGE < ((dist_x * dist_x) + (dist_y * dist_y)):
            return False

        return True
