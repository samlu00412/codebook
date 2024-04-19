LL val;//unnecessary
bool visited[5000] = {false};
vector<LL> graph[5000];
void BFS(LL start) {
    queue<LL> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()){
        LL curr = q.front();
        q.pop();
        for(auto it: graph[curr]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
