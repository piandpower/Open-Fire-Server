from world.actor.building.base import Building
from world.actor.base.actor_type import ActorType


class Castle(Building):
    def __init__(self, node_id: int, actor_id: int):
        Building.__init__(self, node_id, actor_id)
        self.type = ActorType.castle
