/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "st7735.h"
#include "fonts.h"
#include "testimg.h"
#include <string.h>
#include "GNSS.h"
#include "LCDController.h"
#include "lvgl.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi1_tx;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

/* USER CODE BEGIN PV */
uint8_t uartBuffer[256] = {'\0'};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void init() {
    ST7735_Init();
}

void initFatFS(){
	  char buffer[512];
	  static FATFS g_sFatFs;
	  FRESULT fresult;
	  FIL file;
	  int len;
	  UINT bytes_written;
	  fresult = f_mount(&g_sFatFs, "0:", 0);        //mount SD card
	  fresult = f_open(&file, "testfile.txt", FA_OPEN_ALWAYS | FA_WRITE); //open file on SD card
	  //fresult = f_lseek(&file, file.fsize);         //go to the end of the file
	  len = sprintf(buffer, "Hello, World!\r\nThis is demonstration write on SD Card\r\n");    //generate some string
	  fresult = f_write(&file, buffer, len, &bytes_written);     //write data to the file
	  fresult = f_close(&file);
}

void loop() {
    // Check border
    //ST7735_FillScreen(ST7735_BLACK);

//    for(int x = 0; x < ST7735_WIDTH; x++) {
//        ST7735_DrawPixel(x, 0, ST7735_RED);
//        ST7735_DrawPixel(x, ST7735_HEIGHT-1, ST7735_RED);
//    }
//
//    for(int y = 0; y < ST7735_HEIGHT; y++) {
//        ST7735_DrawPixel(0, y, ST7735_RED);
//        ST7735_DrawPixel(ST7735_WIDTH-1, y, ST7735_RED);
//    }
//
//    HAL_Delay(3000);

    // Check fonts
//    ST7735_FillScreen(ST7735_BLACK);
//    char stringData[256] = {'\0'};
//
//    strncpy(stringData, uartBuffer, 255);
//
//    ST7735_WriteString(0, 0, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
////    ST7735_WriteString(0, 0, "Font_7x10, red on black, lorem ipsum dolor sit amet", Font_7x10, ST7735_RED, ST7735_BLACK);
////    ST7735_WriteString(0, 3*10, "Font_11x18, green, lorem ipsum", Font_11x18, ST7735_GREEN, ST7735_BLACK);
////    ST7735_WriteString(0, 3*10+3*18, "Font_16x26", Font_16x26, ST7735_BLUE, ST7735_BLACK);
//    HAL_Delay(1000);

    // Check colors
//    ST7735_FillScreen(ST7735_BLACK);
//    ST7735_WriteString(0, 0, "BLACK", Font_11x18, ST7735_WHITE, ST7735_BLACK);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_BLUE);
//    ST7735_WriteString(0, 0, "BLUE", Font_11x18, ST7735_BLACK, ST7735_BLUE);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_RED);
//    ST7735_WriteString(0, 0, "RED", Font_11x18, ST7735_BLACK, ST7735_RED);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_GREEN);
//    ST7735_WriteString(0, 0, "GREEN", Font_11x18, ST7735_BLACK, ST7735_GREEN);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_CYAN);
//    ST7735_WriteString(0, 0, "CYAN", Font_11x18, ST7735_BLACK, ST7735_CYAN);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_MAGENTA);
//    ST7735_WriteString(0, 0, "MAGENTA", Font_11x18, ST7735_BLACK, ST7735_MAGENTA);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_YELLOW);
//    ST7735_WriteString(0, 0, "YELLOW", Font_11x18, ST7735_BLACK, ST7735_YELLOW);
//    HAL_Delay(500);
//
//    ST7735_FillScreen(ST7735_WHITE);
//    ST7735_WriteString(0, 0, "WHITE", Font_11x18, ST7735_BLACK, ST7735_WHITE);
//    HAL_Delay(500);
//
//
//    // Display test image 128x128
//    ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, (uint16_t*)test_img_128x128);

/*
    // Display test image 128x128 pixel by pixel
    for(int x = 0; x < ST7735_WIDTH; x++) {
        for(int y = 0; y < ST7735_HEIGHT; y++) {
            uint16_t color565 = test_img_128x128[y][x];
            // fix endiness
            color565 = ((color565 & 0xFF00) >> 8) | ((color565 & 0xFF) << 8);
            ST7735_DrawPixel(x, y, color565);
        }
    }
*/
//    HAL_Delay(15000);

}


