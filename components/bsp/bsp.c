#include "bsp.h"

// tarea estructura
bsp_gpio_config_e_t salida = {
	.pin = LED2,
	// aquí van los demás campos que necesites, como .campo = valor,
};

esp_err_t bsp_gpio_salida(uint8_t num){
	return gpio_salida(num);
}

esp_err_t bsp_gpio_entrada(uint8_t num, pull_type_e_t pull_type){
	return gpio_entrada(num, pull_type);
}

esp_err_t bsp_init_entradas(void){
	return ESP_OK;
}

esp_err_t bsp_init_salidas(void){
	return ESP_OK;
}