/**
 * @file board_m5stack_cardputer.h
 * Board definition: M5Stack Cardputer - Đã sửa lại cho mạch ESP32-S3 Custom 
 * (Cấu hình: ST7789 + Khóa nút LEFT, ép chân 39 làm nút BACK độc quyền)
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "M5Stack Cardputer Custom"
#define BOARD_TARGET      "esp32s3"

/* ---- 🛠️ CẤU HÌNH 5 NÚT VẬT LÝ (TẠM THỜI KHÓA LEFT, CHUYỂN CHÂN 39 THÀNH BACK) ---- */
#define BOARD_PIN_BUTTON_UP      41  
#define BOARD_PIN_BUTTON_DOWN    40  
#define BOARD_PIN_BUTTON_RIGHT   38  
#define BOARD_PIN_BUTTON_LEFT    UINT16_MAX /* Khóa hẳn nút LEFT để tránh trùng lệnh */
#define BOARD_PIN_BUTTON_OK      0   
#define BOARD_PIN_BUTTON_BACK    39         /* Ép chân 39 làm nút BACK độc quyền */

/* Bọc lót hệ thống nút BTN cho các driver gọi kiểu cũ */
#define BOARD_PIN_BTN_UP         41  
#define BOARD_PIN_BTN_DOWN       40  
#define BOARD_PIN_BTN_RIGHT      38  
#define BOARD_PIN_BTN_LEFT       UINT16_MAX 
#define BOARD_PIN_BTN_OK         0   
#define BOARD_PIN_BTN_BACK       39  

#define BOARD_PIN_BUTTON_BOOT    0   /* Giữ IO0 làm nút OK kiêm nút BOOT */
#define BOARD_PIN_BUTTON_KEY     UINT16_MAX
#define BOARD_PIN_BATTERY_ADC    UINT16_MAX

/* ---- LCD (ST7789) via SPI2 - Đã đổi chân khớp mạch của bạn ---- */
#define BOARD_PIN_LCD_MOSI      17  /* SDA */
#define BOARD_PIN_LCD_SCLK      18  /* SCL */
#define BOARD_PIN_LCD_CS        7   /* CS */
#define BOARD_PIN_LCD_DC        9   /* DC (Đã dời sang IO9 an toàn) */
#define BOARD_PIN_LCD_RST       16  /* RES */
#define BOARD_PIN_LCD_BL        6   /* BLK */
#define BOARD_PIN_LCD_SPI_MISO  (-1)

/* ---- LCD Display Configuration (Giữ nguyên Offset chuẩn của Cardputer) ---- */
#define BOARD_LCD_H_RES         240
#define BOARD_LCD_V_RES         135
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (20 * 1000 * 1000) /* Để 20MHz cho chạy mạch rời ổn định */
#define BOARD_LCD_CMD_BITS      8
#define BOARD_LCD_PARAM_BITS    8
#define BOARD_LCD_SWAP_XY       true    
#define BOARD_LCD_MIRROR_X      true
#define BOARD_LCD_MIRROR_Y      false
#define BOARD_LCD_INVERT_COLOR  false    /* Đổi về false để màn hình rời của bạn lên màu cam chuẩn */
#define BOARD_LCD_GAP_X         40       /* Offset X chuẩn giúp không lem viền trắng */
#define BOARD_LCD_GAP_Y         53       /* Offset Y chuẩn */
#define BOARD_LCD_BL_ACTIVE_LOW false   
#define BOARD_LCD_COLOR_ORDER_BGR false

/* Bộ màu cam Flipper lật byte */
#define BOARD_LCD_FG_COLOR      0xA0FD  
#define BOARD_LCD_BG_COLOR      0x0000  

/* ---- SD Card via SPI2 (Dùng chung bus với LCD theo mạch của bạn) ---- */
#define BOARD_HAS_SD            1
#define BOARD_PIN_SD_CS         3
#define BOARD_PIN_SD_MOSI       17
#define BOARD_PIN_SD_MISO       8
#define BOARD_PIN_SD_SCLK       18
#define BOARD_SD_SPI_HOST       SPI2_HOST

/* ---- 🔴 TẮT HOÀN TOÀN MA TRẬN BÀN PHÍM 74HC138 CỦA CARDPUTER ---- */
#undef BOARD_KB_TYPE_74HC138
#define BOARD_KB_ROW_COUNT      0
#define BOARD_KB_COL_COUNT      0

/* ---- VÔ HIỆU HÓA CÁC NGOẠI VI KHÔNG CÓ TRÊN MẠCH ---- */
#define BOARD_PIN_ENCODER_A      UINT16_MAX
#define BOARD_PIN_ENCODER_B      UINT16_MAX
#define BOARD_PIN_ENCODER_BTN    UINT16_MAX
#define BOARD_PIN_TOUCH_SCL      UINT16_MAX
#define BOARD_PIN_TOUCH_SDA      UINT16_MAX
#define BOARD_PIN_CC1101_SCK     UINT16_MAX
#define BOARD_PIN_CC1101_CSN     UINT16_MAX
#define BOARD_PIN_CC1101_MISO    UINT16_MAX
#define BOARD_PIN_CC1101_MOSI    UINT16_MAX
#define BOARD_PIN_IR_TX         UINT16_MAX
#define BOARD_PIN_IR_RX         UINT16_MAX
#define BOARD_PIN_SPEAKER_BCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT  UINT16_MAX
#define BOARD_PIN_MIC_DATA      UINT16_MAX
#define BOARD_PIN_MIC_CLK       UINT16_MAX
#define BOARD_PIN_WS2812_DATA    UINT16_MAX
#define BOARD_WS2812_LED_COUNT   0

/* ---- Cấu hình ép Driver nhận diện Nút bấm trực tiếp ---- */
#define BOARD_BUTTONS_TYPE_GPIO 1   /* Kích hoạt đọc nút trực tiếp */
#define BOARD_INPUT_ACTIVE_LOW  1   /* Nhấn nút chập xuống GND */
#define BOARD_HAS_IO_EXPANDER   0   /* Tắt chip mở rộng chân */

/* ---- Feature flags ---- */
#define BOARD_HAS_TOUCH         0
#define BOARD_HAS_ENCODER       0
#define BOARD_HAS_SD_CARD       1
#define BOARD_HAS_BLE           1
#define BOARD_HAS_RGB_LED       0
#define BOARD_HAS_VIBRO         0
#define BOARD_HAS_SPEAKER       0
#define BOARD_HAS_IR            0
#define BOARD_HAS_IBUTTON       0
#define BOARD_HAS_RFID          0
#define BOARD_HAS_NFC           0
#define BOARD_HAS_SUBGHZ        0

/* ---- Giả lập quản lý nguồn (Không có chip quản lý pin) ---- */
#define BQ27220_ADDR            0x00
#define BQ_I2C_PORT             I2C_NUM_0
#define BQ_I2C_SDA              UINT16_MAX
#define BQ_I2C_SCL              UINT16_MAX
#define HIGH_DRAIN_CURRENT_THRESHOLD (-200)
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH     (1520U)
#define BQ25896_CHARGE_LIMIT    0
