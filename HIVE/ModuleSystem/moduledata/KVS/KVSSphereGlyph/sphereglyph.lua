
KVSSphereGlyph = {}
setmetatable(KVSSphereGlyph, {__index = HiveBaseModule})

local sphereglyph = require('KVSSphereGlyph')

KVSSphereGlyph.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.sphereglyph = sphereglyph()

    setmetatable(this, {__index=KVSSphereGlyph})
    return this
end

function KVSSphereGlyph:Do()
    self:UpdateValue()
    return true
end

function KVSSphereGlyph:renderer()
    return self.sphereglyph:Renderer()
end
