/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 25.02.2015
Author  : 
Company : 
Comments: 


Chip type               : ATmega328P
Program type            : Application
AVR Core Clock frequency: 16,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega328p.h>
#include <sleep.h>
#include <delay.h>
#include <ssd1306.c>
// Declare your global variables here

#define dob PIND.1
#define ubr PIND.2
#define zvuk PORTB.1


flash unsigned char signal[7][256] = {
{0,3,6,9,13,16,19,22,25,28,31,34,37,41,44,47,50,53,56,59,62,65,68,71,
74,77,80,83,86,89,92,95,98,100,103,106,109,112,115,117,120,123,126,128,131,134,136,139,142,144,147,
149,152,154,157,159,162,164,167,169,171,174,176,178,180,183,185,187,189,191,193,195,197,199,201,203,
205,207,208,210,212,214,215,217,219,220,222,223,225,226,228,229,231,232,233,234,236,237,238,239,240,
241,242,243,244,245,246,247,247,248,249,249,250,251,251,252,252,253,253,253,254,254,254,255,255,255,
255,255,255,255,255,255,255,255,254,254,254,253,253,253,252,252,251,251,250,249,249,248,247,247,246,
245,244,243,242,241,240,239,238,237,236,234,233,232,231,229,228,226,225,223,222,220,219,217,215,214,
212,210,208,207,205,203,201,199,197,195,193,191,189,187,185,183,180,178,176,174,171,169,167,164,162,
159,157,154,152,149,147,144,142,139,136,134,131,128,126,123,120,117,115,112,109,106,103,100,98,95,92,
89,86,83,80,77,74,71,68,65,62,59,56,53,50,47,44,41,37,34,31,28,25,22,19,16,13,9,6,3},
{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,127},
{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85},
{255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,
    226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,
    198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,
    170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,
    142,141,140,139,138,137,136,135,134,133,132,131,130,129,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,
    22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,
    59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,
    96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,127},
{255,254,252,251,250,248,247,246,244,243,242,240,239,238,236,235,234,232,231,230,228,227,226,224,223,222,220,219,218,216,215,214,212,
211,209,208,207,205,204,203,201,200,199,197,196,195,193,192,191,189,188,187,185,184,183,181,180,179,177,176,175,173,172,171,169,168,
167,165,164,163,161,160,159,157,156,155,153,152,151,149,148,147,145,144,143,141,140,139,137,136,135,133,132,131,129,128,126,125,124,
122,121,120,118,117,116,114,113,112,110,109,108,106,105,104,102,101,100,98,97,96,94,93,92,90,89,88,86,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
    85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85},
{255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,
	255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,
	255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,
	255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,255,
	255,85,85,255,255,85,85,255,255,85,85,255,255,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
	85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
	85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
	85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
	85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85},
{255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,
	255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,
	255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,
	255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,255,127,127,255,
	255,127,127,255,255,127,127,255,255,127,127,255,255,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,
	127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,
	0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,
	127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,0,0,127,127,127}
} ;



int i,j,n,m,k,o, dn_reg, up_reg;
char seans0,chel,vrem, bol0, l;
//Указать название болезней
flash char bolezni[45][103] = {
"ИБС:стенокардия.                                                                                      ",
"ИБС:стенокардия с гипертонической болезнью.                                                           ",
"ИБС:острый инфаркт миокарда.                                                                          ",
"ИБС:стенокардия, постинфарктный кардиосклероз.                                                        ",
"ИБС:стенокардия, постинфарктный кардиосклероз с недостаточностью кровообращения.                      ",
"ИБС:стенокардия,постинфарктный кардиосклероз,недостаточное кровообращения с гипертонией.              ",
"Гипертоническая болезнь с дисциркуляторной энцефалопатией.                                            ",
"Гипертоническая болезнь с дисциркуляторной энцефалопатией.                                            ",
"Нарушения ритма без ИБС.                                                                              ",
"Миокардит.                                                                                            ",
"Порок сердца (ревматический, врожденный) с недостаточностью кровообращения.                           ",
"Порок сердца (ревматический, врожденный), недостаточность кровообращения с гипертонией.               ",
"Бронхиальная астма.                                                                                   ",
"Бронхит (острый).                                                                                     ",
"Пневмония (острая, обострение хронической).                                                           ",
"Язвенная болезнь желудка и 12-ти перстной кишки.                                                      ",
"Гастрит.                                                                                              ",
"Холецисто-панкреатит.                                                                                 ",
"Колит.                                                                                                ",
"Дисциркуляторная энцефалопатия (атеросклероз сосудов головного мозга).                                ",
"Вертебрально-базилярная недостаточность.                                                              ",
"Нейро-циркуляторная дистония.                                                                         ",
"Состояние после нарушения мозгового кровообращения.                                                   ",
"Радикулит, невриты.                                                                                   ",
"Остеохондроз позвоночника.                                                                            ",
"Неврозы.                                                                                              ",
"Сахарный диабет.                                                                                      ",
"Простатит.                                                                                            ",
"Аденома простаты.                                                                                     ",
"Пиелонефрит.                                                                                          ",
"Воспалительные заболевания, эндометриоз.                                                              ",
"Нарушения менструального цикла.                                                                       ",
"Нейродермит, экзема.                                                                                  ",
"Псориаз.                                                                                              ",
"Грипп, ОРВИ.                                                                                          ",
"Тонзиллит.                                                                                            ",
"Хирургическая патология.                                                                              ",
"Травма, в том числе множественная и сочетанная.                                                       ",
"Ожоги и отморожения.                                                                                  ",
"Артрит.                                                                                               ",
"Атеросклероз сосудов конечностей.                                                                     ",
"Гайморит, фронтит.                                                                                    ",
"Перидонтит.                                                                                           ",
"Сексуальные расстройства.                                                                             ",
"Нарушения речевого развития.                                                                          "
};

