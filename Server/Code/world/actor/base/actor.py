from world.actor.base.actor_type import ActorType


class Actor:
    type = ActorType.unknown

    def __init__(self, node_id: int, actor_id: int):
        self.node_id = node_id
        self.actor_id = actor_id
