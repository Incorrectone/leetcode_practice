int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum = 0;
    int current = 0;
    int index = 0;

    for(int i = 0; i < gasSize; i++){

        sum += gas[i] - cost[i];
        current += gas[i] - cost[i];

        if (current < 0){
            index = i + 1;
            current = 0;
        }
    }

    if (sum < 0) {
        return -1;
    }
    
    return index;
}
