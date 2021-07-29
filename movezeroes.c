static inline int cmp(const void *n0, const void *n1)
{
    int arg1 = *(const int*) n0;
    int arg2 = *(const int*) n1;
 
    if (n0 < n1) return -1;
    if (n0 > n1) return 1;
    return 0;
}

void move_zeroes(int* nums, int size)
{
    int buf[size];
    for (int index = 0; index < size; index++)
        buf[index] = *(nums + index);
    unsigned int z_count = 0;
    qsort(buf, size, sizeof(int), cmp);
    unsigned int m_size = 0;
    for (int index = 0; index < size; index++) {
        if (!(*(nums + index) ^ 0))
            m_size++;
        else {
            *(nums + (index - m_size)) = *(nums + index);
        }
    }
    for (; m_size > 0; m_size--) {
        *(nums + ((size) - m_size)) = 0;
    }
}
