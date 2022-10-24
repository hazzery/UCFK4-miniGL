/**
 *  @file   matrix_display.h
 *  @author Harrison Parkes
 *  @date   25th of October 2022
 *  @brief  Driver code for matrix of single colour LEDs
*/

#ifndef MATRIX_DISPLAY_H
#define MATRIX_DISPLAY_H

#include <stdint.h>

/**
 * @brief Set all matrix PIO pins as outputs
 * and turns them all off
 */
void matrix_init();


/**
 * @brief Show single column on the matrix display
 *
 * @param column the column number to be shown
 * @param column_vals array of pixel values to shown on display column
 */
void matrix_show_column(uint8_t column, int8_t column_vals[]);

#endif //MATRIX_DISPLAY_H