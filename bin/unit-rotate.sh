#!/bin/bash

declare readonly WORKING_DIR=$(pwd)
declare readonly USER_DIR=$HOME

cat <<EOF > /tmp/unit-rotate.c
#include <stdio.h>
int main()
{
    int nums[5] = {3,2,5,0,7};
    printf("Original: %d\n", nums[0]);
    naive_rotate(nums, 5, 100);
    printf("Result: %d\n", nums[0]);
    return 0;
}
EOF

gcc -o /tmp/rotate /tmp/unit-rotate.c $WORKING_DIR/rotate.c
if [ $? -eq 0 ]; then
    /tmp/rotate
fi

rm /tmp/unit-rotate.c /tmp/rotate
