let container = $('#battlefield')[0];
let world = new World(container);

world.RegistSeletNodeFunction( function(params)
{
    $('#menu').modal('show');
    console.log(params);
});

RestClient.Get('/islands', function(data)
{
    for (let i in data.strongpoints)
    {
        let strongpoint = data.strongpoints[i];
        world.AddNode(strongpoint.id, strongpoint.x, strongpoint.y, strongpoint.level);
    }

    for (let i in data.roads)
    {
        let road = data.roads[i];
        world.AddEdge(road.start_strongpoint_id, road.end_strongpoint_id);
    }
});
