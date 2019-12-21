/*
 * Lcd.h
 *
 *  Created on: Apr 27, 2017
 *      Author: user
 */

#ifndef SW_EK_LM4F120XL_9453_DRIVERLIB_LCD_H_
#define SW_EK_LM4F120XL_9453_DRIVERLIB_LCD_H_


#define LCDPORT                  GPIO_PORTB_BASE
#define LCDPORTENABLE    SYSCTL_PERIPH_GPIOB
#define RS                               GPIO_PIN_0
#define E                                GPIO_PIN_1
#define D4                               GPIO_PIN_4
#define D5                               GPIO_PIN_5
#define D6                               GPIO_PIN_6
#define D7                               GPIO_PIN_7

void Lcd_Komut(unsigned char);  //Lcd ye komut göndermeye yarar
void Lcd_Temizle(void);                 //Lcd ekranını temizler
void Lcd_Puts(char*);                   //String ifade yazdırır
void Lcd_Goto(char,char);               //Kursorü istenilen yere gönderir
void Lcd_init(void);                    //Lcd başlangıç ayarları
void Lcd_Putch(unsigned char);  //Tek karekter yazdırır


#endif /* SW_EK_LM4F120XL_9453_DRIVERLIB_LCD_H_ */
