from .actor_type import ActorType


class Worker:
    def __init__(self, node_id: int, actor_id: int):
        self.node_id = node_id
        self.actor_id = actor_id
        self.type = ActorType.worker
