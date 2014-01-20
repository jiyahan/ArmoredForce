--
-- 机器人程序，模拟客户端的所有行为
--

require 'Login'

-- 所有连接
local g_total = {}

-- 启动
function OnStartup()
    local m = new_minion()
    local host = '127.0.0.1'
    local port = 32450
    if m:connect(host, port) then
        local id = m:get_id()
        g_total[id] = m        
        print(string.format('Connect %s:%d OK.', host, port))
        VerifyVersion(id)
    else
        print(string.format('Connect %s:%d failed.', host, port))
    end
end

-- 收到消息
function OnMessage(id, msg)
end
