from framework import Vector
from random import choice
from world.actor import Actor
from world.actor.building.base import Building


class Node:
    def __init__(self, node_id: int, location: Vector, level: int):
        self.node_id = node_id
        self.nearby_nodes = []
        self.actors = dict()
        self.buildings = dict()
        self.location = location
        self.level = level

    def update(self):
        pass

    def add_nearby_node(self, node: 'Node'):
        self.nearby_nodes.append(node)

    def add_actor(self, actor: Actor):
        self.actors[actor.actor_id] = actor

    def pop_actor(self, actor_id: int) -> Actor:
        return self.actors.pop(actor_id)

    def add_building(self, building: Building):
        self.buildings[building.actor_id] = building

    def pop_building(self, actor_id):
        return self.buildings.pop(actor_id)

    def get_random_nearby_node(self) -> 'Node':
        return choice(self.nearby_nodes)
