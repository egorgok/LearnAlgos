#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>> &graph, int start, int end, int n) {
    vector<int> dist(n); // Вектор с дистанциями
    queue<int> q; // Создаем очередь проверки вершин
    vector<bool> travel(n); // Провереные вершины

    q.push(start); // Начинаем со стартовой вершины
    travel[start] = 1; // Побывыли в стартовой вершине

    while(!q.empty()) { // Пока очередь не пустая 
        int v = q.front(); // Берем вершину которую будем проверять
        q.pop(); // Больше эту вершины проверять не надо

        for(int now : graph[v]) { // Проверяем соседей
            if(!travel[now]) { // если еще не помещали
                travel[now] = 1; // Отмечаем посещение
                dist[now]=dist[v]+1; // Записываем путь
                q.push(now); // Пихаем новую вершину как непроверенную
            }
        }
    }

    return dist[end]; // Возвращаем дистанцию
}



int main() {
    int n; // Вершины
    cin >> n;
    int x = 0; // Соединения графов
    int a; // Откуда
    int b; // Куда
    vector<vector<int>> graph(n); // Табоица рёбер

    for(int i=0;i<n;i++) { // Перебор вершин
        for(int j=0;j<n;j++) { // Заполнение соседей у вершин
            cin >> x;
            if(x) {
                graph[i].push_back(j); // Кидаем соседа, если есть связь
            }
        }
    }
    cin >> a >> b;
    cout << BFS(graph,a,b,n); // Вызываем поиск в ширину


}