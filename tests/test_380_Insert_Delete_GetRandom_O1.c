#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "solution.h"

int arraysAreEqual(int* arr1, int* arr2, int size) {
    if (arr1 == NULL || arr2 == NULL) return 0;
    
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            // Optional: Print exactly where it failed for debugging
            printf("Mismatch at index %d: Expected %d, but got %d\n", 
                   i, arr2[i], arr1[i]);
            return 0;
        }
    }
    return 1;
}

void test_leetcode_trace() {
    printf("Running LeetCode Trace Test... ");

    // 1. Initialize ("RandomizedSet", [])
    RandomizedSet* obj = randomizedSetCreate();
    assert(obj != NULL);

    // 2. insert(1) -> Expected: true
    // Set is now: {1}
    bool result1 = randomizedSetInsert(obj, 1);
    assert(result1 == true);

    // 3. remove(2) -> Expected: false (2 was not in set)
    // Set is still: {1}
    bool result2 = randomizedSetRemove(obj, 2);
    assert(result2 == false);

    // 4. insert(2) -> Expected: true
    // Set is now: {1, 2}
    bool result3 = randomizedSetInsert(obj, 2);
    assert(result3 == true);

    // 5. getRandom() -> Expected: 1 or 2
    // The screenshot shows 2, but 1 is also a correct return value here.
    int randomVal1 = randomizedSetGetRandom(obj);
    assert(randomVal1 == 1 || randomVal1 == 2);

    // 6. remove(1) -> Expected: true
    // Set is now: {2}
    bool result4 = randomizedSetRemove(obj, 1);
    assert(result4 == true);

    // 7. insert(2) -> Expected: false (2 is already in set)
    // Set is still: {2}
    bool result5 = randomizedSetInsert(obj, 2);
    assert(result5 == false);

    // 8. getRandom() -> Expected: 2
    // Since only '2' remains, this MUST return 2.
    int randomVal2 = randomizedSetGetRandom(obj);
    assert(randomVal2 == 2);

    // Cleanup
    randomizedSetFree(obj);
    printf("PASSED\n");
}

int main() {
    test_leetcode_trace();
    return 0;
}