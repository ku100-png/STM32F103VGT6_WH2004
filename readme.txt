/**
  @page Demonstrations project on STM32F103VGT6 Cortex-M3

  @verbatim
  ******************************************************************************
  * @file    readme.txt
  * @author  KULIKOV V.G.
  * @brief   Description of STM32F103VGT6 UUN_VTC Demo
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

�� ���������������� ����� ������������ ��������� ���������� �����:
  - ���������� ��������� WH2004 �.Winstar �� KS0066 ����������� �� ���������� 
	������� ����������������.
  - ������ "OK", "UP", "DOWN", ������������ �������������� � PA12, PA8, PA9.
  - ���������� LED1, LED2, ������������ �������������� � PE3, PE2.
  
 � ���������������� ������������� ��������� ������������ ������:
  - �����-������ ������ ���������� ��� ��������� ����������� �������.
  - ������ TIM4 ��� ����������� ������������� ��������.
  - ���� ��������� ������� ����������� �� LSI RC 40kHz.
 
 ���� ������� �������� ������ ���������������� ���������:
  - � ���������������� ��������� ������� ������� ������� ��� ������ � 
	���������� �������� 20�4, �� ������� ����� �������� �������/����������
	������� � ����� � ������ �������.
  - ������������ ����������� ���� �� ���������� ����. ��� ������������ �����
	������ ������������ ������ "OK". �������� � ���������� ������� ������ 
	����������� � ������ ����.
	
		 ------------------
	|-->| ���� ����������� |
	|	|__________________|
	|			|
	|			|OK
	|			\/
	|	 ------------------                  ---------------------------
	|	| ���� ����������  |<----Long_OK--->| ���� ��������� ���������� |
	|	|__________________|                |___________________________|
	|			|
	|			|OK
	|			\/
	|	 ------------------                  -------------------------------
	|	| ���� ���������   |<----Long_OK--->| ���� �������������� ��������� |
	|	|__________________|                |_______________________________| 
	|			|
	|			|OK
	|			\/
	|	 ------------------                  ----------------------
	|	| ���� �������     |<----Long_OK--->| ���� ������� ������� |
	|	|__________________|                |______________________| 
	|___________|
	
  - ����������� ������ ������ �� ������� ���� � ����������� � ����������, 
	��������� �� ������� �������� � ������� ������ "UP" � "DOWN". ����� � 
	��������� ��������� �������� ��� ���������� ������� ������ "OK".
  - ������������ ������� ������ ���������� ���������� � ������� ������� � 
	����������� ������� ��� ������� ������ "OK", "UP", "DOWN". � ������� 
	������� ����������� ����� ������� �������. ������ ������� ������� ����� 
	���������� � ��������� ����, ������ ������� � ��������� ����� ������ "OK".
  - ��������� LED1 ������������� ������ 100 ��. ��������� LED2 ������������� 
	��� ����� ���� ���� ���������� WH200.
 

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR.
      This implies that if HAL_Delay() is called from a peripheral ISR process,
      then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to
      1 millisecond to have correct HAL operation.


@par Keywords

Demonstrations, Buttons, LEDs, Symbol display,


@par Hardware and Software environment

  - This demonstration runs on STM32F103VGT6 Cortex-M3 device.
  

@par How to use it ?

In order to make the program work, you must do the following :
 - Open Keil MDK-ARM toolchain
 - Rebuild all files
 - Load images into target memory
 - Run the demonstration

 * <h3><center>&copy; COPYRIGHT KULIKOV V.G. </center></h3>
 */

