#ifndef SOLUTIONS_H
#define SOLUTIONS_H

typedef struct arg_t arg_st;

struct arg_t {
        int *nums;
        const int nm_n;
        const int nm_m;
        const int size;
};

void *fsort(arg_st);
void fsort_r(arg_st, int *);
void single_nm(arg_st);
void half_sort_r(arg_st, int *);
int *intersect(arg_st, arg_st);
void intersect(arg_st, arg_st, int *);

#define INIT (int) 0
#define NINI (int) 1

#endif
