from sqlalchemy import Column, Integer, String, Float, ForeignKey
from sqlalchemy.ext.declarative import declarative_base


Base = declarative_base()


class Node(Base):
    __tablename__ = 'node'

    node_id = Column(Integer, primary_key=True)
    name = Column(String)
    position_x = Column(Float)
    position_y = Column(Float)

    def __init__(self, node_id, name, position_x, position_y):
        self.node_id = node_id
        self.name = name
        self.position_x = position_x
        self.position_y = position_y


class Edge(Base):
    __tablename__ = 'edge'

    start_node_id = Column(Integer, ForeignKey('node.node_id'), primary_key=True)
    end_node_id = Column(Integer, ForeignKey('node.node_id'), primary_key=True)

    def __init__(self, start_node_id, end_node_id):
        self.start_node_id = start_node_id
        self.end_node_id = end_node_id
