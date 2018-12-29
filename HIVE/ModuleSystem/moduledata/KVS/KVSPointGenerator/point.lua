
KVSPointGenerator = {}
setmetatable(KVSPointGenerator, {__index = HiveBaseModule})

local pointdata = require('KVSPointGenerator')

KVSPointGenerator.new = function (varname)
    local this = HiveBaseModule.new(varname)
    this.point = pointdata()

    setmetatable(this, {__index=KVSPointGenerator})
    return this
end

function KVSPointGenerator:Do()
    self:UpdateValue()
    local v = self.value
    self.point:SetMinCoord(v.min_coord[1], v.min_coord[2], v.min_coord[3])
    self.point:SetMaxCoord(v.max_coord[1], v.max_coord[2], v.max_coord[3])
    self.point:Generate();
    return true
end

function KVSPointGenerator:point_object()
    return self.point:Object()
end
