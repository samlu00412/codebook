#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 101
#define pll pair<LL,LL>
#define lc 2*index
#define rc 2*index+1
#define maxdis 1000000009
typedef long long LL;
using namespace std;
struct Node{
    LL in,out,weight;
};
LL dis[RSIZE];
void bellman_ford(vector<Node> &edges,LL v,LL e,LL start){//v for vertex, e for edge
    //vector<LL> dis(v,LLONG_MAX);
    dis[start] = 0;
    //relaxation
    for(LL i = 0; i < v-1; i++){
        for(LL j = 0; j < e; j++){
            LL x = edges[j].in,y = edges[j].out;
            LL w = edges[j].weight;
            if(dis[x] != maxdis && dis[x]+w < dis[y])
                dis[y] = dis[x] + w;
        }
    }
    //check -weight round
    cout << "from " << start << "'s shortest path to each vertexes is:" << endl;
    for(LL i = 0; i < v; i++){
        cout << i << "\t\t" << dis[i] << endl;
    }
}
bool checkinf(vector<Node> &edges,LL e){
    for(LL i = 0; i < e; i++){
        LL x =edges[i].in,y = edges[i].out;
        LL w = edges[i].weight;
        if(dis[x] != maxdis && dis[x] + w < dis[y])
            return true;
    }
    return false;
}
int main(){
    good;
    LL vertex,edge;
    cin >> vertex >> edge;
    memset(dis,maxdis,sizeof(dis));
    vector<Node> graph(edge);
    for(LL i = 0; i < edge; i++)
        cin >> graph[i].in >> graph[i].out >> graph[i].weight;
    LL source;
    cin >> source;
    bellman_ford(graph,vertex,edge,source);
    if(checkinf(graph,edge))
        cout << "found negative round" << endl;
    else
        cout << "not found negative round" << endl;
    return 0;
}