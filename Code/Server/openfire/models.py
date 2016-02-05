from sqlalchemy import Column, Integer, String, Float, ForeignKey
from sqlalchemy.ext.declarative import declarative_base


Base = declarative_base()


class Node(Base):
    __tablename__ = 'node'

    node_id = Column(Integer, primary_key=True)
    name = Column(String)
    position_x = Column(Float)
    position_y = Column(Float)


class Edge(Base):
    __tablename__ = 'edge'

    start_node_id = Column(Integer, ForeignKey('node.node_id'), primary_key=True)
    end_node_id = Column(Integer, ForeignKey('node.node_id'), primary_key=True)
