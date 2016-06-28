let container = $('#battlefield')[0];
let world = new World(container);

world.RegistSeletNodeFunction( function(params)
{
    $('#menu').modal('show');
    console.log(params);
});

RestClient.Get('/islands', function(data)
{
    let nodes = data.nodes;
    for (let i in data.nodes)
    {
        let node = data.nodes[i];
        world.AddNode(node.id, node.x, node.y, node.level);
    }

    for (let i in data.edges)
    {
        let edge = data.edges[i];
        world.AddEdge(edge.start_node_id, edge.end_node_id);
    }
});
