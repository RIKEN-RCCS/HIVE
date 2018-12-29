KVSUniColor = {}
setmetatable(KVSUniColor, {__index = HiveBaseModule})

local uni_color = require('KVSUniColor')

KVSUniColor.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.unc = uni_color()

    setmetatable(this, {__index=KVSUniColor})
    return this
end

function KVSUniColor:Do()
    self:UpdateValue()
    local v = self.value
    self.unc:SetColor(v.color[1], v.color[2], v.color[3], v.color[4])
    self.unc:SetGeometryObject(v.object)
    return true
end

function KVSUniColor:object()
    return self.unc:Object()
end
