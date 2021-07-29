#!/bin/bash

declare readonly WORKING_DIR=$(pwd)
declare readonly USER_DIR=$HOME

cat <<EOF > /tmp/unit-intersect.c
#include <stdio.h>
int main()
{
    int nums_0[4] = {1,2,2,1};
    int nums_1[2] = {2,2};
    unsigned int result_size;
    intersect(nums_0, 4, nums_1, 2, &result_size);
    printf("result: %d\n", result_size);
    return 0;
}
EOF

gcc -o /tmp/unit-intersect /tmp/unit-intersect.c $WORKING_DIR/intersect.c
if [ $? -eq 0 ]; then
    /tmp/unit-intersect
fi

rm /tmp/unit-intersect.c /tmp/unit-intersect