
KVSCellByCellUniformSampling = {}
setmetatable(KVSCellByCellUniformSampling, {__index = HiveBaseModule})

local samplingdata = require('KVSCellByCellUniformSampling')

KVSCellByCellUniformSampling.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.sampling = samplingdata()

   setmetatable(this, {__index=KVSCellByCellUniformSampling})
   return this
end

function KVSCellByCellUniformSampling:Do()
   self:UpdateValue()
   local v = self.value
   self.sampling:SetVolumeObject(v.volume_object)
   self.sampling:SetTransferFunction(v.transfer_function)
   self.sampling:SetRepetitionLevel(v.repetition_level)
   self.sampling:SetSamplingStep(v.sampling_step)
   self.sampling:SetMinMaxValues(v.min_value, v.max_value)
   return true
end

function KVSCellByCellUniformSampling:object()
   self.sampling:Execute()
   return self.sampling:Object()
end
