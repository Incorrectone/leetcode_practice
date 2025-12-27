#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct {
    int capacity;

    int * set;
    int limit;

    // stores the location of the numbers in set, -1
    int * isAssigned;
    int * array; 

} RandomizedSet;

RandomizedSet* randomizedSetCreate();

bool randomizedSetInsert(RandomizedSet* obj, int val);

bool randomizedSetRemove(RandomizedSet* obj, int val);

int randomizedSetGetRandom(RandomizedSet* obj);

void randomizedSetFree(RandomizedSet* obj);

#endif