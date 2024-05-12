LL findLCA(LL u,LL v){
    while(depth[u] > depth[v])
        u = father[u];
    while(depth[v] > depth[u])
        v = father[v];
    while(u != v){
        u = father[u];
        v = father[v];
    }
    return u;//or return v
}
