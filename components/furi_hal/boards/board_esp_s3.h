/**
 * @file board_esp_s3.h
 * Board definition: ESP32-S3 Custom Board (Optimized Layout)
 * MCU:        ESP32-S3
 * Display:    ST7789 240x135 RGB565 via SPI
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "esp_s3"
#define BOARD_TARGET      "esp32s3"

/* ---- 🛠️ HỆ THỐNG NÚT BẤM ĐIỀU HƯỚNG ---- */
/* Kiểu 1: Driver quét trực tiếp */
#define BOARD_PIN_BTN_UP         41
#define BOARD_PIN_BTN_DOWN       40
#define BOARD_PIN_BTN_RIGHT      38
#define BOARD_PIN_BTN_OK         0
#define BOARD_PIN_BTN_BACK       39
#define BOARD_PIN_BTN_LEFT       UINT16_MAX

#define BOARD_PIN_BUTTON_BOOT    UINT16_MAX
#define BOARD_PIN_BUTTON_KEY     UINT16_MAX
#define BOARD_PIN_BATTERY_ADC    UINT16_MAX

/* ---- LCD Pins ---- */
#define BOARD_PIN_LCD_SCLK       18
#define BOARD_PIN_LCD_MOSI       17
#define BOARD_PIN_LCD_DC         15
#define BOARD_PIN_LCD_CS         7
#define BOARD_PIN_LCD_RST        16
#define BOARD_PIN_LCD_BL         6

/* ---- LCD Display Configuration ---- */
#define BOARD_LCD_H_RES          240
#define BOARD_LCD_V_RES          135
#define BOARD_LCD_SPI_HOST       SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ    (20 * 1000 * 1000)
#define BOARD_LCD_CMD_BITS       8
#define BOARD_LCD_PARAM_BITS     8
#define BOARD_LCD_SWAP_XY        true
#define BOARD_LCD_MIRROR_X       true
#define BOARD_LCD_MIRROR_Y       false
#define BOARD_LCD_INVERT_COLOR   true
#define BOARD_LCD_GAP_X          40
#define BOARD_LCD_GAP_Y          53
#define BOARD_LCD_BL_ACTIVE_LOW  false
#define BOARD_LCD_COLOR_ORDER_BGR false
#define BOARD_LCD_FG_COLOR       0xFFFF
#define BOARD_LCD_BG_COLOR       0x0000

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
#define BOARD_PIN_SPEAKER_BCLK   UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK   UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT   UINT16_MAX
#define BOARD_PIN_SPEAKER        UINT16_MAX

/* ---- GIẢ LẬP HỆ THỐNG HỒNG NGOẠI IR ---- */
#define BOARD_PIN_IR_TX          UINT16_MAX
#define BOARD_PIN_IR_RX          UINT16_MAX

/* ---- CẤU HÌNH THẺ NHỚ SD ---- */
#define BOARD_HAS_SD             1
#define BOARD_PIN_SD_CS          3
#define BOARD_PIN_SD_MISO        8
#define BOARD_PIN_SD_MOSI        17
#define BOARD_PIN_SD_SCK         18
#define BOARD_SD_SPI_HOST        SPI2_HOST

/* ---- VÔ HIỆU HÓA CÁC CHÂN NGOẠI VI KHÁC ---- */
#define BOARD_PIN_NRF24_CE       UINT16_MAX
#define BOARD_PIN_NRF24_CSN      UINT16_MAX
#define BOARD_PIN_PWR_EN         UINT16_MAX
#define BOARD_PIN_NFC_SCL        UINT16_MAX
#define BOARD_PIN_NFC_SDA        UINT16_MAX
#define BOARD_PIN_MIC_DATA       UINT16_MAX
#define BOARD_PIN_MIC_CLK        UINT16_MAX

/* ---- FEATURES FLAGS ---- */
#define BOARD_HAS_TOUCH          0
#define BOARD_HAS_ENCODER        0
#define BOARD_HAS_SD_CARD        1
#define BOARD_HAS_BLE            1
#define BOARD_HAS_RGB_LED        0
#define BOARD_HAS_VIBRO          0
#define BOARD_HAS_SPEAKER        0
#define BOARD_HAS_IR             0
#define BOARD_HAS_IBUTTON        0
#define BOARD_HAS_RFID           0
#define BOARD_HAS_NFC            0
#define BOARD_HAS_SUBGHZ         0
#define BOARD_HAS_MIC            0

/* ---- ÉP LÕI DRIVER ĐỌC TRỰC TIẾP GPIO ---- */
#define BOARD_BUTTONS_TYPE_GPIO  1
#define BOARD_INPUT_ACTIVE_LOW   1
#define BOARD_HAS_IO_EXPANDER    0

/* ---- CẤU HÌNH QUẢN LÝ NGUỒN PIN GIẢ LẬP ---- */
#define BQ27220_ADDR             0x00
#define BQ_I2C_PORT              I2C_NUM_0
#define HIGH_DRAIN_CURRENT_THRESHOLD (-200)
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH (1520U)
#define BQ25896_CHARGE_LIMIT     0
