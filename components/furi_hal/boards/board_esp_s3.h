/**
 * @file board_esp_s3.h
 * Board definition: ESP32-S3 Custom Board (Merged Configuration)
 * Giữ nguyên logic nút bấm (BACK=39, LEFT=Disabled) và khớp chân SPI của mạch.
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "ESP32-S3 Custom"
#define BOARD_TARGET      "esp32s3"
/* 🔴 THÊM CÁC DÒNG ĐỊNH NGHĨA "PHÒNG THỦ" NÀY ĐỂ TRÁNH LỖI UNDECLARED 🔴 */
#ifndef BOARD_PIN_TOUCH_SCL
#define BOARD_PIN_TOUCH_SCL      UINT16_MAX
#endif
#ifndef BOARD_PIN_TOUCH_SDA
#define BOARD_PIN_TOUCH_SDA      UINT16_MAX
#endif
#ifndef BOARD_WS2812_LED_COUNT
#define BOARD_WS2812_LED_COUNT   0
#endif
/* ---- 🛠️ LOGIC NÚT BẤM (GIỮ NGUYÊN TỪ YÊU CẦU ĐẦU) ---- */
#define BOARD_PIN_BUTTON_UP      41  
#define BOARD_PIN_BUTTON_DOWN    40  
#define BOARD_PIN_BUTTON_RIGHT   38  
#define BOARD_PIN_BUTTON_LEFT    UINT16_MAX 
#define BOARD_PIN_BUTTON_OK      0   
#define BOARD_PIN_BUTTON_BACK    39         /* Nút BACK độc quyền chân 39 */

/* Bọc lót cho Driver hệ thống */
#define BOARD_PIN_BTN_UP         41  
#define BOARD_PIN_BTN_DOWN       40  
#define BOARD_PIN_BTN_RIGHT      38  
#define BOARD_PIN_BTN_LEFT       UINT16_MAX 
#define BOARD_PIN_BTN_OK         0   
#define BOARD_PIN_BTN_BACK       39  

/* Vô hiệu hóa chân phụ */
#define BOARD_PIN_BUTTON_BOOT    UINT16_MAX
#define BOARD_PIN_BUTTON_KEY     UINT16_MAX
#define BOARD_PIN_BATTERY_ADC    UINT16_MAX

/* ---- LCD (SPI2) - Khớp sơ đồ mạch ---- */
#define BOARD_PIN_LCD_MOSI      17  /* SDA */
#define BOARD_PIN_LCD_SCLK      18  /* SCL */
#define BOARD_PIN_LCD_CS        7   /* CS */
#define BOARD_PIN_LCD_DC        9   /* DC */
#define BOARD_PIN_LCD_RST       16  /* RES */
#define BOARD_PIN_LCD_BL        6   /* BLK */
#define BOARD_PIN_LCD_SPI_MISO  (-1)

/* ---- LCD Display Configuration ---- */
#define BOARD_LCD_H_RES         240
#define BOARD_LCD_V_RES         135
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (20 * 1000 * 1000) 
#define BOARD_LCD_SWAP_XY       true    
#define BOARD_LCD_MIRROR_X      true
#define BOARD_LCD_MIRROR_Y      false
#define BOARD_LCD_INVERT_COLOR  false    
#define BOARD_LCD_GAP_X         40       
#define BOARD_LCD_GAP_Y         53       
#define BOARD_LCD_BL_ACTIVE_LOW false   
#define BOARD_LCD_COLOR_ORDER_BGR true  

#define BOARD_LCD_FG_COLOR      0xFFFF
#define BOARD_LCD_BG_COLOR      0x0000

/* ---- SD Card (SPI2) ---- */
#define BOARD_HAS_SD            1
#define BOARD_PIN_SD_CS         3
#define BOARD_PIN_SD_MISO       8
#define BOARD_PIN_SD_MOSI       17
#define BOARD_PIN_SD_SCK        18
#define BOARD_SD_SPI_HOST       SPI2_HOST

/* ---- VÔ HIỆU HÓA NGOẠI VI (Tránh lỗi Build) ---- */
#define BOARD_PIN_TOUCH_RST      UINT16_MAX
#define BOARD_PIN_TOUCH_INT      UINT16_MAX
#define BOARD_PIN_CC1101_GDO0    UINT16_MAX
#define BOARD_PIN_CC1101_GDO2    UINT16_MAX
#define BOARD_PIN_CC1101_CSN     UINT16_MAX
#define BOARD_PIN_CC1101_SCK     UINT16_MAX
#define BOARD_PIN_CC1101_MISO    UINT16_MAX
#define BOARD_PIN_CC1101_MOSI    UINT16_MAX
#define BOARD_PIN_ENCODER_A      UINT16_MAX
#define BOARD_PIN_ENCODER_B      UINT16_MAX
#define BOARD_PIN_ENCODER_BTN    UINT16_MAX
#define BOARD_PIN_WS2812_DATA    UINT16_MAX
#define BOARD_PIN_SPEAKER        UINT16_MAX
#define BOARD_PIN_IR_TX          UINT16_MAX
#define BOARD_PIN_IR_RX          UINT16_MAX

/* ---- Feature Flags ---- */
#define BOARD_HAS_TOUCH         0
#define BOARD_HAS_ENCODER       0
#define BOARD_HAS_SD_CARD       1
#define BOARD_HAS_BLE           1
#define BOARD_HAS_RGB_LED       0
#define BOARD_HAS_VIBRO         0
#define BOARD_HAS_SPEAKER       0
#define BOARD_HAS_IR            0
#define BOARD_HAS_SUBGHZ        0

/* ---- Cấu hình Driver Nút bấm trực tiếp (GPIO) ---- */
#define BOARD_BUTTONS_TYPE_GPIO 1   
#define BOARD_INPUT_ACTIVE_LOW  1   
#define BOARD_HAS_IO_EXPANDER   0   

/* ---- Power Management ---- */
#define BQ27220_ADDR            0x00
#define BQ_I2C_PORT             I2C_NUM_0
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH (1520U)
