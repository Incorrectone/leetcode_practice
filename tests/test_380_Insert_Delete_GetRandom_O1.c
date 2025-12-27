#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "solution.h"

void test_leetcode_trace() {
    printf("Running LeetCode Trace Test... ");

    RandomizedSet* obj = randomizedSetCreate();
    assert(obj != NULL);

    bool result1 = randomizedSetInsert(obj, 1);
    assert(result1 == true);

    bool result2 = randomizedSetRemove(obj, 2);
    assert(result2 == false);

    bool result3 = randomizedSetInsert(obj, 2);
    assert(result3 == true);

    int randomVal1 = randomizedSetGetRandom(obj);
    assert(randomVal1 == 1 || randomVal1 == 2);

    bool result4 = randomizedSetRemove(obj, 1);
    assert(result4 == true);

    bool result5 = randomizedSetInsert(obj, 2);
    assert(result5 == false);

    int randomVal2 = randomizedSetGetRandom(obj);
    assert(randomVal2 == 2);

    randomizedSetFree(obj);
    printf("PASSED\n");
}

int main() {
    test_leetcode_trace();
    return 0;
}