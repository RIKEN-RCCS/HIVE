
KVSStructuredVolumeImporter = {}
setmetatable(KVSStructuredVolumeImporter, {__index = HiveBaseModule})

local svimporter = require('KVSStructuredVolumeImporter')

KVSStructuredVolumeImporter.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.svi = svimporter()

    setmetatable(this, {__index=KVSStructuredVolumeImporter})
    return this
end

function KVSStructuredVolumeImporter:Do()
    self:UpdateValue()
    local v = self.value
    self.svi:SetFile(v.filepath)
    return true
end

function KVSStructuredVolumeImporter:object()
    return self.svi:Object()
end
