#include <stdio.h>
#include <stdlib.h>
//#include "solutions.h"

#ifndef SOLUTIONS_H
#define SOLUTIONS_H

typedef struct arg_t arg_st;

struct arg_t {
        int *nums;
        const int nm_n;
        const int nm_m;
        const int size;
};

struct node_t {
	int *nums;
};

int *naive_fsort(arg_st);
void naive_fsort_r(arg_st, int **);

#define INIT (int) 0
#define NINI (int) 1

#endif

int *naive_fsort(arg_st nms)
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

// void naive_fsort_r(arg_st nms, int **result_arg)
void naive_fsort_r(int *nms, int siz, int **result_arg)
{
	/* full sort */
	unsigned int index = 0;
	unsigned int inside;
	int template;
	for (; index < (siz - 1); index++) {
		inside = index + 1;
		for (; inside < siz; inside++) {
			if (*(nms + inside) < *(nms + index)) {
				template = *(nms + index);
				*(nms + index) = *(nms + inside);
				*(nms + inside) = template;
			}
		}
	}
	for (index = 0; index < siz; index++) {
		*(*result_arg + index) = *(nms + index);
	}
	return (void) NULL;
}
