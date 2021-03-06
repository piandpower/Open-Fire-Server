from typing import Iterable
from random import uniform
from math import pi, cos, sin
from framework.world.strongpoint import Strongpoint, Road
from framework import Vector

NODE_ID_UNKNOWN = 0
MAX_WORLD_RADIUS = 5000.0
SQ_MAX_WORLD_RADIUS = MAX_WORLD_RADIUS * MAX_WORLD_RADIUS
MIN_NODE_RANGE = 1000.0
SQ_MIN_NODE_RANGE = MIN_NODE_RANGE * MIN_NODE_RANGE
MAX_NODE_RANGE = 1500.0
SQ_MAX_NODE_RANGE = MAX_NODE_RANGE * MAX_NODE_RANGE


class WorldGenerator:
    @classmethod
    def generate_nodes(cls):
        level_0_nodes = [Strongpoint(NODE_ID_UNKNOWN, Vector(0.0, 0.0), 0)]

        nodes = level_0_nodes
        level_1_nodes = []
        for _ in range(10):
            node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
            direction = cls.__generate_random_vector()
            direction *= node_range
            if not cls.__is_overlap(direction, nodes + level_1_nodes):
                level_1_nodes.append(Strongpoint(NODE_ID_UNKNOWN, direction, 1))
        nodes += level_1_nodes

        level_2_nodes = []
        for node in level_1_nodes:
            for _ in range(10):
                node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
                direction = cls.__generate_random_vector()
                direction *= node_range
                location = node.location + direction
                if not cls.__is_overlap(location, nodes + level_2_nodes):
                    level_2_nodes.append(Strongpoint(NODE_ID_UNKNOWN, location, 2))
        nodes += level_2_nodes

        level_3_nodes = []
        for node in level_2_nodes:
            for _ in range(10):
                node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
                direction = cls.__generate_random_vector()
                direction *= node_range
                location = node.location + direction
                if not cls.__is_overlap(location, nodes + level_3_nodes):
                    level_3_nodes.append(Strongpoint(NODE_ID_UNKNOWN, location, 3))
        nodes += level_3_nodes

        level_4_nodes = []
        for node in level_3_nodes:
            for _ in range(10):
                node_range = uniform(MIN_NODE_RANGE, MAX_NODE_RANGE)
                direction = cls.__generate_random_vector()
                direction *= node_range
                location = node.location + direction
                if not cls.__is_overlap(location, nodes + level_4_nodes):
                    level_4_nodes.append(Strongpoint(NODE_ID_UNKNOWN, location, 4))
        nodes += level_4_nodes

        return nodes

    @classmethod
    def generate_edges(cls, nodes: Iterable[Strongpoint]):
        edges = []
        for start_node in nodes:
            for end_node in nodes:
                if start_node.node_id != end_node.node_id and cls.__has_edge(start_node, end_node):
                    edges.append(Road(start_node.node_id, end_node.node_id))

        return edges

    @staticmethod
    def __generate_random_vector():
        theta = uniform(0, 2 * pi)
        x = cos(theta)
        y = sin(theta)
        return Vector(x, y)

    @staticmethod
    def __is_overlap(location: Vector, nodes: Iterable[Strongpoint]):
        for node in nodes:
            dist_x = location.x - node.location.x
            dist_y = location.y - node.location.y
            sq_dist = (dist_x * dist_x) + (dist_y * dist_y)
            if sq_dist <= SQ_MIN_NODE_RANGE:
                return True

        return False

    @staticmethod
    def __has_edge(start_node: Strongpoint, end_node: Strongpoint):
        dist_x = start_node.location.x - end_node.location.x
        dist_y = start_node.location.y - end_node.location.y
        if SQ_MAX_NODE_RANGE < ((dist_x * dist_x) + (dist_y * dist_y)):
            return False

        return True
