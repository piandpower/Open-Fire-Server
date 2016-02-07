from flask import render_template
from database import session
from models import Node, Edge


def create_views(app):
    @app.route('/')
    @app.route('/world-map')
    def hello_world():
        session()
        nodes = session.query(Node).all()
        edges = session.query(Edge).all()

        session.remove()
        return render_template('world-map.html', nodes=nodes, edges=edges)
