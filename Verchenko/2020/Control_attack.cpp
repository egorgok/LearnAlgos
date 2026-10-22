#include <iostream>

using namespace std;

unsigned long long fact(int n) {
    unsigned long long ans = 1;
    if(n==1) {
        return ans;
    }
    else {
        ans=n*fact(n-1);
    }

    return ans;
}

unsigned long long NextPoint(unsigned long long need, unsigned long long count) {

    unsigned long long combos = (fact(count))/(fact(need)*fact(count-need));
    

    return combos;
}

void print128(__int128 n) {
    if (n == 0) { cout << 0; return; }
    string s = "";
    while (n > 0) {
        s = char('0' + (n % 10)) + s;
        n /= 10;
    }
    cout << s;
}

unsigned long long funcSys1(int need, int count) {
    unsigned long long ans = 0;
    for(int i1 = 1;i1<=count;i1++) {
        for(int i2 = i1+1;i2<=count;i2++) {
            for(int i3 = i2+1;i3<=count;i3++) {
                ans +=1;
            }
        }
    }


    return ans;
}

unsigned long long funcWeb2(int need, int count) {
    unsigned long long ans = 0;

    for(int i1 = 1;i1<=count;i1++) {
        for(int i2 = i1+1;i2<=count;i2++) {
            for(int i3 = i2+1;i3<=count;i3++) {
                for(int i4 = i3+1;i4<=count;i4++) {
                    for(int i5 = i4+1;i5<=count;i5++) {
                        for(int i6 = i5+1;i6<=count;i6++) {
                            for(int i7 = i6+1;i7<=count;i7++) {
                                ans +=1;
                            }
                        }
                    }
                }
            }
        }
    }


    return ans;
}

int main() {

    int Web1=20;
    int Web2=40;
    int App=15;
    int Sys1=32;
    int Sys2=18;

    // 3 Web1; 7 Web2; 5 App; 3 Sys1; 2 Sys2

    __int128 ans = 1;

    ans*= NextPoint(3, Web1)*funcWeb2(7,Web2);
    ans*=  NextPoint(5, App);
    ans*= funcSys1(3,Sys1)*NextPoint(2,Sys2);
    print128(ans);
}