from flask.views import MethodView
from .agent import BuildingAgent


class UpdateView(MethodView):
    def post(self):
        building_agent = BuildingAgent()
        building_agent.update()

        return 'complete'
