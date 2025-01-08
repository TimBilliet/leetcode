#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int* same_nr_ptr = nums;
    int end_nr = nums[numsSize - 1];
    int new_count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (*nums == end_nr) {
            return new_count + 1;
        }
        new_count++;
        while (*same_nr_ptr == *nums) {
            same_nr_ptr++;
        }
        nums++;
        *nums = *same_nr_ptr;
    }
    return -1;
}

int main() {
    // int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // int nums[] = {1, 1, 2};
    int nums[] = {1};
    printf("%d, \n", removeDuplicates(nums, sizeof(nums) / sizeof(nums[0])));
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d, ", nums[i]);
    }
}