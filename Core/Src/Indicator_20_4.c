/**
  ******************************************************************************
  * File Name          : Indicator_20_4.c
  * Description        : This file provides code for the configuration
  *                      of the Indicator 20x4.
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
#include "Indicator_20_4.h"
#include "main.h"
#include "Events.h"

//------------------------------------------------------------------------------



unsigned char  n_tek_kursor;
unsigned char  m_ind_znak[11];


unsigned char kiril_char[] =
{
  0x0  ,   /* 0    */
  0x1  ,   /* 1    */
  0x2  ,   /* 2    */
  0x3  ,   /* 3    */
  0x4  ,   /* 4    */
  0x5  ,   /* 5    */
  0x6  ,   /* 6    */
  0x7  ,   /* 7    */
  0x8  ,   /* 8    */
  0x9  ,   /* 9    */
  0xa  ,   /* a    */
  0xb  ,   /* b    */
  0xc  ,   /* c    */
  0xd  ,   /* d    */
  0xe  ,   /* e    */
  0xf  ,   /* f    */


  0x10  ,   /* 10  */
  0x11  ,   /* 11  */
  0x12  ,   /* 12  */
  0x13  ,   /* 13  */
  0x14  ,   /* 14  */
  0x15  ,   /* 15  */
  0x16  ,   /* 16  */
  0x17  ,   /* 17  */
  0x18  ,   /* 18  */
  0x19  ,   /* 19  */
  0x1a  ,   /* 1a  */
  0x1b  ,   /* 1b  */
  0x1c  ,   /* 1c  */
  0x1d  ,   /* 1d  */
  0x1e  ,   /* 1e  */
  0x1f  ,   /* 1f  */
	
  0x20  ,   /* 20  */
  0x21  ,   /* 21 ! */
  0x22  ,   /* 22 " */
  0x01  ,   /* 23 # */
  0x00  ,   /* 24 $ */
  0x25  ,   /* 25 % */
  0x04  ,   /* 26 & */
  0x27  ,   /* 27 ' */
  0x28  ,   /* 28 ( */
  0x29  ,   /* 29 ) */
  0x2a  ,   /* 2a * */
  0x2b  ,   /* 2b + */
  0x2c  ,   /* 2c , */
  0x2d  ,   /* 2d - */
  0x2e  ,   /* 2d . */
  0x2f  ,   /* 2f / */
	
  0x30  ,   /* 30  */
  0x31  ,   /* 31  */
  0x32  ,   /* 32  */
  0x33  ,   /* 33  */
  0x34  ,   /* 34  */
  0x35  ,   /* 35  */
  0x36  ,   /* 36  */
  0x37  ,   /* 37  */
  0x38  ,   /* 38  */
  0x39  ,   /* 39  */
  0x3a  ,   /* 3a  */
  0x3b  ,   /* 3b  */
  0x3c  ,   /* 3c  */
  0x3d  ,   /* 3d  */
  0x3e  ,   /* 3e  */
  0x3f  ,   /* 3f  */
	
  0x40  ,   /* 40  */
  0x41  ,   /* 41  */
  0x42  ,   /* 42  */
  0x43  ,   /* 43  */
  0x44  ,   /* 44  */
  0x45  ,   /* 45  */
  0x46  ,   /* 46  */
  0x47  ,   /* 47  */
  0x48  ,   /* 48  */
  0x49  ,   /* 49  */
  0x4a  ,   /* 4a  */
  0x4b  ,   /* 4b  */
  0x4c  ,   /* 4c  */
  0x4d  ,   /* 4d  */
  0x4e  ,   /* 4e  */
  0x4f  ,   /* 4f  */
	
  0x50  ,   /* 50  */
  0x51  ,   /* 51  */
  0x52  ,   /* 52  */
  0x53  ,   /* 53  */
  0x54  ,   /* 54  */
  0x55  ,   /* 55  */
  0x56  ,   /* 56  */
  0x57  ,   /* 57  */
  0x58  ,   /* 58  */
  0x59  ,   /* 59  */
  0x5a  ,   /* 5a  */
  0x5b  ,   /* 5b  */
  0x5c  ,   /* 5c  */
  0x5d  ,   /* 5d  */
  0xc7  ,   /* 5e  */  // ÿ
  0x5f  ,   /* 5f  */
	
  0x60  ,   /* 60  */
  0x61  ,   /* 61  */
  0x62  ,   /* 62  */
  0x63  ,   /* 63  */
  0x64  ,   /* 64  */
  0x65  ,   /* 65  */
  0x66  ,   /* 66  */
  0x67  ,   /* 67  */
  0x68  ,   /* 68  */
  0x69  ,   /* 69  */
  0x6a  ,   /* 6a  */
  0x6b  ,   /* 6b  */
  0x6c  ,   /* 6c  */
  0x6d  ,   /* 6d  */
  0x6e  ,   /* 6e  */
  0x6f  ,   /* 6f  */
	
  0x70  ,   /* 70  */
  0x71  ,   /* 71  */
  0x72  ,   /* 72  */
  0x73  ,   /* 73  */
  0x74  ,   /* 74  */
  0x75  ,   /* 75  */
  0x76  ,   /* 76  */
  0x77  ,   /* 77  */
  0x78  ,   /* 78  */
  0x79  ,   /* 79  */
  0x7a  ,   /* 7a  */
  0x7b  ,   /* 7b  */
  0x7c  ,   /* 7c  */
  0x7d  ,   /* 7d  */
  0x7e  ,   /* 7e  */
  0x7f  ,   /* 7f  */

  0x80  ,   /* 80   */
  0x81  ,   /* 81   */
  0x82  ,   /* 82   */
  0x83  ,   /* 83   */
  0x84  ,   /* 84   */
  0x85  ,   /* 85   */
  0x86  ,   /* 86   */
  0x87  ,   /* 87   */
  0x88  ,   /* 88   */
  0x89  ,   /* 89   */
  0x8a  ,   /* 8a   */
  0x8b  ,   /* 8b   */
  0x8c  ,   /* 8c   */
  0x8d  ,   /* 8d   */
  0x8e  ,   /* 8e   */
  0x8f  ,   /* 8f   */

  0x90  ,   /* 90   */
  0x91  ,   /* 91   */
  0x92  ,   /* 92   */
  0x93  ,   /* 93   */
  0x94  ,   /* 94   */
  0x95  ,   /* 95   */
  0x96  ,   /* 96   */
  0x97  ,   /* 97   */
  0x98  ,   /* 98   */
  0x99  ,   /* 99   */
  0x9a  ,   /* 9a   */
  0x9b  ,   /* 9b   */
  0x9c  ,   /* 9c   */
  0x9d  ,   /* 9d   */
  0x9e  ,   /* 9e   */
  0x9f  ,   /* 9f   */

  0xa0  ,   /* a0   */
  0xa1  ,   /* a1   */
  0xa2  ,   /* a2   */
  0xa3  ,   /* a3   */
  0xa4  ,   /* a4   */
  0xa5  ,   /* a5   */
  0xa6  ,   /* a6   */
  0xa7  ,   /* a7   */
  0xa8  ,   /* a8   */
  0xa9  ,   /* a9   */
  0xaa  ,   /* aa   */
  0xab  ,   /* ab   */
  0xac  ,   /* ac   */
  0xad  ,   /* ad   */
  0xae  ,   /* ae   */
  0xaf  ,   /* af   */

  0xb0  ,   /* b0   */
  0xb1  ,   /* b1   */
  0xb2  ,   /* b2   */
  0xb3  ,   /* b3   */
  0xb4  ,   /* b4   */
  0xb5  ,   /* b5   */
  0xb6  ,   /* b6   */
  0xb7  ,   /* b7   */
  0xb5  ,   /* b8 ¸ */
  0xb9  ,   /* b9   */
  0xba  ,   /* ba   */
  0xbb  ,   /* bb   */
  0xbc  ,   /* bc   */
  0xbd  ,   /* bd   */
  0xbe  ,   /* be   */
  0xbf  ,   /* bf   */

  'A'   ,   /* c0  A */
  0xa0  ,   /* c1  Á */
  'B'   ,   /* c2  Â */
  0xa1  ,   /* c3  Ã */
  0xe0  ,   /* c4  Ä */
  'E'   ,   /* c5  Å */
  0xa3  ,   /* c6  Æ */
  0xa4  ,   /* c7  Ç */
  0xa5  ,   /* c8  È */
  0xa6  ,   /* c9  É */
  'K'   ,   /* ca  Ê */
  0xa7  ,   /* cb  Ë */
  'M'   ,   /* cc  Ì */
  'H'   ,   /* cd  Í */
  'O'   ,   /* ce  Î */
  0xa8  ,   /* cf  Ï */
	
  'P'   ,   /* d0  Ð */
  'C'   ,   /* d1  Ñ */
  'T'   ,   /* d2  Ò */
  0xa9  ,   /* d3  Ó */
  0xaa  ,   /* d4  Ô */
  'X'   ,   /* d5  Õ */
  0xb3  ,   /* d6  Ö */
  0xab  ,   /* d7  × */
  0xac  ,   /* d8  Ø */
  0xb4  ,   /* d9  Ù */  
  0xad  ,   /* da  Ú */
  0xae  ,   /* db  Û */
  'b'   ,   /* dc  Ü */
  0xaf  ,   /* dd  Ý */
  0xb0  ,   /* de  Þ */
  0xb1  ,   /* df  ß */

	'a'   ,   /* e0  à */
	0xb2  ,   /* e1  á */
	0xb3  ,   /* e2  â */
	0xb4  ,   /* e3  ã */
	0xe3  ,   /* e4  ä */
	'e'   ,   /* e5  å */
	0xb6  ,   /* e6  æ */
	0xb7  ,   /* e7  ç */
	0xb8  ,   /* e8  è */
	0xb9  ,   /* e9  é */
	0xba  ,   /* ea  ê */
	0xbb  ,   /* eb  ë */
  0xbc  ,   /* ec  ì */
  0xbd  ,   /* ed  í */
  'o'   ,   /* ee  î */
  0xbe  ,   /* ef  ï */
	
  'p'   ,   /* f0  ð */
  'c'   ,   /* f1  ñ */
  0xbf  ,   /* f2  ò */
  'y'   ,   /* f3  ó */
  0xe4  ,   /* f4  ô */
  'x'   ,   /* f5  õ */
  0xe5  ,   /* f6  ö */
  0xc0  ,   /* f7  ÷ */
  0xc1  ,   /* f8  ø */
  0xe6  ,   /* f9  ù */
  0xc2  ,   /* fa  ú */
  0xc3  ,   /* fb  û */
  0xc4  ,   /* fc  ü */
  0xc5  ,   /* fd  ý */
  0xc6  ,   /* fe  þ */
  0xc7      /* ff  ÿ */
} ;


