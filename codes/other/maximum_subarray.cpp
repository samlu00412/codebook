#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;

using namespace std;

int main(){
    good;
    //freopen("P_2_1_5.in", "r", stdin);//input redirection
    LL n;
    cin >> n;
    LL num[n];
    for(LL i = 0; i < n; i++)
        cin >> num[i];
    LL max_sum = 0,sum = 0;//allow 0
    for(LL i = 0; i < n; i++){
        sum = max(num[i],sum+num[i]);//choose if restart
        max_sum = max(sum,max_sum);//update max subarray
    }
    cout << max_sum;
    return 0;
}