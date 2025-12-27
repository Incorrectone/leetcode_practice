#include <stdio.h>
#include <assert.h>

#include "solution.h"

void test_leetcode_case1() {
    printf("Running LeetCode Case 1 Test... ");

    int ratings[] = {1, 0, 2};
    
    int result = candy(ratings, 3);

    assert(result == 5);

    printf("PASSED\n");
}

void test_leetcode_case2() {
    printf("Running LeetCode Case 2 Test... ");

    int ratings[] = {1, 2, 2};
    
    int result = candy(ratings, 3);

    assert(result == 4);

    printf("PASSED\n");
}

int main() {
    test_leetcode_case1();
    test_leetcode_case2();
    return 0;
}