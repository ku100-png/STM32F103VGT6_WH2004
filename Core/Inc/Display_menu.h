/**
  ******************************************************************************
  * File Name          : Display_menu.h
  * Description        : This file contains all the functions prototypes for 
  *                      the display menu on the Indicator 20x4.
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
#ifndef __display_menu_H
#define __display_menu_H


/* Includes ------------------------------------------------------------------*/
#include "main.h"



void Print_page_1(void);	// Окно приветствия
void Print_page_2(void);	// Окно параметров
void Print_page_3(void);	// Окно измерений
void Print_page_4(void);	// Окно событий
void Print_page_2_1(uint8_t);	// Окно смены параметров
void Print_page_3_1(void);		// Окно дополнительных измерений
void Print_page_4_1(uint8_t);	// Окно детелизации событий




#endif /*__display_menu_H */ 

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
