#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);


int main() {
    int nums[] = {3,3};
    int target = 6;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }
    else {
        printf("No valid pair found.\n");
    }

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;

                return result;
            }
        }
    }

    return NULL;
}
