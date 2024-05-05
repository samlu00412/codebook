#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 101
typedef long long LL;
using namespace std;

LL parent[503*503];
int graph[503*503] = {0};
int dxy[4] = {1,-1};
LL now_area = 0,max_area = 0;

LL sfind(LL dots){//find leader,leader's parent = size of set
    if(parent[dots] < 0)
        return dots;
    return parent[dots] = sfind(parent[dots]);
}
LL BFS(LL now,LL root){//find root and return size
    parent[now] = root;
    LL cnt = 1;
    for(int k = 0; k < 4; k++){//4 directions
        int u = now+dxy[k];
        if(graph[u] == 1 && parent[u] == -1)//unvisited
            cnt += BFS(u,root);
    }
    return cnt;
}
void combine(LL u,LL v){//merge two sets
    LL set1 = sfind(u),set2 = sfind(v);
    if(set1 == set2) return;//same set

    max_area = max(max_area,-parent[set1]-parent[set2]);
    now_area--;//merge -> 2 pools become 1
    if(parent[set1] < parent[set2]){//1 is larger
        parent[set1] += parent[set2];
        parent[set2] = set1;
    }
    else{
        parent[set2] += parent[set1];
        parent[set1] = set2;
    }
    return;
}
int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL i,j,m,n,k;
    cin >> m >> n >> k;
    memset(parent,-1,sizeof(parent));
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++)
            cin >> graph[i*(n+2)+j];
    }
    n += 2;
    dxy[2] = n,dxy[3] = -n;
    LL mn = (m+1)*n;
    for(LL x = n; x < mn; x++){
        if(graph[x] == 1 && parent[x] == -1){//unvisited
            parent[x] = -BFS(x,x);//first point consider as root
            now_area++;
            max_area = max(max_area,-parent[x]);
        }
    }
    LL ans = now_area,max_ans = max_area;
    while(k--){
        LL x,y,temp;
        cin >> x >> y;
        temp = x*n+y;
        if(graph[temp] == 1) continue;
        graph[temp] = 1;
        now_area++;
        max_area = max(max_area,(LL)1);
        for(i = 0; i < 4; i++){
            if(graph[temp+dxy[i]] == 0) continue;
            combine(temp,temp+dxy[i]);
        }
        ans += now_area;
        max_ans += max_area;
    }
    cout << max_ans << endl << ans;
    return 0;
}