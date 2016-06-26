from .actor import Actor
from .actor_type import ActorType


class Worker(Actor):
    def __init__(self, node_id: int, actor_id: int):
        Actor.__init__(self, node_id, actor_id)
        self.type = ActorType.worker

    def get_update_move_dest_node_id(self, node):
        return node.get_random_nearby_node().node_id

