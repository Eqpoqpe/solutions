/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define LOG()   ({ \
    printf("DONE\n"); \
    })

static inline int cmp(const void *n0, const void *n1)
{
    return (*(int *) n0 - *(int *) n1);
}

int* intersect(int* nums1, int sizen1, int* nums2, int sizen2, int* ret_size)
{
    unsigned int index = 0;
    unsigned int inside = 0;
    unsigned int n_index = 0;    // next
    unsigned int b_index = 0;    // for buf index
    unsigned int count_size = 0; // for malloc
    int buf[10];
    qsort(nums1, sizen1, sizeof(int), cmp);
    qsort(nums2, sizen2, sizeof(int), cmp);
    for (; index < sizen1; index++) {
        inside = n_index;
        while (inside < sizen2) {
            if (!((*(nums1 + index) ^ *(nums2 + n_index)) | 0)) {
                *(buf + b_index) = *(nums1 + index);
                count_size++;
                b_index++;
                n_index++;
                break;
            }
	        inside++;
        }
    }
    *ret_size = count_size;
    int *result = (int *) malloc(sizeof(int) * count_size);
    for (index = 0; index < count_size; index++) {
        *(result + index) = buf[index];
    }
    return result;
}

int main()
{
	int nums0[5] = {1,2,2,1,3};
	int nums1[3] = {2,2,3};

    /* 1 1 2 2
     * 2 2
     */
	int ret_size;
    int *result;
	result = intersect(nums0, 5, nums1, 3, &ret_size);
	printf("%d\n", ret_size);
    // printf("%d\t%d\n", *(result + 0), *(result + 1));
	return 0;
}
