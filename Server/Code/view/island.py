from flask import jsonify
from model import NodeModel, EdgeModel


class Island:
    @staticmethod
    def read():
        nodes = []
        for model in NodeModel.read():
            nodes.append({
                'id': model.id,
                'x': model.location_x,
                'y': model.location_y,
                'level': model.level
            })

        edges = []
        for model in EdgeModel.read():
            edges.append({
                'start_node_id': model.start_strong_point_id,
                'end_node_id': model.end_strong_point_id
            })

        return jsonify(nodes=nodes, edges=edges)
