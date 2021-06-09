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
