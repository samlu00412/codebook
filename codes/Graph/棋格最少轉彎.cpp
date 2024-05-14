#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;

using namespace std;

int main(){
    good;
    LL i,j,m,n;
    LL dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    cin >> m >> n;
    char graph[m+5][n+5];
    LL dis[m+2][n+2];
    for(i = 0; i <= m+1; i++)
        graph[i][0] = graph[i][n+1] = '1';//left/right bound
    for(j = 0; j <= n+1; j++)
        graph[0][j] = graph[m+1][j] = '1';
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            cin >> graph[i][j];
    for(i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            dis[i][j] = -1;//not visited
        }
    }
    queue<pair<LL,LL>> Q;//visit i,j
    Q.push({1,1});
    dis[1][1] = 0;
    //start BFS
    while(!Q.empty() && dis[m][n] < 0){
        auto dots = Q.front();
        Q.pop();
        LL now_x = dots.first,now_y = dots.second;
        for(LL k = 0; k < 4; k++){
            LL new_x = now_x+dx[k],new_y = now_y+dy[k];
            while (graph[new_x][new_y] == '0'){
                if(dis[new_x][new_y] == -1){//not visited
                    dis[new_x][new_y] = dis[now_x][now_y]+1;
                    Q.push({new_x,new_y});
                }
                new_x += dx[k];
                new_y += dy[k];
            }
        }
    }
    if(dis[m][n] > 0) dis[m][n]--;//count one more
    cout << dis[m][n];
    return 0;
}