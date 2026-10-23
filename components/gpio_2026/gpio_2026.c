
#include "esp_err.h"
#include "esp_log.h"
#include "gpio_2026.h"
#include "gpio_config_2026.h"
#include "include/gpio_2026.h"

static const uint32_t IOMUX_ADDR[] =
{
    [0]  = 0x3FF49044,
    [1]  = 0x3FF49088,
    [2]  = 0x3FF49040,
    [3]  = 0x3FF49084,
    [4]  = 0x3FF49048,
    [5]  = 0x3FF4906C,
    [6]  = 0x3FF49060,
    [7]  = 0x3FF49064,
    [8]  = 0x3FF49068,
    [9]  = 0x3FF49054,
    [10] = 0x3FF49058,
    [11] = 0x3FF4905C,
    [12] = 0x3FF49034,
    [13] = 0x3FF49038,
    [14] = 0x3FF49030,
    [15] = 0x3FF4903C,
    [16] = 0x3FF4904C,
    [17] = 0x3FF49050,
    [18] = 0x3FF49070,
    [19] = 0x3FF49074,

    [21] = 0x3FF4907C,
    [22] = 0x3FF49080,
    [23] = 0x3FF4908C,

    [25] = 0x3FF49024,
    [26] = 0x3FF49028,
    [27] = 0x3FF4902C,

    [32] = 0x3FF4901C,
    [33] = 0x3FF49020,
    [34] = 0x3FF49014,
    [35] = 0x3FF49018,
    [36] = 0x3FF49004,
    [37] = 0x3FF49008,
    [38] = 0x3FF4900C,
    [39] = 0x3FF49010
};
 
static esp_err_t valid_pin(uint8_t num){
	const char* tag = "valid_pin";
	if(IS_GPIO(num)){
		return ESP_OK;
	}
	ESP_LOGE(tag, "Error: Gpio invalido");
	return ESP_ERR_INVALID_ARG;
}
static esp_err_t valid_gpio_out(uint8_t num){
	const char* tag = "valid_gpio_out";
	if(IS_GPIO(num)&&IS_ONLY_IN(num)){
		ESP_LOGE(tag, "Error: Gpio no puede ser salida");
		return ESP_ERR_INVALID_ARG;
	}
	return ESP_OK;
}
esp_err_t gpio_salida(uint8_t num){
	const char* tag = "gpio_salida";
	if(valid_gpio_out(num) != ESP_OK){
		ESP_LOGE(tag, "Error: Gpio no se pudo configurar como salida");
		return ESP_ERR_INVALID_ARG;
	}
	GPIO_ENABLE_W1TS = (_BIT(num));
	return ESP_OK;
}
esp_err_t gpio_entrada(uint8_t num, pull_type_e_t pull_type){
	const char* tag = "gpio_entrada";
	if(valid_pin(num) != ESP_OK)
		return ESP_ERR_INVALID_ARG;
	GPIO_ENABLE_W1TC = _BIT(num); // para deshabilitar la salida
	IOMUX_REG(num) |= FUN_IE;
	IOMUX_REG(num) |= MCU_SEL;
	if(pull_type == PULLUP)
		IOMUX_REG(num) |= FUN_WPU;
	if(pull_type == PULLDOWN)
		IOMUX_REG(num) |= FUN_WPD;
	return ESP_OK;
}

esp_err_t gpio_write(uint8_t num, bool state){
	if(state){
		GPIO_W1TS |= (_BIT(num));
		}else{
			GPIO_W1TC |= (_BIT(num));} 	
	return ESP_OK;
}

bool gpio_ready(uint8_t num ){
	if( ((GPIO_IN)>>num) & 0x01 ) return true;
 	return false;
}

