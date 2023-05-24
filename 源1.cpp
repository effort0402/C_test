int main(void)
{
	int K1_202003258_yjs = GPIOA->BSRR;
	int K2_202003258_yjs = GPIOD->BSRR;
	int count_202003258_yjs;//统计按键次数
	GPIOA->BSRR = 0x00000080;
	GPIOD->BSRR = 0x00008000;

	/* GPIOD Periph clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	/* Configure PB5 in output pushpull mode */
	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_5;
	GPIO_yjs_2020032568.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_yjs_2020032568);


	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_0;
	GPIO_yjs_2020032568.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_yjs_2020032568);


	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_7;
	GPIO_yjs_2020032568.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_yjs_2020032568);


	GPIO_yjs_2020032568.GPIO_Pin = GPIO_Pin_15;
	GPIO_yjs_2020032568.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_yjs_2020032568.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_yjs_2020032568);

	while (1)
	{
		if (K2_202003258_yjs == 0x00008000)
		{

			GPIOB->BSRR = 0x00000020;
			//GPIO_SetBits(GPIOB,GPIO_Pin_5);
			//delay_ms(5000);
			GPIOB->BRR = 0x00000020;//置1清0
			//delay_ms(5000);
			//GPIO_ResetBits(GPIOB,GPIO_Pin_5);

			GPIOC->BSRR = 0x0000001;
			//delay_ms(5000);
			//GPIO_SetBits(GPIOC,GPIO_Pin_0);
			GPIOC->BRR = 0x00000001;
			//delay_ms(5000);
			//GPIO_ResetBits(GPIOC,GPIO_Pin_0);
		}
		else
		{


			if (K1_202003258_yjs == 0)
			{
				if (count_202003258_yjs % 2 != 0)//按下为奇数
				{
					GPIOB->BSRR = 0x00000020;
					//delay_ms(5000);
					//GPIO_SetBits(GPIOB,GPIO_Pin_5);
					GPIOB->BRR = 0x00000020;//置1清0
					//delay_ms(5000);
					//GPIO_ResetBits(GPIOB,GPIO_Pin_5);

					GPIOC->BRR = 0x00000001;
					//delay_ms(5000);
					//GPIO_ResetBits(GPIOC,GPIO_Pin_0);
				}
				else   //按下为偶数
				{
					GPIOC->BSRR = 0x0000001;
					//delay_ms(5000);
					GPIOC->BRR = 0x00000001;
					//delay_ms(5000);

					GPIOB->BRR = 0x00000020;
					//delay_ms(5000);
				}
			}
		}
	}
}