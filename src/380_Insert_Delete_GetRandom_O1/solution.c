#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "solution.h"

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet *)malloc(sizeof(RandomizedSet));
    obj->capacity = 1 << 18;

    obj->set = calloc(obj->capacity, sizeof(int));
    obj->limit = 0;

    obj->isAssigned = malloc(obj->capacity * sizeof(int));
    for(int i = 0; i < obj->capacity; i++){
        obj->isAssigned[i] = -1;
    }

    obj->array = calloc(obj->capacity, sizeof(int));

    return obj;
}

static unsigned long getHash(int val){
    unsigned long hash = 0xcbf29ce484222325;

    unsigned char * byte = (unsigned char *)&val;

    for(unsigned long i = 0; i < sizeof(int); i++){
        hash ^= (unsigned long)(byte[i]);
        hash *= 0x100000001b3;
    } 

    return hash;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    unsigned long hash = getHash(val);
    int location = hash & (obj->capacity - 1);

    if (obj->isAssigned[location] >= 0){
        return false;
    }

    obj->set[obj->limit] = val;
    (obj->isAssigned)[location] = obj->limit;
    obj->limit++;

    (obj->array)[location] = val;

    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    unsigned long tbr_hash = getHash(val);
    int tbr_location = tbr_hash & (obj->capacity - 1);

    if (!(obj->isAssigned[tbr_location] >= 0)){
        return false;
    }

    int tbr_set_location = (obj->isAssigned)[tbr_location];

    // 1. swap with last element
    // 2. change the last element set location
    // 3. delete the val

    int last_element_val = obj->set[obj->limit - 1];
    unsigned long last_element_hash = getHash(last_element_val);
    int last_element_location = last_element_hash % (obj->capacity);

    // Place it in place of tbr
    obj->set[tbr_set_location] = last_element_val;
    obj->isAssigned[last_element_location] = tbr_set_location;
    obj->limit--;
    
    (obj->isAssigned)[tbr_location] = -1;
    (obj->array)[tbr_location] = 0;

    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int loc = rand() % obj->limit;
    return obj->set[loc];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->array);
    free(obj->isAssigned);
    free(obj->set);
    free(obj);
}