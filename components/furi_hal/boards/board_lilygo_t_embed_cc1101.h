/**
 * @file board_lilygo_t_embed_cc1101.h
 * Board definition: LilyGo T-Embed CC1101 (Modified for Custom 1.14" Display)
 *
 * MCU:      ESP32-S3 (dual-core Xtensa LX7)
 * Display:  ST7789 240x135 RGB565 via SPI (Custom Pins)
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "ESP32-S3 Custom 1.14 LCD"
#define BOARD_TARGET      "esp32s3"

/* ---- Hardware Button / Encoder Pins ---- */
#define BOARD_PIN_BUTTON_BOOT   UINT16_MAX
#define BOARD_PIN_BUTTON_KEY    UINT16_MAX
#define BOARD_PIN_BATTERY_ADC   UINT16_MAX

/* ---- LCD Pins (Cấu hình chân thực tế nối màn hình của bạn) ---- */
#define BOARD_PIN_LCD_SCLK      18  /* SCL */
#define BOARD_PIN_LCD_MOSI      17  /* SDA */
#define BOARD_PIN_LCD_DC        15  /* DC */
#define BOARD_PIN_LCD_CS        7   /* CS */
#define BOARD_PIN_LCD_RST       16  /* RES */
#define BOARD_PIN_LCD_BL        6   /* BLK */

/* ---- LCD Display Configuration (Tối ưu cho màn 1.14 inch ST7789) ---- */
#define BOARD_LCD_H_RES         240      
#define BOARD_LCD_V_RES         135      
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (40 * 1000 * 1000)
#define BOARD_LCD_CMD_BITS      8
#define BOARD_LCD_PARAM_BITS    8
#define BOARD_LCD_SWAP_XY       true
#define BOARD_LCD_MIRROR_X      false
#define BOARD_LCD_MIRROR_Y      false    
#define BOARD_LCD_INVERT_COLOR  true     
#define BOARD_LCD_GAP_X         40       
#define BOARD_LCD_GAP_Y         53       
#define BOARD_LCD_BL_ACTIVE_LOW false    
#define BOARD_LCD_COLOR_ORDER_BGR false 

/* Màu sắc hiển thị cơ bản */
#define BOARD_LCD_FG_COLOR      0xFFFF  /* Trắng */
#define BOARD_LCD_BG_COLOR      0x0000  /* Đen */

/* ---- GIẢ LẬP HỆ THỐNG CHÂN SUB-GHZ (Sửa lỗi furi_hal_resources.c) ---- */
#define BOARD_PIN_CC1101_CSN    UINT16_MAX
#define BOARD_PIN_CC1101_SCK    UINT16_MAX
#define BOARD_PIN_CC1101_MISO   UINT16_MAX
#define BOARD_PIN_CC1101_MOSI   UINT16_MAX
#define BOARD_PIN_CC1101_GDO0   UINT16_MAX
#define BOARD_PIN_CC1101_GDO2   UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG ĐÈN LED RGB & BACKLIGHT phụ (Sửa lỗi furi_hal_light.c) ---- */
#define BOARD_PIN_WS2812_DATA   UINT16_MAX
#define BOARD_WS2812_LED_COUNT  0
#define BOARD_PIN_BACKLIGHT     UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG LOA/BUZZER (Phòng ngừa lỗi furi_hal_speaker.c) ---- */
#define BOARD_PIN_SPEAKER_BCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT  UINT16_MAX
#define BOARD_PIN_SPEAKER       UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG HỒNG NGOẠI IR (Phòng ngừa lỗi furi_hal_ir.c) ---- */
#define BOARD_PIN_IR_TX         UINT16_MAX
#define BOARD_PIN_IR_RX         UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG THẺ NHỚ SD (Phòng ngừa lỗi cấu hình SD) ---- */
#define BOARD_PIN_SD_CS         UINT16_MAX
#define BOARD_PIN_SD_MISO       UINT16_MAX
#define BOARD_PIN_SD_MOSI       UINT16_MAX
#define BOARD_PIN_SD_SCK        UINT16_MAX

/* ---- VÔ HIỆU HÓA CÁC NGOẠI VI KHÁC ĐỂ TRÁNH XUNG ĐỘT ---- */
#define BOARD_PIN_TOUCH_SCL     UINT16_MAX
#define BOARD_PIN_TOUCH_SDA     UINT16_MAX
#define BOARD_PIN_TOUCH_RST     UINT16_MAX
#define BOARD_PIN_TOUCH_INT     UINT16_MAX
#define BOARD_PIN_NRF24_CSN     UINT16_MAX
#define BOARD_PIN_PWR_EN        UINT16_MAX
#define BOARD_PIN_NFC_SCL       UINT16_MAX
#define BOARD_PIN_NFC_SDA       UINT16_MAX
#define BOARD_PIN_MIC_DATA      UINT16_MAX
#define BOARD_PIN_MIC_CLK       UINT16_MAX

/* ---- FEATURES FLAGS (Tắt hết tính năng thừa, chỉ giữ lại màn hình) ---- */
#define BOARD_HAS_TOUCH         0
#define BOARD_HAS_ENCODER       0
#define BOARD_HAS_SD_CARD       0
#define BOARD_HAS_BLE           0
#define BOARD_HAS_RGB_LED       0
#define BOARD_HAS_VIBRO         0
#define BOARD_HAS_SPEAKER       0
#define BOARD_HAS_IR            0
#define BOARD_HAS_IBUTTON       0
#define BOARD_HAS_RFID          0
#define BOARD_HAS_NFC           0
#define BOARD_HAS_SUBGHZ        0
#define BOARD_HAS_MIC           0

/* ---- CẤU HÌNH QUẢN LÝ NGUỒN PIN GIẢ LẬP (Sửa lỗi furi_hal_power.c) ---- */
#define BQ27220_ADDR            0x55
#define BQ_I2C_PORT             I2C_NUM_0
#define BQ_I2C_SDA              UINT16_MAX
#define BQ_I2C_SCL              UINT16_MAX
#define HIGH_DRAIN_CURRENT_THRESHOLD (-200)
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH     (1300U)
#define BQ25896_CHARGE_LIMIT    1280
