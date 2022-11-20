/**
 *  @file   matrix_display.c
 *  @author Harrison Parkes
 *  @date   25th of October 2022
 *  @brief  Driver code for matrix of single colour LEDs
*/

#include "matrix_display.h"
#include "../drivers/avr/pio.h"


/**
 * Array of PIO pins for matrix rows
 */
static const pio_t matrix_rows[] = {
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO,
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};


/**
 * Array of PIO pins for matrix columns
 */
static const pio_t matrix_cols[] = {
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

#define MATRIX_NUM_ROWS ARRAY_SIZE(matrix_rows)
#define MATRIX_NUM_COLS ARRAY_SIZE(matrix_cols)


/**
 * @brief Set all matrix PIO pins as outputs
 * and turns them all off
 */
void matrix_init(void)
{
    // Pins initialized to HIGH as they're active low
    for (uint8_t row = 0; row < MATRIX_NUM_ROWS; row++)
        pio_config_set (matrix_rows[row], PIO_OUTPUT_HIGH);

    for (uint8_t col = 0; col < MATRIX_NUM_COLS; col++)
        pio_config_set (matrix_cols[col], PIO_OUTPUT_HIGH);
}

/**
 * @brief Show single column on the matrix display
 *
 * @param column the column number to be shown
 * @param column_vals array of pixel values to shown on display column
 */
void matrix_show_column(const uint8_t column, const int8_t column_vals[MATRIX_NUM_ROWS])
{
    static uint8_t prev_column = 0;
    pio_output_high(matrix_cols[prev_column]);
    pio_output_high(matrix_cols[column]);

    for (uint8_t row = 0; row < MATRIX_NUM_ROWS; row++) {
        pio_output_set(matrix_rows[row], !(column_vals[row]));
    }

    pio_output_low(matrix_cols[column]);

    prev_column = column;
}

