#ifndef SPIKEHW_H
#define SPIKEHW_H

#define PROMSTART 0x00000000
#define RAMSTART  0x00000800
#define RAMSIZE   0x400
#define RAMEND    (RAMSTART + RAMSIZE)

#define RAM_START 0x40000000
#define RAM_SIZE  0x04000000

#define FCPU      50000000

#define UART_RXBUFSIZE 32

// 32 Bit
typedef unsigned int  uint32_t;
typedef signed   int   int32_t;

// 8 Bit
typedef unsigned char  uint8_t;
typedef signed   char   int8_t;

void irq_enable();
void irq_disable();
void irq_mask();
void halt();
void jump(uint32_t addr);

void sleep();
void tic_init();

/***************************************************************************
 * GPIO0
 */
typedef struct {
	volatile uint32_t iport;
	volatile uint32_t oport;
} gpio_t;

/***************************************************************************
 * TIMER0
 */
#define TIMER_EN     0x08
#define TIMER_AR     0x04
#define TIMER_IRQEN  0x02
#define TIMER_TRIG   0x01

typedef struct {
	volatile uint32_t tcr0;
	volatile uint32_t compare0;
	volatile uint32_t counter0;
	volatile uint32_t tcr1;
	volatile uint32_t compare1;
	volatile uint32_t counter1;
} timer_t;

/***************************************************************************
 * UART0
 */
#define UART_DR   0x01                    // RX Data Ready
#define UART_ERR  0x02                    // RX Error
#define UART_BUSY 0x10                    // TX Busy

typedef struct {
   volatile uint32_t ucr;
   volatile uint32_t rxtx;
} uart_t;

/***************************************************************************
 * Spike peripheral components
 */
void uart_init();
void uart_putchar(char c);
void uart_putstr(char *str);
char uart_getchar();

extern timer_t  *timer0;
extern uart_t   *uart0; 
extern gpio_t   *gpio0; 
extern uint32_t *sram0; 

#endif // SPIKEHW_H
