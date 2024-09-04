/*******************************************************************************
* Copyright © 2019 TRINAMIC Motion Control GmbH & Co. KG
* (now owned by Analog Devices Inc.),
*
* Copyright © 2024 Analog Devices Inc. All Rights Reserved.
* This software is proprietary to Analog Devices, Inc. and its licensors.
*******************************************************************************/

#ifndef TMC2208_HW_ABSTRACTION
#define TMC2208_HW_ABSTRACTION


// Constants

#define TMC2208_MOTORS           1
#define TMC2208_REGISTER_COUNT   128 // Default register count
#define TMC2208_WRITE_BIT        0x80
#define TMC2208_ADDRESS_MASK     0x7F
#define TMC2208_MAX_VELOCITY     (int32_t)  2147483647
#define TMC2208_MAX_ACCELERATION (uint32_t)  4294967295uL

// Registers in TMC2208
// ===== TMC2208 & 2202 & TMC2208 & 2220 & 2225 "Donkey Kong" family register set =====

#define TMC2208_GCONF         0x00
#define TMC2208_GSTAT         0x01
#define TMC2208_IFCNT         0x02
#define TMC2208_SLAVECONF     0x03
#define TMC2208_OTP_PROG      0x04
#define TMC2208_OTP_READ      0x05
#define TMC2208_IOIN          0x06
#define TMC2208_FACTORY_CONF  0x07

#define TMC2208_IHOLD_IRUN    0x10
#define TMC2208_TPOWERDOWN    0x11
#define TMC2208_TSTEP         0x12
#define TMC2208_TPWMTHRS      0x13

#define TMC2208_VACTUAL       0x22

#define TMC2208_MSCNT         0x6A
#define TMC2208_MSCURACT      0x6B
#define TMC2208_CHOPCONF      0x6C
#define TMC2208_DRVSTATUS     0x6F
#define TMC2208_PWMCONF       0x70
#define TMC2208_PWMSCALE      0x71
#define TMC2208_PWM_AUTO      0x72

// Register fields in TMC2208
#endif
