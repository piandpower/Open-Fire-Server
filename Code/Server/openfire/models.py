from sqlalchemy import Column, Integer, String, Float, ForeignKey, create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from sqlalchemy.ext.declarative import declarative_base

engine = create_engine('sqlite:///:memory:', echo=True)
session_factory = sessionmaker(bind=engine)
Session = scoped_session(session_factory)

Base = declarative_base()


def create_test_database():
    from models import Base
    Base.metadata.create_all(bind=engine)

    __create_test_data()


def __create_test_data():
    import random
    Session()
    for i in range(5):
        node = Node(name='node'+str(i), position_x=random.randrange(1, 11), position_y=random.randrange(1,11))
        Session.add(node)
    Session.commit()


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
