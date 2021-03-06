from framework.world.actor.base import Actor
from framework.world.actor.base.actor_type import ActorType


class Unit(Actor):
    def __init__(self, node_id: int, actor_id: int):
        Actor.__init__(self, node_id, actor_id)
        self.type = ActorType.unit

    def get_update_move_dest_node_id(self, node):
        pass
