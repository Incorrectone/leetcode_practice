#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "solution.h"

void test_leetcode_case1() {
    printf("Running LeetCode Case 1 Test... ");

    int nums[] = {1, 2, 3, 4};
    int * returnSize = malloc(sizeof(int));

    int * return_arr = productExceptSelf(nums, 4, returnSize);

    assert(*returnSize == 4);
    assert(return_arr[0] == 24);
    assert(return_arr[1] == 12);
    assert(return_arr[2] == 8);
    assert(return_arr[3] == 6);

    free(return_arr);
    free(returnSize);

    printf("PASSED\n");
}

void test_leetcode_case2() {
    printf("Running LeetCode Case 2 Test... ");

    int nums[] = {-1, 1, 0, -3, 3};
    int * returnSize = malloc(sizeof(int));

    int * return_arr = productExceptSelf(nums, 5, returnSize);

    assert(*returnSize == 5);
    assert(return_arr[0] == 0);
    assert(return_arr[1] == 0);
    assert(return_arr[2] == 9);
    assert(return_arr[3] == 0);
    assert(return_arr[4] == 0);

    free(return_arr);
    free(returnSize);

    printf("PASSED\n");
}

int main() {
    test_leetcode_case1();
    test_leetcode_case2();
    return 0;
}