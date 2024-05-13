#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 502
#define pll pair<LL,LL>
#define lc 2*index
#define rc 2*index+1
#define far 1000000001//1e9+1
typedef long long LL;
using namespace std;

LL dis[RSIZE][RSIZE];
vector<pll> adjacent[RSIZE];//out neighbor,weight
void floyd_warshall(LL vertex){
    LL t,k,i,j;
    for(t = 1; t <= vertex; t++)
        dis[t][t] = 0;
    for(k = 1; k <= vertex; k++){
        for(i = 1; i <= vertex; i++){
            for(j = 1; j <= vertex; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k]+dis[k][j];
            }
        }
    }
    return;
}
int main(){
    good;
    LL m,n,x;
    cin >> n >> m >> x;//n nodes, m edges,from 1 to n
    memset(dis,far,sizeof(dis));
    for(LL i = 0; i < m; i++){
        LL a,b,w;
        cin >> a >> b >> w;
        adjacent[a].push_back({b,w});
        dis[a][b] = w;
    }
    return 0;
}