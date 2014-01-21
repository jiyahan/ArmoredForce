
local app = {}
app.robots = {}

app.on_connect = function(id, host, port)
end

app.on_error = function(id, err_msg)
end

app.on_read = function(id, msg)
end

local function main()
    local r = new_robots(app)
end

main()

