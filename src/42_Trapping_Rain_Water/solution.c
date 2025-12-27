int trap(int* height, int heightSize) {
    int total_water = 0;
    
    int l = 0;
    int r = heightSize - 1;

    int max_l = 0;
    int max_r = 0;

    while(l < heightSize && r >= 0 && l <= r){
        if(height[l] > max_l){
           max_l = height[l];
        }

        if(height[r] > max_r){
           max_r = height[r];
        }

        if (height[l] <= height[r]){
            total_water += max_l - height[l];
            l++;
        }else{
            total_water += max_r - height[r];
            r--;
        }
    }

    return total_water;
}