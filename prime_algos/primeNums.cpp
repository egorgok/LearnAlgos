#include <iostream>
#include <vector>

using namespace std;


vector<long long> Primes(long long n) {
   
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

    return primas; // Передаем в main() разбиённую n
}


int main() {
    long long n;
    cin >> n;

    vector<long long> ans; // Вектор для ответа
    ans = Primes(n); // Получаем вектор с простыми миножителями n

    for(int i = 0;i<ans.size();i++) { // Вывод
        cout << ans[i] << " ";
    }
}