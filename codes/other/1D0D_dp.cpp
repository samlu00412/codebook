#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;
using namespace std;

int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL i,n;
    LL money[100002],dp[100002] ={0};//dp for last i day max profit
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> money[i];
    dp[0] = 0,dp[1] = money[1],dp[2] = max(money[1],money[2]);
    for(i = 3; i <= n; i++)
        dp[i] = max(dp[i-2]+money[i],dp[i-1]);//choose,discard
    cout << dp[i-1];
    return 0;
}