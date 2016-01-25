from flask import Blueprint, render_template

bp = Blueprint('gameoflife', __name__)


@bp.route('/')
@bp.route('/index')
def index():
    return render_template('index.html')
