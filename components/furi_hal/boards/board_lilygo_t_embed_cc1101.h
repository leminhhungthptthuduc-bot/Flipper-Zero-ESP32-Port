/**
 * @file board_lilygo_t_embed_cc1101.h
 * Board definition: LilyGo T-Embed CC1101 (Đã sửa lỗi xung đột chân IO15 cho màn 1.14" ST7789)
 * * MCU:      ESP32-S3 (dual-core Xtensa LX7 - N16R8)
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

/* ---- LCD Pins (Cấu hình chân chuẩn xác ba đã hàn theo Bruce) ---- */
#define BOARD_PIN_LCD_SCLK      18  /* SCL */
#define BOARD_PIN_LCD_MOSI      17  /* SDA */
#define BOARD_PIN_LCD_DC        15  /* DC (Dùng chung chutyuân IO15) */
#define BOARD_PIN_LCD_CS        9   /* CS */
#define BOARD_PIN_LCD_RST       16  /* RES */
#define BOARD_PIN_LCD_BL        6   /* BLK */

/* ---- LCD Display Configuration (Tối ưu hóa Offset/Gap cho màn 1.14 inch) ---- */
#define BOARD_LCD_H_RES         240      
#define BOARD_LCD_V_RES         135      
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (20 * 1000 * 1000) /* Tần số 20MHz cực kỳ ổn định */
#define BOARD_LCD_CMD_BITS      8
#define BOARD_LCD_PARAM_BITS    8
#define BOARD_LCD_SWAP_XY       false
#define BOARD_LCD_MIRROR_X      false
#define BOARD_LCD_MIRROR_Y      false    
#define BOARD_LCD_INVERT_COLOR  false     
#define BOARD_LCD_GAP_X         0       /* Khớp tọa độ căn giữa màn hình 1.14" */
#define BOARD_LCD_GAP_Y         0       /* Khớp tọa độ tránh lệch sọc màn hình 1.14" */
#define BOARD_LCD_BL_ACTIVE_LOW false     /* Đặt TRUE để ép chân IO6 xuất điện bật đèn nền màn rời */
#define BOARD_LCD_COLOR_ORDER_BGR true 

/* Màu sắc hiển thị cơ bản */
#define BOARD_LCD_FG_COLOR      0xFFFF  /* Trắng */
#define BOARD_LCD_BG_COLOR      0x0000  /* Đen */

/* ---- GIẢ LẬP HỆ THỐNG ENCODER / INPUT ---- */
#define BOARD_PIN_ENCODER_A      UINT16_MAX
#define BOARD_PIN_ENCODER_B      UINT16_MAX
#define BOARD_PIN_ENCODER_BTN    UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG CHÂN SUB-GHZ ---- */
#define BOARD_PIN_CC1101_CSN     UINT16_MAX
#define BOARD_PIN_CC1101_SCK     UINT16_MAX
#define BOARD_PIN_CC1101_MISO    UINT16_MAX
#define BOARD_PIN_CC1101_MOSI    UINT16_MAX
#define BOARD_PIN_CC1101_GDO0    UINT16_MAX
#define BOARD_PIN_CC1101_GDO2    UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG ĐÈN LED RGB & BACKLIGHT ---- */
#define BOARD_PIN_WS2812_DATA    UINT16_MAX
#define BOARD_WS2812_LED_COUNT   0
#define BOARD_PIN_BACKLIGHT      UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG CẢM ỨNG I2C TOUCH ---- */
#define BOARD_TOUCH_I2C_PORT     I2C_NUM_0
#define BOARD_TOUCH_I2C_ADDR     0x00
#define BOARD_TOUCH_I2C_FREQ_HZ  400000
#define BOARD_TOUCH_I2C_TIMEOUT  20
#define BOARD_PIN_TOUCH_SCL      UINT16_MAX
#define BOARD_PIN_TOUCH_SDA      UINT16_MAX
#define BOARD_PIN_TOUCH_RST      UINT16_MAX
#define BOARD_PIN_TOUCH_INT      UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG LOA/BUZZER ---- */
#define BOARD_PIN_SPEAKER_BCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT  UINT16_MAX
#define BOARD_PIN_SPEAKER        UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG HỒNG NGOẠI IR ---- */
#define BOARD_PIN_IR_TX         UINT16_MAX
#define BOARD_PIN_IR_RX         UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG THẺ NHỚ SD ---- */
#define BOARD_PIN_SD_CS         UINT16_MAX
#define BOARD_PIN_SD_MISO        UINT16_MAX
#define BOARD_PIN_SD_MOSI        UINT16_MAX
#define BOARD_PIN_SD_SCK         UINT16_MAX

/* ---- VÔ HIỆU HÓA CÁC CHÂN NGOẠI VI KHÁC ---- */
#define BOARD_PIN_NRF24_CE      UINT16_MAX
#define BOARD_PIN_NRF24_CSN     UINT16_MAX

/* ⚠️ CHỖ NÀY GIẢI CỨU CHÂN IO15: Khóa chân nguồn tổng về UINT16_MAX để buông tha chân IO15 cho màn hình chạy dữ liệu */
#define BOARD_PIN_PWR_EN        UINT16_MAX 

#define BOARD_PIN_NFC_SCL       UINT16_MAX
#define BOARD_PIN_NFC_SDA       UINT16_MAX
#define BOARD_PIN_MIC_DATA      UINT16_MAX
#define BOARD_PIN_MIC_CLK       UINT16_MAX

/* ---- FEATURES FLAGS (Tắt hết tính năng thừa, chỉ tập trung nuôi màn hình) ---- */
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

/* ---- CẤU HÌNH QUẢN LÝ NGUỒN PIN GIẢ LẬP ---- */
#define BQ27220_ADDR            0x55
#define BQ_I2C_PORT             I2C_NUM_0
#define HIGH_DRAIN_CURRENT_THRESHOLD (-200)
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH     (1300U)
#define BQ25896_CHARGE_LIMIT    1280
