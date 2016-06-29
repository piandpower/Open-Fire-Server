from .session import Session
from .base import Edge


class EdgeModel:
    @staticmethod
    def create(start_strong_point_id: int, end_strong_point_id: int):
        session = Session()
        strong_point_edge = Edge(start_strong_point_id, end_strong_point_id)
        session.add(strong_point_edge)
        session.commit()

    @staticmethod
    def read():
        session = Session()
        return session.query(Edge).all()
