from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker

engine = create_engine('sqlite:///:memory:', echo=True)
session_factory = sessionmaker(bind=engine)
Session = scoped_session(session_factory)


def create_test_database():
    from models import Base
    Base.metadata.create_all(bind=engine)

    __create_test_data()


def __create_test_data():
    from models import Node
    import random
    Session()
    for i in range(5):
        node = Node(name='node'+str(i), position_x=random.randrange(1, 11), position_y=random.randrange(1,11))
        Session.add(node)
    Session.commit()