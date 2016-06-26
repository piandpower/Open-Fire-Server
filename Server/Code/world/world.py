from typing import List
from .static_actor import Node, Edge
from .actor import Actor


class World:
    def __init__(self, nodes: List[Node], edges: List[Edge], actors: List[Actor]):
        self.__add_nodes(nodes)
        self.__add_edges(edges)
        self.__add_actors(actors)

    def update_move(self):
        for actor in self.actors:
            dest_node_id = actor.get_update_move_dest_node_id(self.nodes[actor.node_id])
            self.__move_actor(actor.node_id, dest_node_id, actor.actor_id)

    def __add_nodes(self, nodes: List[Node]):
        self.nodes = dict()
        for node in nodes:
            self.nodes[node.node_id] = node

    def __add_edges(self, edges: List[Edge]):
        for node in self.nodes.values():
            for edge in edges:
                if node.node_id == edge.start_node_id:
                    node.add_nearby_node(self.nodes[edge.end_node_id])

    def __add_actors(self, actors: List[Actor]):
        self.actors = actors

        for node in self.nodes.values():
            for actor in actors:
                if node.node_id == actor.node_id:
                    node.add_actor(actor)

    def __move_actor(self, current_node_id: int, dest_node_id: int, actor_id: int):
        actor = self.nodes[current_node_id].pop_actor(actor_id)
        self.nodes[dest_node_id].add_actor(actor)
        actor.node_id = dest_node_id
