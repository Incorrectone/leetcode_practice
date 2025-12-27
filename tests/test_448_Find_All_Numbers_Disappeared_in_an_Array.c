#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "solution.h"

void test_leetcode_case1(){
    printf("Running LeetCode Case 1 Test... ");

    int nums[8] = {4,3,2,7,8,2,3,1};
    int * returnSize = malloc(sizeof(int));

    int * return_arr = findDisappearedNumbers(nums, 8, returnSize);

    assert(*returnSize == 2);
    assert(return_arr[0] == 5);
    assert(return_arr[1] == 6);
    
    free(return_arr);
    free(returnSize);

    printf("PASSED\n");
}

void test_leetcode_case2(){
    printf("Running LeetCode Case 2 Test... ");

    int nums[2] = {1, 1};
    int * returnSize = malloc(sizeof(int));

    int * return_arr = findDisappearedNumbers(nums, 2, returnSize);

    assert(*returnSize == 1);
    assert(return_arr[0] == 2);
    
    free(return_arr);
    free(returnSize);

    printf("PASSED\n");
}

int main() {
    test_leetcode_case1();
    test_leetcode_case2();
    return 0;
}