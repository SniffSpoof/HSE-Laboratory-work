#include <iostream>

using namespace std;

class ComplexNumber{
private:
    double real;
    double imaginary;

public:
    ComplexNumber(): real(0.0), imaginary(0.0) {}// По умолчанию

    ComplexNumber(double r, double i){// По заданным
        real = r;
        imaginary = i;
    }

    ~ComplexNumber(){}// Деструктор

    void setr(double var) {real = var;}
    void seti(double var) {imaginary = var;}

    double getr() const {return real;}
    double geti() const {return imaginary;}
};

ostream& operator << (ostream &os, const ComplexNumber &complexnumber){// Перегрузка вывода
    return os << complexnumber.getr() << " + " << complexnumber.geti() << "*i" << endl;
}

istream& operator >> (istream& in, ComplexNumber& complexnumber){// Перегрузка ввода
    cout << "Введите вещественную и мнимую части: ";
    double r;
    double i;
    in >> r >> i;
    complexnumber.setr(r);
    complexnumber.seti(i);
    return in;
}

void operator - (ComplexNumber c1, ComplexNumber c2){// Перегрузка бинарного минуса
    double r1 = c1.getr();
    double r2 = c2.getr();
    double i1 = c1.geti();
    double i2 = c2.geti();

    cout << "Вычитание: " << r1-r2 << " + " << i1-i2 << "*i" << endl;
}


class MassiveComplexNumbers{
private:
    int size;
    ComplexNumber* array;
public:
    MassiveComplexNumbers(int n){// Массив  комплексных чисел произвольной длинны
        size = n;
        array = new ComplexNumber[size];
    }

    ~MassiveComplexNumbers(){// Деструктор
        delete[] array;
    }

    ComplexNumber& operator[](int index){// Перегрузка оператора обращения по индексу
        return array[index];
    }

    void show(){// Показать весь массив
        for(int i = 0; i < size; i++) cout << array[i];
    }

    MassiveComplexNumbers operator-() const{// Устанавливаем отрицательную вещественную часть
        MassiveComplexNumbers result(size);
        for (int i = 0; i < size; i++){
            double var = array[i].getr();
            result[i].setr(-var);
            result[i].seti(array[i].geti());
        }
        return result;
    }
};


int main()
{// Тестрирование
    cout << "Созданно 2 комплесных числа" << endl;
    ComplexNumber c1 = ComplexNumber(5, 7);
    ComplexNumber c2 = ComplexNumber(2, 1);
    cout << "Вывод первого" << endl;
    cout << c1;
    cout << "Ввод второго" << endl;
    cin >> c2;

    c1 - c2;
    cout << "Создаем массив 2х комплесных чисел" << endl;
    MassiveComplexNumbers m = MassiveComplexNumbers(2);
    cin >> m[0];
    cin >> m[1];
    cout << "Смотрим массив 2х комплесных чисел после унарного минуса" << endl;
    MassiveComplexNumbers negatedM = -m;
    negatedM.show();
    return 0;
}
