// This file has jquey dependency
class RestClient
{
    static Post(url, callback, data)
    {
        this._Ajax('POST', url, callback, data);
    }

    static Get(url, callback, data) 
    {
        this._Ajax('GET', url, callback, data);
    }

    static Put(url, callback, data)
    {
        this._Ajax('PUT', url, callback, data);
    }

    static Delete(url, callback, data)
    {
        this._Ajax('DELETE', url, callback, data);
    }

    static _Ajax(type, url, callback, data)
    {
        $.ajax({
            type: type,
            url: url,
            success:function(data)
            {
                callback(data);
            },
            data: data,
        });
    }
}
