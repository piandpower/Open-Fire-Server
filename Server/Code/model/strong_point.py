from typing import Iterable
from .session import Session
from .base import StrongPoint


class StrongPointModel:
    @staticmethod
    def create(x: float, y: float, level: int):
        session = Session()
        strongpoint = StrongPoint(x, y, level)
        session.add(strongpoint)
        session.commit()

    @staticmethod
    def read() -> Iterable[StrongPoint]:
        session = Session()
        return session.query(StrongPoint).all()
