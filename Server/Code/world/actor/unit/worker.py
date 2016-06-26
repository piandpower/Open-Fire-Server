from .base import Unit
from world.actor.base import ActorType


class Worker(Unit):
    def __init__(self, node_id: int, actor_id: int):
        Unit.__init__(self, node_id, actor_id)
        self.type = ActorType.worker

    def get_update_move_dest_node_id(self, node):
        return node.get_random_nearby_node().node_id

