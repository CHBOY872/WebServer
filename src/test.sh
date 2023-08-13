#!/bin/bash

TEST=""
RES=""

for i in $(find . -name "test.cpp")
do
    TEST=${i%/*}
    g++ $TEST/*.cpp -Wall -g -o $TEST/test
    $TEST/test
    RES=$?
    if [ $RES -eq "0" ]
    then
        echo "SUCCESS test in $TEST" && rm $TEST/test
    else
        echo "FAILED test in $TEST. RESULT $RES"
    fi
done

for i in $(find . -name "test.c")
do
    TEST=${i%/*}
    g++ $TEST/*.cpp -Wall -g -o $TEST/test
    $TEST/test
    RES=$?
    if [ $RES -eq "0" ]
    then
        echo "SUCCESS test in $TEST" && rm $TEST/test
    else
        echo "FAILED test in $TEST. RESULT $RES"
    fi
done