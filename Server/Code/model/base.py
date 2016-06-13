from sqlalchemy import Column, ForeignKey, Integer, Float
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class StrongPoint(Base):
    __tablename__ = 'strong_points'

    id = Column(Integer, primary_key=True)
    location_x = Column(Float, nullable=False)
    location_y = Column(Float, nullable=False)

    def __init__(self, x: float, y: float):
        self.location_x = x
        self.location_y = y

    def to_dict(self):
        return {
            'id': self.id,
            'location': {
                'x': self.location_x,
                'y': self.location_y
            }
        }


class StrongPointEdge(Base):
    __tablename__ = 'strong_point_edges'

    def __init__(self, start_strong_point_id, end_strong_point_id):
        self.start_strong_point_id = start_strong_point_id
        self.end_strong_point_id = end_strong_point_id

    start_strong_point_id = Column(Integer,
                                   ForeignKey('strong_points.id'),
                                   primary_key=True, autoincrement=False,
                                   nullable=False)
    end_strong_point_id = Column(Integer,
                                 ForeignKey('strong_points.id'),
                                 primary_key=True,
                                 autoincrement=False,
                                 nullable=False)


class Actor(Base):
    __tablename__ = 'actors'

    id = Column(Integer, primary_key=True)
    strong_point_id = Column(Integer, ForeignKey('strong_points.id'), autoincrement=False, nullable=False)
