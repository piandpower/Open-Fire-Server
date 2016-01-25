from flask import Blueprint, render_template
from world import World

bp = Blueprint('gameoflife', __name__)


@bp.route('/')
@bp.route('/index')
def index():
    return render_template('index.html')
