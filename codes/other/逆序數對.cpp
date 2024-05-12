#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;

using namespace std;
LL number[100002] = {0};

LL inverse_pair(LL a[],LL left,LL right){
    LL i,j,mid = (left+right)/2;
    if(left+1 >= right) return 0;//one num has no pair
    LL ans = inverse_pair(a,left,mid) + inverse_pair(a,mid+1,right);//pair in same side
    LL cross = 0;//pair cross both side
    sort(a+mid,a+right);//sort right part of num
    for(i = 0; i < mid; i++){
        cross += lower_bound(a+mid,a+right,a[i])-(a+mid);//quantity of smaller than a[i]
    }
    return ans+cross;
}
int main(){
    good;
    LL n;
    cin >> n;
    for(LL i = 0; i < n; i++)
        cin >> number[i];
    cout << inverse_pair(number,0,n);
    return 0;
}