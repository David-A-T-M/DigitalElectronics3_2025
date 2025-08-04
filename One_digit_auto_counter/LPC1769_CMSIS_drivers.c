/**
* @file LPC1769_registers.c
 * @brief Controls a 7-segment display using GPIO pins on the LPC1769 board.
 *
 * This program configures GPIO pins P2.0-P2.6 to drive a 7-segment display.
 * It cycles through hexadecimal digits (0-F) by updating the display in a loop.
 * The display segments are controlled via driver functions from the LPC17xx library.
 */
#include "LPC17xx.h"
#include "LPC17xx_gpio.h"
#include "LPC17xx_pinsel.h"

/**
 * @def DELAY
 * @brief Delay constant for LED timing.
 */
#define DELAY 2500

/**
 * @brief Configures GPIO pins P2.0-P2.6 as outputs to control a 7-segment display.
 *
 * Sets the pin function to GPIO and sets the direction to output.
 * Turns off all segments initially.
 */
void configGPIO(void);

/**
 * @brief Generates a blocking delay using nested loops.
 */
void delay();

int main(void) {
    configGPIO();

    uint32_t i = 0;
    const uint32_t digits[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
                                 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

    // Optional: set mask to avoid modifying other bits in GPIO port
    GPIO_SetMask(GPIO_PORT_2, 0xFFFFFF80, ENABLE);

    while (1) {
        GPIO_WriteValue(GPIO_PORT_2, digits[i % 16]);
        // Alternatively: for atomic operations
        /*
        GPIO_ClearValue(GPIO_PORT_2, 0x7F);             // Turns off all segments.
        GPIO_SetValue(GPIO_PORT_2, digits[i % 16]);     // Sets the segments for the current digit.
        */
        i++;
        delay();
    }
    return 0;
}

void configGPIO(void) {
    PINSEL_CFG_Type pinCfg = {0};
    pinCfg.portNum = PINSEL_PORT_2;
    pinCfg.pinNum = PINSEL_PIN_0;
    pinCfg.funcNum = PINSEL_FUNC_0;
    pinCfg.pinMode = PINSEL_PINMODE_TRISTATE;
    pinCfg.openDrain = PINSEL_OD_MODE_NORMAL;

    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.0 as GPIO.

    pinCfg.pinNum = PINSEL_PIN_1;
    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.1 as GPIO.

    pinCfg.pinNum = PINSEL_PIN_2;
    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.2 as GPIO.

    pinCfg.pinNum = PINSEL_PIN_3;
    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.3 as GPIO.

    pinCfg.pinNum = PINSEL_PIN_4;
    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.4 as GPIO.

    pinCfg.pinNum = PINSEL_PIN_5;
    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.5 as GPIO.

    pinCfg.pinNum = PINSEL_PIN_6;
    PINSEL_ConfigPin(&pinCfg);                  // Configure P2.6 as GPIO.

    // Alternatively: configure multiple pins at once.
    /*
    PINSEL_ConfigMultiplePins(&pinCfg, 0x7F);   // Configures P2.0-P2.6 as GPIO.
    */

    GPIO_SetDir(GPIO_PORT_2, 0x7F, OUTPUT);  // Set P2.0 to P2.6 as output.

    GPIO_ClearValue(GPIO_PORT_2, 0x7F);
}

void delay() {
    for (uint32_t i = 0; i < DELAY; i++)
        for (uint32_t j = 0; j < DELAY; j++);
}
