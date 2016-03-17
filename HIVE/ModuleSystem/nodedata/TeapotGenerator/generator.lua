
TeapotGenerator = {}
setmetatable(TeapotGenerator, {__index = BaseComponent})

TeapotGenerator.new = function (varname)
    local this = BaseComponent.new(varname)
    this.gen = PrimitiveGenerator()    
    setmetatable(this, {__index=TeapotGenerator})
    return this
end

function TeapotGenerator:Do()
    self:UpdateValue()
    return true
end

function TeapotGenerator:MeshData()
    local v = self.value    
    local size = v.size    
    return self.gen:Teapot(size);
end
