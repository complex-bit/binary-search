
/** binary_search.c
 * @brief Uses binary search to find a target.
 * @author Eric Taylor
 * @date 09/21/2025
*/

#include <stdio.h>

// Returns a pointer to the found element:
int *search(int* nums, int size, int target) {
    int *first = nums;
    int *last = &nums[size - 1];
    int *mid;
    int length;

    for (length = size; first <= last; length /= 2) {
        
        mid = (first + (length / 2));  

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

int main() {

    int size = 5;
    int nums[] = {1, 2, 3, 4, 5}; 
    int target = 2;

    printf("target: %d\n", target);

    int* found = search(nums, size, target);

    if (found == NULL) {
        printf("Not found");
        return 0;
    }
    
    printf("found: %d at %p\n", *found, found);
    
    return 0;
}