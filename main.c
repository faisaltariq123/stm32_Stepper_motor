/*----------------------------------------------------------------------------
 Stepper motor
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stm32f4xx.h>


volatile uint32_t msTicks;                      /* counts 1ms timeTicks       */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;
}


/*----------------------------------------------------------------------------
  delays number of tick Systicks (happens every 1 ms)
 *----------------------------------------------------------------------------*/
void Delay (uint32_t dlyTicks) {                                              
 	uint32_t loop=0,dly=0,loope=0;
	dly = dlyTicks ; 
	for(loop=0;loop<dly;loop++){
		for(loope=0;loope<29000;loope++){
			__nop();
		}
	}
}

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void) {

  SystemCoreClockUpdate();             // Get Core Clock Frequency
	
  RCC->AHB1ENR  |= (1 <<  1) ;         // Enable GPIOB clock	

	GPIOB->MODER   =   0x55555555;       // Setting Direction of Port B
	GPIOB->OTYPER  =   0x00000000;       // To configure the output type of Port B
	GPIOB->OSPEEDR =   0xAAAAAAAA;			 // To configure the speed of Port B 
	GPIOB->PUPDR   =   0x00000000;			 // To configure the Port B Pull-up or Pull-down

  while(1) {                           // Infinite Loop 
 	
	GPIOB->BSRRL = ((1 <<  11) );
	GPIOB->BSRRH = ((1 <<  12) );
  GPIOB->BSRRH = ((1 <<  13) );
  GPIOB->BSRRH = ((1 <<  14) ); 		
	Delay(5);
	GPIOB->BSRRH = ((1 <<  11) );
	GPIOB->BSRRL = ((1 <<  12) );
  GPIOB->BSRRH = ((1 <<  13) );
  GPIOB->BSRRH = ((1 <<  14) ); 		
	Delay(5);
	GPIOB->BSRRH = ((1 <<  11) );
	GPIOB->BSRRH = ((1 <<  12) );
  GPIOB->BSRRL = ((1 <<  13) );
  GPIOB->BSRRH = ((1 <<  14) ); 		
	Delay(5);
	GPIOB->BSRRH = ((1 <<  11) );
	GPIOB->BSRRH = ((1 <<  12) );
  GPIOB->BSRRH = ((1 <<  13) );
  GPIOB->BSRRL = ((1 <<  14) ); 		
	Delay(5);		
	}	
}

