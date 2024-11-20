/**
  ******************************************************************************
  * File Name          : Parametrs.c
  * Description        : This file provides code for the configuration
  *                      parametrs.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Indicator_20_4.h"


								// Формат вывода на дисплей 20 символов х 4 строки:
								// 1  2 3 4 5 6 7 8 9 10 11 12 13 14 15  16 17 18 19 20   <- номер символа в строке
// Строка 1			// >  Н а з в а н и е  п а  р  -  р  а   З  н  а  ч  .    <- указатель(1 символ), название (14 сим.), значение (5 сим.)
// Строка 2			//    Н а з в а н и е  п а  р  -  р  а   З  н  а  ч  .    <- указатель(1 символ), название (14 сим.), значение (5 сим.)
// Строка 3			//    Н а з в а н и е  п а  р  -  р  а   З  н  а  ч  .    <- указатель(1 символ), название (14 сим.), значение (5 сим.)
// Строка 4			//    Н а з в а н и е  п а  р  -  р  а   З  н  а  ч  .    <- указатель(1 символ), название (14 сим.), значение (5 сим.)

struct Set_param 		param1 	= {2.7,			"Параметр 1    ",	"A  ",	0.0,		10.0,		0.1, 	0,		&WH2004_print_fl_2_1,	1};
struct Set_param 		param2 	= {33.57,		"Параметр 2    ",	"B  ",	1.0,		100.00,	0.01, 0,		&WH2004_print_fl_2_2,	2};
struct Set_param 		param3 	= {957.5,		"Параметр 3    ",	"c  ",	0.0,		1000.0,	0.1, 	0,		&WH2004_print_fl_3_1,	3};
struct Set_param 		param4 	= {-35,			"Параметр 4    ",	"Ом  ",	-100,		100,			1, 	0,		&WH2004_print_sl_5,		4};
struct Set_param 		param5 	= {21.51,		"Параметр 5    ",	"с  ",	-10.0,	100.0,	0.01, 0,		&WH2004_print_fl_2_2,	5};
struct Set_param 		param6 	= {54540,		"Параметр 6    ",	"В  ",	1100,		60000,		1, 	0,		&WH2004_print_sl_5,		6};
struct Set_param 		param7 	= {2.56,		"Параметр 7    ",	"   ",	1.00,		5.00,		0.01, 0,		&WH2004_print_fl_2_2,	7};
struct Set_param 		param8 	= {35.5,		"Параметр 8    ",	"гр ",	1.0,		50.0,		0.1, 	0,		&WH2004_print_fl_2_1,	8};
struct Set_param 		param9 	= {4,				"Параметр 9    ",	"В  ",	0,			10,				1, 	0,		&WH2004_print_sl_5,		9};
struct Set_param 		param10 = {5,				"Параметр 10   ",	"A  ",	0,			10,				1, 	0,		&WH2004_print_sl_5,		10};


struct Set_param* const param_array[] = {	&param1,
																					&param2,
																					&param3,
																					&param4,
																					&param5,
																					&param6,
																					&param7,
																					&param8,
																					&param9,
																					&param10};

const uint8_t size_param_array = (sizeof(param_array) / sizeof(param_array[0]));
//------------------------------------------------------------------------------



/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
