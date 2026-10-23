#include "bsp.h"
//tarea estructura
bsp_gpio_config_e_t salida{
	.
};


esp_err_t bsp_gpio_salida(int num){
	return gpio_salida(num);
}

esp_err_t bsp_gpio_entrada(int num, pull_type_e_t pull_type){
	return gpio_entrada(num, pull_type);
}
esp_err_t bsp_init_entrada(void){
	
}
esp_err_t bsp_init_salidas(void){
	
}