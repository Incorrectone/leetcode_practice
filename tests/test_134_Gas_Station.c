#include <stdio.h>
#include <assert.h>

#include "solution.h"

void test_leetcode_case1() {
    printf("Running LeetCode Case 1 Test... ");

    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    
    int result = canCompleteCircuit(gas, 5, cost, 5);

    assert(result == 3);

    printf("PASSED\n");
}

void test_leetcode_case2() {
    printf("Running LeetCode Case 2 Test... ");

    int gas[] = {2, 3, 4};
    int cost[] = {3, 4, 3};

    int result = canCompleteCircuit(gas, 3, cost, 3);

    assert(result == -1);

    printf("PASSED\n");
}

int main() {
    test_leetcode_case1();
    test_leetcode_case2();
    return 0;
}