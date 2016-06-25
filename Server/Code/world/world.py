from typing import List
from .static_actor import Node, Edge
from .actor import Actor


class World:
    def __init__(self, nodes: List[Node], edges: List[Edge], actors: List[Actor]):
        self.nodes = nodes
        self.edges = edges
        self.actors = actors

    def update_move(self):
        pass
