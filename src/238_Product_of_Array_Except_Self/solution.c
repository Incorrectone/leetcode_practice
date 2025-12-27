#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int * return_arr = calloc(numsSize, sizeof(int));

    return_arr[0] = 1;

    for(int i = 1; i < numsSize; i++){
        return_arr[i] = return_arr[i - 1] * nums[i - 1];
    }

    int var = 1;
    for(int i = numsSize - 2; i >= 0; i--){
        var *= nums[i+1];
        return_arr[i] = return_arr[i] * var;
    }

    *returnSize = numsSize;
    return return_arr;
}