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
