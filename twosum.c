static inline int cmp(const void *n0, const void *n1)
{
    return (*(int *) n0 - *(int *) n1);
}

int* two_sum(int* nums, int size, int target, int* ret_size)
{
    unsigned int index = 0;
    unsigned int ts_size;
    unsigned int l_index;
    int temp_sav[size];
    qsort(nums, size, sizeof(int), cmp);

    /* malloc */
    int *_result = (int *) malloc(sizeof(int) * 2);
    *ret_size = 2;

    /* [] [] [] [] [] [] [] []
     *  |____________________|
     *      if not ok, and gt than target number, remove it from temp_sav
     */
    for (; index < size; index++) {
        if (*(nums + index) < target)
            temp_sav[index] = *(nums + index);
    }
    index = 0;
    ts_size = sizeof(temp_sav) / sizeof(int);
    for (; index < ts_size; index++) {
        for (l_index = (ts_size - 1); l_index >= 0; l_index--) {
            if ((int) *(nums + index) + temp_sav[l_index] == target) {
                *(_result + 0) = index;
                *(_result + 1) = l_index;
                return _result;
            } else if (*(nums + index) + temp_sav[l_index] > target) {
                l_index--;
            }
        }
    }
}
