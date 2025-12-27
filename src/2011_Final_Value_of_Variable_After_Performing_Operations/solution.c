int finalValueAfterOperations(char** operations, int operationsSize) {
    int x = 0;
    for(int i = 0; i < operationsSize; i++){
        char op = operations[i][1];
        if(op == '+'){
            x++;
        }else{
            x--;
        }
    }
    return x;
}