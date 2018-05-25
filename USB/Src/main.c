
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "usb_device.h"

/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include <string.h>
#include "SSD1331.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim10;
/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
volatile uint16_t pulse_count; // Licznik impulsow
volatile uint16_t positions; // Licznik przekreconych pozycji
uint8_t coodebrac = 0;
volatile int state; //Var needed to change mods
int prevpos;
uint32_t timer10;
//DATA INFO		
uint8_t ln_breaker = '_';
uint8_t Buf[1000];
uint8_t Info1[40];
uint8_t Info2[40];
uint8_t Info3[40];
uint8_t Info4[40];
uint8_t Info5[40];
uint8_t Info6[40];
uint8_t Info7[40];
uint8_t Info8[40];
uint8_t Info9[40];
uint8_t Info10[40];
uint8_t Info11[40];
uint8_t Info12[40];
uint8_t Info13[40];
uint8_t Info14[40];
uint8_t Info15[40];
uint8_t Info16[40];
uint8_t Info17[40];
uint8_t Info18[40];
uint8_t Info19[40];
uint8_t Info20[40];
uint8_t Info21[40];
uint8_t Info22[40];
uint8_t Info23[40];
uint8_t Info24[40];
uint8_t Info25[40];
uint8_t Info26[40];
uint8_t Info27[40];
uint8_t Info28[40];
uint8_t Info29[40];
uint8_t Info30[40];

