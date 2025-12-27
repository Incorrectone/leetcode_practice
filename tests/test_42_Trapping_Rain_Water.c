#include <stdio.h>
#include <assert.h>

#include "solution.h"

void test_leetcode_case1() {
    printf("Running LeetCode Case 1 Test... ");

    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    int result = trap(height, 12);

    assert(result == 6);

    printf("PASSED\n");
}

void test_leetcode_case2() {
    printf("Running LeetCode Case 2 Test... ");

    int height[] = {4, 2, 0, 3, 2, 5};

    int result = trap(height, 6);

    assert(result == 9);

    printf("PASSED\n");
}

int main() {
    test_leetcode_case1();
    test_leetcode_case2();
    return 0;
}