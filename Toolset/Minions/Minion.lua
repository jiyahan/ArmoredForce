--
-- �����˳���ģ��ͻ��˵�������Ϊ
--

-- ��������
local g_total = {}

-- ����
function OnStartup()
    local m = new_minion()
    local host = '127.0.0.1'
    local port = 32450
    if m:connect(host, port) then
        g_total[m:get_id()] = m
        print(string.format('Connect %s:%d OK.', host, port))
    else
        print(string.format('Connect %s:%d failed.', host, port))
    end
end

-- �յ���Ϣ
function OnMessage(id, msg)
end
