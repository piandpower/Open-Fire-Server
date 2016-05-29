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
    def read():
        session = Session()
        strong_points = []
        for row in session.query(StrongPoint).all():
            strong_points.append(row.to_dict())

        return strong_points
