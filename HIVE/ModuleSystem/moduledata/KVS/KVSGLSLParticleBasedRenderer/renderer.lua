
KVSGLSLParticleBasedRenderer = {}
setmetatable(KVSGLSLParticleBasedRenderer, {__index = HiveBaseModule})

local gp_renderer = require('KVSGLSLParticleBasedRenderer')

KVSGLSLParticleBasedRenderer.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.gpr = gp_renderer()

   setmetatable(this, {__index=KVSGLSLParticleBasedRenderer})
   return this
end

function KVSGLSLParticleBasedRenderer:Do()
   self:UpdateValue()
   local v = self.value
   self.gpr:EnableLODControl(v.enable_lod)
   self.gpr:SetRepetitionLevel(math.floor(v.repetition_level + 0.5))
   self.gpr:EnableShading(v.enable_shading)
   return true
end

function KVSGLSLParticleBasedRenderer:renderer()
   return self.gpr:Renderer()
end
