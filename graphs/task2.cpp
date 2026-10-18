#include <iostream>
#include <vector>

using namespace std;

vector<bool> DFS(vector<vector<int>> &graph, int start,vector<bool> &visited) {
    int n = graph.size();
    

    visited[start] =1;

    for(int v : graph[start]) {
        if(!visited[v]) {
            visited[v]=1;
            DFS(graph, v,visited);
        }
    }

    
    return visited;
}

int main() {
    int n;
    int x;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<bool> visited(n,0);

    for(int i = 0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> x;
            if(x) {
                graph[i].push_back(j);
            }
        }
    }
    int start;
    cin >> start;
    visited=DFS(graph,start,visited);

    for(int i =0;i<n;i++) {
        if(visited[i]) {
            cout << i << " ";
        }
    }
}