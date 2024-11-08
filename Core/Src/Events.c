/**
  ******************************************************************************
  * File Name          : Events.c
  * Description        : This file provides code for the configuration
  *                      events.
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

extern RTC_HandleTypeDef hrtc;



// Названия событий
char* EventName[] = {
	"-------",
	"But.Ok ",
	"But.Up ",
	"But.Dwn"
};

// Названия событий
char* EventFullName[] = {
	"-----------------",
	"Press button OK  ",
	"Press button UP  ",
	"Press button DOWN"
};

// Массив событий для отображения на дисплее
struct Event events_array[10];

const uint8_t size_events_array = (sizeof(events_array) / sizeof(events_array[0]));

uint8_t num_ev;


// Инициализация массива событий начальными значениями
void Events_init(void){
	RTC_DateTypeDef date_init;
	RTC_TimeTypeDef time_init;
	
	date_init.Date = 0;
	date_init.Month = 0;
	date_init.WeekDay = 0;
	date_init.Year = 0;
	
	time_init.Hours = 0;
	time_init.Minutes = 0;
	time_init.Seconds = 0;
	
	for(uint8_t i=0; i<10; i++)
  {
		events_array[i].id = 0;
		events_array[i].name = EventName[0];
		events_array[i].full_name = EventFullName[0];
		events_array[i].eventDate = date_init;
		events_array[i].eventTime = time_init;
  }
	num_ev = 0;
}


// Функция добавления события в массив событий
void Add_event(uint8_t type_ev){
	RTC_DateTypeDef date_ev;
	RTC_TimeTypeDef time_ev;
	HAL_RTC_GetTime(&hrtc, &time_ev, RTC_FORMAT_BIN); // RTC_FORMAT_BIN , RTC_FORMAT_BCD
	HAL_RTC_GetDate(&hrtc, &date_ev, RTC_FORMAT_BIN);	// RTC_FORMAT_BIN , RTC_FORMAT_BCD
	
	events_array[num_ev].name = EventName[type_ev];
	events_array[num_ev].full_name = EventFullName[type_ev];
	events_array[num_ev].eventDate = date_ev;
	events_array[num_ev].eventTime = time_ev;
	
	num_ev ++;
	if(num_ev > 9) num_ev = 0;
}


/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
