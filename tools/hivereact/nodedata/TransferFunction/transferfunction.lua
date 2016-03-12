TransferFunction = {}
setmetatable(TransferFunction, {__index = BaseComponent})

TransferFunction.new = function (varname)
    local this = BaseComponent.new(varname)
    setmetatable(this, {__index=TransferFunction})
    this.gentex = GenTexture()
    return this
end

function TransferFunction:Do()
    self:UpdateValue()
    
    local rgba = self.value.rgba;
    --print('rgba=', #rgba)
    
    if #rgba == 0 then
        rgba = {}
        local i
        for i = 1, 256 do
            rgba[4*i]   = 255
            rgba[4*i+1] = 0
            rgba[4*i+2] = 0
            rgba[4*i+3] = i-1
        end
    end
    
	self.gentex:Create2D(rgba, 1, 256, 1);
end

function TransferFunction:Image()
    return self.gentex:ImageData()
end