#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio_2026.h"
/*********************************************************************
* Esta Version es para inciar con el manejo de registros con MACROS
*/

#define BOTON_IZQ   18
#define BOTON_DER   19
#define LED2   2
#define LED4  4


// FUNCION PRINCIPAL
void app_main(void)
{
 
 GPIO_OUT &= ~(0x04);  //gpio_out "ponemos en bajo el bit1 "
 
 GPIO_ENABLE_W1TC  |= _BIT(BOTON_IZQ); //gpio_enable_w1tc Para asegurar que no sea salida
 IOMUX_GPIO18   |= (MCU_SEL|FUN_IE|FUN_WPU); // iomux_gpio18 Para configurar como entrada con pullup
 GPIO_ENABLE_W1TC  |= _BIT(BOTON_DER); //gpio_enable_w1tc Para asegurar que no sea salida
 IOMUX_GPIO19   |= (MCU_SEL|FUN_IE|FUN_WPU); //iomux_gpio19 Para configurar como entrada con pullup 
 
 uint8_t state_old_boton_izq  = true;
 uint8_t state_boton_izq   = true;
 uint8_t state_old_boton_der  = true;
 uint8_t state_boton_der   = true;
 
 // CODIGO DE APLICACION
 while(true){
  state_boton_izq = (((GPIO_IN)>>BOTON_IZQ)&0x01);  //gpio_in

  if((!state_boton_izq)&&state_old_boton_izq){
    GPIO_W1TS |= (_BIT(LED2))|(_BIT(LED4)); //w1ts  LED 2 y 4
   printf("Led Encendido\n");   
  }
  
  state_boton_der = (((GPIO_IN)>>BOTON_DER)&0x01); //gpio_in  
  if(!(state_boton_der)&&state_old_boton_der){
    GPIO_W1TC |= (_BIT(LED2))|(_BIT(LED4)); //w1tc LED 2 y 4
   printf("Led Apagado\n");   
  }
  state_old_boton_izq = state_boton_izq;
  state_old_boton_der = state_boton_der;
  vTaskDelay(pdMS_TO_TICKS(10));  

 }
}