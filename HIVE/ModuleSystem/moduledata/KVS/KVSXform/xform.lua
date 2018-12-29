KVSXform = {}
setmetatable(KVSXform, {__index = HiveBaseModule})

local xform = require('KVSXform')

KVSXform.new = function(varname)
   local this = HiveBaseModule.new(varname)
   this.xfo = xform()

   setmetatable(this, {__index = KVSXform})
   return this
end

function KVSXform:Do()
   self:UpdateValue()
   local v = self.value
   self.xfo:SetRotation(v.rotation[1], v.rotation[2], v.rotation[3])
   self.xfo:SetScaling(v.scaling[1], v.scaling[2], v.scaling[3])
   self.xfo:SetTranslation(v.translation[1], v.translation[2], v.translation[3])
   return true
end

function KVSXform:xform()
   return self.xfo:Xform()
end
