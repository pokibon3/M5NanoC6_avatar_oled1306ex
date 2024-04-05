#pragma once
#include <Arduino.h>       // Atomのヘッダファイル（Arduino.h /Wire.h /FastLED.h含む）
#define LGFX_USE_V1       // v1.0.0 を有効にします(v0からの移行期間の特別措置とのこと。書かない場合は旧v0系で動作)
#include <M5GFX.h>  // lovyanGFXのヘッダを準備

class LGFX_SSD1306_72x40 : public lgfx::LGFX_Device {
  lgfx::Panel_SSD1306   _panel_instance;  // SSD1306を使用する場合
  lgfx::Bus_I2C   _bus_instance;          // I2Cバスのインスタンス (ESP32のみ)

  public:
    LGFX_SSD1306_72x40() {  // コンストラクタ名はクラス名に合わせてLGFXからLGFX_SSD1306に変更してます。（クラス名と同じにする）
      { // バス制御の設定を行います。
        auto cfg = _bus_instance.config();  // I2Cバス設定用の構造体を取得します。
        cfg.i2c_port    = 0;          // 使用するI2Cポートを選択 (0 or 1)
        cfg.freq_write  = 400000;     // 送信時のクロック
        cfg.freq_read   = 400000;     // 受信時のクロック
        cfg.pin_sda     = 1;          // SDAを接続しているピン番号
        cfg.pin_scl     = 2;          // SCLを接続しているピン番号
        cfg.i2c_addr    = 0x3C;       // I2Cデバイスのアドレス

        _bus_instance.config(cfg);    // 設定値をバスに反映します。
        _panel_instance.setBus(&_bus_instance); // バスをパネルにセットします。
      }
      { // 表示パネル制御の設定を行います。
        auto cfg = _panel_instance.config();  // 表示パネル設定用の構造体を取得します。
        cfg.memory_width  = 128;      // ドライバICがサポートしている最大の幅
        cfg.memory_height =  64;      // ドライバICがサポートしている最大の高さ
        cfg.panel_width  =  72;      // ドライバICがサポートしている最大の幅
        cfg.panel_height =  40;      // ドライバICがサポートしている最大の高さ
        cfg.offset_x      =  28;      // パネルのX方向オフセット量
        cfg.offset_y      =   0;       // パネルのY方向オフセット量

        _panel_instance.config(cfg);  // 設定をパネルに反映
      }
      setPanel(&_panel_instance);     // 使用するパネルをセットします。
    }
};
extern LGFX_SSD1306_72x40 lcd; 

