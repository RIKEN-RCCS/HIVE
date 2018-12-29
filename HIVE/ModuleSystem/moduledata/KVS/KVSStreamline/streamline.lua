KVSStreamline = {}
setmetatable(KVSStreamline, {__index = HiveBaseModule})

local streamline = require('KVSStreamline')

KVSStreamline.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.stl = streamline()

   setmetatable(this, {__index=KVSStreamline})
   return this
end

function KVSStreamline:Do()
   self:UpdateValue()
   local v = self.value
   self.stl:SetVolumeObject(v.volume_object)
   self.stl:SetTransferFunction(v.transfer_function)
   self.stl:SetMaxCoord(v.max_coord[1], v.max_coord[2], v.max_coord[3])
   self.stl:SetMinCoord(v.min_coord[1], v.min_coord[2], v.min_coord[3])
   self.stl:SetDelta(v.delta[1], v.delta[2], v.delta[3])
   return true
end

function KVSStreamline:object()
   self.stl:Exec()
   return self.stl:Object()
end
