from flask.views import MethodView


class UpdateView(MethodView):
    def post(self):
        return 'complete'
