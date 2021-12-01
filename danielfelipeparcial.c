#INCLUDE <16F887.H>
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT, NOWRT
#USE DELAY(internal =8MHZ)
#INCLUDE<lcd.C>
#USE fast_io(b)
#USE fast_io(a)

#define a input(pin_b0)
#define b input(pin_b1)
#define c input(pin_b2)
#define d input(pin_b3)
#define i input(pin_b4)

#define e input(pin_a0)
#define f input(pin_a1)
#define g input(pin_a2)
#define h input(pin_a3)
#define j input(pin_a4)

int8 suma1=0,suma2=0,suma3=0,suma4=0,suma5=0;
int8 su1=0,su2=0,su3=0,su4=0,su5=0;
int16 dato1;
suma( int1 n1,int1 n2,int8 n3){
 int8 valor;
 valor = n1+n2+n3;
 return valor;
  } 
  

void main()
{
   lcd_init();
   set_tris_b(0x0F); 
   output_b(0);
   set_tris_a(0x0F);
   output_a(0);
   
  
   while(true)
{
suma1= i+j;
if(suma1 == 2){
suma1 = 0;
su1 = 1;
}
if(suma1 == 1){
su1 = 0;
}

suma2 = h+d+su1;
if(suma2 == 1){
su2 = 0;
}
if(suma2 == 0){
su2 = 0;
}
if(suma2 == 2){
suma2 = 0;
su2 = 1;
}
if(suma2 == 3){
suma2 = 1;
su2 = 1;
}
suma3 = suma(g,c,su2);
if(suma3 == 1){
su3 = 0;
}
if(suma3 == 0){
su3 = 0;
}
if(suma3 == 2){
suma3 = 0;
su3 = 1;
}
if(suma3 == 3){
suma3 = 1;
su3 = 1;
}
suma4 = suma(b,f,su3);
if(suma4 == 1){
su4 = 0;
}
if(suma4 == 0){
su4 = 0;
}
if(suma4 == 2){
suma4 = 0;
su4 = 1;
}
if(suma4 == 3){
suma4 = 1;
su4 = 1;
}
suma5 = suma(a,e,su4);
if(suma5 == 2){
suma5 = 0;
su5=1;
}
if(suma5 == 3){
suma5 = 1;
su5=1;
}

dato1 = suma1*1+suma2*2+suma3*4+suma4*8+suma5*16+su5*32;
if(dato1<52){
delay_us(1000);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"SUMA %u%u%u%u%u%u        ",su5,suma5,suma4,suma3,suma2,suma1);
   lcd_gotoxy(1,2);
   printf(lcd_putc," %lu               ",dato1);
   delay_us(8000);
   su5=0;suma5=0;suma4=0;suma3=0;suma2=0;suma1=0;
}else{
 lcd_gotoxy(1,1);
   printf(lcd_putc,"EXCEDE LIMITES");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                      ");

}
   
}}
