
//============================================================================//
//            G L O B A L   D E F I N I T I O N S                             //
//============================================================================//
#include "osObjects.h"                      // RTOS object definitions

#include "led.h"
#include "system.h"
//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// module global vars
//------------------------------------------------------------------------------
stm32LED	*LED_run;
stm32LED	*LED_com;

//------------------------------------------------------------------------------
// global function prototypes
//------------------------------------------------------------------------------

//============================================================================//
//            P R I V A T E   D E F I N I T I O N S                           //
//============================================================================//

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// local types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// local vars
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
static int init_led(  stm32LED *self, gpio_pins *pin);
static void blink( stm32LED *self);
static void led_destory( stm32LED *self);
static void Turnon( stm32LED *self);
static void Turnoff( stm32LED *self);
static void test( stm32LED *self);



//============================================================================//
//            P U B L I C   F U N C T I O N S                                 //
//============================================================================//


CTOR(stm32LED)
FUNCTION_SETTING(init, init_led);
FUNCTION_SETTING(blink, blink);
FUNCTION_SETTING(destory, led_destory);

FUNCTION_SETTING(turnon, Turnon);
FUNCTION_SETTING(turnoff, Turnoff);

FUNCTION_SETTING(test, test);
END_CTOR
//=========================================================================//
//                                                                         //
//          P R I V A T E   D E F I N I T I O N S                          //
//                                                                         //
//=========================================================================//
/// \name Private Functions
/// \{




static int init_led(  stm32LED *self, gpio_pins *pin)
{
	
	self->pin = pin;
	//���
	GPIO_SetBits( self->pin->Port, self->pin->pin);
	self->led_status = LED_OFF;
	return 0;

}


static void blink( stm32LED *self)
{
	if( self->led_status == LED_OFF)
	{
		self->led_status = LED_ON;
		GPIO_ResetBits( self->pin->Port, self->pin->pin);
	}
	else if( self->led_status == LED_ON)
	{
		
		self->led_status = LED_OFF;
		GPIO_SetBits( self->pin->Port, self->pin->pin);
	}
	
}

static void led_destory( stm32LED *self)
{
	
		
	self->led_status = LED_DIE;
	GPIO_SetBits( self->pin->Port, self->pin->pin);
	
	
}
static void Turnon( stm32LED *self)
{
	
		
	self->led_status = LED_ON;
	GPIO_ResetBits( self->pin->Port, self->pin->pin);
	
	
}

static void Turnoff( stm32LED *self)
{
	
		
	self->led_status = LED_OFF;
	GPIO_SetBits( self->pin->Port, self->pin->pin);
	
	
}

static void test( stm32LED *self)
{
	int i = 0;
	while(1)
	{
		
		i ++;
		osDelay(1000);
		self->blink( self);
		if( i > 15)
			break;
		
	}
	
}





