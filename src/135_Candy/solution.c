int candy(int* ratings, int ratingsSize) {
    int total_candies = 1;

    int index_candy = 1;
    int prev_candy = 1;

    int descent = 0;

    int peak = 0;

    for(int i = 1; i < ratingsSize; i++){
        index_candy = 1;

        if(ratings[i] > ratings[i - 1])
        {
            index_candy = prev_candy + 1;

            prev_candy = index_candy;

            peak = index_candy;

            descent = 0;

        }else if(ratings[i] < ratings[i - 1])
        {
            if(prev_candy >= index_candy && peak < prev_candy){
                peak = prev_candy;
            }

            descent++;

            if(prev_candy == 1){
                if(peak == descent){
                    total_candies += descent;
                    peak++;
                }else{
                    total_candies += descent - 1;
                }
            }

            prev_candy = 1;

        }else if(ratings[i] == ratings[i - 1])
        {
            descent = 0;

            prev_candy = index_candy;

            peak = index_candy;

        }

        total_candies += index_candy;
    }

    return total_candies;
}