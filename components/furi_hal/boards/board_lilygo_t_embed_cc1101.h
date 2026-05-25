/**
 * @file board_custom_st7789_114.h
 * Board definition: Custom ESP32-S3 with 1.14 inch ST7789 Display
 *
 * MCU:      ESP32-S3
 * Display:  ST7789 240x135 RGB565 via SPI
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "ESP32-S3 Custom 1.14 LCD"
#define BOARD_TARGET      "esp32s3"

/* ---- Hardware Button / Encoder Pins (Tạm thời bỏ qua) ---- */
#define BOARD_PIN_BUTTON_BOOT   UINT16_MAX
#define BOARD_PIN_BUTTON_KEY    UINT16_MAX
#define BOARD_PIN_BATTERY_ADC   UINT16_MAX

/* ---- LCD Pins (Cấu hình chính xác theo sơ đồ bạn nối) ---- */
#define BOARD_PIN_LCD_SCLK      18  /* SCL nối với chân 18 */
#define BOARD_PIN_LCD_MOSI      17  /* SDA nối với chân 17 */
#define BOARD_PIN_LCD_DC        15  /* DC nối với chân 15 */
#define BOARD_PIN_LCD_CS        7   /* CS nối với chân 7 */
#define BOARD_PIN_LCD_RST       16  /* RES (Reset) nối với chân 16 */
#define BOARD_PIN_LCD_BL        6   /* BLK (Backlight) nối với chân 6 */

/* ---- LCD Display Configuration (Tối ưu cho màn 1.14 inch ST7789) ---- */
#define BOARD_LCD_H_RES         240      /* Độ phân giải ngang màn 1.14" */
#define BOARD_LCD_V_RES         135      /* Độ phân giải dọc màn 1.14" */
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (40 * 1000 * 1000)
#define BOARD_LCD_CMD_BITS      8
#define BOARD_LCD_PARAM_BITS    8
#define BOARD_LCD_SWAP_XY       true
#define BOARD_LCD_MIRROR_X      false
#define BOARD_LCD_MIRROR_Y      false    
#define BOARD_LCD_INVERT_COLOR  true     /* ST7789 thường cần bật đảo màu để lên đúng màu gốc */
#define BOARD_LCD_GAP_X         40       /* Màn 1.14" ST7789 thường có vùng lệch (Offset) X */
#define BOARD_LCD_GAP_Y         53       /* Vùng lệch (Offset) Y giúp hiển thị không bị sọc/lệch hình */
#define BOARD_LCD_BL_ACTIVE_LOW false    /* Backlight mức cao (HIGH) là sáng */
#define BOARD_LCD_COLOR_ORDER_BGR false 

/* Màu sắc hiển thị cơ bản để test */
#define BOARD_LCD_FG_COLOR      0xFFFF  /* Màu chữ/nền trước: Trắng */
#define BOARD_LCD_BG_COLOR      0x0000  /* Màu nền sau: Đen */

/* ---- Vô hiệu hóa toàn bộ các ngoại vi khác để tránh xung đột chân ---- */
#define BOARD_PIN_SD_CS         UINT16_MAX
#define BOARD_PIN_SD_MISO       UINT16_MAX

#define BOARD_PIN_TOUCH_SCL     UINT16_MAX
#define BOARD_PIN_TOUCH_SDA     UINT16_MAX
#define BOARD_PIN_TOUCH_RST     UINT16_MAX
#define BOARD_PIN_TOUCH_INT     UINT16_MAX

#define BOARD_PIN_CC1101_CSN    UINT16_MAX
#define BOARD_PIN_NRF24_CSN     UINT16_MAX
#define BOARD_PIN_PWR_EN        UINT16_MAX

#define BOARD_PIN_IR_TX         UINT16_MAX
#define BOARD_PIN_IR_RX         UINT16_MAX

#define BOARD_PIN_NFC_SCL       UINT16_MAX
#define BOARD_PIN_NFC_SDA       UINT16_MAX

#define BOARD_PIN_SPEAKER_BCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT  UINT16_MAX

#define BOARD_PIN_WS2812_DATA   UINT16_MAX
#define BOARD_PIN_MIC_DATA      UINT16_MAX
#define BOARD_PIN_MIC_CLK       UINT16_MAX

/* ---- Features Flags ---- */
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
#define BOARD_HAS_SUBGHZ         0
#define BOARD_HAS_MIC           0
