/**
  ******************************************************************************
  * File Name          : Display_menu.c
  * Description        : This file provides code for the configuration
  *                      of display menu on the Indicator 20x4.
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
#include "Display_menu.h"
#include "main.h"
#include "Indicator_20_4.h"
#include "Events.h"

extern struct Set_param* const param_array[];
extern const uint8_t size_param_array;
extern struct Event events_array[];
extern const uint8_t size_events_array;

uint8_t num_param;		// 0...9
uint8_t num_stroki; 	// 0...3
uint8_t fl_scroll;		// ON...OFF

uint8_t num_event;		// 0...9
uint8_t num_stroki_ev; 	// 0...3
uint8_t fl_scroll_ev;		// ON...OFF

extern uint8_t fl_but_Up;
extern uint8_t fl_but_Down;
extern uint8_t fl_but_Ok;
extern uint8_t fl_but_Ok_long;
extern struct Event events_array[];
extern char* EventName[];

uint8_t fl_update_page;
uint8_t num_page;
float current_parametr;

extern unsigned long count;


	// Окно приветствия
void Print_page_1(void){
	if(fl_update_page){
		fl_update_page = OFF;
		char* stroka1 = "   ДЕМО программа   ";
		char* stroka2 = "  реализации меню   ";
		char* stroka3 = "  на дисплее 20x4   ";
		char* stroka4 = "   Winstar WH2004   ";
		
		WH2004_set_cursor(0);
		WH2004_write_str(stroka1);
		WH2004_set_cursor(20);
		WH2004_write_str(stroka2);
		WH2004_set_cursor(40);
		WH2004_write_str(stroka3);
		WH2004_set_cursor(60);
		WH2004_write_str(stroka4);
	}
	
	if(fl_but_Ok){
		num_page = 2;
		fl_update_page = ON;
		fl_but_Ok = OFF;
	}
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
	}
}



	// Окно параметров
void Print_page_2(void){
	
	if(fl_update_page){
		WH2004_cmd_clear_display();
		fl_update_page = OFF;
		WH2004_set_cursor(num_stroki*WH2004_WIDTH);
		WH2004_write_str(">");
		for(uint8_t i = 0; i < WH2004_HIGH; i++)
		{
			uint8_t uc = num_param - num_stroki + i;
			WH2004_set_cursor(i*WH2004_WIDTH+1);
			WH2004_write_str((char *)param_array[uc]->name);
			if(param_array[uc]->print_funk_name == &WH2004_print_fl_2_1){
				WH2004_set_cursor(i*WH2004_WIDTH+15);
				WH2004_write_str(" ");
				param_array[uc]->print_funk_name(i*WH2004_WIDTH+16, param_array[uc]->value);
			}else{
				param_array[uc]->print_funk_name(i*WH2004_WIDTH+15, param_array[uc]->value);
			}
		}
	}
	if(fl_but_Ok){
		num_page = 3;
		fl_update_page = ON;
		fl_but_Ok = OFF;
	}
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
		num_page = 5;
		fl_update_page = ON;
	}
	
	//--------------- Down button------------------
	if(fl_but_Down){
		fl_but_Down = OFF;
		num_param++;
		num_stroki++;
		if(num_stroki > (WH2004_HIGH-1)){
			num_stroki = WH2004_HIGH-1;
			fl_scroll = ON;
		}
		if(num_param >= size_param_array){
			num_param = 0;
			num_stroki = 0;
			fl_scroll = OFF;
			WH2004_set_cursor((WH2004_HIGH-1)*WH2004_WIDTH);
			WH2004_write_str(" ");
		}
		if(fl_scroll){
			WH2004_set_cursor(num_stroki*WH2004_WIDTH);
			WH2004_write_str(">");
			fl_scroll = OFF;
			
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_param-(WH2004_HIGH-1) + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str((char *)param_array[uc]->name);
				if(param_array[uc]->print_funk_name == &WH2004_print_fl_2_1){
					WH2004_set_cursor(i*WH2004_WIDTH+15);
					WH2004_write_str(" ");
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+16, param_array[uc]->value);
				}else{
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+15, param_array[uc]->value);
				}
			}
		}else{
			WH2004_set_cursor(num_stroki*WH2004_WIDTH);
			WH2004_write_str(">");
			if(num_stroki > 0){
				WH2004_set_cursor((num_stroki-1)*WH2004_WIDTH);
				WH2004_write_str(" ");
			}
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_param - num_stroki + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str((char *)param_array[uc]->name);
				if(param_array[uc]->print_funk_name == &WH2004_print_fl_2_1){
					WH2004_set_cursor(i*WH2004_WIDTH+15);
					WH2004_write_str(" ");
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+16, param_array[uc]->value);
				}else{
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+15, param_array[uc]->value);
				}
			}
		}
	}
	
	//----------------- Up button------------------
	if(fl_but_Up){
		fl_but_Up = OFF;
		if(num_param == 0){
			num_param = size_param_array -1;
			num_stroki = WH2004_HIGH-1;
			fl_scroll = OFF;
			WH2004_set_cursor(0);
			WH2004_write_str(" ");
		}else{
			if(num_stroki > 0){
				num_stroki--;
			}else{
				num_stroki = 0;
				fl_scroll = ON;
			}
			num_param--;
		}
		if(fl_scroll){
			WH2004_set_cursor(num_stroki*WH2004_WIDTH);
			WH2004_write_str(">");
			fl_scroll = OFF;
			
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_param + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str((char *)param_array[uc]->name);
				if(param_array[uc]->print_funk_name == &WH2004_print_fl_2_1){
					WH2004_set_cursor(i*WH2004_WIDTH+15);
					WH2004_write_str(" ");
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+16, param_array[uc]->value);
				}else{
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+15, param_array[uc]->value);
				}
			}
		}else{
			WH2004_set_cursor(num_stroki*WH2004_WIDTH);
			WH2004_write_str(">");
			if(num_stroki < (WH2004_HIGH-1)){
				WH2004_set_cursor((num_stroki+1)*WH2004_WIDTH);
				WH2004_write_str(" ");
			}
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_param - num_stroki + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str((char *)param_array[uc]->name);
				if(param_array[uc]->print_funk_name == &WH2004_print_fl_2_1){
					WH2004_set_cursor(i*WH2004_WIDTH+15);
					WH2004_write_str(" ");
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+16, param_array[uc]->value);
				}else{
					param_array[uc]->print_funk_name(i*WH2004_WIDTH+15, param_array[uc]->value);
				}
			}
		}
	}
}


	// Окно измерений
void Print_page_3(void){
	float U, I, P, T;
	
	if(fl_update_page){
		WH2004_cmd_clear_display();
		fl_update_page = OFF;
		
		WH2004_set_cursor(0);
		WH2004_write_str("Напряжение        В ");
		WH2004_set_cursor(20);
		WH2004_write_str("Ток АБ            А ");
		WH2004_set_cursor(40);
		WH2004_write_str("Мощность          Вт");
		WH2004_set_cursor(60);
		WH2004_write_str("Температура       ");
		WH2004_write(0xEF);
		WH2004_write_str("C");
	}
	
	U = (float)count/100.0;
	I = (float)count/200.0;
	P = U*I;
	T = (float)count/100.0 - 6;
	
	WH2004_print_fl_2_1(13, U);
	WH2004_print_fl_2_2(32, I);
	WH2004_print_fl_2_1(53, P);
	WH2004_print_fl_3_1(72, T);
	
	if(fl_but_Ok){
		num_page = 4;
		fl_update_page = ON;
		fl_but_Ok = OFF;
	}
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
		num_page = 6;
		fl_update_page = ON;
	}
	
}


	// Окно событий
void Print_page_4(void){
	
	if(fl_update_page){
		fl_update_page = OFF;
		WH2004_cmd_clear_display();

		WH2004_set_cursor(num_stroki_ev*WH2004_WIDTH);
		WH2004_write_str(">");
		for(uint8_t i = 0; i < WH2004_HIGH; i++)
		{
			uint8_t uc = num_event - num_stroki_ev + i;
			WH2004_set_cursor(i*WH2004_WIDTH+1);
			WH2004_write_str(events_array[uc].name);
			WH2004_set_cursor(i*WH2004_WIDTH + 9);
			WH2004_print_sl_2(events_array[uc].eventTime.Hours);
			WH2004_write_str(":");
			WH2004_print_sl_2(events_array[uc].eventTime.Minutes);
			WH2004_set_cursor(i*WH2004_WIDTH + 15);
			WH2004_print_sl_2(events_array[uc].eventDate.Date);
			WH2004_write_str(".");
			WH2004_print_sl_2(events_array[uc].eventDate.Month);
		}
	}
	
	//--------------- Down button------------------
	if(fl_but_Down){
		fl_but_Down = OFF;
		num_event++;
		num_stroki_ev++;
		if(num_stroki_ev > (WH2004_HIGH-1)){
			num_stroki_ev = WH2004_HIGH-1;
			fl_scroll_ev = ON;
		}
		if(num_event >= size_events_array){
			num_event = 0;
			num_stroki_ev = 0;
			fl_scroll_ev = OFF;
			WH2004_set_cursor((WH2004_HIGH-1)*WH2004_WIDTH);
			WH2004_write_str(" ");
		}
		if(fl_scroll_ev){
			WH2004_set_cursor(num_stroki_ev*WH2004_WIDTH);
			WH2004_write_str(">");
			fl_scroll_ev = OFF;
			
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_event-(WH2004_HIGH-1) + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str(events_array[uc].name);
				WH2004_set_cursor(i*WH2004_WIDTH + 9);
				WH2004_print_sl_2(events_array[uc].eventTime.Hours);
				WH2004_write_str(":");
				WH2004_print_sl_2(events_array[uc].eventTime.Minutes);
				WH2004_set_cursor(i*WH2004_WIDTH + 15);
				WH2004_print_sl_2(events_array[uc].eventDate.Date);
				WH2004_write_str(".");
				WH2004_print_sl_2(events_array[uc].eventDate.Month);
			}
		}else{
			WH2004_set_cursor(num_stroki_ev*WH2004_WIDTH);
			WH2004_write_str(">");
			if(num_stroki_ev > 0){
				WH2004_set_cursor((num_stroki_ev-1)*WH2004_WIDTH);
				WH2004_write_str(" ");
			}
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_event - num_stroki_ev + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str(events_array[uc].name);
				WH2004_set_cursor(i*WH2004_WIDTH + 9);
				WH2004_print_sl_2(events_array[uc].eventTime.Hours);
				WH2004_write_str(":");
				WH2004_print_sl_2(events_array[uc].eventTime.Minutes);
				WH2004_set_cursor(i*WH2004_WIDTH + 15);
				WH2004_print_sl_2(events_array[uc].eventDate.Date);
				WH2004_write_str(".");
				WH2004_print_sl_2(events_array[uc].eventDate.Month);
			}
		}
	}
	
	//----------------- Up button------------------
	if(fl_but_Up){
		fl_but_Up = OFF;
		if(num_event == 0){
			num_event = size_events_array -1;
			num_stroki_ev = WH2004_HIGH-1;
			fl_scroll_ev = OFF;
			WH2004_set_cursor(0);
			WH2004_write_str(" ");
		}else{
			if(num_stroki_ev > 0){
				num_stroki_ev--;
			}else{
				num_stroki_ev = 0;
				fl_scroll_ev = ON;
			}
			num_event--;
		}
		if(fl_scroll_ev){
			WH2004_set_cursor(num_stroki_ev*WH2004_WIDTH);
			WH2004_write_str(">");
			fl_scroll_ev = OFF;
			
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_event + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str(events_array[uc].name);
				WH2004_set_cursor(i*WH2004_WIDTH + 9);
				WH2004_print_sl_2(events_array[uc].eventTime.Hours);
				WH2004_write_str(":");
				WH2004_print_sl_2(events_array[uc].eventTime.Minutes);
				WH2004_set_cursor(i*WH2004_WIDTH + 15);
				WH2004_print_sl_2(events_array[uc].eventDate.Date);
				WH2004_write_str(".");
				WH2004_print_sl_2(events_array[uc].eventDate.Month);
			}
		}else{
			WH2004_set_cursor(num_stroki_ev*WH2004_WIDTH);
			WH2004_write_str(">");
			if(num_stroki < (WH2004_HIGH-1)){
				WH2004_set_cursor((num_stroki_ev+1)*WH2004_WIDTH);
				WH2004_write_str(" ");
			}
			for(uint8_t i = 0; i < WH2004_HIGH; i++)
			{
				uint8_t uc = num_event - num_stroki_ev + i;
				WH2004_set_cursor(i*WH2004_WIDTH+1);
				WH2004_write_str(events_array[uc].name);
				WH2004_set_cursor(i*WH2004_WIDTH + 9);
				WH2004_print_sl_2(events_array[uc].eventTime.Hours);
				WH2004_write_str(":");
				WH2004_print_sl_2(events_array[uc].eventTime.Minutes);
				WH2004_set_cursor(i*WH2004_WIDTH + 15);
				WH2004_print_sl_2(events_array[uc].eventDate.Date);
				WH2004_write_str(".");
				WH2004_print_sl_2(events_array[uc].eventDate.Month);
			}
		}
	}
	
	
	if(fl_but_Ok){
		num_page = 1;
		fl_update_page = ON;
		fl_but_Ok = OFF;
	}
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
		num_page = 7;
		fl_update_page = ON;
	}
}


	// Окно смены параметров (num_page = 5)
void Print_page_2_1(uint8_t n_param){
	if(fl_update_page){
		WH2004_cmd_clear_display();
		fl_update_page = OFF;
		
		WH2004_set_cursor(0);
		WH2004_write_str((char *)param_array[n_param]->name);
		WH2004_set_cursor(20);
		WH2004_write_str("Min ");
		param_array[n_param]->print_funk_name(24, param_array[n_param]->min);
		WH2004_set_cursor(30);
		WH2004_write_str("Max ");
		param_array[n_param]->print_funk_name(34, param_array[n_param]->max);
		WH2004_set_cursor(40);
		WH2004_write_str("Текущ.знач-е: ");
		param_array[n_param]->print_funk_name(54, param_array[n_param]->value);
		WH2004_set_cursor(60);
		WH2004_write_str("Изменить +/-  ");
		current_parametr = param_array[n_param]->value;
	}
	
	if(fl_but_Up){
		fl_but_Up = OFF;
		if((current_parametr += param_array[n_param]->step) >= param_array[n_param]->max)
			current_parametr = param_array[n_param]->max;
	}
	
	if(fl_but_Down){
		fl_but_Down = OFF ;
		if((current_parametr -= param_array[n_param]->step) <= param_array[n_param]->min)
			current_parametr = param_array[n_param]->min;
	}
	
	if(fl_but_Ok){
		param_array[n_param]->value = current_parametr;
		param_array[n_param]->print_funk_name(54, param_array[n_param]->value);
	}
	
	param_array[n_param]->print_funk_name(74, current_parametr);
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
		num_page = 2;
		fl_update_page = ON;
	}
}


	// Окно дополнительных измерений (num_page = 6)
void Print_page_3_1(void){
	float U, I, R, F;
	
	if(fl_update_page){
		WH2004_cmd_clear_display();
		fl_update_page = OFF;
		
		WH2004_set_cursor(0);
		WH2004_write_str("Ia      A Ua       B");
		WH2004_set_cursor(20);
		WH2004_write_str("Ib      A Ub       B");
		WH2004_set_cursor(40);
		WH2004_write_str("Ic      A Uc       B");
		WH2004_set_cursor(60);
		WH2004_write_str("R       Ом F      Hz");
	}
	
	U = (float)count/100.0;
	I = (float)count/200.0;
	R = U/I;
	if(count%3)F = 50.0;
	else F = 50.1;
	
	WH2004_print_fl_2_1(3, I);
	WH2004_print_fl_2_1(23, I-0.1);
	WH2004_print_fl_2_1(43, I+0.1);
	
	WH2004_print_fl_2_2(13, U+0.1);
	WH2004_print_fl_2_2(33, U-0.1);
	WH2004_print_fl_2_2(53, U);
	
	WH2004_print_fl_2_1(63, R);
	WH2004_print_fl_2_1(73, F);
	
	if(fl_but_Ok){
		num_page = 3;
		fl_update_page = ON;
		fl_but_Ok = OFF;
	}
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
		num_page = 3;
		fl_update_page = ON;
	}
}


	// Окно детелизации событий (num_page = 7)
void Print_page_4_1(uint8_t n_event){
	if(fl_update_page){
		WH2004_cmd_clear_display();
		fl_update_page = OFF;
		
		WH2004_set_cursor(0);
		WH2004_write_str("Событие:");
		WH2004_set_cursor(20);
		WH2004_write_str(events_array[n_event].full_name);
		WH2004_set_cursor(40);
		WH2004_write_str("Время:");
		WH2004_set_cursor(60);
		WH2004_print_sl_2(events_array[n_event].eventDate.Date);
		WH2004_set_cursor(62);
		WH2004_write_str("-");
		WH2004_print_sl_2(events_array[n_event].eventDate.Month);
		WH2004_write_str("-");
		WH2004_print_sl_2(events_array[n_event].eventDate.Year);
		WH2004_write_str(" ");
		WH2004_print_sl_2(events_array[n_event].eventTime.Hours);
		WH2004_write_str(":");
		WH2004_print_sl_2(events_array[n_event].eventTime.Minutes);
		WH2004_write_str(":");
		WH2004_print_sl_2(events_array[n_event].eventTime.Seconds);
	}
	
	if(fl_but_Ok){
		num_page = 4;
		fl_update_page = ON;
		fl_but_Ok = OFF;
	}
	
	if(fl_but_Ok_long){
		fl_but_Ok_long = OFF;
		num_page = 4;
		fl_update_page = ON;
	}
}




/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
