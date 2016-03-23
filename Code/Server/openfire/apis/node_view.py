from flask import jsonify
from flask.views import MethodView
from ..database import session
from ..models import Node


class NodeView(MethodView):
    def get(self):

        nodes = []
        for node in session.query(Node).all():
            nodes.append({
                'node_id': node.node_id,
                'name': node.name,
                'position_x': node.position_x,
                'position_y': node.position_y
            })

        response = jsonify({
            'nodes': nodes
        })
        return response
