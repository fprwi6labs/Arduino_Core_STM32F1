/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

/* GPIO ID    | label
  PA0         | A0
  PA1         | A1
  PA2         | D1/TX
  PA3         | D0/RX
  PA4         | A2
  PA5         | D13/SCK
  PA6         | D12/MISO
  PA7         | D11/PWM/MOSI
  PA8         | D7
  PA9         | D8
  PA10        | D2
  PA11        |
  PA12        |
  PA13        |
  PA14        |
  PA15        |
  PB0         | A3
  PB1         |
  PB2         |
  PB3         | D3/PWM
  PB4         | D5/PWM
  PB5         | D4
  PB6         | D10/PWM/CS
  PB7         |
  PB8         | D15/SCL
  PB9         | D14/SDA
  PB10        | D6/PWM
  PB11        |
  PB12        |
  PB13        |
  PB14        |
  PB15        |
  PC13        |
  PC14        |
  PC15        |

*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
extern const PinDescription g_APinDescription[]=

//  arduino_id  |     ulPin    |   ulPort | mode               |          configured
{
  { ARDUINO_PIN_A0,   GPIO_PIN_0,  GPIOA, GPIO_PIN_IO|GPIO_PIN_ADC,                     false },
  { ARDUINO_PIN_A1,   GPIO_PIN_1,  GPIOA, GPIO_PIN_IO|GPIO_PIN_ADC,                     false },
  { ARDUINO_PIN_D1,   GPIO_PIN_2,  GPIOA, GPIO_PIN_IO|GPIO_PIN_UART_TX,                 false },
  { ARDUINO_PIN_D0,   GPIO_PIN_3,  GPIOA, GPIO_PIN_IO|GPIO_PIN_UART_RX,                 false },
  { ARDUINO_PIN_A2,   GPIO_PIN_4,  GPIOA, GPIO_PIN_IO|GPIO_PIN_ADC,                     false },
  { ARDUINO_PIN_D13,  GPIO_PIN_5,  GPIOA, GPIO_PIN_IO|GPIO_PIN_SPI_SCK,                 false },
  { ARDUINO_PIN_D12,  GPIO_PIN_6,  GPIOA, GPIO_PIN_IO|GPIO_PIN_SPI_MISO,                false },
  { ARDUINO_PIN_D11,  GPIO_PIN_7,  GPIOA, GPIO_PIN_IO|GPIO_PIN_SPI_MOSI|GPIO_PIN_PWM,   false },
  { ARDUINO_PIN_D7,   GPIO_PIN_8,  GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_D8,   GPIO_PIN_9,  GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_D2,   GPIO_PIN_10, GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_11, GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_12, GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_13, GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_14, GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_15, GPIOA, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_A3,   GPIO_PIN_0,  GPIOB, GPIO_PIN_ADC,                                 false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_1,  GPIOB, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_EXT,  GPIO_PIN_2,  GPIOB, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_D3,   GPIO_PIN_3,  GPIOB, GPIO_PIN_IO|GPIO_PIN_PWM,                     false },
  { ARDUINO_PIN_D5,   GPIO_PIN_4,  GPIOB, GPIO_PIN_IO|GPIO_PIN_PWM,                     false },
  { ARDUINO_PIN_D4,   GPIO_PIN_5,  GPIOB, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_D10,  GPIO_PIN_6,  GPIOB, GPIO_PIN_IO|GPIO_PIN_PWM|GPIO_PIN_SPI_CS,     false },
  { PB7,              GPIO_PIN_7,  GPIOB, GPIO_PIN_IO,                                  false },
  { ARDUINO_PIN_D15,  GPIO_PIN_8,  GPIOB, GPIO_PIN_IO|GPIO_PIN_I2C_SCL,                 false },
  { ARDUINO_PIN_D14,  GPIO_PIN_9,  GPIOB, GPIO_PIN_IO|GPIO_PIN_I2C_SDA,                 false },
  { ARDUINO_PIN_D6,   GPIO_PIN_10, GPIOB, GPIO_PIN_IO|GPIO_PIN_PWM,                     false },
  { PB11,             GPIO_PIN_11, GPIOB, GPIO_PIN_IO,                                  false },
  { PB12,             GPIO_PIN_12, GPIOB, GPIO_PIN_IO,                                  false },
  { PB13,             GPIO_PIN_13, GPIOB, GPIO_PIN_IO,                                  false },
  { PB14,             GPIO_PIN_14, GPIOB, GPIO_PIN_IO,                                  false },
  { PB15,             GPIO_PIN_15, GPIOB, GPIO_PIN_IO,                                  false },
  { PC13,             GPIO_PIN_13, GPIOC, GPIO_PIN_IO,                                  false },
  { PC14,             GPIO_PIN_14, GPIOC, GPIO_PIN_IO,                                  false },
  { PC15,             GPIO_PIN_15, GPIOC, GPIO_PIN_IO,                                  false }
};

#ifdef __cplusplus
}
#endif

/*
 * UART objects
 */

#ifdef SERIAL_USB 
USBSerial Serial;    //available on PA9/PA10 
#endif 
//UARTClass Serial(USART2_E);    //available on PA2/PA3
UARTClass Serial1(USART1_E);   //available on PA9/PA10
USARTClass Serial2(USART2_E);  //available on PA2/PA3

void serialEvent() __attribute__((weak));
void serialEvent() { }

void serialEventRun(void)
{
#ifdef SERIAL_USB 
  if (Serial.available()) serialEvent(); 
#endif 
}

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SERIAL_USB 
void USBSerial_Rx_Handler(uint8_t *data, uint16_t len){ 
  Serial.CDC_RxHandler(data, len); 
} 
#endif

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_PeriphCLKInitTypeDef PeriphClkInit;

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
    RCC_OscInitStruct.HSICalibrationValue = 16;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB; 
    PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5; 
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);
    
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

    /* SysTick_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void __libc_init_array(void);


void init( void )
{
  hw_config_init();
}

#ifdef __cplusplus
}
#endif
