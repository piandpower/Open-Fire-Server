from .session import Session
from .base import StrongPoint


class StrongPointModel:
    @staticmethod
    def read():
        session = Session()
        strong_points = []
        for row in session.query(StrongPoint).all():
            strong_points.append(row.to_dict())

        return strong_points
