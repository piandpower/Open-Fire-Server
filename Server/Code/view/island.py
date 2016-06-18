from flask import jsonify
from model import StrongPointModel, StrongPointEdgeModel


class Island:
    @staticmethod
    def read():
        nodes = []
        for model in StrongPointModel.read():
            nodes.append({
                'id': model.id,
                'x': model.location_x,
                'y': model.location_y
            })

        edges = []
        for model in StrongPointEdgeModel.read():
            edges.append({
                'start_node_id': model.start_strong_point_id,
                'end_node_id': model.end_strong_point_id
            })

        return jsonify(nodes=nodes, edges=edges)
