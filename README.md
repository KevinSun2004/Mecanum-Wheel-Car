# School RM Version 2.0
本项目是参与2022年（延期至2023年）北京理工大学“机甲大师”赛暨RoboMaster校内选拔赛的电控代码。

## 概述
本代码实现了一个使用PID控制的可以全向运动的麦轮底盘、一个二轴机械臂。代码模块化程度较高，可以很容易进行扩展、添加新功能。

## 物料清单
- STM32F104ZET6 * 1
- JGB37-520 直流减速电机（带编码器） * 4
- TD8030 舵机 * 1
- TD8020 舵机 * 3
- 12V 锂电池
- 自研DC-DC降压模块 * 2
- L298N 驱动模块 * 2
- PS2手柄 & 接收机
- 底盘以及其他机械结构

## 开发进度
- [x] 代码框架搭建
- [x] 遥控器接收 & 解码
- [x] 电机控制 & 底盘运动学解算
- [x] 电机编码器读取
- [x] 电机PID控制
- [ ] 机械臂控制

## Contribution to this contest
- Zhongtian Sun: 电控&视觉代码
- Junxi Li     : 机械结构设计
- Zirui Dai    : DC-DC降压模块制作
- Lujundong Li : 视觉代码

## Copyright
**Copyright (c) 2023 DrinkCat**
