KVSParticleBasedRenderer = {}
setmetatable(KVSParticleBasedRenderer, {__index = HiveBaseModule})

local particle_based_renderer = require('KVSParticleBasedRenderer')

KVSParticleBasedRenderer.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.pbr = particle_based_renderer()

    setmetatable(this, {__index=KVSParticleBasedRenderer})
    return this
end

function KVSParticleBasedRenderer:Do()
    self:UpdateValue()
    local v = self.value
    self.pbr:SetSubpixelLevel(v.subpixel_level)
    self.pbr:EnableShading(v.enable_shading)
    return true
end

function KVSParticleBasedRenderer:renderer()
    return self.pbr:Renderer()
end
