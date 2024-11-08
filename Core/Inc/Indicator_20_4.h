/**
  ******************************************************************************
  * File Name          : Indicator_20_4.h
  * Description        : This file contains all the functions prototypes for 
  *                      the Indicator 20x4. 
	* Author						 : Kulikov V.G.
  ******************************************************************************
  **
  * COPYRIGHT(c) 2024
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of NIPOM nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __indicator_20_4_HPP
#define __indicator_20_4_HPP


/* Includes ------------------------------------------------------------------*/
#include "main.h"


#define IND_SET_RS				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET)
#define IND_CLR_RS				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET)

#define IND_SET_E					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET)
#define IND_CLR_E					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET)



#define KOD_PROBEL   			' '

#define port_ind        	GPIOD->ODR

/* available commands */
#define WH2004_CMD_CLEAR_DISPLAY                   0x01
#define WH2004_CMD_RETURN_HOME                     0x02
#define WH2004_CMD_ENTRY_MODE                      0x04
#define WH2004_CMD_ON_OFF                          0x08
#define WH2004_CMD_SHIFT                           0x10
#define WH2004_CMD_FUNCTION_SET                    0x20
#define WH2004_CMD_SET_CGRAM                       0x40
#define WH2004_CMD_SET_DDRAM                       0x80

/* command entry mode */
#define WH2004_INCREMENT_ADDRESS                   2	// 0b00000010
#define WH2004_DECREMENT_ADDRESS                   0
#define WH2004_SHIFT_ENABLED                       1	// 0b00000001
#define WH2004_SHIFT_DISABLED                      0

/* display on/of and cursor configuration */
#define WH2004_DISPLAY_ON                          4	// 0b00000100
#define WH2004_DISPLAY_OFF                         0
#define WH2004_CURSOR_ON                           2	// 0b00000010
#define WH2004_CURSOR_OFF                          0
#define WH2004_CURSOR_POSITION_ON                  1	// 0b00000001
#define WH2004_CURSOR_POSITION_OFF                 0

/* screen or cursor shift */
#define WH2004_SHIFT_SCREEN                        8	// 0b00001000
#define WH2004_SHIFT_CURSOR                        0
#define WH2004_SHIFT_RIGHT                         4	// 0b00000100
#define WH2004_SHIFT_LEFT                          0

/* display functional settings */
#define WH2004_8_BITS_DATA                         16	// 0b00010000
#define WH2004_4_BITS_DATA                         0
#define WH2004_2_LINE_DISPLAY                      8	// 0b00001000
#define WH2004_1_LINE_DISPLAY                      0
#define WH2004_5x11_SIZE                           4	// 0b00000100
#define WH2004_5x8_SIZE                            0

#define WH2004_WIDTH															 20
#define WH2004_HIGH														 		 4

// Set DDRAM Address Display
// RS RW DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
// 0  0  1   AC6 AC5 AC4 AC3 AC2 AC1 AC0  Code
// In 2-line display mode (N = 1), DDRAM address in the 1st line is from "00H" to "27H", and
// DDRAM address in the 2nd line is from "40H" to "67H".
#define KURSOR_STROKA_0   128
#define KURSOR_STROKA_1   192
#define KURSOR_STROKA_2   128 + 20
#define KURSOR_STROKA_3   192 + 20


/* basic communication */
void WH2004_init(void);
void WH2004_write(uint8_t data);
void WH2004_write_str(char*);
void WH2004_set_cursor(uint8_t position);
void WH2004_print_sl_5(uint8_t position, float value);
void WH2004_print_fl_2_2(uint8_t position, float value);
void WH2004_print_fl_2_1(uint8_t position, float value);
void WH2004_print_fl_3_1(uint8_t position, float value);
void WH2004_print_sl_2(uint8_t value);

/* simple command that can be processed by the display */
void WH2004_cmd_clear_display(void);
void WH2004_cmd_return_home(void);
void WH2004_cmd_entry_mode(uint8_t increment, uint8_t shift);
void WH2004_cmd_on_off(uint8_t display, uint8_t cursor, uint8_t cursor_position);
void WH2004_cmd_shift(uint8_t screen_or_cursor, uint8_t right_or_left);
void WH2004_cmd_function_set(uint8_t bits, uint8_t lines, uint8_t size);
void WH2004_cmd_set_cgram(uint8_t address);
void WH2004_cmd_set_ddram(uint8_t address);





#endif /*__indicator_20_4_HPP */ 

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