///* Initialize low level display driver */
//void lv_port_disp_init(void);
//
///* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
// */
//void disp_enable_update(void);
//
///* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
// */
//void disp_disable_update(void);

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

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
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  MX_FATFS_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  //HAL_DMA_RegisterCallback(hdma_spi1_tx, HAL_DMA_XFER_CPLT_CB_ID, pCallback);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  ST7735_Init();
  ST7735_FillScreen(ST7735_BLACK);
  initFatFS();
  /* Initialize LVGL */
  lv_init();
  lv_port_disp_init();
  lv_demo_benchmark();

//	ST7735_FillScreen(ST7735_BLACK);
//	GNSS_Init(&GNSS_Handle, &huart2);
//	HAL_Delay(1000);
//	GNSS_LoadConfig(&GNSS_Handle);
//	GNSS_SetMode(&GNSS_Handle, Automotiv);
//	uint32_t Timer = HAL_GetTick();
//	ST7735_FillScreen(ST7735_BLACK);



  //HAL_UART_Receive_DMA(&huart2, uartBuffer, 256U);
  char stringData[256] = {'\0'};
  while (1)
  {
    //loop();
	  lv_task_handler();
	  HAL_Delay(5);




//	  if ((HAL_GetTick() - Timer) > 1000) {
//	  			GNSS_GetUniqID(&GNSS_Handle);
//	  			GNSS_ParseBuffer(&GNSS_Handle);
//	  			HAL_Delay(250);
//	  			GNSS_GetPVTData(&GNSS_Handle);
//	  			GNSS_ParseBuffer(&GNSS_Handle);
//
//
//
//	  			sprintf(stringData, "Day: %d-%d-%d", GNSS_Handle.day, GNSS_Handle.month,GNSS_Handle.year);
//	  			ST7735_WriteString(0, 0, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Time: %d:%d:%d", GNSS_Handle.hour, GNSS_Handle.min,GNSS_Handle.sec);
//	  			ST7735_WriteString(0, 10, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Status of fix: %d", GNSS_Handle.fixType);
//	  			ST7735_WriteString(0, 20, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Lat: %f", GNSS_Handle.fLat);
//	  			ST7735_WriteString(0, 30, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Lon: %f", GNSS_Handle.fLon);
//	  			ST7735_WriteString(0, 40, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			//memset(stringData, 0, 256);
//	  			sprintf(stringData, "Height above ellipsoid: %d", GNSS_Handle.height);
//	  			ST7735_WriteString(0, 50, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Height above mean sea level: %d", GNSS_Handle.hMSL);
//	  			ST7735_WriteString(0, 70, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Ground Speed (2-D): %d", GNSS_Handle.gSpeed);
//	  			ST7735_WriteString(0, 90, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			sprintf(stringData, "Unique ID: %04X %04X %04X %04X %04X \n\r",
//	  					GNSS_Handle.uniqueID[0], GNSS_Handle.uniqueID[1],
//	  					GNSS_Handle.uniqueID[2], GNSS_Handle.uniqueID[3],
//	  					GNSS_Handle.uniqueID[4], GNSS_Handle.uniqueID[5]);
//	  			ST7735_WriteString(0, 110, stringData, Font_7x10, ST7735_WHITE, ST7735_BLACK);
//	  			Timer = HAL_GetTick();
//	  		    //ST7735_FillScreen(ST7735_BLACK);
//	  }
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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 200;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
  /* DMA2_Stream2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|CS_SD_CARD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA9 PA10 CS_SD_CARD_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|CS_SD_CARD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
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
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
