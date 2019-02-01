
KVSPolygonObject = {}
setmetatable(KVSPolygonObject, {__index = HiveBaseModule})

local render_object = require('KVSPolygonObject')

KVSPolygonObject.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.obj = render_object()

   setmetatable(this, {__index=KVSPolygonObject})
   return this
end

function KVSPolygonObject:Do()
   self:UpdateValue()
   local v = self.value
   self.obj:SetPolygonObject(v.object)
   self.obj:SetRenderer(v.renderer)
   self.obj:SetTranslate(v.translate[1], v.translate[2], v.translate[3])
   self.obj:SetRotate(v.rotate[1], v.rotate[2], v.rotate[3])
   self.obj:SetScale(v.scale[1], v.scale[2], v.scale[3])
   self.obj:SetColor(v.color[1], v.color[2], v.color[3], v.color[4])
   self.obj:SetShowFlag(v.show)
   return true
end

function KVSPolygonObject:render_object()
   local v = self.value
   self.obj:Release()
   return {
      object = self.obj:PolygonObject(),
      renderer = self.obj:Renderer()
   }
end
