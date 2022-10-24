/**
 *  @file   miniGL.h
 *  @author Harrison Parkes
 *  @date   23rd of October 2022
 *  @brief  Graphics library for matrix of single colour LEDs
*/


#ifndef MINIGL_H
#define MINIGL_H

#include <stdint.h>
#include <stdbool.h>

#define MINIGL_WIDTH 5
#define MINIGL_HEIGHT 7


typedef int8_t miniGL_pixel_value_t;

/**
 * Define a position as a coordinate on the display.
 * The display origin is the top left corner.
 */
typedef struct miniGL_pos_s
{
    int8_t col;
    int8_t row;
} miniGL_pos_t;


/**
 * @brief Draw character on the display.
 *
 * @param character character to show on the display
 */
void miniGL_draw_char (char character);


/**
 * @brief Set the value of a single pixel
 *
 * @param pos position of pixel to set
 * @param pixel_value value to set pixel to
*/
void miniGL_set_pixel (miniGL_pos_t pos, miniGL_pixel_value_t pixel_value);


/**
 * @brief Draw a line on the display
 *
 * @param start_pos position of the beginning of the line
 * @param end_pos position of the end of the line
 * @param pixel_value value to set all pixels to
 */
void miniGL_draw_line (miniGL_pos_t start_pos, miniGL_pos_t end_pos, miniGL_pixel_value_t pixel_value);


/**
 * @brief Draw a box on the display
 *
 * @param top_left position of top left corner of box
 * @param bottom_right position of bottom right corner of box
 * @param fill `true` to fill in box, or `false` for just outline
 * @param pixel_value pixel value to draw box.  */
void miniGL_draw_box (miniGL_pos_t top_left, miniGL_pos_t bottom_right, bool fill, miniGL_pixel_value_t pixel_value);


/**
 * @brief Turn off all pixels on the display
 */
void miniGL_clear (void);


/**
 * @brief Update pixels on the matrix display
 */
void miniGL_update (void);


/**
 * @brief Initialise the display matrix
 */
void miniGL_init (uint16_t frequency);

#endif // MINIGL_H