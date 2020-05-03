#include<LPC21xx.h>
#include<string.h>
void lcd_init(void);
void writeCommand(void);
void clearDisplay(void);
void delay(unsigned int);
void writeData(void);
void lcdData(void);
void lcdCommand(void);
void LCD(char disp[30],char disp1[30]);
void LCDhead(char l[]); 
unsigned char temp1;
unsigned long int temp,r=0;
char *ptr;
char disp2[20];
void LCDhead(char l[20])
{
	strcpy(disp2,l);
	return;
}

void LCD(char disp[30],char disp1[30])
	{
		IO0DIR=0x000000FC;
		IO0PIN=0x00000000;

		lcd_init();
		delay(3200);
		clearDisplay();
		delay(500);

		temp1=0x80;
		lcdCommand();
		delay(645);
		ptr=disp;
		while(*ptr!='\0')
			{
					temp1=*ptr;
					delay(3200);
					lcdData();
					ptr++;
					delay(3200);
			}
		temp1=0xC0;
		lcdCommand();
		delay(800);
		ptr=disp1;
		while(*ptr!='\0')
			{
				temp1=*ptr;
				delay(3200);
				lcdData();
				ptr++;
				delay(3200);
			}
			return;
}


void lcd_init(void){
temp=0x30;
writeCommand();
delay(3200);
temp=0x30;
writeCommand();
delay(3200);
temp=0x30;
writeCommand();
delay(3200);
temp=0x20;
writeCommand();
delay(3200);
temp=0x28;
lcdCommand();
delay(3200);

//load a command for display on cursor and blinking off
temp1=0x0C;
lcdCommand();
delay(800);

//command for cursor increment after data dump
temp1=0x06;
lcdCommand();
delay(800);
temp1=0x80;
lcdCommand();
delay(800);

}

void lcdCommand(void){

temp=temp1&0xF0;
writeCommand();
temp=temp1&0x0F;
temp=temp<<4;
writeCommand();
delay(500);
}

void writeCommand(void){
IO0CLR=0x000000FC;
IO0SET=temp;
IO0CLR=0x00000004;
IO0SET=0x00000008;
delay(10);
IO0CLR=0x00000008;
}

void writeData(void){

IO0CLR=0x000000FC;
IO0SET=temp;
IO0SET=0x000000004;
IO0SET=0x000000008;
delay(10);
IO0CLR=0x000000008;
}
//data o/p routine that o/p high nibble first first then low nibble next
void lcdData(){
temp=temp1&0xF0;
temp=temp;
writeData();
temp=temp1&0x0F;
temp=temp<<4;
writeData();
delay(100);
}
void clearDisplay(void){
temp1=0x01;
lcdCommand();
delay(500);

}

void delay(unsigned int r1){
for(r=0; r<r1; r++);
}

