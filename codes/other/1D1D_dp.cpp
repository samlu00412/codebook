#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 101
typedef long long LL;
using namespace std;
LL p = 1000000009;
LL memo[RSIZE];
LL cata(LL times){
    if(memo[times] >= 0) return memo[times];
    LL sum = 0;
    for(LL i = 0; i < times; i++){
        LL temp = cata(i)*cata(times-1-i)%p;
        sum = (sum+temp) % p;
    }
    return memo[times] = sum;
}
int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL n;
    for(LL i = 1; i <= RSIZE; i++)
        memo[i] = -1;
    memo[0] = 1;
    cin >> n;
    cout << cata(n);
    return 0;
}