//Указать программы
flash unsigned char rezhimi[45][20] = {
{2,2,2,5,5,6,5,5,4,4,2,2,2,5,5,6,4,4,4,4},
{4,4,2,5,5,3,5,4,4,4,4,4,2,5,5,4,4,4,4,4},
{2,2,2,5,5,5,5,2,2,2,2,2,2,5,5,5,5,2,2,2},
{4,4,2,5,5,6,2,4,4,4,4,4,2,5,5,6,2,4,4,4},
{4,4,4,4,4,4,3,3,3,4,4,4,4,4,4,4,3,3,3,4},
{4,4,4,2,2,2,2,5,5,4,4,4,4,2,2,2,2,5,5,4},
{2,2,2,2,5,5,1,5,4,4,2,2,2,2,5,5,1,5,4,4},
{4,4,4,4,3,3,3,4,4,4,4,4,4,4,3,3,3,4,4,4},
{4,4,4,2,2,1,5,2,4,4,4,4,4,2,2,1,5,2,4,4},
{2,2,2,5,5,6,6,5,2,2,2,2,2,5,5,6,6,5,2,2},
{4,4,4,4,2,5,5,4,4,4,4,4,4,4,2,5,5,4,4,4},
{4,4,4,4,4,2,2,4,4,4,4,4,4,4,4,2,2,4,4,4},
{2,2,5,5,5,2,2,2,4,4,2,2,5,5,5,2,2,2,4,4},
{2,2,2,2,1,1,1,5,6,2,2,2,2,2,1,1,1,5,6,2},
{2,2,1,5,5,3,3,5,5,4,2,2,1,5,5,3,3,3,4,4},
{2,2,2,5,5,5,5,2,2,2,2,2,2,5,5,5,5,2,2,2},
{2,2,2,5,6,1,5,2,4,4,2,2,2,5,6,1,5,2,4,4},
{4,4,2,5,5,5,5,5,4,4,4,4,2,5,5,5,5,5,4,4},
{2,2,2,5,5,4,4,5,2,2,2,2,2,5,5,4,4,5,2,2},
{4,4,4,4,4,3,3,3,5,4,4,4,4,4,4,3,3,4,4,4},
{4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,3,3,4,4,4},
{4,4,3,3,3,5,5,5,5,5,4,4,4,4,4,4,4,4,5,5},
{4,4,3,3,3,3,5,4,4,4,4,4,4,4,4,4,4,4,4,4},
{2,2,2,2,5,5,6,6,5,5,2,2,2,2,5,5,6,6,5,5},
{4,4,2,2,5,5,6,6,2,2,4,4,2,2,5,5,6,6,2,2},
{4,4,4,3,2,2,4,4,4,4,4,4,4,3,2,2,4,4,4,4},
{2,1,5,6,6,5,3,3,4,4,2,1,5,6,6,5,3,3,4,4},
{2,5,5,5,5,5,2,2,2,2,2,5,5,5,5,5,3,3,2,2},
{4,4,4,3,3,1,1,6,5,5,4,4,4,3,3,1,1,6,5,5},
{5,5,5,2,2,3,4,4,5,5,5,5,5,2,2,3,4,4,5,5},
{2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,2,2},
{4,4,4,3,1,6,1,6,5,5,4,4,4,3,1,6,1,6,5,5},
{2,2,5,5,5,5,6,6,4,4,2,2,5,5,5,5,6,6,4,4},
{4,4,4,4,3,3,6,1,5,5,4,4,4,4,3,3,6,1,5,5},
{2,5,1,2,5,5,5,2,2,1,2,5,1,2,5,5,5,2,2,1},
{2,2,2,2,4,3,4,2,5,5,2,2,2,2,4,3,4,2,5,5},
{2,2,5,5,6,6,6,2,4,4,2,2,5,5,6,6,6,2,4,4},
{5,5,6,6,6,2,2,2,2,2,5,5,6,6,6,2,2,2,2,2},
{5,5,6,6,4,4,3,5,2,2,5,5,6,6,4,4,3,5,2,2},
{2,2,5,5,4,4,3,4,5,2,2,2,5,5,4,4,3,4,5,2},
{2,2,2,2,2,5,5,5,5,5,2,2,2,2,2,5,5,5,5,5},
{2,2,2,2,5,5,5,6,5,5,2,2,3,3,4,4,4,6,5,5},
{2,2,2,2,5,1,1,5,5,5,2,2,2,2,5,1,1,5,5,5},
{4,3,6,5,5,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4},
{4,4,3,3,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
};



eeprom char seans[10], bol[10];



unsigned int tok,tok0, period, a, mod, paus, time; 
unsigned char a1,a2,a3, rezh0,tok1;
long timer;
bit fl1, fl2, fl3, fl4, fl5, reg1, reg2, flag0, fubr;

// Voltage Reference: Int., cap. on AREF
#define ADC_VREF_TYPE ((1<<REFS1) | (1<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here
    fubr = 1;
}


// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    if(reg1)
    {        
      if(reg2)
      {
            TCNT1H=period >> 8;
            TCNT1L=period & 0xff;
            if(a1 < 254)
            {        
                 OCR2A = signal[0][a1++];
            }
            else
            {
                a1 = 0;                                                  
                if(timer > 9000000) period = 2048 + (timer - 9000000)/143;  // 15584  64736  
                else
                if (timer > 6000000) period = 58592 - (timer - 6000000)/53;
                else 
                {   
                    if(fl2) period-=4; else period+=4;
                    if (period > 0xED40) fl2 = 1;
                    if (period < 0xE4E0) fl2 = 0;
                }     
                if (tok >= tok0) 
                {     
                    if(fl1) { if(a3<128) a3 += 1;} else a3 = 1; 
                    fl1 = 1; 
                    if (OCR0B == 0)
                    {         
                        if(OCR0A > 64) OCR0A = 64;
                        if((unsigned char)OCR0A > a3) OCR0A = OCR0A - a3; else OCR0A=0x00; 
                    }
                    else
                    {  if((unsigned char)OCR0B > a3) OCR0B = OCR0B - a3; 
                        else
                        { 
                            OCR0B=0x00;
                            a3 = 1;
                        } 
                    }
                }
                else 
                {
                    if(fl1==0)  { if(a3<16) a3 *= 1;} else a3 = 1;                         
                    fl1 = 0;  
                    if (OCR0A == 0xFF)
                    { if((unsigned char)OCR0B < (0x98 - a3)) OCR0B = OCR0B + a3; else OCR0B=0x98; }
                    else
                    {   if(OCR0A < (0xFF - a3) & OCR0A < 64) OCR0A = OCR0A + a3; 
                        else 
                        {   
                            OCR0A=0xFF; 
                            a3 = 1;
                        } 
                    }           
                }                        

                
            } 
            if (a1 == 128) tok = read_adc(0);  
            
      }
      else
      {  
        // Reinitialize Timer1 value
        TCNT1H=0xE0;//80 >> 8;
        TCNT1L=0xC0;//0xFE80 & 0xff;      // 0.5 ms       
        if (a1++ == 0)  
        {
            OCR2A = 0xFF;
        }
        else
        { 
            TCNT1H=0x06;
            TCNT1L=0x00;  
            if(a1 == 2)
            {
                tok = read_adc(0);  
                OCR2A = 0x00;            
                if (tok >= tok0) 
                {     
                    if(fl1) { if(a3<128) a3 += 1;} else a3 = 1; 
                    fl1 = 1; 
                    if (OCR0B == 0)
                    {         
                        if(OCR0A > 64) OCR0A = 64;
                        if((unsigned char)OCR0A > a3) OCR0A = OCR0A - a3; else OCR0A=0x00; 
                    }
                    else
                    {  if((unsigned char)OCR0B > a3) OCR0B = OCR0B - a3; 
                        else
                        { 
                            OCR0B=0x00;
                            a3 = 1;
                        } 
                    }
                }
                else 
                {
                    if(fl1==0)  { if(a3<16) a3 *= 1;} else a3 = 1;                         
                    fl1 = 0;  
                    if (OCR0A == 0xFF)
                    { if((unsigned char)OCR0B < (0x98 - a3)) OCR0B = OCR0B + a3; else OCR0B=0x98; }
                    else
                    {   if(OCR0A < (0xFF - a3) & OCR0A < 64) OCR0A = OCR0A + a3; 
                        else 
                        {   
                            OCR0A=0xFF; 
                            a3 = 1;
                        } 
                    }           
                }                        

                timer = timer - 130; 
            }
            if(a1 > 4)
            {           
            TCNT1H=0xE2;
            TCNT1L=0xC4 ;  
            a1 = 0;       
            }
        }
      }
    }
    else
    {   
        // Reinitialize Timer1 value
        TCNT1H=0xFE;//80 >> 8;
        TCNT1L=0x40;//0xFE80 & 0xff;
            if(a1 < 254)
            {    
                if(a1 == 2)
                {
                    ADMUX = ADC_VREF_TYPE;
                    // Delay needed for the stabilization of the ADC input voltage
                    delay_us(5);
                    // Start the AD conversion
                    ADCSRA|=(1<<ADSC);
                    // Wait for the AD conversion to complete
                    while ((ADCSRA & (1<<ADIF))==0);
                    ADCSRA|=(1<<ADIF);
                    tok = ADCW;
                }      
                OCR2A = signal[rezh0][a1++];       //8 ms
            }
            else 
            {  
                if(a1 == 254)
                {
                    TCNT1H=0x4B;
                    TCNT1L=0x80;  
                    OCR2A = signal[rezh0][254]; 
                    a1++;                 
                } 
                else
                {     
                    
                    if(fl2) period -=  mod; else period +=  mod;
                    if (period > 60000) fl2 = 1;
                    if (period < 5000) fl2 = 0;
                    TCNT1H=period >> 8;
                    TCNT1L=period & 0xff;
                    timer = timer - 111 - (60000-period)/1618;          
                    if (tok >= tok0) 
                    {     
                        if(fl1) { if(a3<128) a3 += 1;} else a3 = 1; 
                        fl1 = 1; 
                        if (OCR0B == 0)
                        {         
                            if(OCR0A > 64) OCR0A = 64;
                            if((unsigned char)OCR0A > a3) OCR0A = OCR0A - a3; else OCR0A=0x00; 
                        }
                        else
                        {  if((unsigned char)OCR0B > a3) OCR0B = OCR0B - a3; 
                            else
                            { 
                                OCR0B=0x00;
                                a3 = 1;
                            } 
                        }
                    }
                    else 
                    {
                        if(fl1==0)  { if(a3<16) a3 *= 1;} else a3 = 1;                         
                        fl1 = 0;  
                        if (OCR0A == 0xFF)
                        { if((unsigned char)OCR0B < (0x98 - a3)) OCR0B = OCR0B + a3; else OCR0B=0x98; }
                        else
                        {   if(OCR0A < (0xFF - a3) & OCR0A < 64) OCR0A = OCR0A + a3; 
                            else 
                            {   
                                OCR0A=0xFF; 
                                a3 = 1;
                            } 
                        }           
                    }                        

                    a2 = 0;   
                    a1 = 0;   

                }    
            }      

    }
}


// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
// Place your code here
if (fl5) OCR2B = ++l; else OCR2B = --l; 
if (l == 0) fl5 = !fl5;         
}


void ZnachZ(int x, int y, int zn, int zoom)
{
  int a,b; 

    if(zn<10) 
    {       
        drawCharZo(x,y,'0',1, zoom);
        drawCharZo(x+12*zoom,y,'0',1, zoom);
        drawCharZo(x+18*zoom,y,0x30+zn,1, zoom);    
    }
    else 
    if(zn<100)
    { 
        a = zn/10;
        zn = zn - a*10;
        drawCharZo(x,y,'0',1, zoom);
        drawCharZo(x+12*zoom,y,0x30+a,1, zoom);
        drawCharZo(x+18*zoom,y,0x30+zn,1, zoom);        
    }  
    else
    {   b = zn/100;  
        a = (zn - b*100)/10;
        zn = zn - b*100 - a*10;
        drawCharZo(x,y,0x30+b,1, zoom);
        drawCharZo(x+12*zoom,y,0x30+a,1, zoom);
        drawCharZo(x+18*zoom,y,0x30+zn,1, zoom);        
        
    }
    drawCharZo(x+6*zoom,y,'.',1, zoom);             
}

void ZnachZo(int x, int y, int zn, int zoom)
{
   int a,b;
    if(zn<10) 
    {       
        drawCharZo(x,y,'0',1, zoom);
        drawCharZo(x+6*zoom,y,'0',1, zoom);
        drawCharZo(x+12*zoom,y,0x30+zn,1, zoom);    
    }
    else 
    if(zn<100)
    { 
        a = zn/10;
        zn = zn - a*10;
        drawCharZo(x,y,'0',1, zoom);
        drawCharZo(x+6*zoom,y,0x30+a,1, zoom);
        drawCharZo(x+12*zoom,y,0x30+zn,1, zoom);        
    }  
    else
    {   b = zn/100;  
        a = (zn - b*100)/10;
        zn = zn - b*100 - a*10;
        drawCharZo(x,y,0x30+b,1, zoom);
        drawCharZo(x+6*zoom,y,0x30+a,1, zoom);
        drawCharZo(x+12*zoom,y,0x30+zn,1, zoom);        
        
    } 
}


