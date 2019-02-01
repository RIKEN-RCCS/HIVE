
KVSGLSLRayCastingRenderer = {}
setmetatable(KVSGLSLRayCastingRenderer, {__index = HiveBaseModule})

local raycasting = require('KVSGLSLRayCastingRenderer')

KVSGLSLRayCastingRenderer.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.raycasting = raycasting()

    setmetatable(this, {__index=KVSGLSLRayCastingRenderer})
    return this
end

function KVSGLSLRayCastingRenderer:Do()
    self:UpdateValue()
    local v = self.value
    self.raycasting:SetOpaqueValue(v.opaque_value)
    self.raycasting:SetSamplingStep(v.sampling_step)
    return true
end

function KVSGLSLRayCastingRenderer:renderer()
    return self.raycasting:Renderer()
end

