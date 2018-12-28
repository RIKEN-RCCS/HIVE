
KVSTornadoVolumeData = {}
setmetatable(KVSTornadoVolumeData, {__index = HiveBaseModule})

local tvdata = require('KVSTornadoVolumeData')

KVSTornadoVolumeData.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.tvd = tvdata()

    setmetatable(this, {__index=KVSTornadoVolumeData})
    return this
end

function KVSTornadoVolumeData:Do()
    self:UpdateValue()
    local v = self.value
	self.tvd:SetResolution(v.resolution[1], v.resolution[2], v.resolution[3])
	self.tvd:SetTime(v.time)
    return true
end

function KVSTornadoVolumeData:object()
    return self.tvd:Object()
end
