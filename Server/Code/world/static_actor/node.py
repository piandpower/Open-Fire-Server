from framework import Vector


class Node:
    def __init__(self, node_id: int, location: Vector, level: int):
        self.node_id = node_id
        self.location = location
        self.level = level
