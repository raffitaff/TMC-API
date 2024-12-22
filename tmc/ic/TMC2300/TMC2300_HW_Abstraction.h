/*******************************************************************************
* Copyright © 2019 TRINAMIC Motion Control GmbH & Co. KG
* (now owned by Analog Devices Inc.),
*
* Copyright © 2024 Analog Devices Inc. All Rights Reserved.
* This software is proprietary to Analog Devices, Inc. and its licensors.
*******************************************************************************/

#ifndef TMC2300_HW_ABSTRACTION
#define TMC2300_HW_ABSTRACTION


// Constants
#define TMC2300_MOTORS           1
#define TMC2300_REGISTER_COUNT   128
#define TMC2300_WRITE_BIT        0x80
#define TMC2300_ADDRESS_MASK     0x7F
#define TMC2300_MAX_VELOCITY     (int32_t)  2147483647
#define TMC2300_MAX_ACCELERATION (uint32_t)  4294967295uL

// Registers
#define TMC2300_GCONF         0x00
#define TMC2300_GSTAT         0x01
#define TMC2300_IFCNT         0x02
#define TMC2300_SLAVECONF     0x03
#define TMC2300_IOIN          0x06

#define TMC2300_IHOLD_IRUN    0x10
#define TMC2300_TPOWERDOWN    0x11
#define TMC2300_TSTEP         0x12

#define TMC2300_TCOOLTHRS     0x14

#define TMC2300_VACTUAL       0x22
#define TMC2300_XDIRECT       0x22

#define TMC2300_SGTHRS        0x40
#define TMC2300_SG_VALUE      0x41
#define TMC2300_COOLCONF      0x42

#define TMC2300_MSCNT         0x6A
#define TMC2300_CHOPCONF      0x6C
#define TMC2300_DRVSTATUS     0x6F
#define TMC2300_PWMCONF       0x70
#define TMC2300_PWM_SCALE     0x71
#define TMC2300_PWMAUTO       0x72


// Register fields (manually add)
#define TMC2300_EN_SPREADCYCLE_MASK 0x04 // GCONF // par_mode (Reset default=0)
#define TMC2300_EN_SPREADCYCLE_SHIFT 2 // par_mode (Reset default=0)
#define TMC2300_EN_SPREADCYCLE_SHIFT_FIELD   ((RegisterField) {TMC2300_EN_SPREADCYCLE_MASK, TMC2300_EN_SPREADCYCLE_SHIFT, TMC2300_GCONF, false})

