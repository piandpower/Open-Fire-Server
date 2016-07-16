from framework import guid
from typing import Dict
from world.actor.base.actor_type import ActorType
from world.actor.building.base import Building
from world.actor.unit.base import Unit
from world.actor.unit.worker import Worker


class Castle(Building):
    def __init__(self, node_id: int, actor_id: int):
        Building.__init__(self, node_id, actor_id)
        self.type = ActorType.castle

    def update_act(self, buildings: Dict[int, Building], units: Dict[int, Unit]):
        worker_id = guid()
        units[worker_id] = Worker(self.node_id, worker_id)
