
KVSRayCastingRenderer = {}
setmetatable(KVSRayCastingRenderer, {__index = HiveBaseModule})

local raycasting = require('KVSRayCastingRenderer')

KVSRayCastingRenderer.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.raycasting = raycasting()

   setmetatable(this, {__index=KVSRayCastingRenderer})
   return this
end

function KVSRayCastingRenderer:Do()
   self:UpdateValue()
   local v = self.value
   self.raycasting:SetOpaqueValue(v.opaque_value)
   self.raycasting:SetSamplingStep(v.sampling_step)
   self.raycasting:SetTransferFunction(v.transfer_function)
   return true
end

function KVSRayCastingRenderer:renderer()
   return self.raycasting:Renderer()
end
