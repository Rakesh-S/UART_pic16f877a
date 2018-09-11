/* connections 
*	RS -> RC0
*	EN -> RC1
*	D0:D7 -> RB0:RB7 */

#include<pic.h>
#include "settings.h"
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=0;j<a;j++);
}
void cmd(int);
void lcd_print(char);
void lcd_init();
int main()
{
	TRISB = 0X00;
	TRISC = 0X00;
	lcd_init();
	SPBRG = 129;
	TXSTA = 0X26;
	RCSTA = 0X80;
	while(1)	
	{	
		while(!RCIF);
		char b = RCREG;
		lcd_print(b);
		delay(500);
	}
}
void lcd_init()
{
	cmd(0x01);
	cmd(0x0E);
	cmd(0x38);
	cmd(0x80);
	cmd(0x06);
}
void cmd(int a)
{
	lcd_data = a;
	RS = 0;
	EN = 1;
	delay(100);
	EN = 0;
}
void lcd_print(char b)
{
	lcd_data = b;
	RS = 1;
	EN = 1;
	delay(100);
	EN = 0;
}

