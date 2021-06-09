#include <stdlib.h>
#include <dtools.h>
#include "solutions.h"

/* fsort()
 *
 * MIN_VALUE_TEMPLATE
 * MAX_VALUE_TEMPLATE
 *
 * [0] [1] [2] [4] [5]
 *
 * [0] -> [] => min value write it in index [0]
 */

int *fsort(arg_st nms)
{
	/* full sort */
	unsigned int index = 0;
	unsigned int inside;

	/* TODO remember free it the return data */
	int *result = (int *)malloc(sizeof(nms.nums));
	int template;
	for (; index < (nms.size - 1); index++) {
		inside = index + 1;
		for (; inside < nms.size; inside++) {
			// TODO del
			// printf("%d\t%d\n", index, inside);
			if (*(nms.nums + inside) < *(nms.nums + index)) {
				template = *(nms.nums + index);
				*(nms.nums + index) = *(nms.nums + inside);
				*(nms.nums + inside) = template;
			}
		}
	}
	result = nms.nums;
	return result;
}

void fsort_r(arg_st nms, int *result_arg)
{
	/* full sort */
	unsigned int index = 0;
	unsigned int inside;
	int template;
	for (; index < (nms.size - 1); index++) {
		inside = index + 1;
		for (; inside < nms.size; inside++) {
			if (*(nms.nums + inside) < *(nms.nums + index)) {
				template = *(nms.nums + index);
				*(nms.nums + index) = *(nms.nums + inside);
				*(nms.nums + inside) = template;
			}
		}
	}
	for (index = 0; index < nms.size; index++) {
		*(result_arg + index) = *(nms.nums + index);
	}
	return (void) NULL;
}

void single_nm(arg_st nms)
{
	// LOG(STR, (log) "Result is 21");
	return (void) 0;
}

/* half sort
 *
 * [0] [1] [2] [3] [4]
 *  =   =   =   =   =
 *  0   1   2   3   4
 *
 * size % 2 is NOT OK, so got the min/max value, at first.
 * Then ont and one cmp result for the min value.
 *
 * [0] [1] [2] [3]
 *  |___|   |___|
 *    |       |
 * [Min_n] [Min_m]  The Min_n [0,1], Min_m [2,3]
 *    |_______|        'cmp' cpkg_st min_n, min_m;
 *        |
 *      [Min]
 *
 * Sort Number => Ending, ok here, if Min_n is
 *
 * [Min_n] [Min_m] -> [0,1],[2,3],4
 */
void half_sort_r(arg_st nms, int *result_arg)
{
	if (!nms.size%2) {
		unsigned int index = 1;
		int min_val = *(nms.nums + index);
		for (; index < nms.size; index++) {
			if (*(nms.nums + index) < min_val) {
				min_val = *(nms.nums + index);
				// *&nms.size = nms.size - 1;
				*(&nms.size) = 5 - 1;
			}
		}
		unsigned int index = nms.size;
		unsigned int count = 0;
		int buf[nms.size];
		for (; index> 0; index--) {
			if ((*(nms.nums + index) == min_val) && \
					!(count | 0)) {
				count = 1;
				*(buf + index) = min_val;
			} else {
				*(buf + index) = *(nms.nums + index);
			}
	}
}

/* intersect, remember free it */
int *intersect(arg_st nms1, arg_st nms2)
{
	int *ret_result = (int *)malloc(sizeof(int) * \
			(nms1.size > nms2.size) ? \
			nms1.size : nms2.size);
}

void intersect_r(arg_st nms1, arg_st nms2, int *result)
{
}
