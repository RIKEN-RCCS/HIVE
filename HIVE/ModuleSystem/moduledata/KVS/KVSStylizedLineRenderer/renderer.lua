
KVSStylizedLineRenderer = {}
setmetatable(KVSStylizedLineRenderer, {__index = HiveBaseModule})

local line_renderer = require('KVSStylizedLineRenderer')

KVSStylizedLineRenderer.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.slr = line_renderer()

    setmetatable(this, {__index=KVSStylizedLineRenderer})
    return this
end

function KVSStylizedLineRenderer:Do()
    self:UpdateValue()
    local v = self.value
    self.slr:EnableShading(v.enable_shading)
    return true
end

function KVSStylizedLineRenderer:renderer()
    return self.slr:Renderer()
end
