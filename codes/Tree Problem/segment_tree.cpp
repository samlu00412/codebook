#include<bits/stdc++.h>
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define RSIZE 100000
#define pll pair<LL,LL>
#define lc 2*index //c means child
#define rc 2*index+1
typedef long long LL;
using namespace std;

LL tree[4*RSIZE];//saving range maximum
LL lazy[4*RSIZE] = {0};
LL num[RSIZE],cnt = 1;

//using range maximum as example
void build(LL L,LL R,LL index){
    LL temp = index;
    if(L == R){
        tree[index] = num[cnt];
        cnt++;
        return;
    }
    LL M = (L+R)/2;
    build(L,M,lc);
    build(M+1,R,rc);
    tree[index] = max(tree[lc],tree[rc]);
}
//single point modify
void modify(LL x,LL v,LL L,LL R,LL index){
    if(L == R){
        tree[index] = v;
        return;
    }
    LL M = (L+R)/2;
    if(x <= M)//left side
        modify(x,v,L,M,lc);
    else
        modify(x,v,M+1,R,rc);
    tree[index] = max(tree[lc],tree[rc]);
}
//a range including index has to add tag
void addtag(LL tag,LL index){
    tree[index] += tag;
    lazy[index] += tag;
}
//transfering tag to child
void push(LL index){
    addtag(lazy[index],lc);
    addtag(lazy[index],rc);
    lazy[index] = 0;//tag is transfered to child
}
//lower variables are queried range,UPPER ones are full range
LL query(LL l,LL r,LL L,LL R,LL index){
    if(l <= L && R <= r) return tree[index];
    push(index);//if use single point modify,no need
    LL M = (L+R)/2;
    if(r <= M) //answer in the left side, don't need to query right side
        return query(l,r,L,M,lc);
    else if(l > M) //in right side
        return query(l,r,M+1,R,rc);
    else //answer cross both side
        return max(query(l,r,L,M,lc),query(l,r,M+1,R,rc));//choose better one
}
void multi_modify(LL l,LL r,LL v,LL L,LL R,LL index){
    if(l <= L && R <= r){
        addtag(v,index);
        return;
    }
    push(index);
    LL M = (L+R)/2;
    if(r <= M) multi_modify(l,r,v,L,M,lc);
    else if(l > M) multi_modify(l,r,v,M+1,R,rc);
    else{
        multi_modify(l,r,v,L,M,lc);
        multi_modify(l,r,v,M+1,R,rc);
    }
    tree[index] = max(tree[lc],tree[rc]);
}

int main(){
    good;
    LL k,n;
    //build(1,n,1)at first,can use query(l,r,1,n,1).
    return 0;
}