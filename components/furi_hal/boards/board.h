/**
 * @file board.h
 * Master board selection header for Flipper Zero ESP32 Port
 */

#pragma once

#if defined(BOARD_M5STACK_CARDPUTER)
#include "board_m5stack_cardputer.h"

#elif defined(BOARD_M5STACK_CARDPUTER_ADV)
#include "board_m5stack_cardputer_adv.h"

#elif defined(BOARD_LILYGO_T_EMBED_CC1101)
#include "board_lilygo_t_embed_cc1101.h"

#elif defined(BOARD_WAVESHARE_C6_1.47)
#include "board_waveshare_c6_1.47.h"

#elif defined(BOARD_WAVESHARE_C6_1.9)
#include "board_waveshare_c6_1.9.h"

/* 🚀 Kích hoạt file cấu hình riêng độc lập của bạn */
#elif defined(BOARD_ESP_S3)
#include "board_esp_s3.h"

#else
#include "board_esp32s3_generic.h"
#endif
