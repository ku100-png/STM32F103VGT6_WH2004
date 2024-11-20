# STM32F103VGT6_WH2004
  Demonstrations project on STM32F103VGT6 Cortex-M3.
  This example helps you to discover STM32F103VGT6 Cortex-M3 device with WH2004 symbol display

  @verbatim
  ******************************************************************************
  * @file    readme
  * @author  KULIKOV V.G.
  * @brief   Description of project on STM32F103VGT6 with WH2004
  ******************************************************************************
  @endverbatim

@par Demo Description

Demonstration firmware based on STM32Cube. This example helps you to discover
STM32 Cortex-M3 device that are plugged onto UUN_VTC board

The SystemClock_Config() function is used to configure the system clock :
  - The Cortex-M3 SYSCLK at 60MHz.
  - HSE 12MHz.
  - HCLK 60MHz.
  - APB1 Timer 4 clock 60MHz.
  - LSI RC for Real Time Clock (RTC) 40kHz

На демонстрационной плате используются следующие аппаратные блоки:
  - Символьный индикатор WH2004 ф.Winstar на KS0066 контроллере со встроенным 
	русским знакогенератором.
  - Кнопки "OK", "UP", "DOWN", подключенные соответственно к PA12, PA8, PA9.
  - Энкодер инкрементный, подключенный к каналам таймера TIM4 на выводы PD12 и 
    PD13. Центральная кнопка энкодера подключена к PA10.
  - Светодиоды LED1, LED2, подключенные соответственно к PE3, PE2.
  
 В микроконтроллере задействованы следующие периферийные модули:
  - Вводы-выводы общего назначения для уравления аппаратными блоками.
  - Таймер TIM3 для организации микросекундых задержек.
  - Таймер TIM4 для обработки сигналов с инкрементного энкодера.
  - Часы реального времени тактируемые от LSI RC 40kHz.
 
 Ниже краткое описание работы демонстрационной программы:
  - В демонстрационной программе написан простой драйвер для работы с 
	символьным дисплеем 20х4, на который можно выводить русские/английские
	символы и цифры в разном формате.
  - Организовано программное меню из нескольких окон. Для переключения между
	окнами импользуется кнопка "OK". Короткое и длительное нажатие кнопки 
	переключает в разные окна.
  - Представлен пример вывода на дисплей меню с параметрами с прокруткой, 
	навигация по которым возможна с помощью кнопок "UP" и "DOWN". Выбор и 
	изменение параметра возможен при длительном нажатии кнопки "OK". Для
	изменения и ввода нового значения параметра можно использовать энкодер.
  - Представлены примеры вывода измеренных параметров и журнала событий с 
	обновлением событий при нажатии кнопок "OK", "UP", "DOWN". В журнале 
	событий фиксируется время каждого события. Детали каждого события можно 
	посмотреть в отдельном окне, выбрав событие и длительно нажав кнопку "OK".
  - Светодиод LED1 переключается каждые 100 мс. Светодиод LED2 переключается 
	при смене окна меню индикатора WH200.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR.
      This implies that if HAL_Delay() is called from a peripheral ISR process,
      then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to
      1 millisecond to have correct HAL operation.

@par Hardware and Software environment

  - This demonstration runs on STM32F103VGT6 Cortex-M3 device.
  
@par How to use it ?

In order to make the program work, you must do the following :
 - Open Keil MDK-ARM toolchain
 - Rebuild all files
 - Load images into target memory
 - Run the demonstration

 * <h3><center>&copy; COPYRIGHT KULIKOV V.G. </center></h3>
 
