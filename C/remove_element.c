#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int nr_index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[nr_index] = nums[i];
            nr_index++;
        } else {
            nums[i] = 0;
        }
    }
    return nr_index;
}

int main() {
    int nums[] = {2, 4, 2, 2, 4, 7};
    printf("%d \n", removeElement(nums, sizeof(nums) / sizeof(nums[0]), 2));
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d, ", nums[i]);
    }
}