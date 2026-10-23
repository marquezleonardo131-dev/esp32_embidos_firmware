#ifndef GPIO_2026_H
#define GPIO_2026_H

#include "esp_err.h"
#include "esp_log.h"
#include <stdbool.h>
#include <stdint.h>


// Definición de los Enums
typedef enum{ NONE_PULL, PULLUP, PULLDOWN} pull_type_e_t; 		// se coloca porque se usa 
typedef enum{ INPUT, OUTPUT, OUTPWM} gpio_mode_e_t; 			// se coloca porque se usa 

// Prototipos de funciones 
extern esp_err_t gpio_salida(uint8_t num);						//extern es para dejarlo explicito de la funciones a 
extern esp_err_t gpio_entrada(uint8_t num, pull_type_e_t pull_type);
extern esp_err_t gpio_write(uint8_t num, bool state);
bool gpio_ready(uint8_t num);

#endif