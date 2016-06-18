class World
{
    constructor(container)
    {
        this.nodes = new vis.DataSet();
        this.edges = new vis.DataSet();

        let data = {
            nodes: this.nodes,
            edges: this.edges
        };
        let options = {};

        this.network = new vis.Network(container, data, options);
    }

    AddNode(nodeId, x, y)
    {
        this.nodes.add({
            id: nodeId,
            label: nodeId,
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
}
