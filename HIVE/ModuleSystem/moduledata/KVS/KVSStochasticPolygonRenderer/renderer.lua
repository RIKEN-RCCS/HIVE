
KVSStochasticPolygonRenderer = {}
setmetatable(KVSStochasticPolygonRenderer, {__index = HiveBaseModule})

local sp_renderer = require('KVSStochasticPolygonRenderer')

KVSStochasticPolygonRenderer.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.spr = sp_renderer()

    setmetatable(this, {__index=KVSStochasticPolygonRenderer})
    return this
end

function KVSStochasticPolygonRenderer:Do()
    self:UpdateValue()
    local v = self.value
    self.spr:EnableShading(v.enable_shading)
    return true
end

function KVSStochasticPolygonRenderer:renderer()
    return self.spr:Renderer()
end