//------------------------------------------------------------------------------
static void send_command(uint8_t command)
{
	IND_CLR_RS;
	usDelay(49);	// 50 mks
	port_ind = command;
	IND_SET_E;
	usDelay(0);	// 1 mks
	IND_CLR_E;
}
//------------------------------------------------------------------------------
static void send_data(uint8_t data)
{
	IND_SET_RS;
	usDelay(49);	// 50 mks
	port_ind = data;
	IND_SET_E;
	usDelay(0);	// 1 mks
	IND_CLR_E;
}
//------------------------------------------------------------------------------
void WH2004_write(uint8_t data)
{
	send_data(data);
	usDelay(37);
}
//------------------------------------------------------------------------------
void WH2004_write_str(char *str)
{
	unsigned char sym;
	for(unsigned char i = 0; (i <= 79)&&(str[i] != 0x00) ; i++)
  {
		if(n_tek_kursor == 20 )   WH2004_cmd_set_ddram(KURSOR_STROKA_1 );
		if(n_tek_kursor == 40 )   WH2004_cmd_set_ddram(KURSOR_STROKA_2 );
		if(n_tek_kursor == 60 )   WH2004_cmd_set_ddram(KURSOR_STROKA_3 );
		
		sym = str[i];
		WH2004_write(kiril_char[sym]);
		n_tek_kursor ++ ;
  }
}
//------------------------------------------------------------------------------
void WH2004_cmd_clear_display()
{
	send_command(WH2004_CMD_CLEAR_DISPLAY);
	usDelay(1520);
}
//------------------------------------------------------------------------------
void WH2004_cmd_return_home()
{
	send_command(WH2004_CMD_RETURN_HOME);
	usDelay(1520);
}
//------------------------------------------------------------------------------
void WH2004_cmd_entry_mode(uint8_t increment, uint8_t shift)
{
	send_command(WH2004_CMD_ENTRY_MODE | increment | shift);
	usDelay(37);
}
//------------------------------------------------------------------------------
void WH2004_cmd_on_off(uint8_t display, uint8_t cursor, uint8_t cursor_position)
{
	send_command(WH2004_CMD_ON_OFF | display | cursor | cursor_position);
	usDelay(37);
}
//------------------------------------------------------------------------------
void WH2004_cmd_shift(uint8_t screen_or_cursor, uint8_t right_or_left)
{
	send_command(WH2004_CMD_SHIFT | screen_or_cursor | right_or_left);
	usDelay(37);
}
//------------------------------------------------------------------------------
void WH2004_cmd_function_set(uint8_t bits, uint8_t lines, uint8_t size)
{
	send_command(WH2004_CMD_FUNCTION_SET | bits | lines | size);
	usDelay(37);
}
//------------------------------------------------------------------------------
void WH2004_cmd_set_cgram(uint8_t address)
{
	send_command(WH2004_CMD_SET_CGRAM | (address & 0x3F));
	usDelay(37);
}
//------------------------------------------------------------------------------
void WH2004_cmd_set_ddram(uint8_t address)
{
	send_command(WH2004_CMD_SET_DDRAM | (address & 0x7F));
	//send_command(address);
	usDelay(37);
}
//------------------------------------------------------------------------------


