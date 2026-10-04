#include <iostream>
#include <vector>
#include <utility>
#include <queue>


using namespace std;

vector<vector<int>> getEdgeList(vector<vector<int>> mas, int n) {
    vector<vector<int>> temp(n);
    int tempNUM=0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            tempNUM = j;
            if(mas[i][j]) {
                temp[i].push_back(tempNUM);
            }
        }
    }

    return temp;
}

int BFS(vector<vector<int>> bo, int n, int start, int end) {
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> fallen;
    int v;
    dist[start] = 0;
    fallen.push(start); 

    while(!fallen.empty()) {
        v = fallen.front();
        fallen.pop();
        for(auto to : bo[v]) {
            if(dist[to] == -1) {
                dist[to] = dist[v] + 1;
                parent[to] = v;
                fallen.push(to);
            }
        }
    }
    return dist[end];
}

int main() {
    int n;
    int start;
    int end;

    cin >> n >> start >> end;
    start--;
    end--;
    vector<vector<int>> matrix (n);
    char a;
    int b;


    for(int i = 0;i<n;i++) { // Заполнение матрицы смежности
        for(int j = 0;j<n;j++) {
            cin >> a;
            b=a-'0';
            matrix[i].push_back(b);
        }
    }

    matrix = getEdgeList(matrix, n);

    cout << BFS(matrix, n, start, end);
}