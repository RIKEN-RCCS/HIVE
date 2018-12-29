
KVSObject = {}
setmetatable(KVSObject, {__index = HiveBaseModule})

local kvsobject = require('KVSObject')

KVSObject.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.obj = kvsobject()

   setmetatable(this, {__index=KVSObject})
   return this
end

function KVSObject:Do()
   self:UpdateValue()
   local v = self.value
   self.obj:SetObject(v.object)
   self.obj:SetRenderer(v.renderer)
   self.obj:SetTranslate(v.translate[1], v.translate[2], v.translate[3])
   self.obj:SetRotate(v.rotate[1], v.rotate[2], v.rotate[3])
   self.obj:SetScale(v.scale[1], v.scale[2], v.scale[3])
   self.obj:SetShowFlag(v.show)
   return true
end

function KVSObject:KVSRenderObj()
   local v = self.value
   self.obj:Release()
   return {
      object = self.obj:Object(),
      renderer = self.obj:Renderer()
   }
end
