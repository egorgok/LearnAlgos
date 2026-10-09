#include <iostream>
#include <vector>


using namespace std;

int FUNC(vector<vector<int>> vec, int comp) {
    int ans = comp;

    for(int i = 0;i<vec.size();i++) {
        
    }



    return ans;
}


int main() {

    int V, R;
    cin >> V >> R;
    
    vector<vector<int>> UV(V);
    int v1,v2;
    while(R--){
        cin >> v1 >> v2;

        UV[v1].push_back(v2);
        UV[v2].push_back(v1);

    }


    cout << FUNC(UV, V);
    
        
}