/* INTERSECT C FILE */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

static inline int cmp(const void *n0, const void *n1)
{
    const int *ia = (const int *)n0;
    const int *ib = (const int *)n1;
    return *ia  - *ib; 
}

#define INIT_0  ((unsigned int) 0x00000000)
#define INIT_1  ((unsigned int) 0x00000001)

int *intersect(int *nums0, int size0, int *nums1, int size1, int *ret_size)
{
    // int buf_0[size0];
    // int buf_1[size1];
    // for (unsigned int index = INIT_0; \
    //     index < size0; index++) buf_0[index] = *(nums0 + index);
    // for (unsigned int index = INIT_0; \
    //     index < size1; index++) buf_1[index] = *(nums1 + index);
    // qsort(buf_0, size0, sizeof(int), cmp);
    // qsort(buf_1, size1, sizeof(int), cmp);
    unsigned int index = INIT_0;
    unsigned int inside = INIT_0;
    unsigned int ret_count = INIT_0;
    unsigned int n_insde = INIT_0; /* means same as last index */
    int template_result[((size0 < size1) ? size0 : size1)];
    // for (; index < size0; index++) {
    //     inside = n_insde;
    //     while (inside < size1) {
    //         if (!(buf_0[index] ^ buf_1[inside])) {
    //             template_result[ret_count] = *(buf_0 + index);
    //             ret_count++;
    //             n_insde = (inside + 1);
    //             break;
    //         }
    //         inside++;
    //     }
    // }
    qsort(nums0, size0, sizeof(int), cmp);
    qsort(nums1, size1, sizeof(int), cmp);
    for (; index < size0; index++) {
        inside = n_insde;
        while (inside < size1) {
            if (!(nums0[index] ^ nums1[inside])) {
                template_result[ret_count] = *(nums0 + index);
                ret_count++;
                n_insde = (inside + 1);
                break;
            }
            inside++;
        }
    }
    *ret_size = ret_count;
    int *result = (int *) malloc(sizeof(int) * ret_count);
    for (index = 0; index < ret_count; index++)
        *(result + index) = template_result[index];
    return result;
}