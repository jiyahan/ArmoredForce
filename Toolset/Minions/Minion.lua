--
-- �����˳���ģ��ͻ��˵�������Ϊ
--

require 'Login'

-- ��������
local g_total = {}

-- ����
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

-- �յ���Ϣ
function OnMessage(id, msg)
end
