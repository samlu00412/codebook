#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define N 10002
#define oo 1000000001//1e9+1
typedef long long LL;

using namespace std;

vector<pair<LL,LL>> adjacent[N];//out neighbor,weight of edge
LL dis[N],parent[N];
bool visit[N] = {false};

int main(){
    good;
    LL i,n,m;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        LL x,y,w;
        cin >> x >> y >> w;
        adjacent[x].push_back({y,w});
        adjacent[y].push_back({x,w});
    }
    //initial
    LL source = 0;
    memset(dis,oo,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    priority_queue<pair<LL,LL>> PQ;//-dis[],vertex，技巧性讓最小值pop
    PQ.push({dis[source] = 0,source});
    //dijkstra
    while (!PQ.empty()){
        auto p = PQ.top();
        PQ.pop();
        LL v = p.second;//vertex
        if(visit[v]) continue;
        visit[v] = true;
        for(auto it : adjacent[v]){
            LL e = it.first,w = it.second;
            if(w + dis[v] < dis[e]){
                dis[e] = w + dis[v];
                parent[e] = v;
                PQ.push({-dis[e],e});
            }
        }
    }
    LL maxd = -1,cnt = 0,far;
    for(i = 0; i < n; i++){
        if(dis[i] < oo){
            if(dis[i] > maxd)
                maxd = dis[i],far = i;
        }
        else
            cnt++;//for can't reach
    }
    cout << maxd << endl << cnt;
    return 0;
}