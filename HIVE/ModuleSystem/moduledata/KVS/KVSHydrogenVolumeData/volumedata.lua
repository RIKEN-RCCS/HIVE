
KVSHydrogenVolumeData = {}
setmetatable(KVSHydrogenVolumeData, {__index = HiveBaseModule})

local hvdata = require('KVSHydrogenVolumeData')

KVSHydrogenVolumeData.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.hvd = hvdata()

    setmetatable(this, {__index=KVSHydrogenVolumeData})
    return this
end

function KVSHydrogenVolumeData:Do()
    self:UpdateValue()
    local v = self.value
	self.hvd:SetResolution(v.resolution[1], v.resolution[2], v.resolution[3])
    return true
end

function KVSHydrogenVolumeData:object()
    return self.hvd:Object()
end
