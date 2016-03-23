from flask import jsonify
from flask.views import MethodView


class NodeView(MethodView):
    def get(self):
        response = jsonify(
            {
                'node_view': 'data'
            })
        return response
