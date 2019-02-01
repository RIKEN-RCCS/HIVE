
KVSHAVSVolumeRenderer = {}
setmetatable(KVSHAVSVolumeRenderer, {__index = HiveBaseModule})

local line_renderer = require('KVSHAVSVolumeRenderer')

KVSHAVSVolumeRenderer.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.slr = line_renderer()

    setmetatable(this, {__index=KVSHAVSVolumeRenderer})
    return this
end

function KVSHAVSVolumeRenderer:Do()
    self:UpdateValue()
    local v = self.value
    self.slr:SetKBufferSize(v.k_buff_size)
    return true
end

function KVSHAVSVolumeRenderer:renderer()
    return self.slr:Renderer()
end
