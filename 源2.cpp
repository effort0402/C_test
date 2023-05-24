/**
  ******************************************************************************
  * @file    EXTI/EXTI_Config/main.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"


/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

  /** @addtogroup EXTI_Config
	* @{
	*/

	/* Private typedef -----------------------------------------------------------*/
	/* Private define ------------------------------------------------------------*/
	/* Private macro -------------------------------------------------------------*/
	/* Private variables ---------------------------------------------------------*/
EXTI_InitTypeDef   EXIT_yjs_2020032568;
GPIO_InitTypeDef   GPIO_yjs_2020032568;
NVIC_InitTypeDef   NVIC_yjs_2020032568;

/* Private function prototypes -----------------------------------------------*/
void EXTI0_Config(void);
void EXTI15_10_Config(void);

/* Private functions ---------------------------------------------------------*/
void delay_ms(uint16_t ms)
{
	uint16_t i_cnt, j_cnt;
	for (i_cnt = 0; i_cnt < 3000; i_cnt++)
		for (j_cnt = 0; j_cnt < ms; j_cnt++);
}
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured,
		 this is done through SystemInit() function which is called from startup
		 file (startup_stm32f10x_xx.s) before to branch to application main.
		 To reconfigure the default setting of SystemInit() function, refer to
		 system_stm32f10x.c file
	   */

	   /* Initialize LED1 and Key Button mounted on STM3210X-EVAL board */

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	/* Configure PA.00 pin as input floating */

	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_0;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_yjs_2020032568.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_yjs_2020032568);

	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_yjs_2020032568.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_yjs_2020032568);

	/* Configure PA.00 in interrupt mode */
	EXTI0_Config();

	/* Configure PB.09 or PG.08 in interrupt mode */
	EXTI15_10_Config();

	/* Generate software interrupt: simulate a falling edge applied on EXTI0 line */
	EXTI_GenerateSWInterrupt(EXTI_Line0);

	while (1)
	{
		delay_ms(3000);
		GPIOC->BRR = 0X0010;
		delay_ms(3000);
		GPIOC->BSRR = 0X0010;

	}
}

/**970 934 021
  * @brief  Configure PA.00 in interrupt mode
  * @param  None
  * @retval None
  */
void EXTI0_Config(void)
{
	/* Enable GPIOA clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	/* Configure PA.00 pin as input floating */
	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_0;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_yjs_2020032568);

	/* Enable AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/* Connect EXTI0 Line to PA.00 pin */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

	/* Configure EXTI0 line */
	EXIT_yjs_2020032568.EXTI_Line = EXTI_Line0;
	EXIT_yjs_2020032568.EXTI_Mode = EXTI_Mode_Interrupt;
	EXIT_yjs_2020032568.EXTI_Trigger = EXTI_Trigger_Rising;
	EXIT_yjs_2020032568.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXIT_yjs_2020032568);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_yjs_2020032568.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_yjs_2020032568.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_yjs_2020032568.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_yjs_2020032568.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_yjs_2020032568);
}

/**
  * @brief  Configure PB.09 or PG.08 in interrupt mode
  * @param  None
  * @retval None
  */
void EXTI15_10_Config(void)
{

	/* Enable GPIOG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	/* Configure PG.08 pin as input floating */
	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_13;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_yjs_2020032568);

	/* Enable AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	/* Connect EXTI8 Line to PG.08 pin */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);

	/* Configure EXTI8 line */
	EXIT_yjs_2020032568.EXTI_Line = EXTI_Line13;
	EXIT_yjs_2020032568.EXTI_Mode = EXTI_Mode_Interrupt;
	EXIT_yjs_2020032568.EXTI_Trigger = EXTI_Trigger_Falling;
	EXIT_yjs_2020032568.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXIT_yjs_2020032568);

	/* Enable and set EXTI9_5 Interrupt to the lowest priority */
	NVIC_yjs_2020032568.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_yjs_2020032568.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_yjs_2020032568.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_yjs_2020032568.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_yjs_2020032568);

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	   /* Infinite loop */
	while (1)
	{
	}
}

#endif

/**
  * @}
  */

  /**
	* @}
	*/

	/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
