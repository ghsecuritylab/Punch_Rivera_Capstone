#ifndef INCLUDE_ADXL362_H_
#define INCLUDE_ADXL362_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "main.h"

// ADXL362 Registers
#define DEVID_AD 		0x00
#define DEVID_MST		0x01
#define PARTID			0x02
#define REVID			0x03
#define XDATA		 	0x08
#define YDATA 			0x09
#define ZDATA 			0x0A
#define STATUS 			0x0B
#define XDATA_L 		0x0E
#define XDATA_H 		0x0F
#define YDATA_L 		0x10
#define YDATA_H 		0x11
#define ZDATA_L 		0x12
#define ZDATA_H 		0x13
#define TEMP_L 			0x14
#define TEMP_H 			0x15
#define SOFT_RESET 		0x1F
#define THRESH_ACT_L 	0x20
#define THRESH_ACT_H 	0x21
#define TIME_ACT 		0x22
#define THRESH_INACT_L 	0x23
#define THRESH_INACT_H 	0x24
#define TIME_INACT_L 	0x25
#define TIME_INACT_H 	0x26
#define ACT_INACT_CTL	0x27
#define FIFO_CONTROL	0x28
#define FIFO_SAMPLES	0x29
#define INTMAP1 		0x2A
#define INTMAP2 		0x2B
#define FILTER_CTL 		0x2C
#define POWER_CTL 		0x2D
#define SELF_TEST		0x2E
// ADXL362 SPI Commands
#define WR_ADXL 		0x0A
#define RD_ADXL 		0x0B
#define FIFO_ADXL		0x0D
// ADXL362 ACC Offsets
#define G_LSB			0.001
#define T_LSB			0.065
#define X_OFFSET		0.023
#define Y_OFFSET		0.033
#define Z_OFFSET		0.145
#define TEMP_OFFSET		-17
#define G_SCALER		1.01
// ADXL362 USER Defined Constants
#define USER_ACT_TIME		50		// 1 seconds
#define USER_ACT_THRESH		50		// 350 mg
#define USER_INACT_TIME		50		// 5 seconds
#define USER_INACT_THRESH	50		// 300 mg
// Garage Defines
#define T_ANG 6

/* Function prototypes -----------------------------------------------*/
uint8_t ADXL362_ReadReg(uint8_t address);
void ADXL362_WriteReg(uint8_t address, uint8_t cmd);
void ADXL362_GetXYZ8(int8_t *x, int8_t *y, int8_t *z);
void ADXL362_GetXYZ12(int16_t *x, int16_t *y, int16_t *z);
void ADXL362_GetXYZT(int16_t *xyzt, uint32_t offset);
void ADXL362_GetAngT(double *xyzt, uint32_t offset);
void ADXL362_GetTiltState(double *ang, int32_t offset, double *thresh, double *tilt, int16_t *GarageState);
void ADXL362_Init(void);
void ADXL362_ActivityInit (uint16_t thresh, uint8_t timer);
void ADXL362_InactivityInit (uint16_t thresh, uint16_t timer);
#endif /* INCLUDE_ADXL362_H_ */
