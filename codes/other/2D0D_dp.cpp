#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 202
typedef long long LL;
using namespace std;

int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL graph[RSIZE][RSIZE] = {0};
    LL m,n,i,j;
    cin >> m >> n;
    for(i = 0; i < m; i++)//0 base draw graph
        for(j = 0; j < n; j++)
            cin >> graph[i][j];
    for(i = 1; i < m; i++)
        graph[i][0] += graph[i-1][0];
    for(j = 1; j < n; j++)
        graph[0][j] += graph[0][j-1];
    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
            graph[i][j] += max(graph[i-1][j],graph[i][j-1]);
    cout << graph[m-1][n-1];
    return 0;
}