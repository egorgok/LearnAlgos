#include <iostream>
#include <vector>

using namespace std;


int binSearch(vector<int> &vec, int min, int max, int X) {
    int index = -1; // Наш индекс 

    if(min>max) { // Не нашли
        return index; 
    }

    int mid=(max+min)/2; // Опорное число

    if(vec[mid]==X) { // Если нашли
        index = mid;
        return index;
    }

    if(vec[mid]>X) { // искомое меньше
        return binSearch(vec, min, mid-1, X);
    }
    else { // искомое больше
        return binSearch(vec, mid+1, max, X);
    }


    return index;
}


int main() {
    int n; // Размер массива
    cin >> n;
    vector<int> mas(n); // Наш массив

    for(int i =0;i<n;i++) { // Заполнение массива 
        cin >> mas[i];
    }

    int X; // То что мы ищем 
    cin >> X;

    cout << binSearch(mas, 0, mas.size()-1, X); // Применение бинарного поиска

}