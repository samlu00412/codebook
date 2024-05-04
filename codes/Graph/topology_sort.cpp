int main(){
    good;
    LL indeg[1002] = {0};
    vector<LL> graph[1002];
    LL n,m,a,b;
    cin >> n >> m;
    for(LL i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    LL topo[1002],head = 0,tail = 0;//??queue
    for(LL i = 0; i < n; i++)
        if(indeg[i] == 0)
            topo[tail++] = i;
    while(head < tail){
        LL v = topo[head++];//get data and pop
        for(LL u : graph[v]){
            if(--indeg[u] == 0)
                topo[tail++] = u;
        }
    }
    if(tail < n) cout << "not a DAG" << endl;
    else{
        for(LL i = 0; i < n; i++)
            cout << topo[i] << ' ';
    }
    return 0;
}