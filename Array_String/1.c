#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
typedef struct {
    int key;
    int val;
    int used;
} HashItem;


int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
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
    int mapSize = numsSize * 2;
    HashItem* hashMap = (HashItem*)calloc(mapSize, sizeof(HashItem));

    for (int i=0; i<numsSize; i++) {
        int complement = target - nums[i];

        int hashKey = abs(complement) % mapSize;
        while (hashMap[hashKey].used) {
            if (complement == hashMap[hashKey].key) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = hashMap[hashKey].val;
                result[1] = i;
                *returnSize = 2;
                free(hashMap);

                return result;
            }

            hashKey = (hashKey + 1) % mapSize;
        }

        int curKey = abs(nums[i]) % mapSize;
        while (hashMap[curKey].used) {
            curKey = (curKey + 1) % mapSize;
        }

        hashMap[curKey].key = nums[i];
        hashMap[curKey].val = i;
        hashMap[curKey].used = 1;
    }

    free(hashMap);
    *returnSize = 0;
    return NULL;
}
