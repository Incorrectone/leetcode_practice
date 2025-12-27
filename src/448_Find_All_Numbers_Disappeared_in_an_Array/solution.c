#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        int temp = abs(nums[i]) - 1;
        if (nums[temp] > 0){
            count++;
            nums[temp] *= -1;
        }
    }

    count = numsSize - count;
    int * return_arr = malloc(sizeof(int) * count);
    int index = 0;

    for(int i = 0; i < numsSize; i++){
        if (nums[i] > 0){
            return_arr[index] = i + 1;
            index++;
        }
    }

    *returnSize = count;
    return return_arr;
}