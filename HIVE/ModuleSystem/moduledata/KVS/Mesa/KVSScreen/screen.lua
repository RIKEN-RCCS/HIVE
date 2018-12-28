KVSScreen = {}
setmetatable(KVSScreen, {__index = HiveBaseModule})

local screen = require('KVSScreen')

KVSScreen.new = function(varname)
    local this = HiveBaseModule.new(varname)
    this.scr = screen.Screen()

    setmetatable(this, {__index = KVSScreen})
    return this
end

function KVSScreen:Do()
    self:UpdateValue()
    self.scr:Clear()
    local v = self.value
    self.scr:SetScreenSize(v.screen_size[1], v.screen_size[2])
    if v.render_object ~= nil then
        for i, obj in pairs(v.render_object) do
            self.scr:Register(obj.object, obj.renderer)
        end
    end
    self.scr:Render()
    return true
end

function KVSScreen:Image()
    return self.scr:Image()
end
