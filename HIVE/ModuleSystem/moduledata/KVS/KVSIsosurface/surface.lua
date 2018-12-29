KVSIsosurface = {}
setmetatable(KVSIsosurface, {__index = HiveBaseModule})

local isosurface = require('KVSIsosurface')

KVSIsosurface.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.iso = isosurface()

    setmetatable(this, {__index=KVSIsosurface})
    return this
end

function KVSIsosurface:Do()
    self:UpdateValue()
    local v = self.value
    self.iso:SetTransferFunction(v.transfer_function)
    self.iso:SetVolumeObject(v.object)
    self.iso:SetIsolevel(v.isolevel)
    return true
end

function KVSIsosurface:object()
    return self.iso:Object()
end
