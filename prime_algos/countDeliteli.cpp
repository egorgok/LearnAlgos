#include <iostream>
#include <vector>

using namespace std;


long long countDels(long long n) {
   
    vector<long long> primas;

    while(n%2==0) { // Убираем все двойки
        primas.push_back(2);
        n/=2;
    }

    for(long long i=3;i*i<=n;i+=2){ // Убираем все простые числа
        while(n%i==0){
            primas.push_back(i);
            n/=i;
        }
    }
    if(n>1) { // если n>1 и не поделился, то он и сам простой
        primas.push_back(n);
    }
    int i = 0;
    int count = 1;
    int last = -1;

    if(primas.size()==1) { // если n изначально простое
        return 2;
    }

    while(!primas.empty()) {
        if(primas.back()==last) {
            i++;
            primas.pop_back();
        }
        else {
            count*=(i+1);
            i=1;
            last=primas.back();
            primas.pop_back();
        }
    }

    count *=(i+1);

    return count;
}


int main() {
    long long n;
    cin >> n;
    cout << countDels(n);
}