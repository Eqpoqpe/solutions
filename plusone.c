/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int *plus_one(int* digits, int d_size, int* ret_size)
{
    /* [] [] []
     *        ^                                      
     *   if plus 1 gt than 9,                 [] [] []
     *    and then the pointer moves one step to ^
     *   if '0' plus 1 gt than 9, will be [1] [0] [] []
     *
     * Constraints: 0 <= digits[i] <= 9
     */

    /* 0 or 1 */
    unsigned int mov_s;
    for (unsigned int index = (d_size - 1); index > 0; index--) {
        if (!(*(digits + index) ^ 9) | 0) {
            *(digits + index) = 0;
            mov_s = 1;
        } else {
            if (!(mov_s ^ 1)) {
                *(digits + index) += 1;
                mov_s = 0;
            } else *(digits + index) += 1;
        }
    }
    if (!(mov_s ^ 0)) {
        if (!(*(digits + 0) ^ 9)) {
            *(digits + 0) = 0;
            int n_num = 1;
            *ret_size = (d_size + 1);
        } else *(digits + 0) += 1;
    }
}