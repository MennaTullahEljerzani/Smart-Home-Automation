/*
 ============================================================================
 Name        : smart_home.c
 Author      : Menna Tullah Medhat
 Description : main.c
 *  The driver uses Timer0 in PWM mode
 Date        : 10/6/2024
 ============================================================================
 */
#include "temperature_sensor.h"
#include "adc.h"
#include "flame_sensor.h"
#include "buzzer.h"
#include "lcd.h"
#include <util/delay.h>
#include "led.h"
#include "ldr.h"
#include "dc_motor.h"
#include "gpio.h"

int main(void)
{
	uint8 tempValue = 0;               /* Variable to Store the Temperature value (initialized with 0) */
	uint16 lightIntensity = 0;
	uint8 flameDetected = 0;
	uint8 flag1 = 0;
	uint8 flag2 = 0;

		ADC_init();     /* Passing this Pointer as Parameter to ADC_init() to initailize ADC with these requirements */

		FlameSensor_init();        /* Initialize flame sensor*/

		LCD_init();               /* Initialize LCD */

		DcMotor_Init();           /* Initialize DC-Motor */

		Buzzer_init();           /* Initialize Buzzer */

		LEDS_init();          /* Initialize LEDs */

		LCD_displayStringRowColumn(0, 1, "FAN IS ");     /* Display String "FAN IS" at (ROW 0, COLUMN 2) on LCD */
		LCD_displayStringRowColumn(1, 1, "TEMP=");    /* Display String "TEMP = " at (ROW 1, COLUMN 2) on LCD */
		LCD_displayStringRowColumn(1, 9, "LDR= ");

		for(;;)
		{
			tempValue = LM35_getTemperature();    /* Get the value of Temperature from LM35 Sensor */
			lightIntensity = LDR_getLightIntensity();
			flameDetected = FlameSensor_getValue();  // Get the flame sensor value

			/*  If the temperature is less than 30 C, Turn off the fan */
			if (tempValue < 25)
				LCD_displayStringRowColumn(0, 9,"OFF");
			else
			{
				LCD_displayStringRowColumn(0, 9,"ON");
				/* To Clear the next digit if OFF state happened first */
				LCD_displayCharacter(' ');
			}


			LCD_moveCursor(1, 6);              /* Move Cursor to (ROW 1 , COLUMN 9) on LCD */
			LCD_intgerToString(tempValue);    /* Convert Temperature's Decimal value into String to Display it on LCD */

			/* To handle the transitions of the digital value from 3 digits to 2 or 1 , Print space in the next digit place */
			LCD_displayString(" ");

		    LCD_moveCursor(1, 13);                         /* Move cursor to row 1, column 9 */
			LCD_intgerToString(lightIntensity);           /* Convert light intensity to string and display */
			LCD_displayString("%");                       /* Append "%" to indicate percentage */



			if(tempValue >= 40)
			{
				/* If the temperature is greater than or equal 120C , Turn on the fan with 100% of its maximum speed */
				DcMotor_Rotate(ClockWise, 255);
			}
			else if((tempValue >= 35)&&(tempValue<40))
			{
				/* If the temperature is greater than or equal 90C , Turn on the fan with 75% of its maximum speed */
				DcMotor_Rotate(ClockWise, 192);
			}
			else if((tempValue >= 30)&&(tempValue<35))
			{
				/* If the temperature is greater than or equal 60C , Turn on the fan with 50% of its maximum speed */
				DcMotor_Rotate(ClockWise, 128);
			}
			else if ((tempValue >= 25)&&(tempValue<30))
			{
				/* If the temperature is greater than or equal 30C , Turn on the fan with 25% of its maximum speed */
				DcMotor_Rotate(ClockWise, 64);
			}
			else
			{
				/* If the temperature is less than 30 C, Turn off the fan
				 * With DC_MotorState = STOP , To Stop the Motion of DC-Motor (Fan OFF)
				 * Speed MUST be ZERO , To Make OCR0 = ZERO --> NO PWM Signal (NO Speed)
	 			 */
				DcMotor_Rotate(STOP, 0);
			}
			if (lightIntensity <= 15)
			{
				LED_on(LEDPIN1_ID);
				LED_on(LEDPIN2_ID);
				LED_on(LEDPIN3_ID);
			}
			else if((lightIntensity <= 50)&&(lightIntensity >= 16))
			{
				LED_on(LEDPIN1_ID);
				LED_on(LEDPIN2_ID);
				LED_off(LEDPIN3_ID);
			}
			else if((lightIntensity <= 70)&&(lightIntensity >= 51))
			{
				LED_on(LEDPIN1_ID);
				LED_off(LEDPIN2_ID);
				LED_off(LEDPIN3_ID);
			}
			else if ((lightIntensity > 70))
			{
				LED_off(LEDPIN1_ID);
				LED_off(LEDPIN2_ID);
				LED_off(LEDPIN3_ID);
			}
			 if ((flameDetected == 1) && (flag2 ==0))
			 {
				 flag2 = 1;
				LCD_clearScreen();
			    LCD_displayStringRowColumn(0, 0, "Flame Detected!");
			    Buzzer_on();
			   flag1 =1;
			  }
			 if ((flameDetected == 0) && (flag1 ==1))
				  {

				    flag1 =0;
					LCD_clearScreen();
					Buzzer_off();
				    LCD_displayStringRowColumn(0, 1, "FAN IS ");     /* Display String "FAN IS" at (ROW 0, COLUMN 2) on LCD */
					LCD_displayStringRowColumn(1, 1, "TEMP=");    /* Display String "TEMP = " at (ROW 1, COLUMN 2) on LCD */
					LCD_displayStringRowColumn(1, 9, "LDR= ");

					 }

			_delay_ms(1000);
		}
}
