#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "solution.h"

void test_leetcode_case1() {
    printf("Running LeetCode Case 1 Test... ");

    char *operations[] = {"--X", "X++", "X++"};
    int result = finalValueAfterOperations(operations, 3);

    assert(result == 1);

    printf("PASSED\n");
}

void test_leetcode_case2() {
    printf("Running LeetCode Case 2 Test... ");

    char *operations[] = {"++X", "++X", "X++"};
    int result = finalValueAfterOperations(operations, 3);

    assert(result == 3);

    printf("PASSED\n");
}

void test_leetcode_case3() {
    printf("Running LeetCode Case 3 Test... ");

    char *operations[] = {"X++", "++X", "--X", "X--"};
    int result = finalValueAfterOperations(operations, 4);

    assert(result == 0);

    printf("PASSED\n");
}

int main() {
    test_leetcode_case1();
    test_leetcode_case2();
    test_leetcode_case3();
    return 0;
}