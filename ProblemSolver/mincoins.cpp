#include <iostream>
#include <cstring>

using namespace std;
int minCoins_dp(int vals[], int N, int sum) {
    if (sum < 0) {
        return -1;
    }
    if (!vals || N == 0) {
        return 0;
    }
    
    int* dp = new int[sum + 1];
    
    dp[0] = 0;
    unsigned int min;
    for (int p = 1; p <= sum; p++) {
        min = 0xFFFFFFFF;
        for (int j = 0; j < N; j++)
        {
            if (vals[j] <= p)
            {
                if (dp[p-vals[j]] != 0xFFFFFFFF)
                {
                    if (1+dp[p-vals[j]] < min)
                    {
                        min = 1+dp[p-vals[j]];
                    }
                }
            }
        }
        dp[p] = min;
    }

    
    int min_count = dp[sum];
    
#ifdef DEBUG
    for (int i=0; i<sum+1;i++)
    {
        printf("dp[%d]=%d\n", i, dp[i]);
    }
#endif
    delete [] dp;
    
    return min_count;
}

int minCoins_slow( int a[], int N, int S ){

    if (S==0)
    {
        return 0;
    }
    else if (S<0)
    {
        return -1;
    }
    
    if (N==0)
    {
        return (S)?(-1):0;
    }
    
    /* N: Length of the array */
    int value = 0;
    int max_coins = 0;
    int min_coins = -1;
    
    for (int i=N-1;i>=0;i--)
    {
        value = a[i];
        max_coins = S/value;
        
        int this_plan;
        int future_plan;
        for (int j=max_coins;j>=0;j--)
        {
            if (min_coins != -1 && j > min_coins)
            {
                continue;
            }
            
            future_plan = minCoins_slow(a, N-1, S-j*value);
            if (future_plan != -1)
            {
                this_plan = j + future_plan;
                if (min_coins == -1 || this_plan < min_coins)
                {
                    min_coins = this_plan;
                }
            }
            
        }
        
    }
    
    
    return min_coins;
}

int solve_mincoins(void)
{
    int a[] = {5,5};
    int total = 11;
    //int min_coins = minCoins(a, 3, total);
    int min_coins = minCoins_dp(a, 2, total);
    
    cout << min_coins;
    
    return 0;
}