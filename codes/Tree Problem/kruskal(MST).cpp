#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 10002
#define pll pair<LL,LL>
typedef long long LL;
using namespace std;

struct EDGE{
    LL u,v,w;
};

vector<EDGE> adjacent;//out neighbor, weight
LL fa[RSIZE];

bool cmp(EDGE &a,EDGE &b){//sort by weight
    return a.w < b.w;
}
LL sfind(LL now){//find root,root's father=set size
    if(fa[now] < 0)
        return now;
    return fa[now] = sfind(fa[now]);
}
bool merge(LL u,LL v){//find two root, comparing size(by root's father)
    LL set1 = sfind(u),set2 = sfind(v);
    if(set1 == set2) return false;//same root-> no need to merge
    if(fa[set1] < fa[set2]){ //set1 is larger
        fa[set1] += fa[set2];
        fa[set2] = set1;
    }
    else{
        fa[set2] += fa[set1];
        fa[set1] = set2;
    }
    return true;
}

int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL i,n,m;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        LL x,y,weight;
        cin >> x >> y >> weight;
        adjacent.push_back({x,y,weight});
    }
    memset(fa,-1,sizeof(fa));//unvisited
    sort(adjacent.begin(),adjacent.end(),cmp);//sort by weight
    LL cost = 0,now_edge = 0;
    for(EDGE e : adjacent){
        if(merge(e.u,e.v)){//connect edge
            cost += e.w;
            now_edge++;
        }
    }
    if(now_edge < n-1)//not a MST
        cout << -1 << endl;
    else
        cout << cost << endl;
    return 0;
}