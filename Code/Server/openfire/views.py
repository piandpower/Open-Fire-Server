from database import session
from models import Node


def create_views(app):
    @app.route('/')
    def hello_world():
        session()
        temp = session.query(Node).all()

        session.remove()
        return 'Hello World!'
