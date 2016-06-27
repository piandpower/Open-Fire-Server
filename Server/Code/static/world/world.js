const NODE_LEVEL_0_COLOR = '#ffffff';
const NODE_LEVEL_1_COLOR = '#aaffff';
const NODE_LEVEL_2_COLOR = '#aaaaff';
const NODE_LEVEL_3_COLOR = '#ffaaaa';
const NODE_LEVEL_4_COLOR = '#ffffaa';

class World
{
    constructor(container, selectNodeFunction)
    {
        this.nodes = new vis.DataSet();
        this.edges = new vis.DataSet();

        let data = {
            nodes: this.nodes,
            edges: this.edges
        };
        let options = {
            nodes:{
                physics: false
            }
        };

        this.network = new vis.Network(container, data, options);

        this.network.on("selectNode", function (params) {
            selectNodeFunction(params);
        });
    }

    AddNode(nodeId, x, y, level)
    {
        this.nodes.add({
            id: nodeId,
            label: level,
            color: this._GetColor(level),
            x: x,
            y: y
        });
    }

    AddEdge(from, to)
    {
        this.edges.add({
            from: from,
            to: to
        });
    }

    _GetColor(level)
    {
        switch(level)
        {
            case 0: return NODE_LEVEL_0_COLOR;
            case 1: return NODE_LEVEL_1_COLOR;
            case 2: return NODE_LEVEL_2_COLOR;
            case 3: return NODE_LEVEL_3_COLOR;
            case 4: return NODE_LEVEL_4_COLOR;
            default: return NODE_LEVEL_0_COLOR;
        }
    }
}
