/**
 * @file board.h
 * Master board selection header - Ép chạy cấu hình Custom 5 nút của bạn
 */

#pragma once

/* Xóa bỏ hoàn toàn cấu hình generic cũ nếu có */
#undef BOARD_ESP32S3_GENERIC

/* Ép hệ thống luôn định nghĩa bo mạch của bạn */
#ifndef BOARD_ESP_S3
#define BOARD_ESP_S3
#endif

/* Bắn thẳng vào file cấu hình mạch của bạn luôn, không đi lòng vòng */
#include "board_esp_s3.h"
