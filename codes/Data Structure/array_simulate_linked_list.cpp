#include<bits/stdc++.h>
#define pll pair<LL,LL>
#define RSIZE 100002
#define oo 1000000001
#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;
using namespace std;

struct {
    LL center,height;
    LL pre,next;
    bool alive;
}tree[RSIZE];

queue<LL> Q;//check removed tree
void removable(LL index){
    if(!tree[index].alive) return;
    LL s = tree[index].pre,t = tree[index].next;
    if(tree[index].center-tree[index].height >= tree[s].center ||
       tree[index].center+tree[index].height <= tree[t].center){
            tree[index].alive = false;
            Q.push(index);
            tree[s].next = t;
            tree[t].pre = s;
       }
}

int main(){
    good;
    LL bound,n,total = 0,high = 0;
    cin >> n >> bound;
    for(LL i = 1; i <= n; i++)
        cin >> tree[i].center;
    for(LL i = 1; i <= n; i++)
        cin >> tree[i].height;
    for(LL i = 1; i <= n; i++){
        tree[i].pre = i-1;
        tree[i].next = i+1;
        tree[i].alive = true;
    }
    tree[0].center = 0,tree[0].height = oo;
    tree[n+1].center = bound,tree[n+1].height = oo;
    for(LL i = 1; i <= n; i++)
        removable(i);
        while (!Q.empty()){
            LL v = Q.front();
            Q.pop();
            total++;
            high = max(high,tree[v].height);
            removable(tree[v].pre);
            removable(tree[v].next);
        }
        cout << total << endl << high;
    return 0;
}