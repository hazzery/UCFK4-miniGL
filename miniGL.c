/**
 *  @file   miniGL.c
 *  @author Harrison Parkes
 *  @date   23rd of October 2022
 *  @brief  Graphics library for matrix of single colour LEDs
*/

#include "miniGL.h"
#include "matrix_display.h"
#include <string.h>

#define BITMASK(x) (1 << (x))
#define ABS(x) (x < 0 ? -x : x)


/**
 * The display grid
 * Array of display columns
 * always index as grid[col][row]
 */
miniGL_pixel_value_t grid[MINIGL_WIDTH][MINIGL_HEIGHT];


/**
 * @brief Construct a `miniGL_pos` from a pair of ordinates.
 *
 * @param row row of pixel
 * @param col column of pixel
 * @return a `miniGL_pos` representing (col, row)
*/
static inline miniGL_pos_t miniGL_pos (const int8_t row, const int8_t col)
{
    return (miniGL_pos_t) {.row = row, .col = col};
}


/**
 * @brief Show bitmap on the display.
 *
 * @param bitmap bitmap to be shown on the display
 */
void miniGL_show_bitmap (const miniGL_bitmap_t bitmap)
{
    miniGL_clear();

    for (uint8_t row = 0; row < MINIGL_HEIGHT; row++) {
        for (uint8_t col = 0; col < MINIGL_WIDTH; col++) {
            grid[col][row] = (bool)(bitmap[col] & BITMASK(row));
        }
    }
}

/**
 * @brief Set the value of a single pixel
 *
 * @param pos position of pixel to set
 * @param pixel_value value to set pixel to
*/
void miniGL_set_pixel (const miniGL_pos_t pos, const miniGL_pixel_value_t pixel_value)
{
    grid[pos.col][pos.row] = pixel_value;
}


/**
 * @brief Draw a line on the display
 *
 * @param start_pos position of the beginning of the line
 * @param end_pos position of the end of the line
 * @param pixel_value value to set all pixels to
 */
void miniGL_draw_line (const miniGL_pos_t start_pos, const miniGL_pos_t end_pos, const miniGL_pixel_value_t pixel_value)
{
    //Uses Bresenham's line algorithm
    //Pseudo code found at:
    //https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#Algorithm_for_integer_arithmetic

    const int8_t dx = end_pos.col - start_pos.col;
    const int8_t dy = end_pos.row - start_pos.row;

    int8_t difference = (2 * dy) - dx;

    const int8_t col_increment = (dx < 0) ? -1 : 1;

    int8_t row = start_pos.row;
    for (int8_t col = start_pos.col; col < end_pos.col; col += col_increment) {
        grid[col][row] = pixel_value;
        if (difference > 0) {
            row += 1;
            difference -= 2 * dx;
        }
        difference += 2 * dy;
    }
}


/**
 * @brief Draw a box on the display
 *
 * @param top_left position of top left corner of box
 * @param bottom_right position of bottom right corner of box
 * @param fill `true` to fill in box, or `false` for just outline
 * @param pixel_value pixel value to draw box.  */
void miniGL_draw_box (const miniGL_pos_t top_left, const miniGL_pos_t bottom_right, const bool fill, const miniGL_pixel_value_t pixel_value)
{
    if (fill) {
        // Fill in every row of every column in box
        for (int8_t col = top_left.col; col <= bottom_right.col; col ++) {
            for (int8_t row = top_left.row; row <= bottom_right.row; row ++) {
                grid[col][row] = pixel_value;
            }
        }
    } else {
        // Set vertical sides of box
        for (int8_t row = top_left.row; row <= bottom_right.row; row ++) {
            grid[top_left.col][row] = pixel_value;
            grid[bottom_right.col][row] = pixel_value;
        }
        // Set horizontal sides of box
        for (int8_t col = top_left.col + 1; col < bottom_right.col; col ++) {
            grid[col][top_left.row] = pixel_value;
            grid[col][bottom_right.row] = pixel_value;
        }
    }
}


/**
 * @brief Turn off all pixels on the display
 */
void miniGL_clear (void)
{
    memset(grid, 0, MINIGL_WIDTH * MINIGL_HEIGHT);
}


/**
 * @brief Update pixels on the matrix display
 */
void miniGL_update (void)
{
    static uint8_t counter = 0;
    static uint8_t column = 0;

    int8_t column_states[MINIGL_HEIGHT] = {0};

    for (uint8_t row = 0; row < MINIGL_HEIGHT; row++) {
        column_states[row] = (ABS(grid[column][row]) > counter);
    }

    matrix_show_column(column, column_states);

    counter = (counter + 1) % 128;
    column = (column + 1) % MINIGL_WIDTH;
}


/**
 * @brief Initialise the display matrix
 */
void miniGL_init (void)
{
    matrix_init();
    miniGL_clear();
}