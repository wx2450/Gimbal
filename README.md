# 云台代码简析

## Framework

**DEBUGC:** 串口调试，使用uart1，参数较为杂乱，可以考虑重构 

**GIMBALC:** 云台主程序，包含云台控制主循环，底盘通讯函数和其他辅助函数，移植时应调试修改CarChoose函数中的pid参数


**IMU:** 姿态解算，算法较复杂不易重构

**IWDG:** 看门狗防死机

**LED:** 之前调试时好像没用

**PID:** PID，在GIMBALC和SHOOTC中有调用

**REMOTEC:** 遥控器遥控模块

**SHOOTC:** 发射主程序，负责摩擦轮控制和热量控制

**SMC:** 快速终端滑膜算法，有详解文档

**VISION:** 小电脑视觉模块通讯？

**两个.h** 把要的.h封装进去了，core.h是Core里的，BSP.h是User里的

## Includes
两个文件夹都是matlab生成的pid相关文件

## MCUDriver

Framework里的函数需要的通讯函数对应的封装，没有太多修改必要

IT文件夹是尝试加的，考虑将Core中的stm32f4xx_it.c进行移出重定义，目前还不能正常使用

## Task

包含云台控制task，IMU实时解算task，小电脑通讯task

通过StartTask.cpp把Core中的任务安排函数移出到User里了