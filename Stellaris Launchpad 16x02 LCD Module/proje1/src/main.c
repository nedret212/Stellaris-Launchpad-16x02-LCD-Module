#include "inc/lm4f120h5qr.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "stdio.h"
#include <stdint.h>

// fonksiyonlar
void fonk1();
void fonk2();
void fonk3();
void fonk4();
void led();
void tazele();
void ekran_sifirla();

int main(void)
{

		while(1)
		{
			ekran_sifirla();
			fonk1();
			ekran_sifirla();
			fonk2();
			ekran_sifirla();
			fonk4();
			ekran_sifirla();
			fonk3();
		}

}
void tazele()
{
	//------------------- Stellaris Launchpad System Initilization------------------//
		SysCtlClockSet(SYSCTL_SYSDIV_16 | SYSCTL_USE_PLL| SYSCTL_XTAL_16MHZ|
		SYSCTL_OSC_MAIN);

		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

		GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7);
		GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7);

		//------------------End of Stellaris Launchpad System Initilization------------//

		//Wait 15 Miliseconds after LCD Power Up//
		SysCtlDelay(2000000);

		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);

		//-------------------------------First LCD Command----------------------------//

		//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x38);

		//Register Select(RS) = 0, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

		//Enable Pulse Width (High Level) 230 nano second//
		SysCtlDelay(200);

		//Register Select(RS) = 0, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
		//---------------------------End of First LCD Command------------------------//

		//1 milliseconds delay//
		SysCtlDelay(41670);

		//-------------------------------Second LCD Command----------------------------//

		//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x38);

		//Register Select(RS) = 0, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

		//Enable Pulse Width (High Level) 230 nano second//
		SysCtlDelay(200);

		//Register Select(RS) = 0, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
		//---------------------------End of Second LCD Command------------------------//

		//1 milliseconds delay//
		SysCtlDelay(41670);

		//-------------------------------Third LCD Command----------------------------//

		//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x06);

		//Register Select(RS) = 0, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

		//Enable Pulse Width (High Level) 230 nanosecond//
		SysCtlDelay(200);

		//Register Select(RS) = 0, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
		//---------------------------End of Third LCD Command------------------------//

		//1 milliseconds delay//
		SysCtlDelay(41670);

		//-------------------------------Fourth LCD Command----------------------------//

		//Put on the Data Pins 0x0E Command to get Display ON, Cursor Blinking//
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x0E);

		//Register Select(RS) = 0, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

		//Enable Pulse Width (High Level) 1 microsecond//
		SysCtlDelay(200);

		//Register Select(RS) = 0, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
		//---------------------------End of Fourth LCD Command------------------------//

		// 1 millisecond delay
		SysCtlDelay(41670);

		//-------------------------------Fifth LCD Command----------------------------//

		//Put on the Data Pins 0x01 command to Clear the LCD Screen//
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x01);

		//Register Select(RS) = 0, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

		//Enable Pulse Width (High Level) 1 microsecond//
		SysCtlDelay(200);

		//Register Select(RS) = 0, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);

		//Delay 2ms after the 0x01 and 0x02//
		SysCtlDelay(83330);
		//---------------------------End of Fifth LCD Command------------------------//

		//1 Millisecond Delay//
		SysCtlDelay(416700);
}
void fonk1()
{
	int i=0;
	int kou[11]={107,111,99,97,101,108,105,32,117,110,105};
	int ned[15]={78,69,68,82,69,84,32,71,69,71,69,79,71,76,85};

	for(i=0;i<11;i++){
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, kou[i]);

		//Register Select(RS) = 1, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

		//Enable Pulse Width (High Level) 1 microsecond//
		SysCtlDelay(2);

		//Register Select(RS) = 1, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

		//Delay 2ms after the 0x01 and 0x02//
		SysCtlDelay(833300);
	}

							//alt satira gec

			GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
			|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0b10101000);

			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

			SysCtlDelay(2);

			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);

			SysCtlDelay(416700);

	//delay
	SysCtlDelay(5000000);

	for(i=0;i<15;i++){
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
				|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, ned[i]);

				//Register Select(RS) = 1, Enable(E) = 1//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

				//Enable Pulse Width (High Level) 1 microsecond//
				SysCtlDelay(2);

				//Register Select(RS) = 1, Enable(E) = 0//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

				//Delay 2ms after the 0x01 and 0x02//
				SysCtlDelay(833300);
	}

}
void fonk2()
{
		int i=0;
		int kou[11]={107,111,99,97,101,108,105,32,117,110,105};
		int ned[15]={78,69,68,82,69,84,32,71,69,71,69,79,71,76,85};

			for(i=0;i<15;i++){
				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
						|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, ned[i]);

						//Register Select(RS) = 1, Enable(E) = 1//
						GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

						//Enable Pulse Width (High Level) 1 microsecond//
						SysCtlDelay(2);

						//Register Select(RS) = 1, Enable(E) = 0//
						GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

						//Delay 2ms after the 0x01 and 0x02//
						SysCtlDelay(833300);
			}

						//alt satira gec

				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
				|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0b10101000);

				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

				SysCtlDelay(2);

				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);

				SysCtlDelay(416700);

				//delay
				SysCtlDelay(5000000);

			for(i=0;i<11;i++){

						GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
						|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, kou[i]);

						//Register Select(RS) = 1, Enable(E) = 1//
						GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

						//Enable Pulse Width (High Level) 1 microsecond//
						SysCtlDelay(2);

						//Register Select(RS) = 1, Enable(E) = 0//
						GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

						//Delay 2ms after the 0x01 and 0x02//
						SysCtlDelay(833300);
			}
}
void fonk3()
{
		int i=0;
		int kou[15]={107,111,99,97,101,108,105,32,117,110,105,32,32,32,32};
		int ned[15]={78,69,68,82,69,84,32,71,69,71,69,79,71,76,85};

		int bas=0;
		int kontrol=15;
		int harf=0;

		while(kontrol!=bas){

			//bosluk
			for(i=0;i<kontrol;i++){
			GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
			|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 32);

			//Register Select(RS) = 1, Enable(E) = 1//
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

			//Enable Pulse Width (High Level) 1 microsecond//
			SysCtlDelay(2);

			//Register Select(RS) = 1, Enable(E) = 0//
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

			//Delay 2ms after the 0x01 and 0x02//
			SysCtlDelay(8333);
			}

		harf=16-kontrol;
		kontrol-=1;

		for(i=0;i<harf;i++){
			//kou uni
				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
				|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, kou[i]);

				//Register Select(RS) = 1, Enable(E) = 1//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

				//Enable Pulse Width (High Level) 1 microsecond//
				SysCtlDelay(2);

				//Register Select(RS) = 1, Enable(E) = 0//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

				//Delay 2ms after the 0x01 and 0x02//
				SysCtlDelay(8333);
		}

		tazele();
		}

		//son kez yaz ve ekranda kalici olmasini sagla

		for(i=0;i<harf;i++){

		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, kou[i]);

		//Register Select(RS) = 1, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

		//Enable Pulse Width (High Level) 1 microsecond//
		SysCtlDelay(2);

		//Register Select(RS) = 1, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

		//Delay 2ms after the 0x01 and 0x02//
		SysCtlDelay(8333);
		}

		//bekle
		SysCtlDelay(10000000);

		//ned yazdir
		 bas=0;
		 kontrol=15;
		 harf=0;

		 while(kontrol!=bas){

		 //bosluk
		 for(i=0;i<kontrol;i++){
		 GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		 |GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 32);

		 //Register Select(RS) = 1, Enable(E) = 1//
		 GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

		 //Enable Pulse Width (High Level) 1 microsecond//
		 SysCtlDelay(2);

		 //Register Select(RS) = 1, Enable(E) = 0//
		 GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

		 //Delay 2ms after the 0x01 and 0x02//
		 SysCtlDelay(8333);
		 }

		 harf=16-kontrol;
		 kontrol-=1;

		 for(i=0;i<harf;i++){
		 GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		 |GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, ned[i]);

		 //Register Select(RS) = 1, Enable(E) = 1//
		 GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

		 //Enable Pulse Width (High Level) 1 microsecond//
		 SysCtlDelay(2);

		 //Register Select(RS) = 1, Enable(E) = 0//
		 GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

		 //Delay 2ms after the 0x01 and 0x02//
		 SysCtlDelay(8333);

		 }

		tazele();
		}

		//son kez yaz ve ekranda kalici olmasini sagla

		for(i=0;i<harf;i++){

		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
		|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, ned[i]);

		//Register Select(RS) = 1, Enable(E) = 1//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

		//Enable Pulse Width (High Level) 1 microsecond//
		SysCtlDelay(2);

		//Register Select(RS) = 1, Enable(E) = 0//
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

		//Delay 2ms after the 0x01 and 0x02//
		SysCtlDelay(8333);
		}

		//bekle
		SysCtlDelay(10000000);

}
void fonk4()
{
	int i=0;
	int kou[11]={107,111,99,97,101,108,105,32,117,110,105};
	int ned[15]={78,69,68,82,69,84,32,71,69,71,69,79,71,76,85};

	int kontrol=0;
	int son=11;
	int harf=1;
	int deger=10;
	int hedef=10;

	while(kontrol!=11){

		for(i=son;i>hedef;i--)
		{

			//kou uni

			GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
			|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, kou[deger]);

			//Register Select(RS) = 1, Enable(E) = 1//
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

			//Enable Pulse Width (High Level) 1 microsecond//
			SysCtlDelay(2);

			//Register Select(RS) = 1, Enable(E) = 0//
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

			//Delay 2ms after the 0x01 and 0x02//
			SysCtlDelay(8333);

			deger++;

		}

		harf++;
		kontrol++;
		deger=11-harf;
		hedef=deger;
		tazele();
	}
	//kou son kez kalici olmasi icin yaz
	for(i=0;i<son;i++){

			GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
			|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, kou[i]);

			//Register Select(RS) = 1, Enable(E) = 1//
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

			//Enable Pulse Width (High Level) 1 microsecond//
			SysCtlDelay(2);

			//Register Select(RS) = 1, Enable(E) = 0//
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

			//Delay 2ms after the 0x01 and 0x02//
			SysCtlDelay(8333);
			}

	 //bekle
	 SysCtlDelay(10000000);

	 kontrol=0;
	 son=15;
	 harf=1;
	 deger=14;
	 hedef=14;
	 tazele();

	while(kontrol!=15){

			for(i=son;i>hedef;i--)
			{

				//ned

				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
				|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, ned[deger]);

				//Register Select(RS) = 1, Enable(E) = 1//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

				//Enable Pulse Width (High Level) 1 microsecond//
				SysCtlDelay(2);

				//Register Select(RS) = 1, Enable(E) = 0//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

				//Delay 2ms after the 0x01 and 0x02//
				SysCtlDelay(8333);

				deger++;

			}

			harf++;
			kontrol++;
			deger=15-harf;
			hedef=deger;
			tazele();
		}
		//ned son kez kalici olmasi icin yaz
		for(i=0;i<son;i++){

				GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
				|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, ned[i]);

				//Register Select(RS) = 1, Enable(E) = 1//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0xC0);

				//Enable Pulse Width (High Level) 1 microsecond//
				SysCtlDelay(2);

				//Register Select(RS) = 1, Enable(E) = 0//
				GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x40);

				//Delay 2ms after the 0x01 and 0x02//
				SysCtlDelay(8333);
				}

		//bekle
		SysCtlDelay(10000000);

}

