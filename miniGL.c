/**
 *  @file   miniGL.c
 *  @author Harrison Parkes
 *  @date   23rd of October 2022
 *  @brief  Graphics library for matrix of single colour LEDs
*/

#include "miniGL.h"

#define BITMASK(x) (1 << (x))


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
static inline miniGL_pos_t miniGL_pos (int8_t row, int8_t col)
{
    return (miniGL_pos_t) {.row = row, .col = col};
}


/**
 * @brief Show bitmap on the display.
 *
 * @param bitmap bitmap to be shown on the display
 */
void miniGL_show_bitmap (miniGL_bitmap_t bitmap)
{

}

/**
 * @brief Set the value of a single pixel
 *
 * @param pos position of pixel to set
 * @param pixel_value value to set pixel to
*/
void miniGL_set_pixel (miniGL_pos_t pos, miniGL_pixel_value_t pixel_value)
{

}


/**
 * @brief Draw a line on the display
 *
 * @param start_pos position of the beginning of the line
 * @param end_pos position of the end of the line
 * @param pixel_value value to set all pixels to
 */
void miniGL_draw_line (miniGL_pos_t start_pos, miniGL_pos_t end_pos, miniGL_pixel_value_t pixel_value)
{

}


/**
 * @brief Draw a box on the display
 *
 * @param top_left position of top left corner of box
 * @param bottom_right position of bottom right corner of box
 * @param fill `true` to fill in box, or `false` for just outline
 * @param pixel_value pixel value to draw box.  */
void miniGL_draw_box (miniGL_pos_t top_left, miniGL_pos_t bottom_right, bool fill, miniGL_pixel_value_t pixel_value)
{

}


/**
 * @brief Turn off all pixels on the display
 */
void miniGL_clear (void)
{

}


/**
 * @brief Update pixels on the matrix display
 */
void miniGL_update (void)
{

}


/**
 * @brief Initialise the display matrix
 */
void miniGL_init (uint16_t frequency)
{

}