void WH2004_init(void){
	IND_CLR_E;
	HAL_Delay(15);
	WH2004_cmd_function_set(WH2004_8_BITS_DATA, WH2004_2_LINE_DISPLAY, WH2004_5x8_SIZE);
	HAL_Delay(5);
	WH2004_cmd_clear_display();
	HAL_Delay(5);
	WH2004_cmd_entry_mode(WH2004_INCREMENT_ADDRESS, WH2004_SHIFT_DISABLED);
	HAL_Delay(5);
	WH2004_cmd_on_off(WH2004_DISPLAY_ON, WH2004_CURSOR_OFF, WH2004_CURSOR_POSITION_OFF);
}
//------------------------------------------------------------------------------


void WH2004_set_cursor(uint8_t position)
{
	n_tek_kursor = position;
	uint8_t addr;
	
	if(position < 20){
		addr = (KURSOR_STROKA_0 + position);
	}     
	else if((position >= 20)&&(position < 40)){
		addr = ((KURSOR_STROKA_1 - 20) + position );
	}
	else if((position >= 40)&&(position < 60)){
		addr = ( (KURSOR_STROKA_2 - 40) + position );
	}
	else if((position >= 60)&&(position < 80)){
		addr = ( (KURSOR_STROKA_3 - 60) + position );
	}
	
	WH2004_cmd_set_ddram(addr);
	
}
//------------------------------------------------------------------------------


