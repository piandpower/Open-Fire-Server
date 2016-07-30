from framework import Vector
from random import choice
from framework.world.actor import ActorType, Unit
from framework.world.actor.building.base import Building


class Strongpoint:
    def __init__(self, node_id: str, location: Vector, level: int):
        self.node_id = node_id
        self.nearby_nodes = []
        self.units = dict()
        self.buildings = dict()
        self.location = location
        self.level = level

    def update_act(self):
        for building in self.buildings.values():
            building.update_act(self.buildings, self.units)

        for unit in self.units.values():
            unit.update_act(self.buildings, self.units)

    def add_nearby_node(self, node: 'Strongpoint'):
        self.nearby_nodes.append(node)

    def add_unit(self, unit: Unit):
        self.units[unit.actor_id] = unit

    def pop_unit(self, actor_id: int) -> Unit:
        return self.units.pop(actor_id)

    def add_building(self, building: Building):
        self.buildings[building.actor_id] = building

    def pop_building(self, actor_id):
        return self.buildings.pop(actor_id)

    def get_unit_by_type(self, unit_type: ActorType):
        for unit in self.units.values():
            if unit.type == unit_type:
                return unit

        return None

    def get_building_by_type(self, building_type: ActorType):
        for building in self.buildings.values():
            if building.type == building_type:
                return building

        return None

    def get_random_nearby_node(self) -> 'Strongpoint':
        return choice(self.nearby_nodes)
