/**
  ******************************************************************************
  * File Name          : Buttons.c
  * Description        : This file provides code for the configuration
  *                      buttons.
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
#include "Events.h"


uint8_t fl_but_Up;
uint8_t fl_but_Down;
uint8_t fl_but_Ok;
uint8_t fl_but_Ok_temp;
uint8_t fl_but_Ok_long;


void Buttons_control(void)
{
	static unsigned char wait_up_but = 0;
	static unsigned char wait_down_but = 0;
	static unsigned char wait_ok_but = 0;
	
	if(Button_UP){
		wait_up_but = 0;
		fl_but_Up = OFF;
	}else{
		if(++wait_up_but == 1){
		fl_but_Up = ON;
		Add_event(but_Up);
		}
		if(wait_up_but > 2) wait_up_but = 2;
	}

	if(Button_DOWN){
		wait_down_but = 0;
		fl_but_Down = OFF;
	}else{
		if(++wait_down_but == 1){
		fl_but_Down = ON;
			Add_event(but_Down);
		}
		if(wait_down_but > 2) wait_down_but = 2;
	}
		
	if(Button_OK){
		wait_ok_but = 0;
		if(fl_but_Ok_temp){	// Кнопка была нажата
			fl_but_Ok = ON;		// Срабатывает при отпускании кнопки
			Add_event(but_Ok);
		}else{
			fl_but_Ok = OFF;
		}
		fl_but_Ok_temp =OFF;
	}else{
		if(++wait_ok_but == 1){
		fl_but_Ok_temp = ON;
		}
		if(wait_ok_but > 15){	// Фиксируем длительное нажание кнопки Ok
			wait_ok_but = 1;
			fl_but_Ok_temp = OFF;
			fl_but_Ok_long = ON;
		}
	}
}



/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
