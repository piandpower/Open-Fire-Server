from typing import Iterable
from .session import Session
from .base import StrongPoint


class StrongPointModel:
    @staticmethod
    def create(x: float, y: float):
        session = Session()
        strongpoint = StrongPoint(x, y)
        session.add(strongpoint)
        session.commit()

    @staticmethod
    def read() -> Iterable[StrongPoint]:
        session = Session()
        return session.query(StrongPoint).all()
