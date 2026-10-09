#include <iostream>
#include <vector>

using namespace std;


bool binSearch(vector<int> &mas, int X, int min, int max) {

    if(min>max) {
        return 0;
    }
    if(mas.empty()) {
        return 0;
    }
    int mid = (max+min)/2;
    bool flag = 0;
    if(mas[mid]==X) {
        return 1;
    }

    if(X>mas[mid]) {
        flag = binSearch(mas, X, mid+1, max);
    }
    else {
        flag = binSearch(mas,X,min,mid-1);
    }

    return flag;
}


int main() {
    int n, s;
    cin >> n >> s;
    vector<int> mas (n);
    int a;

    for(int i =0; i<n;i++) {
        cin >> a;
        mas[i] = a;
    }    
    int X;
    while(s--) {
        cin >> X;
        if(binSearch(mas,X, 0, n)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}