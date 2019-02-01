KVSWriteFld = {}
setmetatable(KVSWriteFld, {__index = HiveBaseModule})

local write_fld = require('KVSWriteFld')

KVSWriteFld.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.fld = write_fld()

    setmetatable(this, {__index=KVSWriteFld})
    return this
end

function KVSWriteFld:Do()
    self:UpdateValue()
    local v = self.value
    self.fld:SetVolumeObject(v.object)
    self.fld:SetOutputFilePath(v.filepath)
    return true
end
