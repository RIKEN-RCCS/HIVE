
KVSObjectCompositor = {}
setmetatable(KVSObjectCompositor, {__index = HiveBaseModule})

local kvsobject = require('KVSObjectCompositor')

KVSObjectCompositor.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.obj = kvsobject()

   setmetatable(this, {__index=KVSObjectCompositor})
   return this
end

function KVSObjectCompositor:Do()
   self:UpdateValue()
   local v = self.value
   self.obj:SetObject(v.object1, 0)
   self.obj:SetObject(v.object2, 1)
   self.obj:SetRenderer(v.renderer)
   self.obj:SetTranslate(v.translate[1], v.translate[2], v.translate[3])
   self.obj:SetRotate(v.rotate[1], v.rotate[2], v.rotate[3])
   self.obj:SetScale(v.scale[1], v.scale[2], v.scale[3])
   self.obj:SetShowFlag(v.show)
   return true
end

function KVSObjectCompositor:KVSRenderObj()
   local v = self.value
   self.obj:Release()
   return {
      object = self.obj:Object(),
      renderer = self.obj:Renderer()
   }
end
