
KVSStochasticTetrahedraRenderer = {}
setmetatable(KVSStochasticTetrahedraRenderer, {__index = HiveBaseModule})

local st_renderer = require('KVSStochasticTetrahedraRenderer')

KVSStochasticTetrahedraRenderer.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.str = st_renderer()

    setmetatable(this, {__index=KVSStochasticTetrahedraRenderer})
    return this
end

function KVSStochasticTetrahedraRenderer:Do()
    self:UpdateValue()
    local v = self.value
    self.str:SetTransferFunction(v.transfer_function)
    self.str:EnableShading(v.enable_shading)
    return true
end

function KVSStochasticTetrahedraRenderer:renderer()
    return self.str:Renderer()
end
