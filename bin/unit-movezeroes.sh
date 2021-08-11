#!/bin/bash

declare readonly WORKING_DIR=$(pwd)
declare readonly USER_DIR=$HOME

cat <<EOF > /tmp/movezeroes.c
#include <stdio.h>
int main()
{
    int nums_0[7] = {1,2,0,0,2,0,1};
    return 0;
}
EOF

gcc -o /tmp/movezeroes /tmp/movezeroes.c $WORKING_DIR/movezeroes.c
if [ $? -eq 0 ]; then
    /tmp/movezeroes
fi

rm /tmp/movezeroes.c /tmp/movezeroes