void timeZ(int x, int y, int sec, int zoom)
{
int min,a;
    min = sec / 60;
    sec -=  min * 60;
    if(min<10) 
    {       
        drawCharZo(x,y,'0',1, zoom);
        drawCharZo(x+6*zoom,y,0x30+min,1, zoom);    
    }
    else
    {      
        a = min/10;
        min -= a*10;        
        drawCharZo(x,y,0x30+a,1, zoom);
        drawCharZo(x+6*zoom,y,0x30+min,1, zoom);        
    }   
    drawCharZ(x+12*zoom,y,':',1, zoom);      
    if(sec<10) 
    {       
        drawCharZo(x+18*zoom,y,'0',1, zoom);
        drawCharZo(x+24*zoom,y,0x30+sec,1, zoom);    
    }
    else
    {      
        a = sec/10;
        sec -= a*10;        
        drawCharZo(x+18*zoom,y,0x30+a,1, zoom);
        drawCharZo(x+24*zoom,y,0x30+sec,1, zoom);        
    }

}



int vibor(void)
{
flag0 = 1;
j=-2;
  while (flag0)
  { 
    timer=0;
    if(!dob) 
    {
        delay_ms(200);
        while(!dob& timer++<100000);
         for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
        j++;
    }
    if(!ubr) 
    {
        delay_ms(200);
        while(!ubr & timer++<100000) ;  
         for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
        if (timer>=100000) flag0 = 0;
        else j--;
    }                
    if(j > 42) j = -2; 
    if(j<-2) j = 42;
    clearDisplay(); 
    for(i = 0 ; i < 2 ; i++)
    { 
        for (n = 0; n < 21; n++) 
        {
           if((j+i) < 45 & (j+i) >= 0) drawChar(6*n,i,bolezni[j+i+ubr-dob][n]);
        }  
    } 
    if(!dob | !ubr)   for (n = 0; n < 11; n++) if((j+i) < 45 & (j+i) >= 0) drawCharZ(12*n,16,bolezni[j+2+ ubr][n],1,2);
    for(i = 4 ; i < 7 ; i++)
    { 
        for (n = 0; n < 21; n++) 
        {
           if((j+i) < 45) drawChar(6*n,i,bolezni[j+i-1+ubr-dob][n]);
        }  
    } 
    display(0,0,127,7); 
    for (i = 0 ; i < 102 ; i++)
    {
    //    
        for(m = 12; m >= 0; m-=2)
        {    
//      //      delay_ms(10);
            for (n = 0; n < 10; n++) 
            {
        //               clearDisplay(); 
//      
                    if ((n+i)>9)  drawCharZo(m+12*n,16,bolezni[j+2][n+i-10],1,2); 
                    else  for(k = 0; k < 12; k++)
                    {   
                        buffer[256+11-m+12*n+k] = buffer[256+12-m+12*n+k]; 
                        buffer[384+11-m+12*n+k] = buffer[384+12-m+12*n+k]; 
                    }
                    if(bolezni[j+2][i+n-11]=='.') 
                    {
                        i = 0; //else i = 102;// m = 0;
                    } 
                    if (!dob | !ubr) i = 102;
            }
            if (dob & ubr) display(0,2,127,3);  
            
        } 
//     if(i == 0) delay_ms(300);  
//     if(i == 101) delay_ms(500);  
     
      //  drawString(0,0,bol0,41);
    //    display(0,0,63,1);
    }

  }
  return (j+2);
}




