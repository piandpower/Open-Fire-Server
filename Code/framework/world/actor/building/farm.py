from framework.world.actor.building.base import Building
from framework.world.actor.base.actor_type import ActorType


class Farm(Building):
    def __init__(self, node_id: int, actor_id: int):
        Building.__init__(self, node_id, actor_id)
        self.type = ActorType.farm
