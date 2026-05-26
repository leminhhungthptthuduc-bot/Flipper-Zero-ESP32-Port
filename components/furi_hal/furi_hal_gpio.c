/**
 * @file furi_hal_gpio.c
 * GPIO HAL for ESP32 - Bản tích hợp HARDWARE TEST BUTTON qua Đèn nền LCD (IO6)
 */

#include "furi_hal_gpio.h"

#include <driver/gpio.h>
#include <esp_err.h>

static GpioInterrupt furi_hal_gpio_interrupts[GPIO_NUM_MAX] = {0};
static bool furi_hal_gpio_isr_service_ready = false;

static bool furi_hal_gpio_is_valid(const GpioPin* gpio) {
    return gpio && gpio->pin != UINT16_MAX && gpio->pin < GPIO_NUM_MAX;
}

static void furi_hal_gpio_isr_handler(void* arg) {
    const uint32_t pin = (uint32_t)(uintptr_t)arg;
    if(pin >= GPIO_NUM_MAX) return;

    GpioInterrupt interrupt = furi_hal_gpio_interrupts[pin];
    if(interrupt.callback) interrupt.callback(interrupt.context);
}

static void furi_hal_gpio_ensure_isr_service(void) {
    if(furi_hal_gpio_isr_service_ready) return;

    esp_err_t err = gpio_install_isr_service(0);
    if(err == ESP_OK || err == ESP_ERR_INVALID_STATE) {
        furi_hal_gpio_isr_service_ready = true;
    }
}

static gpio_mode_t furi_hal_gpio_convert_mode(GpioMode mode) {
    switch(mode) {
    case GpioModeInput:
    case GpioModeInterruptRise:
    case GpioModeInterruptFall:
    case GpioModeInterruptRiseFall:
    case GpioModeEventRise:
    case GpioModeEventFall:
    case GpioModeEventRiseFall:
        return GPIO_MODE_INPUT;
    case GpioModeOutputPushPull:
        return GPIO_MODE_OUTPUT;
    case GpioModeOutputOpenDrain:
        return GPIO_MODE_OUTPUT_OD;
    case GpioModeAltFunctionPushPull:
        return GPIO_MODE_INPUT_OUTPUT;
    case GpioModeAltFunctionOpenDrain:
        return GPIO_MODE_INPUT_OUTPUT_OD;
    case GpioModeAnalog:
    default:
        return GPIO_MODE_DISABLE;
    }
}

static gpio_int_type_t furi_hal_gpio_convert_interrupt(GpioMode mode) {
    switch(mode) {
    case GpioModeInterruptRise:
    case GpioModeEventRise:
        return GPIO_INTR_POSEDGE;
    case GpioModeInterruptFall:
    case GpioModeEventFall:
        return GPIO_INTR_NEGEDGE;
    case GpioModeInterruptRiseFall:
    case GpioModeEventRiseFall:
        return GPIO_INTR_ANYEDGE;
    default:
        return GPIO_INTR_DISABLE;
    }
}

void furi_hal_gpio_init_simple(const GpioPin* gpio, const GpioMode mode) {
    furi_hal_gpio_init(gpio, mode, GpioPullNo, GpioSpeedLow);
}

void furi_hal_gpio_init(
    const GpioPin* gpio,
    const GpioMode mode,
    const GpioPull pull,
    const GpioSpeed speed) {
    furi_hal_gpio_init_ex(gpio, mode, pull, speed, GpioAltFnUnused);
}

