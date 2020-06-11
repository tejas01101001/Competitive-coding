1)Here we break copies into 1,2,4..,2^(k-1),
(copies-(2^k)+1) and discard zero terms.

int n, target;
vector<int> val, wt;
 
int knapsack()
{
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    forz(i, n)
    {
        for (int j = target; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    return dp[target];
}

int main()
{
    kira;
 
    cin >> n >> target;
    int price[n], weight[n], copies[n];
 
    forz(i, n) cin >> weight[i];
    forz(i, n) cin >> price[i];
    forz(i, n) cin >> copies[i];
 
    forz(i, n)
    {
        int temp = 1;
        int total = 0;
        while (total <= copies[i])
        {
            if (temp + total > copies[i])
                break;
                
            val.pb(temp * price[i]);
            wt.pb(temp * weight[i]);
            total += temp;
            temp *= 2;
        }
 
        if (total != copies[i])
        {
            val.pb((copies[i] - total) * price[i]);
            wt.pb((copies[i] - total) * weight[i]);
        }
    }
    debug(val);
    debug(wt);
    n=int(val.si);
    cout << knapsack();
    run_time();
    return 0;
}