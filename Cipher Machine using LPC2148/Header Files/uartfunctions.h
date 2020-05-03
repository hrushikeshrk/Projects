#include<LPC21xx.h>
void uartinit()
{
	PINSEL0=0x5;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=00;
	U0LCR=0x03;
}

void uartwrite(char ch[30])
{
	int i;
	for(i=0;i<30;i++)
	{
		while((U0LSR & 0x20)==0);
		if(ch[i]=='\0')
			break;
		U0THR=ch[i];
	}
}

void uartwritech(char c)
{
	while((U0LSR & 0x20)==0);
	U0THR=c;
}

char uartread()
{
	while((U0LSR & 0x1)==0);
	return(U0RBR);
}
