#ifndef ap3426_H_
#define ap3426_H_
#endif

//System Register
#define AP3426_ADDR 0x1E      //AP3426 I2C Address
#define AP3426_W 0
#define AP3426_R 1
#define SYS_CONTROL_ADDR 0x00 //AP3426 Register-0x00
#define Int_Status 0x01 //AP3426 Register-0x01 
#define INT_CONTROL 0x02 //AP3426 Register-0x02
#define Waiting_Time 0x06 //AP3426 Register-0x06   
#define IR_Data_Low 0x0A //AP3426 IR Data Low Register
#define IR_Data_High 0x0B //AP3426 IR Data High Register
#define ALS_Data_Low 0x0C  //AP3426 ALS Data Low Register 
#define ALS_Data_High 0x0D //AP3426 ALS Data High Register
#define PS_Data_Low 0x0E //AP3426 PS Data Low Register
#define PS_Data_High 0x0F //AP3426 Data High Register

//ALS Register Setting
#define ALS_Gain 0x10 //Gain control of ALS
#define ALS_LowLow_Threshold 0x1A //Lower part of ALS Low threshold
#define ALS_UpLow_Threshold 0x1B //Upper part of ALS Low threshold
#define ALS_LowHigh_Threshold 0x1C //Lower part of ALS High threshold
#define ALS_UpHigh_Threshold 0x1D //Upper part of ALS High threshold

//PS Register Setting
#define PS_Gain 0x20 //Gain control of PS
#define PS_Led_Driver 0x21 //Control of LED driver current
#define PS_Int_Form 0x22 //Interrupt algorithms style select of PS
#define PS_Mean_Time 0x23 //PS average time selector
#define PS_Smart_Int 0x24 //Accelerate the INT response time of PS
#define PS_IR_IntegrationTime 0x25 //PS integration time setting
#define PS_Persistence 0x26 // Configure the Persist count of PS
#define PS_Calibration_L 0x28 //Offset value to eliminate the Cross talk effect
#define PS_Calibration_H 0x29 //Offset value to eliminate the Cross talk effect
#define PS_Low_LowThreshold 0x2A //Lower part of PS low threshold(7:0)
#define PS_Low_UpThresuold 0x2B //Upper part of PS low threshold(9:8)
#define PS_High_LowThreshold 0x2C //Lower part of PS high threshold(7:0)
#define PS_High_UpThreshold 0x2D //Upper part of PS high threshold(9:8)

#define Init_ps_lowThreshold 0xC8 //PS Low Threshold=200
#define Init_pshi_lowbyteThreshold 0xF4  //PS High Threshold=500
#define Init_pshi_upbyteThreshold 0x01  //PS High Threshold=500

#define Init_als_lowThreshold 0xC8 //ALS Low Threshold=200
#define Init_alshi_lowbyteThreshold 0xF4  //ALS High Threshold=500
#define Init_lashi_upbyteThreshold 0x01  //ALS High Threshold=500

enum AP3426_mode_value           //Register 0x00 value
{
    AP3426_MODE_POWER_DOWN,      //Power down (Default)
    AP3426_MODE_ALS,             //ALS function active
    AP3426_MODE_PS,              //PS+IR function active
    AP3426_MODE_IR_ALS_AND_PS,      //ALS and PS+IR functions active
    AP3426_MODE_SW_RESET,        //SW reset
    AP3426_MODE_ALS_ONCE,        //ALS function once
    AP3426_MODE_PS_ONCE,         //PS+IR function once
    AP3426_MODE_ALS_AND_PS_ONCE, //ALS and PS+IR functions once
};

enum AP3426_INTFlag_value        //Register 0x01 value
{
    AP3426_ALS_INT=0,
    AP3426_PS_INT=0,
	AP3426_Object_detect,
	AP3426_IROverflow,
};

enum AP3426_INT_control_value   //Register 0x02 value
{
	AP3426_Clear_Manner=0,
	AP3426_ALS_INT_enable=1,
	AP3426_PS_INT_enable=1,
};