void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=Out Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (1<<DDB3) | (0<<DDB2) | (1<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=0 Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (1<<DDC1) | (0<<DDC0);
// State: Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (1<<PORTC0);

// Port D initialization
// State: Bit7=T Bit6=0 Bit5=0 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (1<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (1<<PORTD1) | (1<<PORTD0);
// Function: Bit7=In Bit6=Out Bit5=Out Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (1<<DDD6) | (1<<DDD5) | (0<<DDD4) | (1<<DDD3) | (0<<DDD2) | (0<<DDD1) | (1<<DDD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 16000,000 kHz
// Mode: Fast PWM top=0xFF
// OC0A output: Inverted PWM
// OC0B output: Non-Inverted PWM
// Timer Period: 0,016 ms
// Output Pulse(s):
// OC0A Period: 0,016 ms Width: 0,016 ms
// OC0B Period: 0,016 ms Width: 0 us
TCCR0A=(1<<COM0A1) | (1<<COM0A0) | (1<<COM0B1) | (0<<COM0B0) | (1<<WGM01) | (1<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;


// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 16000,000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 1,9179 ms
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0x88;
TCNT1L=0x22;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 16000,000 kHz
// Mode: Fast PWM top=0xFF
// OC2A output: Inverted PWM
// OC2B output: Non-Inverted PWM
// Timer Period: 0,016 ms
// Output Pulse(s):
// OC2A Period: 0,016 ms Width: 0,016 ms
// OC2B Period: 0,016 ms Width: 0 us
ASSR=(0<<EXCLK) | (0<<AS2);
TCCR2A=(1<<COM2A1) | (1<<COM2A0) | (1<<COM2B1) | (0<<COM2B0) | (1<<WGM21) | (1<<WGM20);
TCCR2B=(0<<WGM22) | (0<<CS22) | (0<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;


// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=(0<<OCIE0B) | (0<<OCIE0A) | (0<<TOIE0);

// Timer/Counter 1 Interrupt(s) initialization
TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (0<<TOIE1);

// Timer/Counter 2 Interrupt(s) initialization
TIMSK2=(0<<OCIE2B) | (0<<OCIE2A) | (0<<TOIE2);


// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-14: Off
// Interrupt on any change on pins PCINT16-23: Off
EICRA=(0<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT1) | (1<<INT0);
EIFR=(0<<INTF1) | (1<<INTF0);
PCICR=(0<<PCIE2) | (0<<PCIE1) | (0<<PCIE0);

// USART initialization
// USART disabled
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (0<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
// Digital input buffer on AIN0: On
// Digital input buffer on AIN1: On
DIDR1=(0<<AIN0D) | (0<<AIN1D);

// ADC initialization
// ADC Clock frequency: 1000,000 kHz
// ADC Voltage Reference: Int., cap. on AREF
// ADC Auto Trigger Source: ADC Stopped
// Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
// ADC4: On, ADC5: On
DIDR0=(0<<ADC5D) | (0<<ADC4D) | (0<<ADC3D) | (0<<ADC2D) | (0<<ADC1D) | (0<<ADC0D);
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);
ADCSRB=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);


// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Global enable interrupts
#asm("sei")
//OCR0B=0xE0;
for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
delay_ms(2);
a3 = 1;
tok0 = 0;
mod = 2;
period = 10000;
//period = 10900;
initDisplay();
zvuk = 1;
clearDisplay();
tok = read_adc(0);
zvuk = 0;
drawStringZ(0, 0, " Батарея:", 9, 1, 2);
ZnachZ(16,24,tok,3) ;
drawStringZ(16+24*3, 24, "v", 1, 1, 3); 
display(0,0,127,7);
delay_ms(2000);
PORTC.0 = 0;
//TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (1<<TOIE1);
clearDisplay();
drawStringZ(0, 0, "Выберите:", 9, 1, 2);
drawStringZ(0, 20, "Трансаир:-", 10, 1, 2);
drawStringZ(0, 40, "Медаптон:+", 10, 1, 2);
display(0,0,127,7);
for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
while(ubr & dob & paus++<1000)
{
    delay_ms(10);
    
}
for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
clearDisplay();
delay_ms(50);
if(fubr) 
{
    drawStringZ(0, 0, "Выбран", 6, 1, 3);
    drawStringZ(0, 30, " Трансаир ", 10, 1, 2);
    reg1 = 1;  
    fubr = 0;
}   
else 
{
    drawStringZ(0, 0, "Выбран", 6, 1, 3);
    drawStringZ(0, 30, " Медаптон ", 10, 1, 2);
}
display(0,0,127,7);
clearDisplay();
delay_ms(1000);
if(!reg1)
{
    
  clearDisplay(); 
  chel = 0;  
  drawStringZ(0, 0, "Выберите", 8, 1, 2);      
  drawStringZ(0, 16, "пациента", 8, 1, 2);      
  drawStringZ(0, 40, "Пациент ", 8, 1, 2);
  drawCharZ(96, 40, 0x30 + chel, 1, 2);
  display(0,0,127,7);  
  for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
 flag0 = 1;
 while (flag0 & timer++<650)
  {     if(!dob) 
    {
        delay_ms(200);
        while(!dob& time++<65000);  
         for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
        chel++ ; 
         timer = 0;
    }
    if(!ubr) 
    {
        delay_ms(200);
        while(!ubr & time++<65000) ;  
        for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
        if (time>=65000) flag0 = 0;
        else if(chel != 0) chel--;
         timer = 0;
    }   
    time = 0;
    if(chel > 9) chel = 9;   
    drawCharZo(96, 40, 0x30 + chel, 1, 2); 
    display(96,5,127,7) ;       
  }   
  clearDisplay();
  drawStringZ(0, 0, "Пациент ", 8, 1, 2);
  drawCharZ(96, 0, 0x30 + chel, 1, 2);
  drawStringZ(0, 16, "Удержи + ", 9, 1, 2);
  drawStringZ(0, 32, "для новой", 9, 1, 2);
  drawStringZ(0, 48, "установки.", 10, 1, 2);
  display(0,0,127,7);      
  for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }     
  while(!ubr);  
  delay_ms(300);
  paus = 0;
    while(ubr & paus++<500)
    {
        delay_ms(10);
        
    }
//=========================================
//Установка для пациента
//=========================================
        if (!dob)
        {
                for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
         paus = 0;
          clearDisplay();
        drawStringZ(0, 16, " Сначала? ", 10, 1, 2);    
        drawStringZ(0, 32, "- Нет,+ Да", 10, 1, 2);    
        display(0,2,127,5);
        delay_ms(400);        
        while(!dob) #asm("wdr");
        while (ubr&&dob&&(paus<100)) {#asm("wdr") delay_ms(100); paus = paus+1;};
            if(!dob)
            {
// Тут напишем выбор болезни и запоминание в бол2
            bol[chel] = vibor();
            for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
            delay_ms(400); 
            seans[chel] = 0;
            };
        
        }; 
clearDisplay();
seans0=seans[chel];
bol0 = bol[chel];   
    if (seans0 == 0)
    {
    n=0;
        drawStringZ(0, 0, " КУРС  ", 7, 1, 3);    
        drawStringZ(0, 32, "СНАЧАЛА", 7, 1, 3);    
        display(0,0,127,7);
        while(n++<20)
        {
            delay_ms(30);                      // просигналить 20 раз
            for(o=0;o<96;o++) { zvuk = 1 ; delay_us(300); zvuk = 0; delay_us(300); }
        }
    n=290;
    }         
clearDisplay();
drawStringZ(0, 0, "Заб. No ", 8, 1, 2);
i = bol0;
    if(i<10) 
    {       
        drawCharZ(104,0,'0',1, 2);
        drawCharZ(116,0,0x30+i,1, 2);    
    }
    else if(i < 100)
    {      
        a = i/10;
        i -= a*10;        
        drawCharZ(104,0,0x30+a,1, 2);
        drawCharZ(116,0,0x30+i,1, 2);        
    }   
 
rezh0 = rezhimi[bol0][seans0] ;
drawCharZ(0, 16, rezh0+0x30, 1, 2);
drawStringZ(12, 16, "режим  ", 7, 1, 2);
drawCharZ(0, 32, chel+0x30, 1, 2);
drawStringZ(12, 32, "пациент", 7, 1, 2);
drawCharZ(0, 48, seans0+0x30, 1, 2);
drawStringZ(12, 48, "сеанс  ", 7, 1, 2);
display(0,0,127,7);
for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }   
delay_ms(1000);
paus = 0;
vrem = 0;
#asm("wdr")
PORTC = 0b1000000;
timer = 18600000; 
clearDisplay();  
for (n = 0; n < 42; n++) drawChar(6*n+2,0,bolezni[bol0][n]);  
display(0,0,127,1);
for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
}
else
{
      clearDisplay();  
      drawStringZ(0, 0, "Транс+Гипн", 10, 1, 2);  
      drawStringZ(30, 48, "+Гипноз", 7, 1, 2);
      display(0,0,127,7);
}
               

drawStringZ(30, 16, "Нажмите", 7, 1, 2); 
drawStringZ(30, 32, "-(пуск)", 7, 1, 2); 
for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
display(24,2,127,7);
clearDisplay(); 
while(ubr & dob & paus++<1000)
{
    delay_ms(10);
    
}
delay_ms(50);
if(reg1)
{
    if(!fubr) 
    {
        reg2 = 1;
      clearDisplay(); 
      drawStringZ(0, 0, "SinP 014mS", 10, 1, 2);  
      drawChar(0,2,'Г');
      drawChar(0,3,'и');
      drawChar(0,4,'п');
      drawChar(0,5,'н');
      drawChar(0,6,'о');
      drawChar(0,7,'з');
      display(0,0,127,7);    
      period = 64736;
      timer = 18000000;  
      TIMSK2=(0<<OCIE2B) | (0<<OCIE2A) | (1<<TOIE2);
    }
    else
    {  
      fubr = 0;
      clearDisplay(); 
      timer = 3300000;  
      drawStringZ(0, 0, "Установка", 9, 1, 2);      
      drawStringZ(0, 16, "времени", 7, 1, 2);      
      timeZ(30,40,timer/10000,3);
      display(0,0,127,7);  
      for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
      flag0 = 1;  
      paus = 150;
     while (flag0 & --paus > 0)
      {    
        if(!dob) 
        {
            delay_ms(200); 
            paus = 150;
            while(!dob& time++<65000);  
            for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
            timer += 3000000;
        }
        if(!ubr) 
        {
            delay_ms(200);
            paus = 150;
            while(!ubr & time++<65000) ;  
            for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
            if (time>=65000) flag0 = 0;
            else timer -= 3000000;
        }   
        time = 0;
        if(timer < 3300000) timer = 3300000; 
        if(timer > 57300000) timer = 57300000;   
        clearDisplay(); 
        timeZ(30,40,timer/10000,3);
        display(0,5,127,7);  
                 
      }
      clearDisplay(); 
      drawStringZ(0, 0, "77Гц 0.5mS", 10, 1, 2);  
      drawChar(0,2,'Т');
      drawChar(0,3,'р');
      drawChar(0,4,'а');
      drawChar(0,5,'н');
      drawChar(0,6,'с');
      drawChar(0,7,'а');  
      display(0,0,127,7);  
    }
}
for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
if(paus>1000) timer = 0;
paus=0;
EICRA=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT1) | (0<<INT0);
EIFR=(0<<INTF1) | (0<<INTF0);
TIMSK1=(0<<ICIE1) | (0<<OCIE1B) | (0<<OCIE1A) | (1<<TOIE1);
drawStringZ(30, 16, "I=", 2, 1, 2); 
drawStringZ(102, 16, "mA", 2, 1, 2); 

