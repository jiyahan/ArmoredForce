--
--
--

require('MsgDef')

function VerifyVersion(id)
    local msg = new_message(MID_VERSION_VERIFY)
    msg:pack('%i%i', 100, 200)
    msg:send(id)
end

