#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;
using namespace std;

LL mod_inverse_by_speed_exp(LL x,LL y,LL p){
    if(y == 0) return 1;
    if(y % 2) return (mod_inverse_by_speed_exp(x,y-1,p)*x)%p;
    else{
        LL temp = mod_inverse_by_speed_exp(x,y/2,p);
        return (temp*temp)%p;
    }
}
int main(){
    good;
    LL n,i,p,x;
    cin >> n >> p;
    for(i = 0; i < n; i++){
        cin >> x;
        cout << mod_inverse_by_speed_exp(x,p-2,p) <<' ';
    }
    return 0;
}