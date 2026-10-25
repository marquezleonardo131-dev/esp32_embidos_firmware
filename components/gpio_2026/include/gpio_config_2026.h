/*************************************************************************
* @subject:   SOFTWARE EMBEBIDO
* @filename:   gpio_config_2026.c
* @project:   Workshop_driver_GpioAg2026
* @dependencies: 
* @processor:       ESP32
* @board:           PANTHER48
* @program_version: esp-idf v5.3.1
* @company:         TecNM /IT Chihuahua
* @description:     DEFIICION DE MACROS A REGISTROS
* @authors:         ALFREDO CHACON
* @brief:
* @created_on: 29 sept. 2026
* @updated_on:
*/
/**************************************************************************
 * * Copyright (C) 2026 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en 
 * formato fuente o binario siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/

#ifndef GPIO_CONFIG_2026_H
#define GPIO_CONFIG_2026_H

// REGISTROS
#define GPIO_OUT            (*((volatile uint32_t*)(0x3FF44004)))
#define GPIO_W1TS           (*((volatile uint32_t*)(0x3FF44008)))
#define GPIO_W1TC           (*((volatile uint32_t*)(0x3FF4400C)))
#define GPIO_ENABLE_W1TS    (*((volatile uint32_t*)(0x3FF44024)))
#define GPIO_ENABLE_W1TC    (*((volatile uint32_t*)(0x3FF44028)))
#define IOMUX_GPIO18        (*((volatile uint32_t*)(0x3FF49070)))
#define IOMUX_GPIO19        (*((volatile uint32_t*)(0x3FF49074)))
#define GPIO_IN             (*((volatile uint32_t*)(0x3FF4403C)))
#define HWREG32(ADDR)       (*((volatile uint32_t *)(ADDR)))
#define IOMUX_REG(NUM)      HWREG32(IOMUX_ADDR[NUM])
// MASCARAS DE BITS
#define FUN_WPD  (1UL<<7)
#define FUN_WPU  (1UL<<8)
#define FUN_IE   (1UL<<9)
#define MCU_SEL  (1UL<<13)
#define _BIT(X)  (1UL<<X)
// MACROSFUNCIONES
#define IS_IN_RANGE(VAL, MIN, MAX)  ((MIN <= VAL) && (VAL <= MAX))

#define IS_GPIO(NUM)   (((NUM) <= 19)   || (IS_IN_RANGE((NUM), 21, 23)) \
          || IS_IN_RANGE((NUM), 25, 27) \
          || IS_IN_RANGE((NUM), 32, 39))
      
#define IS_ONLY_IN(NUM)       ( IS_IN_RANGE(NUM,34,39) )
#endif