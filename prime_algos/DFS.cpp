#include <iostream>
#include <vector>

using namespace std;

vector<bool> DFS(vector<vector<int>> &graph, int start,vector<bool> &visited) {
    int n = graph.size(); // Вершины графа
    

    visited[start] =1; // Стартовая вершина посещена т.к. мы с нее начинаем

    for(int v : graph[start]) { // Перебираем соседей
        if(!visited[v]) { // Если у соседа не было проверки, то стартуем от него
            visited[v]=1; // В соседе побывали
            DFS(graph, v,visited);
        }
    }

    
    return visited; // Возвращам ем все вершины, до которых дошел DFS (в одной компоненте)
}

int main() {
    int n; // Вершины
    int x; // Есть ли связь (для таблицы смежности)
    cin >> n;
    vector<vector<int>> graph(n); // Создаем таблицу соседей
    vector<bool> visited(n,0); // Создаем массив проверенных

    for(int i = 0;i<n;i++) { // Заполнение таблицы
        for(int j=0;j<n;j++) {
            cin >> x;
            if(x) {
                graph[i].push_back(j);
            }
        }
    }
    int start; 
    cin >> start;// Задаем стартовую точку
    visited=DFS(graph,start,visited); //Получаем массив вершин, до которых дошел DFS

    for(int i =0;i<n;i++) { // Вывод точек в одной компоненте
        if(visited[i]) {
            cout << i << " ";
        }
    }
}

/*
Для теста:
5
0 1 1 0 0
1 0 1 0 0
1 1 0 0 0
0 0 0 0 1
0 0 0 1 0
{start}

O(N+M)

Для лабиринтов, поиска компонентов связности
*/