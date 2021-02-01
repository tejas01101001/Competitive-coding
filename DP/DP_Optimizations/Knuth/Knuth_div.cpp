
int main()
{
    kira;
 
    lli n;
    cin >> n;
 
    lli dp[n + 1][n + 1];
    lli h[n + 1][n + 1];
    lli a[n + 1], pre[n + 1] = {0};
 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
 
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            if (len == 1)
            {
                dp[i][j] = 0;
                h[i][j] = i;
                continue;
            }
            if (len == 2)
            {
                dp[i][j] = a[i] + a[j];
                h[i][j] = i;
                continue;
            }
 
            dp[i][j] = INF;
            lli curr;
            for (int k = h[i][j - 1]; k <= h[i + 1][j]; k++)
            {
 
                curr = dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1];
                if (dp[i][j] > curr)
                {
                    dp[i][j] = curr;
                    h[i][j] = k;
                }
            }
        }
    }
    p1(dp[1][n]);
 
    run_time();
    return 0;
}