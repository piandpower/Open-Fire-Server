from . import Unit
from framework import guid
from typing import Dict
from world.actor import ActorType, Building
from world.actor.building import Farm


class Worker(Unit):
    def __init__(self, node_id: int, actor_id: int):
        Unit.__init__(self, node_id, actor_id)
        self.type = ActorType.worker

    def get_update_move_dest_node_id(self, node):
        return node.get_random_nearby_node().node_id

    def update_act(self, buildings: Dict[int, Building], units: Dict[int, Unit]):
        farm_id = guid()
        buildings[farm_id] = Farm(self.node_id, farm_id)

