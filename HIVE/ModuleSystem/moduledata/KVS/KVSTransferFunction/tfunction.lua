
KVSTransferFunction = {}
setmetatable(KVSTransferFunction, {__index = HiveBaseModule})

local transfer_function = require('KVSTransferFunction')

KVSTransferFunction.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.tf = transfer_function()

    setmetatable(this, {__index=KVSTransferFunction})
    return this
end

function KVSTransferFunction:Do()
    self:UpdateValue()
    local v = self.value
    self.tf:SetFile(v.filepath)
    return true
end

function KVSTransferFunction:transfer_function()
    return self.tf:TransferFunction()
end
