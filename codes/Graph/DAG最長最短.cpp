#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define sobig 1000000001
typedef long long LL;

using namespace std;

int main(){
    good;
    LL n,m,a,b,w,start,fin,cnt = 0;
    cin >> n >> m;
    cin >> start >> fin;
    vector<pair<LL,LL>> adj[n];// n-> out neighbor for first,weight for second
    LL indeg[n] = {0};
    LL shortest[n],longest[n];//dis. from start to i
    for(LL i = 0; i < m; i++){
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        indeg[b]++;
    }

    queue<LL> Q;//manage tolopogy sequence
    for(LL i = 0; i < n; i++)
        shortest[i] = sobig,longest[i] = -sobig;
    shortest[start] = longest[start] = 0;
    for(LL i = 0; i < n; i++)
        if(indeg[i] == 0)
            Q.push(i);

    while(!Q.empty()){
        LL v = Q.front();
        Q.pop(),cnt++;
        for(auto e : adj[v]){
            if(shortest[v] < sobig){//path exist
                shortest[e.first] = min(shortest[e.first],e.second + shortest[v]);
                longest[e.first] = max(longest[e.first],e.second + longest[v]);
            }
            if(--indeg[e.first] == 0)
                Q.push(e.first);
        }
    }
    if(cnt != n) cout << "not a DAG" << endl;
    if(shortest[fin] == sobig)
        cout << "No path" << endl << "No path";
    else
        cout << shortest[fin] << endl << longest[fin];
    return 0;
}