//
// Created by mjw on 2023/1/12.
//

#ifndef GIMBAL_2023_ABOARD_VISIONCOM_TASK_H
#define GIMBAL_2023_ABOARD_VISIONCOM_TASK_H
#include "stm32f4xx_hal.h"

// void Vision_JudgeUpdate(float shoot_speed, int8_t color, int8_t type);
void VisionChattingLoop(uint8_t mode);

#endif //GIMBAL_2023_ABOARD_VISIONCOM_TASK_H