void WH2004_print_sl_5(uint8_t position, float value)
{
	uint8_t  uc;
	uint8_t  fl_0;
	uint8_t  fl_minus;

	WH2004_set_cursor(position);

	fl_0 = 0;
	fl_minus = 0;

	if(value > 99999)    value = 99999;
	if(value < -9999)    value = -9999;

	if(value < 0){
		value = -value;
		fl_minus = 1;
	}

	m_ind_znak[4] =  (int32_t)value / 10000l;
	m_ind_znak[3] = ((int32_t)value % 10000l)/1000l;
	m_ind_znak[2] = ((int32_t)value % 1000l)/100l;
	m_ind_znak[1] = ((int32_t)value % 100l)/10l;
	m_ind_znak[0] =  (int32_t)value % 10l;

	for (uc=4; uc>=1 ; uc--){
		if((m_ind_znak[uc])||(fl_0)){
			send_data(m_ind_znak[uc] + 0x30);
			fl_0 = 1;
		}
		else{
			if(fl_minus && ((m_ind_znak[uc-1]) || ((uc-1)== 0)) ){
				send_data('-');
			}
			else{
				send_data(KOD_PROBEL);
			}
		}
	}
	send_data (m_ind_znak[0] + 0x30);
}
//------------------------------------------------------------------------------


