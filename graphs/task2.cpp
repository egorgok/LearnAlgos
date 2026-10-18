#include <iostream>
#include <vector>

using namespace std;

vector<bool> DFS(vector<vector<int>> &graph, int start, vector<bool> &visited) {
\
    int n=graph.size();
    visited[start]=1;

    for(int v : graph[start]) {
        if(!visited[v]) {
            DFS(graph,v,visited);
        }
    }

    return visited;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1,false); 
    visited[0]=1;

    int a,b;
    for(int i =0;i<m;i++) {
        cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;

    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            visited = DFS(graph,i,visited);
            ans+=1;
        }
    }
    
    cout << ans;
}