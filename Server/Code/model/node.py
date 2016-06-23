from typing import Iterable
from .session import Session
from .base import Node


class NodeModel:
    @staticmethod
    def create(x: float, y: float, level: int):
        session = Session()
        strongpoint = Node(x, y, level)
        session.add(strongpoint)
        session.commit()

    @staticmethod
    def read() -> Iterable[Node]:
        session = Session()
        return session.query(Node).all()