void WH2004_print_fl_2_2(uint8_t position, float value)
{
	uint8_t  fl_minus = 0;
	signed long sl;
	
	WH2004_set_cursor(position);
	
	if(value > 99.99)    value = 99.99;
	if(value < -9.99)    value = -9.99;

	sl = value * 1000.0;

	if(sl < 0){
		sl = -sl;
		fl_minus = 1;
	}

	if((sl % 10l) > 4 )     sl += 10;
	sl /= 10;

	m_ind_znak[3] =  sl / 1000l;
	m_ind_znak[2] = (sl % 1000l)/100l;
	m_ind_znak[1] = (sl % 100l)/10l;
	m_ind_znak[0] =  sl % 10l;

	if(m_ind_znak[3]){
		send_data(m_ind_znak[3] + 0x30);
	}
	else{
		if(fl_minus){
			send_data('-');
		}
		else{
			send_data(KOD_PROBEL);
		}
	}
	
	send_data(m_ind_znak[2] + 0x30);
	send_data('.');
	send_data(m_ind_znak[1] + 0x30);
	send_data(m_ind_znak[0] + 0x30);
}
//------------------------------------------------------------------------------


void WH2004_print_fl_2_1(uint8_t position, float value)
{
	uint8_t  fl_minus = 0;
	signed long sl;
	
	WH2004_set_cursor(position);
	
	if(value > 99.9)    value = 99.9;
	if(value < -9.9)    value = -9.9;

	sl = value * 100.0;

	if(sl < 0){
		sl = -sl;
		fl_minus = 1;
	}

	if((sl % 10l) > 4 )     sl += 10;
	sl /= 10;

	m_ind_znak[2] =  sl / 100l;
  m_ind_znak[1] = (sl % 100l)/10l;
  m_ind_znak[0] =  sl % 10l;

	if(m_ind_znak[2]){
		send_data(m_ind_znak[2] + 0x30);
	}
	else{
		if(fl_minus){
			send_data('-');
		}
		else{
			send_data(KOD_PROBEL);
		}
	}
	
	send_data(m_ind_znak[1] + 0x30);
	send_data('.');
	send_data(m_ind_znak[0] + 0x30);
}
//------------------------------------------------------------------------------


void WH2004_print_fl_3_1(uint8_t position, float value)
{
	uint8_t  fl_minus = 0;
	signed long sl;
	
	WH2004_set_cursor(position);
	
	if(value > 999.9)    value = 999.9;
	if(value < -99.9)    value = -99.9;

	sl = value * 100.0;

	if(sl < 0){
		sl = -sl;
		fl_minus = 1;
	}

	if((sl % 10l) > 4 )     sl += 10;
	sl /= 10;

	m_ind_znak[3] =  sl / 1000l;
	m_ind_znak[2] = (sl % 1000l)/100l;
	m_ind_znak[1] = (sl % 100l)/10l;
	m_ind_znak[0] =  sl % 10l;

	if(m_ind_znak[3]){
		send_data(m_ind_znak[3] + 0x30);
	}
	else{
		if(fl_minus){
			send_data('-');
		}
		else{
			send_data(KOD_PROBEL);
		}
	}
	
	send_data(m_ind_znak[2] + 0x30);
	send_data(m_ind_znak[1] + 0x30);
	send_data('.');
	send_data(m_ind_znak[0] + 0x30);
}



void WH2004_print_sl_2(uint8_t value){
	if(value > 99)    value = 99;

	m_ind_znak[1] = ((int32_t)value / 10);
	m_ind_znak[0] = ((int32_t)value % 10);
	
	send_data (m_ind_znak[1] + 0x30);
	send_data (m_ind_znak[0] + 0x30);
}

//------------------------------------------------------------------------------




/************************ (C) COPYRIGHT NIPOM *****END OF FILE*****************/
