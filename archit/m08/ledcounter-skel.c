/*
  References:
  AM335x ARM Cortex-A8 Microprocessors Technical Reference Manual rev.O, spruh73o, September 2016 ("TRM")
  AM335x Sitara Processors Datasheet rev.J, sprs717j, April 2016 ("DS")

  The BeagleBone has 4 LEDs, connected to GPIO

  This program will show binary counting on the LEDs

 */

#include "soc_AM335x.h"
#include "beaglebone.h"
#include "gpio_v2.h"

static void Delay(unsigned int count);

#define LED_BASE 21
#define CM_PER_GPIO1_CLKCTRL *((volatile unsigned int *)
#define CM_PER_L4LS_CLKSTCTRL 
#define CONF_GPMC_A(n) 
#define GPIO1_CTRL  
#define GPIO1_OE  
#define GPIO1_SYSCONFIG  
#define GPIO1_SYSSTATUS  
#define GPIO1_CLEARDATAOUT  
#define GPIO1_SETDATAOUT  

int main()
{
  /* Enabling functional clocks for GPIO1 instance. */
  // TRM p.1237
  CM_PER_GPIO1_CLKCTRL
  // wait for it to settle
  while ( (CM_PER_GPIO1_CLKCTRL
    ;
  // OPTFCLKEN... enable optional functional clock p.583
  CM_PER_GPIO1_CLKCTRL
  // wait for it to settle
  while ( (CM_PER_GPIO1_CLKCTRL
    ;
  
  // IDLEST: wait for the module to become fully functional
  while ( (CM_PER_GPIO1_CLKCTRL
    ;
  
  // wait for the GPIO1GDBCLK clock to become active
  while ( (CM_PER_L4LS_CLKSTCTRL
    ;
  
	   /*
     in CONTROL_MODULE, lowercase named
     TRM p.1468 conf_gpmc_a{5,6,7,8}
     DS p.24
  */
  CONF_GPMC_A(
  CONF_GPMC_A(
  CONF_GPMC_A(
  CONF_GPMC_A(

  /* Enabling the GPIO module. */
  // GPIOModuleEnable(GPIO_INSTANCE_ADDRESS);
  GPIO1_CTRL
  
  
  /* Resetting the GPIO module. */
  // GPIOModuleReset(GPIO_INSTANCE_ADDRESS);
  // TRM p.4927, SOFTRESET the GPIO1 module
  GPIO1_SYSCONFIG
  // TRM p.4939, wait for the softreset to complete by reading the SYSSTATUS register
  while ( !(GPIO1_SYSSTATUS
    ;

  /* Setting the GPIO pin as an output pin. */
  //GPIODirModeSet(GPIO_INSTANCE_ADDRESS, GPIO_INSTANCE_PIN_NUMBER, GPIO_DIR_OUTPUT);
  while (1)
    {
    }
} 

/*
** A function which is used to generate a delay.
*/
static void Delay(volatile unsigned int count)
{
    while(count--);
}


/******************************* End of file *********************************/
