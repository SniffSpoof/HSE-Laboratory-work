#include <iostream>

using namespace std;

class DynamicIntArray{
private:
    int* array;
    int size;

public:
    DynamicIntArray(int n, int value){
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++){
            array[i] = value;
        }
    }

    ~DynamicIntArray(){
        delete[] array;
    }

    void input(){
        for (int i = 0; i < size; i++){
            cin >> array[i];
        }
    }

    void output(){
        for (int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void findMinMax(int n){
        int min = array[0];
        int max = array[0];
        for (int i = 0; i < n * 2 && i < size; i += 2){
            if (array[i] < min){
                min = array[i];
            }
            if (array[i] > max){
                max = array[i];
            }
        }
        cout << "Минимальное значение: " << min << endl;
        cout << "Максимальное значение: " << max << endl;
    }
};

int main(){
    int n, value;
    cout << "Введите размер массива: ";
    cin >> n;
    cout << "Введите начальное значение для массива: ";
    cin >> value;

    DynamicIntArray arr(n, value);
    cout << "Элементы массива: ";
    arr.output();

    cout << "Введите " << n << " элементов для массива:" << endl;
    arr.input();

    cout << "Элементы массива: ";
    arr.output();

    int searchCount;
    cout << "Введите количество четных позиций для поиска минимального и максимального значений: ";
    cin >> searchCount;

    arr.findMinMax(searchCount);

    return 0;
}
