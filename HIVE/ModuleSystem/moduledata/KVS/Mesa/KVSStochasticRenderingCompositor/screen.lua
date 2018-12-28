KVSStochasticRenderingCompositor = {}
setmetatable(KVSStochasticRenderingCompositor, {__index = HiveBaseModule})

local compositor = require('KVSScreen')

KVSStochasticRenderingCompositor.new = function(varname)
    local this = HiveBaseModule.new(varname)
    this.com = compositor.StochasticRenderingCompositor()
    
    setmetatable(this, {__index = KVSStochasticRenderingCompositor})
    return this
end

function KVSStochasticRenderingCompositor:Do()
    self:UpdateValue()
    self.com:Clear()
    local v = self.value
    self.com:SetScreenSize(v.screen_size[1], v.screen_size[2])
    if v.render_object ~= nil then
        for i, obj in pairs(v.render_object) do
            self.com:Register(obj.object, obj.renderer)
        end
    end
    self.com:EnableLODControl(v.enable_lod)
    self.com:SetRepetitionLevel(math.floor(v.repetition_level + 0.5))
    self.com:Composite()
    return true
end

function KVSStochasticRenderingCompositor:Image()
    return self.com:Image()
end
