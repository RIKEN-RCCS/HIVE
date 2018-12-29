
KVSUnstructuredVolumeImporter = {}
setmetatable(KVSUnstructuredVolumeImporter, {__index = HiveBaseModule})

local uvimporter = require('KVSUnstructuredVolumeImporter')

KVSUnstructuredVolumeImporter.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.uvi = uvimporter()

    setmetatable(this, {__index=KVSUnstructuredVolumeImporter})
    return this
end

function KVSUnstructuredVolumeImporter:Do()
    self:UpdateValue()
    local v = self.value
    self.uvi:SetFile(v.filepath)
    return true
end

function KVSUnstructuredVolumeImporter:object()
    return self.uvi:Object()
end

function KVSUnstructuredVolumeImporter:min_value()
    return self.uvi:MinValue()
end

function KVSUnstructuredVolumeImporter:max_value()
    return self.uvi:MaxValue()
end
