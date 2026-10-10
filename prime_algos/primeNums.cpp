#include <iostream>
#include <vector>

using namespace std;


void Primes(long long n) {
   
    vector<long long> primas;

    while(n%2==0) {
        primas.push_back(2);
        n/=2;
    }

    for(long long i=3;i*i<=n;i+=2){
        while(n%i==0){
            primas.push_back(i);
            n/=i;
        }
    }
    if(n>1) {
        primas.push_back(n);
    }

    for(int i = 0;i<primas.size();i++) {
        cout << primas[i] << " ";
    }

}


int main() {
    long long n;
    cin >> n;
    Primes(n);
}