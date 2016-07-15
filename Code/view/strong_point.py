'''
from flask import jsonify
from model import NodeModel


class StrongPoint:
    @staticmethod
    def read():
        strong_points = []
        for model in NodeModel.read():
            strong_points.append({
                'id': model.id,
                'location': {
                    'x': model.location_x,
                    'y': model.location_y
                }

            })
        return jsonify(strong_points=strong_points)

    @staticmethod
    def read_by_user(user_id):
        return 'id: ' + str(user_id)
'''
