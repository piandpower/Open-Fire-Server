from typing import Iterable
from random import uniform
from math import pi, cos, sin
from copy import deepcopy
from .static_actor import Node, Edge
from framework import Vector

NODE_ID_UNKNOWN = 'NODE_ID_UNKNOWN'
MAX_WORLD_RADIUS = 500.0
SQ_MAX_WORLD_RADIUS = MAX_WORLD_RADIUS * MAX_WORLD_RADIUS
MIN_NODE_RANGE = 100.0
SQ_MIN_NODE_RANGE = MIN_NODE_RANGE * MIN_NODE_RANGE
MAX_NODE_RANGE = 150.0
SQ_MAX_NODE_RANGE = MAX_NODE_RANGE * MAX_NODE_RANGE


class WorldGenerator:
    @classmethod
    def generate_nodes(cls):
        level_0_nodes = [Node(NODE_ID_UNKNOWN, 0.0, 0.0, 0)]

        nodes = level_0_nodes
        level_1_nodes = []
        for _ in range(10):
            node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
            direction = cls.__generate_random_vector()
            direction *= node_range
            if not cls.__is_overlap(direction.x, direction.y, nodes + level_1_nodes):
                level_1_nodes.append(Node(NODE_ID_UNKNOWN, direction.x, direction.y, 1))
        nodes += level_1_nodes

        level_2_nodes = []
        for node in level_1_nodes:
            for _ in range(10):
                node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
                direction = cls.__generate_random_vector()
                direction *= node_range
                location_x = node.location_x + direction.x
                location_y = node.location_y + direction.y
                if not cls.__is_overlap(location_x, location_y, nodes + level_2_nodes):
                    level_2_nodes.append(Node(NODE_ID_UNKNOWN, location_x, location_y, 2))
        nodes += level_2_nodes

        level_3_nodes = []
        for node in level_2_nodes:
            for _ in range(10):
                node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
                direction = cls.__generate_random_vector()
                direction *= node_range
                location_x = node.location_x + direction.x
                location_y = node.location_y + direction.y
                if not cls.__is_overlap(location_x, location_y, nodes + level_3_nodes):
                    level_3_nodes.append(Node(NODE_ID_UNKNOWN, location_x, location_y, 3))
        nodes += level_3_nodes

        level_4_nodes = []
        for node in level_3_nodes:
            for _ in range(10):
                node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
                direction = cls.__generate_random_vector()
                direction *= node_range
                location_x = node.location_x + direction.x
                location_y = node.location_y + direction.y
                if not cls.__is_overlap(location_x, location_y, nodes + level_4_nodes):
                    level_4_nodes.append(Node(NODE_ID_UNKNOWN, location_x, location_y, 4))
        nodes += level_4_nodes

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
    def __generate_random_vector():
        theta = uniform(0, 2 * pi)
        x = cos(theta)
        y = sin(theta)
        return Vector(x, y)

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
        if SQ_MAX_NODE_RANGE < ((dist_x * dist_x) + (dist_y * dist_y)):
            return False

        return True
