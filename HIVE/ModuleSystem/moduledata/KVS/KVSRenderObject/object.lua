KVSRenderObject = {}
setmetatable(KVSRenderObject, {__index = HiveBaseModule})

local render_object = require('KVSRenderObject')

KVSRenderObject.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.reo = render_object()

   setmetatable(this, {__index=KVSRenderObject})
   return this
end

function KVSRenderObject:Do()
   self:UpdateValue()
   local v = self.value
   self.reo:SetObject(v.object)
   self.reo:SetRenderer(v.renderer)
   self.reo:SetShaderFlag(v.shader)
   self.reo:SetShadingFlag(v.shading)
   self.reo:SetShowFlag(v.show)
   self.reo:SetXform(v.xform)
   return true
end

function KVSRenderObject:render_object()
   local v = self.value
   self.reo:Release()
   return {
      object = self.reo:Object(),
      renderer = self.reo:Renderer()
   }
end
