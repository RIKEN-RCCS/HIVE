
QuadGenerator = {}
setmetatable(QuadGenerator, {__index = BaseComponent})

QuadGenerator.new = function (varname)
    local this = BaseComponent.new(varname)
    this.gen = PrimitiveGenerator()
    setmetatable(this, {__index=QuadGenerator})
    return this
end

function QuadGenerator:Do()
    self:UpdateValue()
end

function QuadGenerator:MeshData()
    local v = self.value
    local width = v.width
	local height = v.height
    return self.gen:Quad(width, height);
end