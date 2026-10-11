#include <iostream>
#include <vector>

using namespace std;

struct ways {
    int from;
    int to;
    int cost;
};

/*
Работает даже с отрицательными рёбрами!
Сложность: O(N*M) 
*/

int Way(vector<ways> &graph, int &start, int &end, int &n) {

    vector<int> dist(n, 10000000); // Все дистанции бесконечны
    dist[start] = 0; // Стартовая точка может прийти в себя за 0

    for(int i=0;i<=n-1;i++) { // Проходимся n раз, чтобы проверить ВСЕ пути
        for (auto e : graph) { // Перебираем все ребра
            if(dist[e.from] + e.cost < dist[e.to]) { // Если путь дешевле, то присвоить (0+cost < inf , если первый проход)
                dist[e.to] = dist[e.from] + e.cost; // присвоение
            }
        }
    }
    return dist[end]; // Выводим кротчайший
}

int main() {
    int n; // Вершины графа
    int re; // Рёбра графа
    cin >> n >> re;
    vector<ways> graph(re); // Таблица ребер графа

    for(int i =0;i<re;i++) { // Заполнение таюлицы рёбер
        cin >> graph[i].from >> graph[i].to >> graph[i].cost;
    }

    int A,B; // Откуда(A) и куда(B) надо попасть
    cin >> A >> B;

    cout << "Самый короткий путь из A в B: " << Way(graph, A, B, n) << endl;
}

/* Для теста
6 7
0 1 3
0 2 10
1 2 4
2 3 -1
2 5 6
3 4 2
4 5 1
0 5
*/