void furi_hal_gpio_init_ex(
    const GpioPin* gpio,
    const GpioMode mode,
    const GpioPull pull,
    const GpioSpeed speed,
    const GpioAltFn alt_fn) {
    (void)speed;
    (void)alt_fn;

    if(!furi_hal_gpio_is_valid(gpio)) return;

    // Bộ lọc nhận diện 6 chân nút bấm của bạn
    bool is_custom_button = (gpio->pin == 41 || gpio->pin == 40 || gpio->pin == 38 || gpio->pin == 39 || gpio->pin == 0 || gpio->pin == 4);

    gpio_config_t config = {
        .pin_bit_mask = 1ULL << gpio->pin,
        .mode = furi_hal_gpio_convert_mode(mode),
        .pull_up_en = is_custom_button ? false : (pull == GpioPullUp),
        .pull_down_en = is_custom_button ? false : (pull == GpioPullDown),
        .intr_type = furi_hal_gpio_convert_interrupt(mode),
    };
    gpio_config(&config);
    
    // Nếu là chân nút bấm, cấu hình thêm chân Đèn nền LCD (IO6) làm Output để test
    if(is_custom_button) {
        gpio_reset_pin(GPIO_NUM_6);
        gpio_set_direction(GPIO_NUM_6, GPIO_MODE_OUTPUT);
    }
}

void furi_hal_gpio_add_int_callback(const GpioPin* gpio, GpioExtiCallback cb, void* ctx) {
    if(!furi_hal_gpio_is_valid(gpio)) return;

    furi_hal_gpio_ensure_isr_service();
    if(!furi_hal_gpio_isr_service_ready) return;

    furi_hal_gpio_interrupts[gpio->pin].callback = cb;
    furi_hal_gpio_interrupts[gpio->pin].context = ctx;
    gpio_isr_handler_remove((gpio_num_t)gpio->pin);
    gpio_isr_handler_add(
        (gpio_num_t)gpio->pin, furi_hal_gpio_isr_handler, (void*)(uintptr_t)gpio->pin);
    gpio_intr_enable((gpio_num_t)gpio->pin);
}

void furi_hal_gpio_enable_int_callback(const GpioPin* gpio) {
    if(!furi_hal_gpio_is_valid(gpio)) return;
    gpio_intr_enable((gpio_num_t)gpio->pin);
}

void furi_hal_gpio_disable_int_callback(const GpioPin* gpio) {
    if(!furi_hal_gpio_is_valid(gpio)) return;
    gpio_intr_disable((gpio_num_t)gpio->pin);
}

void furi_hal_gpio_remove_int_callback(const GpioPin* gpio) {
    if(!furi_hal_gpio_is_valid(gpio)) return;

    gpio_intr_disable((gpio_num_t)gpio->pin);
    if(furi_hal_gpio_isr_service_ready) {
        gpio_isr_handler_remove((gpio_num_t)gpio->pin);
    }
    furi_hal_gpio_interrupts[gpio->pin].callback = NULL;
    furi_hal_gpio_interrupts[gpio->pin].context = NULL;
}

void furi_hal_gpio_write(const GpioPin* gpio, const bool state) {
    if(!furi_hal_gpio_is_valid(gpio)) return;
    gpio_set_level((gpio_num_t)gpio->pin, state ? 1 : 0);
}

bool furi_hal_gpio_read(const GpioPin* gpio) {
    if(!furi_hal_gpio_is_valid(gpio)) return false;

    // Đọc trạng thái thực tế từ chân chip
    int level = gpio_get_level((gpio_num_t)gpio->pin);

    // 🔴 ĐOẠN CODE TEST PHẦN CỨNG TRỰC TIẾP:
    // Nếu hệ thống quét trúng 1 trong 6 nút của bạn VÀ nút đó đang ĐƯỢC BẤM (mức 0)
    if ((gpio->pin == 41 || gpio->pin == 40 || gpio->pin == 38 || gpio->pin == 39 || gpio->pin == 0 || gpio->pin == 4) && (level == 0)) {
        // TẮT ngay đèn nền màn hình (IO6) để báo hiệu cho bạn biết chip ĐÃ NHẬN nút!
        gpio_set_level(GPIO_NUM_6, 0); 
    } else {
        // Bình thường giữ đèn nền SÁNG (mức 1)
        gpio_set_level(GPIO_NUM_6, 1);
    }

    return level != 0;
}
