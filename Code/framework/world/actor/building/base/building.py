from framework.world.actor.base.actor import Actor
from framework.world.actor.base.actor_type import ActorType


class Building(Actor):
    def __init__(self, node_id: int, actor_id: int):
        Actor.__init__(self, node_id, actor_id)
        self.type = ActorType.building