while(1)
{
               

        timeZ(30,40,timer/10000,3);
        ZnachZ(54,16,tok,2) ; 
        if (reg2)
        {
            ZnachZo(60,0,(65535-period)/65,2);
            timer = timer - 5000;
            display(60,0,96,1);  
        }
        if(tok0 > (tok + 20))
        { 
            if(tok1++>2)
            {     
                
                fillRect(54,16,48,16,2);
                for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }      
                delay_ms(50); 
                for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); } 
                    
            }
        } 
        else tok1 = 0;
        display(24,2,127,7);  
        time = timer / 10000; 
        mod = 20;
       delay_ms(450);    
       if(!dob) 
       {
            if(!ubr)
            {
                if (paus++ > 5)
                {
                    clearDisplay(); 
                    drawStringZ(0, 20, "Выключение", 10, 1, 2); 
                    drawStringZ(0, 40, " Пока! ", 7, 1, 3); 
                    display(0,2,127,7); 
                    delay_ms(1000);
                    timer = 0;
                }
            }
            else
            if(tok0 < 1000)  
            {    
                for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }
                tok0+=10;
            }
       }
       if(!ubr | timer < 300000) 
       {  
            if(!reg1) if(!fl4)
            if( timer < 300000)
            {
                fl4 = 1;
                if (timer > 0) 
                {   
                    if(seans0 == 9) 
                    {      
                        n = 0;
                        while(n++<20)
                        {
                            delay_ms(30);                      // просигналить 20 раз
                            for(o=0;o<96;o++) { zvuk = 1 ; delay_us(300); zvuk = 0; delay_us(300); }
                        }                       
                        seans[chel] = 0;
                    }
                    else  seans[chel] = seans[chel] + 1;
                }
            };
           if(tok0 > 0) 
           {    
                if(tok0 < 20) tok0 = 0; else tok0-=10;
                for(o=0;o<32;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); }

           }
       }
       if (!fl3) 
       {
            if(!reg1) if (timer < 9000000) 
            {  
                if (rezh0 > 4) dn_reg = tok0/4; else  dn_reg = 0;
                if (rezhimi[bol0][seans0 + 10] > 4) up_reg = tok0/4;  else  up_reg = 0;
                up_reg =  tok0 + up_reg - dn_reg;      
                tok0 = 0;
                n = 0;
                while(n++<3)
                {
                    delay_ms(100);                      // просигналить 3 раз
                    for(o=0;o<300;o++) { zvuk = 1 ; delay_us(300); zvuk = 0; delay_us(300); }
                }                       
                rezh0 = rezhimi[bol0][seans0 + 10];
                tok0 = up_reg;
                drawCharZ(0, 16, rezh0+0x30, 1, 2);
                drawCharZ(12, 16, 'р', 1, 2);  
                display(0,2,23,3); 
                fl3 = 1;                              
            }
       }
       if (timer <= 0)
       {         
            tok0 = 0;             
            OCR0A=0x00;
            OCR0B=0x00;
            bufer[0] = 0x80; 
            bufer[1] = 0xAE;
            twi_master_trans(0x3C, bufer, 2, rx_data, 0) ;
            #asm("cli")                     // дальше действия по выключению 
            for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); } 
            delay_ms(50);
            for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); } 
            delay_ms(50);
            for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); } 
            delay_ms(50);
            for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); } 
            delay_ms(50);
            for(o=0;o<128;o++) { zvuk = 1 ; delay_us(200); zvuk = 0; delay_us(200); } 
            OCR0A=0x00;
            OCR0B=0x00;
            TWCR = 0; 
            DDRC=DDRB=DDRD=0;
            PORTC=0;
            PORTD=0;
            PORTD.6=1;           
            PORTB=0;    
            ASSR=(0<<EXCLK) | (0<<AS2);
        TCCR2A=(0<<COM2A1) | (0<<COM2A0) | (0<<COM2B1) | (0<<COM2B0) | (0<<WGM21) | (0<<WGM20);
        TCCR2B=(0<<WGM22) | (0<<CS22) | (0<<CS21) | (0<<CS20);
        MCUSR &= ~(1<<WDRF);
    /* Write logical one to WDCE and WDE */
    /* Keep old prescaler setting to prevent unintentional
    time-out */
        WDTCSR |= (1<<WDCE) | (1<<WDE);
    /* Turn off WDT */
        WDTCSR = 0x00;            
            ADMUX=00;
            ADCSRA=0x00;
            MCUCR = 0x10;
    
            sleep_enable(); //разрешение спящего режима
            powerdown();
            //       Окончание
       }
    
}

}
