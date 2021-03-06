-------------------------------------------------------
--  app.lua
--  机器人程序的入口脚本
--  chenqiang01@7aurora.com
--  Jan 24, 2014
-------------------------------------------------------

require 'login'

local app = {}
app.minions = {}
app.handlers = {}

function get_minion(id)
    return assert(app.minions[id])
end

-- 创建连接
function on_start()
    local host = '127.0.0.1'
    local port = 32450
    
    for n=1, 2 do
        local id, minion = new_minion(host, port, callback)
        if id then
            app.minions[id] = minion    
        end
        print(string.format('%d [%s:%d] start connecting...', id, host, port))
    end
end

local function timer_callback()

end

-- 连接上服务器
function on_connect(minion, host, port)    
    print(tostring(minion))
    print(id, 'connected OK.')
    verify_version(minion)
end

-- 读取到数据
function on_read(minion, msg)
    print(tostring(minion), tostring(msg))
    print(msg:id())
end

-- 发生错误
function on_error(minion, err)
    print(minion:id(), err)
end




