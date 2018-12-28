KVSExternalFaces = {}
setmetatable(KVSExternalFaces, {__index = HiveBaseModule})

local external_faces = require('KVSExternalFaces')

KVSExternalFaces.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.exf = external_faces()

    setmetatable(this, {__index=KVSExternalFaces})
    return this
end

function KVSExternalFaces:Do()
    self:UpdateValue()
    local v = self.value
    self.exf:SetTransferFunction(v.transfer_function)
    self.exf:SetVolumeObject(v.object)
    return true
end

function KVSExternalFaces:object()
    return self.exf:Object()
end
