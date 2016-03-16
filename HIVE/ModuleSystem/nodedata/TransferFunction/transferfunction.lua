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
    local v = self.value
    
    -- Analyze min/max
    if v.volume and self.vol ~= v.volume then
        self.vol = v.volume
        local analyzer = require('Analyzer').VolumeAnalyzer()
        analyzer:Execute(v.volume)
        minval = analyzer:MinX()
        maxval = analyzer:MaxX()
        self.property.minval = minval
        self.property.maxval = maxval        
        print('Tranferfunction analyzed: min=', minval, ' max=', maxval)
        local ht = analyzer:GetHistgram()
        local hist = "["
        for a,b in pairs(ht) do
            hist = hist .. string.format("%.4f", b) .. (a ~= #ht and ',' or '')
        end
        hist = hist .. "]"
        
        if network then
            local analyzedInfo = [[{
                "JSONRPC" : "2.0",
                "method" : "analyzedInfo",            
                "to" : ]] .. targetClientId ..[[,
                "id":0,
                "param" : {
                    "minval" : "]] .. minval .. [[",
                    "maxval" : "]] .. maxval .. [[",
                    "varname": "]] .. self.varname .. [[",
                    "histgram": ]] .. hist .. [[
                }
            }]]
            --print('json=', analyzedInfo)        
            network:SendJSON(analyzedInfo);
        end
    end
        
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

function TransferFunction:Min()
    print('TransferFunction:Min() > ', self.value.minval)
    return self.value.minval
end

function TransferFunction:Max()
    print('TransferFunction:Max() > ', self.value.maxval)
    return self.value.maxval
end