void led()
{
		volatile unsigned long delay;
		init_port_D();

		GPIO_PORTD_DATA_R |= 0b1;
		GPIO_PORTD_DATA_R &= ~(0b110);

		for(delay = 0; delay < 400000; delay++)
					/* bos dongu ile bekle */;

		GPIO_PORTD_DATA_R |= 0b10;
		GPIO_PORTD_DATA_R &= ~(0b101);

		for(delay = 0; delay < 400000; delay++)
						/* bos dongu ile bekle */;

		GPIO_PORTD_DATA_R |= 0b100;
		GPIO_PORTD_DATA_R &= ~(0b011);

		for(delay = 0; delay < 400000; delay++)
						/* bos dongu ile bekle */;


}
void ekran_sifirla()
{
	//------------------- Stellaris Launchpad Sistem Kurulumu------------------//
	SysCtlClockSet(SYSCTL_SYSDIV_16 | SYSCTL_USE_PLL| SYSCTL_XTAL_16MHZ|
	SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
	|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7);

	//------------------Stellaris Launchpad Sistem Kurulumu sonu------------//

	//Wait 15 Miliseconds after LCD Power Up//
	SysCtlDelay(6250000);

	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);

	//-------------------------------Lcd ekran komut 1----------------------------//

	//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
	|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x38);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

	//Enable Pulse Width (High Level) 230 nano second//
	SysCtlDelay(200);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
	//---------------------------Lcd ekran komut 1 sonu------------------------//

	//1 milliseconds delay//
	SysCtlDelay(416700);

	//-------------------------------Lcd Ekran komut 2----------------------------//

	//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
	|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x38);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

	//Enable Pulse Width (High Level) 230 nano second//
	SysCtlDelay(200);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
	//---------------------------Lcd ekran komut 2 sonu-----------------------//

	//1 milliseconds delay//
	SysCtlDelay(416700);

	//-------------------------------Lcd Ekran komut 3----------------------------//

	//Put on the Data Pins 0x38 to get 2 Lines 5x7 Matrix (D0-D7, 8Bit)//
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
	|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x06);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

	//Enable Pulse Width (High Level) 230 nanosecond//
	SysCtlDelay(200);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
	//---------------------------Lcd ekran komut 3 sonu------------------------//

	//1 milliseconds delay//
	SysCtlDelay(416700);

	//-------------------------------Lcd Ekran komut 4 ----------------------------//

	//Put on the Data Pins 0x0E Command to get Display ON, Cursor Blinking//
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
	|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x0E);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(200);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);
	//---------------------------Komut 4 sonu------------------------//

	// 1 millisecond delay
	SysCtlDelay(416700);

	//-------------------------------Lcd ekran komut 5----------------------------//

	//Put on the Data Pins 0x01 command to Clear the LCD Screen//
	GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1| GPIO_PIN_2 | GPIO_PIN_3
	|GPIO_PIN_4 | GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7, 0x01);

	//Register Select(RS) = 0, Enable(E) = 1//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x80);

	//Enable Pulse Width (High Level) 1 microsecond//
	SysCtlDelay(200);

	//Register Select(RS) = 0, Enable(E) = 0//
	GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7, 0x00);

	//Delay 2ms after the 0x01 and 0x02//
	SysCtlDelay(833300);
	//---------------------------Komut 5 Sonu------------------------//

	//1 Millisecond Delay//
	SysCtlDelay(416700);
}
