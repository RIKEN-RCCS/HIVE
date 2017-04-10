
LoadSTL = {}
setmetatable(LoadSTL, {__index = HiveBaseModule})

LoadSTL.new = function (varname)
    local this = HiveBaseModule.new(varname);
    this.loader = require('StlLoader')()
    setmetatable(this, {__index=LoadSTL})
    return this
end

function LoadSTL:Do()
    self:UpdateValue()
    print("swapendian")
    print(self.value.swapEndian)
    return self.loader:Load(self.value.filepath, self.value.swapEndian)
end

function LoadSTL:MeshData()
    return self.loader:MeshData()
end
