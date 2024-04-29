#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long LL;
using namespace std;
int fa[100000],d[100000] = {0};//unnecessary
bool visit[100000] = {false};
vector<LL> v[100000];
void dfs(LL now,LL depth){
    for(auto x:v[now]){
        if(!visit[x]){
            cout << x << ' ';
            visit[x] = true;
            d[x] = depth;
            fa[x] = now;
            dfs(x,depth+1);
        }
    }
}
int main(){
    good;
    LL i,n,a,b;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0,1);
    return 0;
}