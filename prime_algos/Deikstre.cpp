#include <iostream>
#include <vector>

using namespace std;

struct ways{
    int from;
    int to;
    int cost;
};

int Deikstre(vector<ways> &graph, int &start, int &end, int n) {

    

}
/*
Работает от ()
*/

int main() {

    int n; // Кол-во вершин
    int re; // Кол-во рёбер
    cin >> n;
    cin >> re;

    vector<ways> vec(re);

    for(int i = 0;i<re;i++) { // Заполнение ребер
        cin >> vec[i].from >> vec[i].to >> vec[i].cost;
    }

    int a,b; // откуда (a) и куда (b)
    cin >> a >> b;

    cout << "Кротчайший путь: " << Deikstre(vec,a,b,n);

}