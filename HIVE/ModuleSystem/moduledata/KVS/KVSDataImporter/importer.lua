KVSDataImporter = {}
setmetatable(KVSDataImporter, {__index = HiveBaseModule})

local data_importer = require('KVSDataImporter')

KVSDataImporter.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.dim = data_importer()

    setmetatable(this, {__index=KVSDataImporter})
    return this
end

function KVSDataImporter:Do()
    self:UpdateValue()
    local v = self.value
    self.dim:SetFile(v.filepath)
    return true
end

function KVSDataImporter:object()
    return self.dim:Object()
end