enum AP3426_WaitTime_value   //Register 0x06 value
{
	AP3426_WaitTime=0,
};

enum ALS_Gain_value        //Register 0x10 value
{
	AP3426_ALGGAIN_Bit4=0,
	AP3426_ALGGAIN_Bit5=0,
};

enum ALS_Persistence_value        //Register 0x14 value
{
    AP3426_ALSPersistence_Bit0=1,
	AP3426_ALSPersistence_Bit1=0,
	AP3426_ALSPersistence_Bit2=0,
	AP3426_ALSPersistence_Bit3=0,
	AP3426_ALSPersistence_Bit4=0,
	AP3426_ALSPersistence_Bit5=0,
	AP3426_Bit6,
	AP3426_Bit7,
};

enum PS_Gain_value                //Register 0x20 value
{
	AP3426_PSGAIN_Bit2=0,
	AP3426_PSGAIN_Bit3=0,
};

enum PS_DRV_value                //Register 0x21 value
{
    AP3426_PSDRVRBit0=1,
	AP3426_PSDRVRBit1=1,
};

enum PS_INTForm_value                //Register 0x22 value
{
    AP3426_INTForm=1,
};

enum PS_MeanTime_value                //Register 0x23 value
{
    AP3426_MeanTimeBit0=0,
	AP3426_MeanTimeBit1=0,
};

enum PS_SmartINT_value                //Register 0x24 value
{
    AP3426_SmartINT=0,
};

enum PS_IntegrationTime_value        //Register 0x25 value
{
    AP3426_PSIntegrationTime_Bit0=0,
	AP3426_PSIntegrationTime_Bit1=0,
	AP3426_PSIntegrationTime_Bit2=0,
	AP3426_PSIntegrationTime_Bit3=0,
	AP3426_PSIntegrationTime_Bit4=0,
	AP3426_PSIntegrationTime_Bit5=0,
};

enum PS_Persistence_value        //Register 0x26 value
{
    AP3426_PSPersistence_Bit0=0,
	AP3426_PSPersistence_Bit1=1,
	AP3426_PSPersistence_Bit2=0,
	AP3426_PSPersistence_Bit3=0,
	AP3426_PSPersistence_Bit4=0,
	AP3426_PSPersistence_Bit5=0,
};

enum ALS_LowThreshold_L_value        //Register 0x1A value
{
    AP3426_ALSLowThresholdL_Bit0=0,
	AP3426_ALSLowThresholdL_Bit1=0,
	AP3426_ALSLowThresholdL_Bit2=0,
	AP3426_ALSLowThresholdL_Bit3=0,
	AP3426_ALSLowThresholdL_Bit4=0,
	AP3426_ALSLowThresholdL_Bit5=0,
	AP3426_ALSLowThresholdL_Bit6=0,
	AP3426_ALSLowThresholdL_Bit7=0,
};

enum ALS_LowThreshold_H_value        //Register 0x1B value
{
    AP3426_ALSLowThresholdH_Bit0=0,
	AP3426_ALSLowThresholdH_Bit1=0,
	AP3426_ALSLowThresholdH_Bit2=0,
	AP3426_ALSLowThresholdH_Bit3=0,
	AP3426_ALSLowThresholdH_Bit4=0,
	AP3426_ALSLowThresholdH_Bit5=0,
	AP3426_ALSLowThresholdH_Bit6=0,
	AP3426_ALSLowThresholdH_Bit7=0,
};

enum ALS_HiThreshold_L_value        //Register 0x1C value
{
    AP3426_ALSHiThresholdL_Bit0=1,
	AP3426_ALSHiThresholdL_Bit1=1,
	AP3426_ALSHiThresholdL_Bit2=1,
	AP3426_ALSHiThresholdL_Bit3=1,
	AP3426_ALSHiThresholdL_Bit4=1,
	AP3426_ALSHiThresholdL_Bit5=1,
	AP3426_ALSHiThresholdL_Bit6=1,
	AP3426_ALSHiThresholdL_Bit7=1,
};

