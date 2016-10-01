#ifndef __HARDWARECONFIG_H__
#define __HARDWARECONFIG_H__
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"


#define	GPRS_COM			3			///< gprsģ��ʹ�õĴ��ں�	
#define	DEBUG_COM			1
#define GPRS_USART_RXBUF_SIZE		256


#if GPRS_COM == 3
#define GPRS_USART	USART3
#elif GPRS_COM == 1
#define GPRS_USART	USART1
#endif

#if DEBUG_COM == 3
#define DEBUG_USART	USART3
#elif DEBUG_COM == 1
#define DEBUG_USART	USART1
#endif



typedef struct 
{
	GPIO_TypeDef	*Port;
	uint16_t		pin;
}gpio_pins;




typedef struct 
{
	
	DMA_Channel_TypeDef		*dma_tx_base;
	uint32_t				dma_tx_flag;
	int 					dma_tx_irq;
	
	DMA_Channel_TypeDef		*dma_rx_base;
	uint32_t				dma_rx_flag;
	int 					dma_rx_irq;
	

}Dma_source;


extern gpio_pins	Gprs_powerkey;





extern USART_InitTypeDef USART_InitStructure;
extern USART_InitTypeDef Conf_GprsUsart;
extern Dma_source DMA_gprs_usart;
extern char Gprs_usart_txbuf[64];
extern char Gprs_usart_rxbuf[GPRS_USART_RXBUF_SIZE];

#endif