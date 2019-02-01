KVSCellByCellMetropolisSampling = {}
setmetatable(KVSCellByCellMetropolisSampling, {__index = HiveBaseModule})

local metropolis_sampling = require('KVSCellByCellMetropolisSampling')

KVSCellByCellMetropolisSampling.new = function (varname)
   local this = HiveBaseModule.new(varname)
   this.mes = metropolis_sampling()

   setmetatable(this, {__index=KVSCellByCellMetropolisSampling})
   return this
end

function KVSCellByCellMetropolisSampling:Do()
   self:UpdateValue()
   local v = self.value
   self.mes:SetMinMaxValues(v.min_value, v.max_value)
   self.mes:SetSamplingStep(v.sampling_step)
   self.mes:SetRepetitionLevel(v.repetition_level)
   self.mes:SetTransferFunction(v.transfer_function)
   self.mes:SetVolumeObject(v.object)
   return true
end

function KVSCellByCellMetropolisSampling:object()
   self.mes:Execute()
   return self.mes:Object()
end
