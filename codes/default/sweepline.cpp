#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;
using namespace std;

struct Seg{
    LL left,right;
};
bool cmp(Seg &a,Seg &b){
    return a.left < b.left;
}

int main(){
    good;
    LL n;
    cin >> n;
    Seg line[n];
    for(LL i = 0; i < n; i++)
        cin >> line[i].left >> line[i].right;
    sort(line,line+n,cmp);
    Seg last = line[0];
    LL total = 0;
    for(LL i = 1; i < n; i++){
        if(line[i].left > last.right){
            total += last.right - last.left;
            last = line[i];
            continue;
        }
        last.right = max(last.right,line[i].right);//merge last and line[i]
    }
    total += last.right - last.left;
    cout << total;
    return 0;
}