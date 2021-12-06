#include<lpc21xx.h>



void delay(unsigned int c)
{unsigned int a;
for(a=1;a<=50000;a++);}



int main()
{
PINSEL0=0x00000000; //GPIO
PINSEL1=0x00000000;
PINSEL2=0x00000000;

IO0DIR|=0xffffffff; //making all the bits as output
IO1DIR = ~(1<<16); //switch is acting as input hence send 0 to p1.16 without altering other bits

while(1)
{
unsigned long int j;
//int i,a[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // 0 to 9
int i,a[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; //anode type
//int b[]={0x6F,0x7F,0x07,0x7D,0x6D,0x66,0x4F,0x5B,0x06,0x3F}; //9 to 0
int b[] ={0x90,0x80, 0xF8, 0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};



if(IO1PIN & (1<<16)) // if switch is ON
{
for(j=0;j<10;j++)
{ IO0SET=IO0SET|a[j]; // send 0 to 9 - up counter



delay(10000);
IO0CLR=a[j];
delay(10000);
}
}
else // if switch is OFF
{



for(j=0;j<10;j++)
{
IO0SET=IO0SET|b[j]; // send 9 to 0 - down counter





delay(10000);
IO0CLR=b[j];
delay(10000);



}



}
}
}
