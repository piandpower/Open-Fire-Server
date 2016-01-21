from flask import Blueprint
from world import World

bp = Blueprint('gameoflife', __name__)


@bp.route('/')
@bp.route('/index')
def index():
    world = World()
    for tile in world.get_tiles():
        print(tile)
    return 'Helo World!'
