
/** binary_search.c
 * @brief Uses binary search to find a target.
 * @author Eric Taylor
 * @date 09/21/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Returns a pointer to the found element:
int* search(int* nums, int length, int target) {
    int* first = nums;
    int* last = &nums[length - 1];
    int* mid;
    int jump;

    for (jump = length; first <= last; jump /= 2) {
        
        mid = (first + (jump / 2));  

        if (*mid < target) {
            first = (mid + 1);
            continue;
        }

        if (*mid > target) {
            last = (mid - 1);
            continue;
        }

        if (*mid == target) {
            return mid;
        }
    }
    return NULL;
}

int* get_nums(int length) {
    int* nums = (int*) malloc((length) * sizeof(int));
    for (int i = 0; i < length; i++) {
        nums[i] = i;
    }
    return nums;
}

int main() {
    int target = 30000000;
    int LENGTH = 100000000;
    int* nums = get_nums(LENGTH);
    int* found = search(nums, LENGTH, target);

    free(nums);
    nums = NULL;
    
    if (found == NULL) {
        printf("Target: %d not found\n", target);
        return 0;
    }
    
    printf("Target: %d\n", target);
    printf("Found: %d at %p\n", *found, found);
    


    return 0;
}