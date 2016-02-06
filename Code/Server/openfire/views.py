from flask import render_template
from database import session
from models import Node


def create_views(app):
    @app.route('/')
    def hello_world():
        session()
        nodes = session.query(Node).all()

        session.remove()
        return render_template('index.html', nodes=nodes)