// Register fields
#define TMC2300__MASK                    0x00000001
#define TMC2300__SHIFT                   0
#define TMC2300__FIELD                   ((RegisterField) {TMC2300__MASK, TMC2300__SHIFT, TMC2300_GCONF, false})
#define TMC2300_EXTCAP_MASK              0x00000002
#define TMC2300_EXTCAP_SHIFT             1
#define TMC2300_EXTCAP_FIELD             ((RegisterField) {TMC2300_EXTCAP_MASK, TMC2300_EXTCAP_SHIFT, TMC2300_GCONF, false})
#define TMC2300_SHAFT_MASK               0x00000008
#define TMC2300_SHAFT_SHIFT              3
#define TMC2300_SHAFT_FIELD              ((RegisterField) {TMC2300_SHAFT_MASK, TMC2300_SHAFT_SHIFT, TMC2300_GCONF, false})
#define TMC2300_DIAG_INDEX_MASK          0x00000010
#define TMC2300_DIAG_INDEX_SHIFT         4
#define TMC2300_DIAG_INDEX_FIELD         ((RegisterField) {TMC2300_DIAG_INDEX_MASK, TMC2300_DIAG_INDEX_SHIFT, TMC2300_GCONF, false})
#define TMC2300_DIAG_STEP_MASK           0x00000020
#define TMC2300_DIAG_STEP_SHIFT          5
#define TMC2300_DIAG_STEP_FIELD          ((RegisterField) {TMC2300_DIAG_STEP_MASK, TMC2300_DIAG_STEP_SHIFT, TMC2300_GCONF, false})
#define TMC2300_MULTISTEP_FILT_MASK      0x00000040
#define TMC2300_MULTISTEP_FILT_SHIFT     6
#define TMC2300_MULTISTEP_FILT_FIELD     ((RegisterField) {TMC2300_MULTISTEP_FILT_MASK, TMC2300_MULTISTEP_FILT_SHIFT, TMC2300_GCONF, false})
#define TMC2300_TEST_MODE_MASK           0x00000080
#define TMC2300_TEST_MODE_SHIFT          7
#define TMC2300_TEST_MODE_FIELD          ((RegisterField) {TMC2300_TEST_MODE_MASK, TMC2300_TEST_MODE_SHIFT, TMC2300_GCONF, false})
#define TMC2300_RESET_MASK               0x00000001
#define TMC2300_RESET_SHIFT              0
#define TMC2300_RESET_FIELD              ((RegisterField) {TMC2300_RESET_MASK, TMC2300_RESET_SHIFT, TMC2300_GSTAT, false})
#define TMC2300_DRV_ERR_MASK             0x00000002
#define TMC2300_DRV_ERR_SHIFT            1
#define TMC2300_DRV_ERR_FIELD            ((RegisterField) {TMC2300_DRV_ERR_MASK, TMC2300_DRV_ERR_SHIFT, TMC2300_GSTAT, false})
#define TMC2300_U3V5_MASK                0x00000004
#define TMC2300_U3V5_SHIFT               2
#define TMC2300_U3V5_FIELD               ((RegisterField) {TMC2300_U3V5_MASK, TMC2300_U3V5_SHIFT, TMC2300_GSTAT, false})
#define TMC2300_IFCNT_MASK               0x000000FF
#define TMC2300_IFCNT_SHIFT              0
#define TMC2300_IFCNT_FIELD              ((RegisterField) {TMC2300_IFCNT_MASK, TMC2300_IFCNT_SHIFT, TMC2300_IFCNT, false})
#define TMC2300_SLAVECONF_MASK           0x00000F00
#define TMC2300_SLAVECONF_SHIFT          8
#define TMC2300_SLAVECONF_FIELD          ((RegisterField) {TMC2300_SLAVECONF_MASK, TMC2300_SLAVECONF_SHIFT, TMC2300_SLAVECONF, false})
#define TMC2300_EN_MASK                  0x00000001
#define TMC2300_EN_SHIFT                 0
#define TMC2300_EN_FIELD                 ((RegisterField) {TMC2300_EN_MASK, TMC2300_EN_SHIFT, TMC2300_IOIN, false})
#define TMC2300_NSTDBY_MASK              0x00000002
#define TMC2300_NSTDBY_SHIFT             1
#define TMC2300_NSTDBY_FIELD             ((RegisterField) {TMC2300_NSTDBY_MASK, TMC2300_NSTDBY_SHIFT, TMC2300_IOIN, false})
#define TMC2300_MS1_MASK                 0x00000004
#define TMC2300_MS1_SHIFT                2
#define TMC2300_MS1_FIELD                ((RegisterField) {TMC2300_MS1_MASK, TMC2300_MS1_SHIFT, TMC2300_IOIN, false})
#define TMC2300_MS2_MASK                 0x00000008
#define TMC2300_MS2_SHIFT                3
#define TMC2300_MS2_FIELD                ((RegisterField) {TMC2300_MS2_MASK, TMC2300_MS2_SHIFT, TMC2300_IOIN, false})
#define TMC2300_DIAG_MASK                0x00000010
#define TMC2300_DIAG_SHIFT               4
#define TMC2300_DIAG_FIELD               ((RegisterField) {TMC2300_DIAG_MASK, TMC2300_DIAG_SHIFT, TMC2300_IOIN, false})
#define TMC2300_STEPPER_CLK_INPUT_MASK   0x00000020
#define TMC2300_STEPPER_CLK_INPUT_SHIFT  5
#define TMC2300_STEPPER_CLK_INPUT_FIELD  ((RegisterField) {TMC2300_STEPPER_CLK_INPUT_MASK, TMC2300_STEPPER_CLK_INPUT_SHIFT, TMC2300_IOIN, false})
#define TMC2300_PDN_UART_MASK            0x00000040
#define TMC2300_PDN_UART_SHIFT           6
#define TMC2300_PDN_UART_FIELD           ((RegisterField) {TMC2300_PDN_UART_MASK, TMC2300_PDN_UART_SHIFT, TMC2300_IOIN, false})
#define TMC2300_MODE_INPUT_MASK          0x00000080
#define TMC2300_MODE_INPUT_SHIFT         7
#define TMC2300_MODE_INPUT_FIELD         ((RegisterField) {TMC2300_MODE_INPUT_MASK, TMC2300_MODE_INPUT_SHIFT, TMC2300_IOIN, false})
#define TMC2300_STEP_MASK                0x00000100
#define TMC2300_STEP_SHIFT               8
#define TMC2300_STEP_FIELD               ((RegisterField) {TMC2300_STEP_MASK, TMC2300_STEP_SHIFT, TMC2300_IOIN, false})
#define TMC2300_DIR_MASK                 0x00000200
#define TMC2300_DIR_SHIFT                9
#define TMC2300_DIR_FIELD                ((RegisterField) {TMC2300_DIR_MASK, TMC2300_DIR_SHIFT, TMC2300_IOIN, false})
#define TMC2300_COMP_A1A2_MASK           0x00000400
#define TMC2300_COMP_A1A2_SHIFT          10
#define TMC2300_COMP_A1A2_FIELD          ((RegisterField) {TMC2300_COMP_A1A2_MASK, TMC2300_COMP_A1A2_SHIFT, TMC2300_IOIN, false})
#define TMC2300_COMP_B1B2_MASK           0x00000800
#define TMC2300_COMP_B1B2_SHIFT          11
#define TMC2300_COMP_B1B2_FIELD          ((RegisterField) {TMC2300_COMP_B1B2_MASK, TMC2300_COMP_B1B2_SHIFT, TMC2300_IOIN, false})
#define TMC2300_VERSION_MASK             0xFF000000
#define TMC2300_VERSION_SHIFT            24
#define TMC2300_VERSION_FIELD            ((RegisterField) {TMC2300_VERSION_MASK, TMC2300_VERSION_SHIFT, TMC2300_IOIN, false})
#define TMC2300_IHOLD_MASK               0x0000001F
#define TMC2300_IHOLD_SHIFT              0
#define TMC2300_IHOLD_FIELD              ((RegisterField) {TMC2300_IHOLD_MASK, TMC2300_IHOLD_SHIFT, TMC2300_IHOLD_IRUN, false})
#define TMC2300_IRUN_MASK                0x00001F00
#define TMC2300_IRUN_SHIFT               8
#define TMC2300_IRUN_FIELD               ((RegisterField) {TMC2300_IRUN_MASK, TMC2300_IRUN_SHIFT, TMC2300_IHOLD_IRUN, false})
#define TMC2300_IHOLDDELAY_MASK          0x000F0000
#define TMC2300_IHOLDDELAY_SHIFT         16
#define TMC2300_IHOLDDELAY_FIELD         ((RegisterField) {TMC2300_IHOLDDELAY_MASK, TMC2300_IHOLDDELAY_SHIFT, TMC2300_IHOLD_IRUN, false})
#define TMC2300_TPOWERDOWN_MASK          0x000000FF
#define TMC2300_TPOWERDOWN_SHIFT         0
#define TMC2300_TPOWERDOWN_FIELD         ((RegisterField) {TMC2300_TPOWERDOWN_MASK, TMC2300_TPOWERDOWN_SHIFT, TMC2300_TPOWERDOWN, false})
#define TMC2300_TSTEP_MASK               0x000FFFFF
#define TMC2300_TSTEP_SHIFT              0
#define TMC2300_TSTEP_FIELD              ((RegisterField) {TMC2300_TSTEP_MASK, TMC2300_TSTEP_SHIFT, TMC2300_TSTEP, false})
#define TMC2300_TCOOLTHRS_MASK           0xFFFFFFFF
#define TMC2300_TCOOLTHRS_SHIFT          0
#define TMC2300_TCOOLTHRS_FIELD          ((RegisterField) {TMC2300_TCOOLTHRS_MASK, TMC2300_TCOOLTHRS_SHIFT, TMC2300_TCOOLTHRS, true})
#define TMC2300_VACTUAL_MASK             0x00FFFFFF
#define TMC2300_VACTUAL_SHIFT            0
#define TMC2300_VACTUAL_FIELD            ((RegisterField) {TMC2300_VACTUAL_MASK, TMC2300_VACTUAL_SHIFT, TMC2300_VACTUAL, true})
#define TMC2300_SGTHRS_MASK              0x000000FF
#define TMC2300_SGTHRS_SHIFT             0
#define TMC2300_SGTHRS_FIELD             ((RegisterField) {TMC2300_SGTHRS_MASK, TMC2300_SGTHRS_SHIFT, TMC2300_SGTHRS, false})
#define TMC2300_SG_VALUE_MASK            0x000003FF
#define TMC2300_SG_VALUE_SHIFT           0
#define TMC2300_SG_VALUE_FIELD           ((RegisterField) {TMC2300_SG_VALUE_MASK, TMC2300_SG_VALUE_SHIFT, TMC2300_SG_VALUE, false})
#define TMC2300_SEMIN_MASK               0x0000000F
#define TMC2300_SEMIN_SHIFT              0
#define TMC2300_SEMIN_FIELD              ((RegisterField) {TMC2300_SEMIN_MASK, TMC2300_SEMIN_SHIFT, TMC2300_COOLCONF, false})
#define TMC2300_SEUP_MASK                0x00000060
#define TMC2300_SEUP_SHIFT               5
#define TMC2300_SEUP_FIELD               ((RegisterField) {TMC2300_SEUP_MASK, TMC2300_SEUP_SHIFT, TMC2300_COOLCONF, false})
#define TMC2300_SEMAX_MASK               0x00000F00
#define TMC2300_SEMAX_SHIFT              8
#define TMC2300_SEMAX_FIELD              ((RegisterField) {TMC2300_SEMAX_MASK, TMC2300_SEMAX_SHIFT, TMC2300_COOLCONF, false})
#define TMC2300_SEDN_MASK                0x00006000
#define TMC2300_SEDN_SHIFT               13
#define TMC2300_SEDN_FIELD               ((RegisterField) {TMC2300_SEDN_MASK, TMC2300_SEDN_SHIFT, TMC2300_COOLCONF, false})
#define TMC2300_SEIMIN_MASK              0x00008000
#define TMC2300_SEIMIN_SHIFT             15
#define TMC2300_SEIMIN_FIELD             ((RegisterField) {TMC2300_SEIMIN_MASK, TMC2300_SEIMIN_SHIFT, TMC2300_COOLCONF, false})
#define TMC2300_MSCNT_MASK               0x000003FF
#define TMC2300_MSCNT_SHIFT              0
#define TMC2300_MSCNT_FIELD              ((RegisterField) {TMC2300_MSCNT_MASK, TMC2300_MSCNT_SHIFT, TMC2300_MSCNT, false})
#define TMC2300_CUR_A_MASK               0x000001FF
#define TMC2300_CUR_A_SHIFT              0
#define TMC2300_CUR_A_FIELD              ((RegisterField) {TMC2300_CUR_A_MASK, TMC2300_CUR_A_SHIFT, TMC2300_MSCURACT, true})
#define TMC2300_CUR_B_MASK               0x01FF0000
#define TMC2300_CUR_B_SHIFT              16
#define TMC2300_CUR_B_FIELD              ((RegisterField) {TMC2300_CUR_B_MASK, TMC2300_CUR_B_SHIFT, TMC2300_MSCURACT, true})
#define TMC2300_ENABLEDRV_MASK           0x00000001
#define TMC2300_ENABLEDRV_SHIFT          0
#define TMC2300_ENABLEDRV_FIELD          ((RegisterField) {TMC2300_ENABLEDRV_MASK, TMC2300_ENABLEDRV_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_TBL_MASK                 0x00018000
#define TMC2300_TBL_SHIFT                15
#define TMC2300_TBL_FIELD                ((RegisterField) {TMC2300_TBL_MASK, TMC2300_TBL_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_MRES_MASK                0x0F000000
#define TMC2300_MRES_SHIFT               24
#define TMC2300_MRES_FIELD               ((RegisterField) {TMC2300_MRES_MASK, TMC2300_MRES_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_INTPOL_MASK              0x10000000
#define TMC2300_INTPOL_SHIFT             28
#define TMC2300_INTPOL_FIELD             ((RegisterField) {TMC2300_INTPOL_MASK, TMC2300_INTPOL_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_DEDGE_MASK               0x20000000
#define TMC2300_DEDGE_SHIFT              29
#define TMC2300_DEDGE_FIELD              ((RegisterField) {TMC2300_DEDGE_MASK, TMC2300_DEDGE_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_DISS2G_MASK              0x40000000
#define TMC2300_DISS2G_SHIFT             30
#define TMC2300_DISS2G_FIELD             ((RegisterField) {TMC2300_DISS2G_MASK, TMC2300_DISS2G_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_DISS2VS_MASK             0x80000000
#define TMC2300_DISS2VS_SHIFT            31
#define TMC2300_DISS2VS_FIELD            ((RegisterField) {TMC2300_DISS2VS_MASK, TMC2300_DISS2VS_SHIFT, TMC2300_CHOPCONF, false})
#define TMC2300_OTPW_MASK                0x00000001
#define TMC2300_OTPW_SHIFT               0
#define TMC2300_OTPW_FIELD               ((RegisterField) {TMC2300_OTPW_MASK, TMC2300_OTPW_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_OT_MASK                  0x00000002
#define TMC2300_OT_SHIFT                 1
#define TMC2300_OT_FIELD                 ((RegisterField) {TMC2300_OT_MASK, TMC2300_OT_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_S2GA_MASK                0x00000004
#define TMC2300_S2GA_SHIFT               2
#define TMC2300_S2GA_FIELD               ((RegisterField) {TMC2300_S2GA_MASK, TMC2300_S2GA_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_S2GB_MASK                0x00000008
#define TMC2300_S2GB_SHIFT               3
#define TMC2300_S2GB_FIELD               ((RegisterField) {TMC2300_S2GB_MASK, TMC2300_S2GB_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_S2VSA_MASK               0x00000010
#define TMC2300_S2VSA_SHIFT              4
#define TMC2300_S2VSA_FIELD              ((RegisterField) {TMC2300_S2VSA_MASK, TMC2300_S2VSA_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_S2VSB_MASK               0x00000020
#define TMC2300_S2VSB_SHIFT              5
#define TMC2300_S2VSB_FIELD              ((RegisterField) {TMC2300_S2VSB_MASK, TMC2300_S2VSB_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_OLA_MASK                 0x00000040
#define TMC2300_OLA_SHIFT                6
#define TMC2300_OLA_FIELD                ((RegisterField) {TMC2300_OLA_MASK, TMC2300_OLA_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_OLB_MASK                 0x00000080
#define TMC2300_OLB_SHIFT                7
#define TMC2300_OLB_FIELD                ((RegisterField) {TMC2300_OLB_MASK, TMC2300_OLB_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_T120_MASK                0x00000100
#define TMC2300_T120_SHIFT               8
#define TMC2300_T120_FIELD               ((RegisterField) {TMC2300_T120_MASK, TMC2300_T120_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_T150_MASK                0x00000200
#define TMC2300_T150_SHIFT               9
#define TMC2300_T150_FIELD               ((RegisterField) {TMC2300_T150_MASK, TMC2300_T150_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_CS_ACTUAL_MASK           0x001F0000
#define TMC2300_CS_ACTUAL_SHIFT          16
#define TMC2300_CS_ACTUAL_FIELD          ((RegisterField) {TMC2300_CS_ACTUAL_MASK, TMC2300_CS_ACTUAL_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_STST_MASK                0x80000000
#define TMC2300_STST_SHIFT               31
#define TMC2300_STST_FIELD               ((RegisterField) {TMC2300_STST_MASK, TMC2300_STST_SHIFT, TMC2300_DRVSTATUS, false})
#define TMC2300_PWM_OFS_MASK             0x000000FF
#define TMC2300_PWM_OFS_SHIFT            0
#define TMC2300_PWM_OFS_FIELD            ((RegisterField) {TMC2300_PWM_OFS_MASK, TMC2300_PWM_OFS_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_GRAD_MASK            0x0000FF00
#define TMC2300_PWM_GRAD_SHIFT           8
#define TMC2300_PWM_GRAD_FIELD           ((RegisterField) {TMC2300_PWM_GRAD_MASK, TMC2300_PWM_GRAD_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_FREQ_MASK            0x00030000
#define TMC2300_PWM_FREQ_SHIFT           16
#define TMC2300_PWM_FREQ_FIELD           ((RegisterField) {TMC2300_PWM_FREQ_MASK, TMC2300_PWM_FREQ_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_AUTOSCALE_MASK       0x00040000
#define TMC2300_PWM_AUTOSCALE_SHIFT      18
#define TMC2300_PWM_AUTOSCALE_FIELD      ((RegisterField) {TMC2300_PWM_AUTOSCALE_MASK, TMC2300_PWM_AUTOSCALE_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_AUTOGRAD_MASK        0x00080000
#define TMC2300_PWM_AUTOGRAD_SHIFT       19
#define TMC2300_PWM_AUTOGRAD_FIELD       ((RegisterField) {TMC2300_PWM_AUTOGRAD_MASK, TMC2300_PWM_AUTOGRAD_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_FREEWHEEL_MASK           0x00300000
#define TMC2300_FREEWHEEL_SHIFT          20
#define TMC2300_FREEWHEEL_FIELD          ((RegisterField) {TMC2300_FREEWHEEL_MASK, TMC2300_FREEWHEEL_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_REG_MASK             0x0F000000
#define TMC2300_PWM_REG_SHIFT            24
#define TMC2300_PWM_REG_FIELD            ((RegisterField) {TMC2300_PWM_REG_MASK, TMC2300_PWM_REG_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_LIM_MASK             0xF0000000
#define TMC2300_PWM_LIM_SHIFT            28
#define TMC2300_PWM_LIM_FIELD            ((RegisterField) {TMC2300_PWM_LIM_MASK, TMC2300_PWM_LIM_SHIFT, TMC2300_PWMCONF, false})
#define TMC2300_PWM_SCALE_SUM_MASK       0x000000FF
#define TMC2300_PWM_SCALE_SUM_SHIFT      0
#define TMC2300_PWM_SCALE_SUM_FIELD      ((RegisterField) {TMC2300_PWM_SCALE_SUM_MASK, TMC2300_PWM_SCALE_SUM_SHIFT, TMC2300_PWM_SCALE, false})
#define TMC2300_PWM_SCALE_AUTO_MASK      0xFFFF0000
#define TMC2300_PWM_SCALE_AUTO_SHIFT     16
#define TMC2300_PWM_SCALE_AUTO_FIELD     ((RegisterField) {TMC2300_PWM_SCALE_AUTO_MASK, TMC2300_PWM_SCALE_AUTO_SHIFT, TMC2300_PWM_SCALE, true})
#define TMC2300_PWM_OFS_AUTO_MASK        0x000000FF
#define TMC2300_PWM_OFS_AUTO_SHIFT       0
#define TMC2300_PWM_OFS_AUTO_FIELD       ((RegisterField) {TMC2300_PWM_OFS_AUTO_MASK, TMC2300_PWM_OFS_AUTO_SHIFT, TMC2300_PWMAUTO, false})
#define TMC2300_PWM_GRAD_AUTO_MASK       0x00FF0000
#define TMC2300_PWM_GRAD_AUTO_SHIFT      16
#define TMC2300_PWM_GRAD_AUTO_FIELD      ((RegisterField) {TMC2300_PWM_GRAD_AUTO_MASK, TMC2300_PWM_GRAD_AUTO_SHIFT, TMC2300_PWMAUTO, false})

#endif
