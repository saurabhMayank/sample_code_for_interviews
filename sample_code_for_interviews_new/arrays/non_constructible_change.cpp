
int non_constructible_change(vector<int> input_coins){
    
    // return the smallest change
    // that you cannot create

    sort(input_coins.begin(), input_coins.end());
    int change = 0; 

    for(int i = 0; i<input_coins.size(); ++i){
        if(input_coins[i] > change+1){
            return change+1;
        }
        // by adding coin[i] to change
        // we are asserting that we can
        // create all the changes till change+coin[i]
        // either directly or combination of coins
        // because we are going in sequence
        // everytime we are doing + 1
        // so no change can be missed
        change = change+coin[i];
    }


}