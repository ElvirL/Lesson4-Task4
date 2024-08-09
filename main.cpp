/*
Задача 4
Что нужно сделать:
Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.
Пример:
Массив {-100,-50, -5, 1, 10, 15}
Вывод: 1, -5, 10, 15, -50, -100

Советы и рекомендации:
Положительные числа уже отсортированы в порядке возрастания модулей.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");
    cout << "Введите количество элементов массива: ";
    int n;
    cin >> n;
    cout << "Введите элементы массива: ";
    vector<int> v(n);
    for (int i=0; i<n; ++i){
        cin >> v[i];
    }

    int index1=0;
    while (index1 < v.size() && v[index1] < 0){
        ++index1;
    }

    vector<int> sort_vector;

    if (index1 == v.size()){
        for (int i= v.size()-1; i>=0; --i){
            cout << v[i] << " ";
        }
    }
    else if (index1 == 0){
        for (size_t i=0; i< v.size(); ++i){
            cout << v[i] << " ";
        }
    }
    else {
        int index2 = index1-1;

        while (index1 != v.size() && index2 >= 0){
            if (v[index1] <= abs(v[index2])){
                sort_vector.push_back(v[index1]);
                ++index1;
            }
            else if (v[index1] >= abs(v[index2])){
                sort_vector.push_back(v[index2]);
                --index2;
            }
            if (index1 == v.size()){
                while (index2 >= 0){
                    sort_vector.push_back(v[index2]);
                    --index2;
                }
            }
            if (index2 < 0){
                while (index1 != v.size()){
                    sort_vector.push_back(v[index1]);
                    ++index1;
                }
            }
        }
    }
   
   for (size_t i=0; i < sort_vector.size(); ++i){
    cout << sort_vector[i] << " ";
   }

}