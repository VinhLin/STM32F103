/**
 * Olivier Van den Eede (4ilo) 2019
 * This library uses the MAX31865 RTD-to-Digital Converter to measure the temperature using a Pt100 or Pt1000 temperature probe.
 *
 * This library is written for Stm32f4 microcontrollers using the stm32-HAL software library.
 * The usage of software SPI in this library is due to issues with reading data using the SPI-HAL functions.
 */
#ifndef MAX31865_LIB_MAX31865_H
#define MAX31865_LIB_MAX31865_H

#include "stm32f1xx_hal.h"

/********************* MAX31865 registers and config bits *********************/
#define MAX31865_READ                   0x00
#define MAX31865_WRITE                  0x80
#define MAX31856_RTDMSB_REG             0x01
#define MAX31856_CONFIG_REG             0x00
#define MAX31856_CONFIG_BIAS            0x80
#define MAX31856_CONFIG_1SHOT           0x20
#define MAX31856_CONFIG_3WIRE           0x10
#define MAX31856_CONFIG_MODEAUTO        0x40


/********************* Constants *********************/
#define RREF 430                        // Reference resistor
#define FACTOR 32768                    // 2^15 used for data to resistance conversion
#define ALPHA 0.003851                  // PT-100 temperature coefficient


/********************* General defines *********************/
#define ON 1
#define OFF 0
#define DELAY(x) HAL_Delay(x)

#define RTD_A 3.9083e-3
#define RTD_B -5.775e-7

#define GPIO_PORT_CS	GPIOA
#define GPIO_PIN_CS		GPIO_PIN_12

#endif //MAX31865_LIB_MAX31865_H