int info_pos[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int first_row = 1, second_row = 2, third_row = 3, forth_row = 4;									

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM10_Init(void);


/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

void search_for_data_packets(){
	int i, pos;
	pos = 0;
	for(i = 0; i <= 1000; i++){
		if(Buf[i] == ln_breaker){
				if (pos == 0){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 1){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 2){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 3){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 4){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 5){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 6){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 7){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 8){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 9){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 10){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 11){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 12){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 13){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 14){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 15){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 16){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 17){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 18){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 19){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 20){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 21){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 22){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 23){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 24){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 25){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 26){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 27){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 28){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 29){
					info_pos[pos] = i;
					pos++;
				} else if (pos == 30){
					info_pos[pos] = i;
					pos++;
				} else break;
		}
	}
	
	}
	
void buf_partition(uint16_t start_pos, uint16_t end_pos, uint8_t table[100]){
		if (start_pos <= end_pos){
		uint16_t cnt = 0;
		while(start_pos != end_pos){
		table[cnt] = Buf[start_pos];
		start_pos++;
		cnt++;
		}
	}
	}
	
	
int check_what_to_display(uint8_t pos){
	if (pos == 1)
	return first_row;
	else
	if (pos == 2)
	return second_row;
	else
	if (pos == 3)
	return third_row;
	else
	if (pos == 4)
	return forth_row;
}


void disp_row(uint8_t row, bool option){
	//FALSE to display first portion of data, TRUE to display second portion of data
	int end_at = 11;
	int start_at = 12;
switch(check_what_to_display(row)){
		case 1:
			for(int i = 0; i < end_at; i++){
			if(Info1[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info1[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
		
		case 2:
			for(int i = 0; i < end_at; i++){
			if(Info2[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info2[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 3:
			for(int i = 0; i < end_at; i++){
			if(Info3[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info3[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 4:
			for(int i = 0; i < end_at; i++){
			if(Info4[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info4[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 5:
			for(int i = 0; i < end_at; i++){
			if(Info5[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info5[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 6:
			for(int i = 0; i < end_at; i++){
			if(Info6[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info6[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 7:
			for(int i = 0; i < end_at; i++){
			if(Info7[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info7[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 8:
			for(int i = 0; i < end_at; i++){
			if(Info8[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info8[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 9:
			for(int i = 0; i < end_at; i++){
			if(Info9[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info9[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 10:
			for(int i = 0; i < end_at; i++){
			if(Info10[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info10[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 11:
			for(int i = 0; i < end_at; i++){
			if(Info11[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info11[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 12:
			for(int i = 0; i < end_at; i++){
			if(Info12[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info12[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 13:
			for(int i = 0; i < end_at; i++){
			if(Info13[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info13[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 14:
			for(int i = 0; i < end_at; i++){
			if(Info14[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info14[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 15:
			for(int i = 0; i < end_at; i++){
			if(Info15[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info15[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 16:
			for(int i = 0; i < end_at; i++){
			if(Info16[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info16[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 17:
			for(int i = 0; i < end_at; i++){
			if(Info17[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info17[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 18:
			for(int i = 0; i < end_at; i++){
			if(Info18[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info18[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 19:
			for(int i = 0; i < end_at; i++){
			if(Info19[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info19[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 20:
			for(int i = 0; i < end_at; i++){
			if(Info20[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info20[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 21:
			for(int i = 0; i < end_at; i++){
			if(Info21[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info21[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 22:
			for(int i = 0; i < end_at; i++){
			if(Info22[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info22[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 23:
			for(int i = 0; i < end_at; i++){
			if(Info23[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info23[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 24:
			for(int i = 0; i < end_at; i++){
			if(Info24[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info24[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 25:
			for(int i = 0; i < end_at; i++){
			if(Info25[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info25[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 26:
			for(int i = 0; i < end_at; i++){
			if(Info26[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info26[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 27:
			for(int i = 0; i < end_at; i++){
			if(Info27[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info27[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 28:
			for(int i = 0; i < end_at; i++){
			if(Info28[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info28[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 29:
			for(int i = 0; i < end_at; i++){
			if(Info29[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info29[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
			
			case 30:
			for(int i = 0; i < end_at; i++){
			if(Info30[(start_at*option)+i] != NULL)
			ssd1331_display_char(i*8,(row-1)*16,Info30[(start_at*option)+i],FONT_1608, GREEN);
			}	
		break;
		}
	}

void set_row(uint8_t row, bool option){
	//0 is incrementing, 1 is decrementing
	if(!option){
		if(row == 1)
			first_row++;
		if(row == 2)
			second_row++;
		if(row == 3)
			third_row++;
		if(row == 4)
			forth_row++;
	} else if(option){
		if(row == 1)
			first_row--;
		if(row == 2)
			second_row--;
		if(row == 3)
			third_row--;
		if(row == 4)
			forth_row--;
	}
	
		if(first_row == 31)
		first_row = 1;
		if(first_row == 0)
		first_row = 30;
		
		if(second_row == 31)
		second_row = 1;
		if(second_row == 0)
		second_row = 30;
	 
		if(third_row == 31)
		third_row = 1;
		if(third_row == 0)
		third_row = 30;
		
		if(forth_row == 31)
		forth_row = 1;
		if(forth_row == 0)
		forth_row = 30;
}
	
void change_info(uint8_t which_place){
		
	while(state != which_place+1){
		pulse_count = TIM1->CNT; // przepisanie wartosci z rejestru timera
		positions = pulse_count/4;
		
	if (prevpos > positions){
		set_row(which_place, 0);
		ssd1331_fill_rect(0, (which_place - 1) * 16, 100, 16, BLUE);
		disp_row(which_place,0);
		HAL_Delay(400);
		ssd1331_fill_rect(0, (which_place - 1) * 16, 100, 16, BLUE);
		disp_row(which_place,1);
		prevpos = positions;
			} 
	else if (prevpos < positions){
		set_row(which_place, 1);
		ssd1331_fill_rect(0, (which_place - 1) * 16, 100, 16, BLUE);
		disp_row(which_place,0);
		HAL_Delay(400);
		ssd1331_fill_rect(0, (which_place - 1) * 16, 100, 16, BLUE);
		disp_row(which_place,1);
		prevpos = positions;
			} 
		}
}	

void show_display(bool option){

	//Data display on the screen
	ssd1331_clear_screen(BLACK);
	disp_row(1,option);
	disp_row(2,option);
	disp_row(3,option);
	disp_row(4,option);
}	

void get_data(){
	search_for_data_packets();
	buf_partition(1, info_pos[0], Info1);
	buf_partition(info_pos[0]+1, info_pos[1], Info2);
	buf_partition(info_pos[1]+1, info_pos[2], Info3);
	buf_partition(info_pos[2]+1, info_pos[3], Info4);
	buf_partition(info_pos[3]+1, info_pos[4], Info5);
	buf_partition(info_pos[4]+1, info_pos[5], Info6);
	buf_partition(info_pos[5]+1, info_pos[6], Info7);
	buf_partition(info_pos[6]+1, info_pos[7], Info8);
	buf_partition(info_pos[7]+1, info_pos[8], Info9);
	buf_partition(info_pos[8]+1, info_pos[9], Info10);
	buf_partition(info_pos[9]+1, info_pos[10], Info11);
	buf_partition(info_pos[10]+1, info_pos[11], Info12);
	buf_partition(info_pos[11]+1, info_pos[12], Info13);
	buf_partition(info_pos[12]+1, info_pos[13], Info12);
	buf_partition(info_pos[13]+1, info_pos[14], Info14);
	buf_partition(info_pos[14]+1, info_pos[15], Info15);
	buf_partition(info_pos[15]+1, info_pos[16], Info16);
	buf_partition(info_pos[16]+1, info_pos[17], Info17);
	buf_partition(info_pos[17]+1, info_pos[18], Info18);
	buf_partition(info_pos[18]+1, info_pos[19], Info19);
	buf_partition(info_pos[19]+1, info_pos[20], Info20);
	buf_partition(info_pos[20]+1, info_pos[21], Info21);
	buf_partition(info_pos[21]+1, info_pos[22], Info22);
	buf_partition(info_pos[22]+1, info_pos[23], Info23);
	buf_partition(info_pos[23]+1, info_pos[24], Info24);
	buf_partition(info_pos[24]+1, info_pos[25], Info25);
	buf_partition(info_pos[25]+1, info_pos[26], Info26);
	buf_partition(info_pos[26]+1, info_pos[27], Info27);
	buf_partition(info_pos[27]+1, info_pos[28], Info28);
	buf_partition(info_pos[28]+1, info_pos[29], Info29);

}
/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4,GPIO_PIN_RESET);
	state = 0;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_TIM10_Init();

  /* USER CODE BEGIN 2 */
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIM_Base_Start_IT(&htim10);
	ssd1331_init();
	timer10 = __HAL_TIM_GetCounter(&htim10); 
	ssd1331_clear_screen(BLACK);
	ssd1331_display_string(20,0,"PCInfo",FONT_1608,BLUE);
	ssd1331_display_string(37,16,"By",FONT_1206,RED);
	ssd1331_display_string(8,28,"Rafal Adamski",FONT_1206,RED);
	ssd1331_display_string(40,40,"&",FONT_1206,RED);
	ssd1331_display_string(8,52,"Adam Olszewski",FONT_1206,RED);
	  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	while(Buf[0] != '!'){	}
	get_data();
		switch(state){
			case 0:
				//Data display on the screen
			show_display(0);
			HAL_Delay(800);
			show_display(1);
			HAL_Delay(800);
			break;
			//Change displayed data (first row)
			case 1:
				prevpos = positions;
				ssd1331_fill_rect(0, 0, 100, 16, BLUE);
				disp_row(1,0);
				change_info(1);
			  ssd1331_fill_rect(0, 0, 100, 16, BLACK);
				disp_row(1,0);
			break;
			
			case 2:
				prevpos = positions;
				ssd1331_fill_rect(0, 16, 100, 16, BLUE);
				disp_row(2,0);
				change_info(2);
				ssd1331_fill_rect(0, 16, 100, 16, BLACK);
				disp_row(2,0);
			break;
			
			case 3:
				prevpos = positions;
				ssd1331_fill_rect(0, 32, 100, 16, BLUE);
				disp_row(3,0);
				change_info(3);
				ssd1331_fill_rect(0, 32, 100, 16, BLACK);
				disp_row(3,0);
			break;
			
			case 4:
				prevpos = positions;
				ssd1331_fill_rect(0, 48, 100, 16, BLUE);
				disp_row(4,0);
				change_info(4);
				ssd1331_fill_rect(0, 48, 100, 16, BLACK);
				disp_row(4,0);
			break;
			
			default:
				state = 0;
			break;
		
		}

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */





void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM1 init function */
static void MX_TIM1_Init(void)
{

  TIM_Encoder_InitTypeDef sConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 403;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 15;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 15;
  if (HAL_TIM_Encoder_Init(&htim1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM10 init function */
static void MX_TIM10_Init(void)
{

  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 9999;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 49909;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : ENC_BUTTON_Pin */
  GPIO_InitStruct.Pin = ENC_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(ENC_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CS_Pin */
  GPIO_InitStruct.Pin = CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DC_Pin */
  GPIO_InitStruct.Pin = DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : RES_Pin */
  GPIO_InitStruct.Pin = RES_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RES_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

/* USER CODE BEGIN 4 */
void CDC_ReceiveCallBack(uint8_t *buf, uint32_t len){
	//CDC_Transmit_FS(buf, len);
	if(buf[0] == '!'){
		strcpy(Buf, buf);
	} else
	strcat(Buf,buf);
	//memcpy(Buf, buf, 1000);
HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
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
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
