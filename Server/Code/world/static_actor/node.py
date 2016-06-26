from framework import Vector
from random import choice
from world.actor import Actor


class Node:
    def __init__(self, node_id: int, location: Vector, level: int):
        self.node_id = node_id
        self.nearby_nodes = []
        self.actors = dict()
        self.location = location
        self.level = level

    def add_nearby_node(self, node: 'Node'):
        self.nearby_nodes .append(node)

    def add_actor(self, actor: Actor):
        self.actors[actor.actor_id] = actor

    def pop_actor(self, actor_id: int) -> Actor:
        return self.actors.pop(actor_id)

    def get_random_nearby_node(self) -> 'Node':
        return choice(self.nearby_nodes)
