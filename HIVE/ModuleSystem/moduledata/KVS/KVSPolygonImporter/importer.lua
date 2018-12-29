
KVSPolygonImporter = {}
setmetatable(KVSPolygonImporter, {__index = HiveBaseModule})

local svimporter = require('KVSPolygonImporter')

KVSPolygonImporter.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.svi = svimporter()

    setmetatable(this, {__index=KVSPolygonImporter})
    return this
end

function KVSPolygonImporter:Do()
    self:UpdateValue()
    local v = self.value
    self.svi:SetFile(v.filepath)
    return true
end

function KVSPolygonImporter:object()
    return self.svi:Object()
end
