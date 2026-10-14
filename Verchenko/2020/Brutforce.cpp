#include <iostream>

using namespace std;

bool gcd(int a, int b) {
    while(b!=0) {
        a%=b;
        swap(a,b);
    }
    if(a>1){
        return 0;
    }
    else {
        return 1;
    }
}

int main() {

    int count = 0;

    for(int i = 10;i<100;i++) {
        for(int j = 10; j<100;j++) {
            for(int k = 10;k<100;k++) {
                if(i<j && i<k) {
                    if(((i*i+j*j==k*k) || (i*i+k*k==j*j)) && gcd(i,j) && gcd(j,k) && gcd(i,k)) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count*2-1;
}