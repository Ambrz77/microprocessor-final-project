/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 16/07/2020 02:01:32
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            16000000
#define MX_HSE_VALUE                            25000000
#define MX_EXTERNAL_CLOCK_VALUE                 12288000
#define MX_PLLCLKFreq_Value                     84000000
#define MX_SYSCLKFreq_VALUE                     84000000
#define MX_HCLKFreq_Value                       84000000
#define MX_FCLKCortexFreq_Value                 84000000
#define MX_CortexFreq_Value                     84000000
#define MX_AHBFreq_Value                        84000000
#define MX_APB1Freq_Value                       42000000
#define MX_APB2Freq_Value                       84000000
#define MX_APB1TimFreq_Value                    84000000
#define MX_APB2TimFreq_Value                    84000000
#define MX_48MHZClocksFreq_Value                42000000
#define MX_EthernetFreq_Value                   16000000
#define MX_I2SClocksFreq_Value                  192000000
#define MX_RTCFreq_Value                        32000
#define MX_WatchDogFreq_Value                   32000
#define MX_MCO1PinFreq_Value                    16000000
#define MX_MCO2PinFreq_Value                    84000000

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- USART2     --------------------------------*/

#define MX_USART2                               1

#define MX_USART2_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PA2 */
#define MX_USART2_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART2_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART2_TX_Pin                        PA2
#define MX_USART2_TX_GPIOx                      GPIOA
#define MX_USART2_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART2_TX_GPIO_Pin                   GPIO_PIN_2
#define MX_USART2_TX_GPIO_AF                    GPIO_AF7_USART2

/* Pin PA3 */
#define MX_USART2_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART2_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART2_RX_Pin                        PA3
#define MX_USART2_RX_GPIOx                      GPIOA
#define MX_USART2_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART2_RX_GPIO_Pin                   GPIO_PIN_3
#define MX_USART2_RX_GPIO_AF                    GPIO_AF7_USART2

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PA5 */
#define MX_PA5_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA5_Pin                              PA5
#define MX_PA5_GPIOx                            GPIOA
#define MX_PA5_PinState                         GPIO_PIN_RESET
#define MX_PA5_GPIO_PuPd                        GPIO_NOPULL
#define MX_LED                                  PA5
#define MX_PA5_GPIO_Pin                         GPIO_PIN_5
#define MX_PA5_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PC13-ANTI_TAMP */
#define MX_PC13_ANTI_TAMP_Pin                   PC13_ANTI_TAMP
#define MX_PC13_ANTI_TAMP_GPIOx                 GPIOC
#define MX_PC13_ANTI_TAMP_GPIO_PuPd             GPIO_NOPULL
#define MX_BUTTON                               PC13_ANTI_TAMP
#define MX_PC13_ANTI_TAMP_GPIO_Pin              GPIO_PIN_13
#define MX_PC13_ANTI_TAMP_GPIO_Mode             GPIO_MODE_INPUT

#endif  /* __MX_DEVICE_H */

