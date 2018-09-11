#include<pic.h>
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=0;j<a;j++);
}
void uart_init();
void uart_send(char b);
int main()
{
	TRISB = 0xFF;
	uart_init();
	while(1)
	{
		if(RB0 == 0)
		{
			uart_send('A');
			delay(300);
		}
		else if(RB0 == 1)
		{
			uart_send('B');
			delay(300);
		}
	}
}
void uart_init()
{
	SPBRG = 129;
	TXSTA = 0X26;
	RCSTA = 0X80;
}
void uart_send(char b)
{
	TXREG = b;
	while(!TXIF);
}
