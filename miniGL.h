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
typedef uint8_t miniGL_bitmap_t[MINIGL_WIDTH];

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
 * @brief Show bitmap on the display.
 *
 * @param bitmap bitmap to be shown on the display
 */
extern void miniGL_show_bitmap (const miniGL_bitmap_t bitmap);


/**
 * @brief Set the value of a single pixel
 *
 * @param pos position of pixel to set
 * @param pixel_value value to set pixel to
*/
extern void miniGL_set_pixel (const miniGL_pos_t pos, const miniGL_pixel_value_t pixel_value);


/**
 * @brief Draw a line on the display
 *
 * @param start_pos position of the beginning of the line
 * @param end_pos position of the end of the line
 * @param pixel_value value to set all pixels to
 */
extern void miniGL_draw_line (const miniGL_pos_t start_pos, const miniGL_pos_t end_pos, const miniGL_pixel_value_t pixel_value);


/**
 * @brief Draw a box on the display
 *
 * @param top_left position of top left corner of box
 * @param bottom_right position of bottom right corner of box
 * @param fill `true` to fill in box, or `false` for just outline
 * @param pixel_value pixel value to draw box.  */
extern void miniGL_draw_box (const miniGL_pos_t top_left, const miniGL_pos_t bottom_right, const bool fill, const miniGL_pixel_value_t pixel_value);


/**
 * @brief Turn off all pixels on the display
 */
extern void miniGL_clear (void);


/**
 * @brief Update pixels on the matrix display
 */
extern void miniGL_update (void);


/**
 * @brief Initialise the display matrix
 */
extern void miniGL_init (void);

#endif // MINIGL_H