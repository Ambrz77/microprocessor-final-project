#include "stm32f4xx.h"

#define RS 0x20     /* PB5 mask for reg select */
#define RW 0x40     /* PB6 mask for read/write */
#define EN 0x80     /* PB7 mask for enable */

void delayMs(int n);
void LCD_command(unsigned char command);
void LCD_data(char data);
void LCD_init(void);
void PORTS_init(void);
void INIT_PORTA(void);
void INIT_PORTB(void);
void USART2_init(void);
char USART2_read(void);
void USART2_write(int c);

int main(void) {

    /* initialize LCD controller */
		INIT_PORTA();
		INIT_PORTB();
    LCD_init();
		int a=0;
	
		LCD_data('9');
		LCD_data('6');
		LCD_data('2');
		LCD_data('4');
		LCD_data('3');
		LCD_data('0');
		LCD_data('8');
		LCD_data('7');
			
		delayMs(60000);
		LCD_command(1);
	
		LCD_data('1');
		LCD_data(')');
		LCD_data('S');
		LCD_data('i');
		LCD_data('n');
		LCD_data(' ');
	
		LCD_data('2');
		LCD_data(')');
		LCD_data('S');
		LCD_data('q');
		LCD_data('r');
		
		LCD_data('3');
		LCD_data(')');
		LCD_data('T');
		LCD_data('r');
		LCD_data('i');
		
		LCD_data('4');
		LCD_data(')');
		LCD_data('S');
		LCD_data('a');
		LCD_data('w');
		

		//while(a!=0) {
		//	LCD_data('9');
		//	LCD_data('6');
		//	LCD_data('2');
		//	LCD_data('4');
		//	LCD_data('3');
		//	LCD_data('0');
		//	LCD_data('8');
		//	LCD_data('7');
		//	delayMs(600000);
		//	LCD_command(1);
		//	a++;
		//}
    
}

void INIT_PORTA(void){
	//clock for GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//MODER PORT A
	GPIOA->MODER = 0x55555555;
}

void INIT_PORTB(void){
	//clock for GPIOB
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	//MODER PORT B
	GPIOB->MODER = 0x55000000;
}

void PORTS_init(void) {
    RCC->AHB1ENR |=  0x06;          

    GPIOB->MODER &= ~0x0000FC00;    /* clear pin mode */
    GPIOB->MODER |=  0x00005400;    /* set pin output mode */
    GPIOB->BSRR = 0x00C00000;       /* turn off EN and R/W */

    /* PC0-PC7 for LCD D0-D7, respectively. */
    GPIOC->MODER &= ~0x0000FFFF;    /* clear pin mode */
    GPIOC->MODER |=  0x00005555;    /* set pin output mode */
}

/* initialize port pins then initialize LCD controller */
void LCD_init(void) {
    PORTS_init();

    delayMs(30);            /* initialization sequence */
    LCD_command(0x30);
    delayMs(10);
    LCD_command(0x30);
    delayMs(1);
    LCD_command(0x30);

    LCD_command(0x38);      /* set 8-bit data, 2-line, 5x7 font */
    LCD_command(0x06);      /* move cursor right after each char */
    LCD_command(0x01);      /* clear screen, move cursor to home */
    LCD_command(0x0F);      /* turn on display, cursor blinking */
}


void LCD_command(unsigned char command) {
    GPIOB->BSRR = (RS | RW) << 16;  /* RS = 0, R/W = 0 */
    GPIOC->ODR = command;           /* put command on data bus */
    GPIOB->BSRR = EN;               /* pulse E high */
    delayMs(0);
    GPIOB->BSRR = EN << 16;         /* clear E */

    if (command < 4)
        delayMs(2);         /* command 1 and 2 needs up to 1.64ms */
    else
        delayMs(1);         /* all others 40 us */
}

void LCD_data(char data) {
    GPIOB->BSRR = RS;               /* RS = 1 */
    GPIOB->BSRR = RW << 16;         /* R/W = 0 */
    GPIOC->ODR = data;              /* put data on data bus */
    GPIOB->BSRR = EN;               /* pulse E high */
    delayMs(0);
    GPIOB->BSRR = EN << 16;         /* clear E */

    delayMs(1);
}

void USART2_init (void) {
    RCC->AHB1ENR |= 1;          /* Enable GPIOA clock */
    RCC->APB1ENR |= 0x20000;    /* Enable USART2 clock */

    /* Configure PA3 for USART2 RX */
    GPIOA->AFR[0] &= ~0xF000;
    GPIOA->AFR[0] |=  0x7000;   /* alt7 for USART2 */
    GPIOA->MODER  &= ~0x00C0;
    GPIOA->MODER  |=  0x0080;   /* enable alternate function for PA3 */

    USART2->BRR = 0x008B;       /* 115200 baud @ 16 MHz */
    USART2->CR1 = 0x0004;       /* enable Rx, 8-bit data */
    USART2->CR2 = 0x0000;       /* 1 stop bit */
    USART2->CR3 = 0x0000;       /* no flow control */
    USART2->CR1 |= 0x2000;      /* enable USART2 */
}

/* Write a character to USART2 */
void USART2_write (int ch) {
    while (!(USART2->SR & 0x0080)) {}   // wait until Tx buffer empty
    USART2->DR = (ch & 0xFF);
}



/* Read a character from USART2 */
char USART2_read(void) {
    while (!(USART2->SR & 0x0020)) {}   // wait until char arrives
    return USART2->DR;
}

/* turn on or off the LEDs according to the value */



/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n) {
    int i;
    for (; n > 0; n--)
        for (i = 0; i < 3195; i++) ;
}
