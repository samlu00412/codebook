LL dp[101][100001] = {0};//前i個物品所湊出重量j的最大價值
int main(){
    good;
    LL j,i,n,w,svalue = 0,sweight = 0;
    cin >> n >> w;
    pair<LL,LL> item[n+1];//weight,value;
    for(i = 1; i <= n; i++)
        cin >> item[i].first;
    for(i = 1; i <= n; i++)
        cin >> item[i].second;
    for(i = 0; i <= n; i++)
        dp[i][0] = dp[0][i] = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= w; j++){
            if(item[i].first > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],item[i].second + dp[i-1][j-item[i].first]);
        }
    }
    cout << dp[n][w];
    return 0;
}