enum ALS_HiThreshold_H_value        //Register 0x1D value
{
    AP3426_ALSHiThresholdH_Bit0=1,
	AP3426_ALSHiThresholdH_Bit1=1,
	AP3426_ALSHiThresholdH_Bit2=1,
	AP3426_ALSHiThresholdH_Bit3=1,
	AP3426_ALSHiThresholdH_Bit4=1,
	AP3426_ALSHiThresholdH_Bit5=1,
	AP3426_ALSHiThresholdH_Bit6=1,
	AP3426_ALSHiThresholdH_Bit7=1,
};

enum PS_LowThreshold_L_value        //Register 0x2A value
{
    AP3426_PSLowThresholdL_Bit0=0,
	AP3426_PSLowThresholdL_Bit1=0,
	AP3426_PSLowThresholdL_Bit2=0,
	AP3426_PSLowThresholdL_Bit3=1,
	AP3426_PSLowThresholdL_Bit4=0,
	AP3426_PSLowThresholdL_Bit5=0,
	AP3426_PSLowThresholdL_Bit6=1,
	AP3426_PSLowThresholdL_Bit7=1,
};

enum PS_LowThreshold_H_value        //Register 0x2B value
{
    AP3426_PSLowThresholdH_Bit0=0,
	AP3426_PSLowThresholdH_Bit1=0,
	AP3426_PSLowThresholdH_Bit2=0,
	AP3426_PSLowThresholdH_Bit3=0,
	AP3426_PSLowThresholdH_Bit4=0,
	AP3426_PSLowThresholdH_Bit5=0,
	AP3426_PSLowThresholdH_Bit6=0,
	AP3426_PSLowThresholdH_Bit7=0,
};

enum PS_HiThreshold_L_value        //Register 0x2C value
{
    AP3426_PSHiThresholdL_Bit0=1,
	AP3426_PSHiThresholdL_Bit1=1,
	AP3426_PSHiThresholdL_Bit2=1,
	AP3426_PSHiThresholdL_Bit3=1,
	AP3426_PSHiThresholdL_Bit4=1,
	AP3426_PSHiThresholdL_Bit5=1,
	AP3426_PSHiThresholdL_Bit6=1,
	AP3426_PSHiThresholdL_Bit7=1,
};

enum PS_HiThreshold_H_value        //Register 0x2D value
{
    AP3426_PSHiThresholdH_Bit0=1,
	AP3426_PSHiThresholdH_Bit1=1,
	AP3426_PSHiThresholdH_Bit2=1,
	AP3426_PSHiThresholdH_Bit3=1,
	AP3426_PSHiThresholdH_Bit4=1,
	AP3426_PSHiThresholdH_Bit5=1,
	AP3426_PSHiThresholdH_Bit6=1,
	AP3426_PSHiThresholdH_Bit7=1,
};

enum PS_Calibration_L_value        //Register 0x28 value
{
    AP3426_PSCalL_Bit0=0,
	AP3426_PSCalL_Bit1=0,
	AP3426_PSCalL_Bit2=0,
	AP3426_PSCalL_Bit3=0,
	AP3426_PSCalL_Bit4=0,
	AP3426_PSCalL_Bit5=0,
	AP3426_PSCalL_Bit6=0,
	AP3426_PSCalL_Bit7=0,
};

enum PS_Calibration_H_value        //Register 0x29 value
{
    AP3426_PSCalH_Bit0=0,
	AP3426_PSCalH_Bit1=0,
	AP3426_PSCalH_Bit2=0,
	AP3426_PSCalH_Bit3=0,
	AP3426_PSCalH_Bit4=0,
	AP3426_PSCalH_Bit5=0,
	AP3426_PSCalH_Bit6=0,
	AP3426_PSCalH_Bit7=0,
};






