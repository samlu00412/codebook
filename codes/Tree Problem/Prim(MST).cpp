#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 502
#define oo 1000000001 //1e9+1
typedef long long LL;
using namespace std;

vector<pair<LL,LL>> adjacent[RSIZE];//out neighbor, weight of edge
LL dis[RSIZE],fa[RSIZE];//dis for weight of two vertexes
bool visit[RSIZE] = {false};

int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL i,n,m;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        LL x,y,w;
        cin >> x >> y >> w;
        adjacent[x].push_back({y,w});
        adjacent[y].push_back({x,w});
    }
    //initial
    LL start = 0;
    memset(dis,oo,sizeof(dis));
    memset(fa,-1,sizeof(fa));
    priority_queue<pair<LL,LL>> PQ;//-dis[],vertex
    PQ.push({dis[start] = 0,start});
    //prim
    while (!PQ.empty()){
        auto pt = PQ.top();
        PQ.pop();
        LL v = pt.second;
        if(visit[v]) continue;
        visit[v] = true;
        for(auto it : adjacent[v]){
            LL neibor = it.first,w = it.second;
            if(visit[neibor]) continue;
            if(w < dis[neibor]){ //new edge is shorter
                dis[neibor] = w;
                fa[neibor] = v;
                PQ.push({-dis[neibor],neibor});
            }
        }
    }
    LL cost = 0,cnt = 0;
    //count cost and check if MST exists
    for(i = 0; i < n; i++){
        if(dis[i] < oo)
            cost += dis[i];
        else
            cnt++;
    }
    if(cnt)
        cout << -1 << endl;
    else
        cout << cost << endl;
    return 0;
}