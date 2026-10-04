#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
};

int main() {

    int cikl;
    cin >> cikl;
    int n = cikl;
    int i = 0;
    char a ='0';
    int number = 0;
    vector<Edge> graph;

    while(cikl--) {
        for(int j =0;j<n;j++){
            cin >> a;
            if(a=='1') {
                graph.push_back({i,j});
            }
        }
        i++;
    }

    cikl = 0;
    int vivod = -1;
    int now = 0;
    for (int v = 0; v < n; v++) {
        int count = 0;
        
        for (auto edge : graph) {
            if (edge.from == v) {
                count++;
            }
        }

        cout << count;

        for (auto edge : graph) {
            if (edge.from == v) {
                cout << " " << edge.to + 1;
            }
        }
        cout << "\n";
    }

}


            /*
            if (j.from == vivod) {
                cout << " " << j.to+1;
            }
            else {
                vivod = j.from;
                for(int k = 0;k<graph.size();k++) {
                    if(graph[k].from==vivod) {
                        cikl++;
                    }
                }
                if(cikl==0) {
                    cout << "\n" << 0;
                    cikl = 0;
                }
                else {
                    cout << "\n" << cikl << " " << j.to+1;
                    cikl = 0;
                }   
            }
            */