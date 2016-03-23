from flask import Blueprint
from .node_view import NodeView

apis = Blueprint('apis', __name__)
apis.add_url_rule('/nodes', view_func=NodeView.as_view('nodes'))
