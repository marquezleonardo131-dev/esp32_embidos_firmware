#ifndef BSP_H
#define BSP_H
#include "gpio_2026.h"

//DECLARACIONES DE CONSTANTES PARA HADWARE [PANTHER48]
#define LED2  2
#define LED4  4
#define LED5  5
#define LED16 16
#define LED17 17

typedef enum{LEDB =12, LEDG, LEDR}led_rgb_e_t;
typedef enum{BTN_IZQ =18, BTN_DER}boton_e_t;
typedef enum{LDR =39, NTC = 36}sensores_e_t;
typedef enum{SDA =21, SLA = 22}oled_e_t;

typedef void (*isr_gpio_t)(void * arg);

typedef struct{
	uint8_t timer;
	uint8_t frec;
	uint8_t resolution;
	uint8_t channel;
	union{ 
		uint8_t duty;
		uint8_t duty_percent;
	}pwm_value;
} pwm_t;

typedef struct{
	uint8_t 		pin;
	gpio_mode_e_t 	mode;
	pull_type_e_t 	pull_mode;
	uint8_t 		intr_type;
	bool 			inv_logic;
	uint8_t 		state;
	uint8_t 		state_old;	
	isr_gpio_t  	callback;
	pwm_t 			pwm;
}bsp_gpio_config_e_t;

// PROTOTIPOS (INTERFAZ DEL DRIVER)
extern esp_err_t bsp_init_salidas(void);	//extern es para dejarlo explicito de la funciones a 
extern esp_err_t bsp_init_entradas(void);
extern esp_err_t bsp_gpio_board(void);


extern esp_err_t bsp_gpio_salida(uint8_t num);	//extern es para dejarlo explicito de la funciones a 
extern esp_err_t bsp_gpio_entrada(uint8_t num, pull_type_e_t pull_type);
extern esp_err_t bsp_gpio_write(uint8_t num, bool state);
bool bsp_gpio_ready(uint8_t num);

#endif