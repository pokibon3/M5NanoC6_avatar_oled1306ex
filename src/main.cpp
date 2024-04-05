// for SSD1306 72x40 OLED
#include <lgfx/v1/panel/Panel_SSD1306.hpp>
#include <M5Unified.h>
#include "lgfx.h"
#include <Avatar.h>

using namespace m5avatar;
Avatar avatar;
LGFX_SSD1306_72x40 lcd; 

// Arduino Setup
void setup(void) 
{
    auto cfg = M5.config();
    M5.begin(cfg);
    lcd.init();
    lcd.setBrightness(255);
    lcd.setRotation(2);
    lcd.clear();
    avatar.setScale(0.35);
    avatar.setPosition(-100, -124);
    avatar.init();
}

// Arduino Main Loop
void loop(void) 
{
    delay(100);
}
