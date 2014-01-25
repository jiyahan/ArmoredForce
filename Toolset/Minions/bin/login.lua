-------------------------------------------------------
--  login.lua
--  ´¦ÀíµÇÂ¼
--  chenqiang01@7aurora.com
--  Jan 25, 2014
-------------------------------------------------------

require 'def'

local handler = {}

function verify_version(minion)
    local major, minor = 0, 0
    local msg = new_message(MID_VERSION_VERIFY)
    msg:pack('%i%i', major, minor)
    minion:send(msg)
end

local function on_verify(minion, msg)
    print(minion:id(), msg:id(), len(msg))
end

return handler