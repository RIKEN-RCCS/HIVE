KVSLineRenderer = {}
setmetatable(KVSLineRenderer, {__index = HiveBaseModule})

local line_renderer = require('KVSLineRenderer')

KVSLineRenderer.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.lir = line_renderer()

   setmetatable(this, {__index=KVSLineRenderer})
   return this
end

function KVSLineRenderer:Do()
   self:UpdateValue()
   local v = self.value
   self.lir:SetEnabledShading(v.enable_shading)
   return true
end

function KVSLineRenderer:renderer()
   return self.lir:Renderer()
end
