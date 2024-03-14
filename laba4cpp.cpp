#include <iostream>

using namespace std;

class MyVector;

void operator != (MyVector& myvector, double var);

class MyVector {
friend void operator != (MyVector& myvector, double var);
private:
    double x0;
    double y0;
    double x1;
    double y1;
public:
    MyVector(){
        x0 = 0;
        y0 = 0;
        x1 = 1;
        y1 = 1;
        cout << "Вектор с началом {" << x0 << ";" << y0 << "}, и концом {" << x1 << ";" << y1 << "} создан" << endl;
    }
    MyVector(double x00, double y00, double x11, double y11){
        x0 = x00;
        y0 = y00;
        x1 = x11;
        y1 = y11;
        cout << "Вектор с началом {" << x0 << ";" << y0 << "}, и концом {" << x1 << ";" << y1 << "} создан" << endl;
    }
    ~MyVector(){
        cout << "Вектор с началом {" << x0 << ";" << y0 << "}, и концом {" << x1 << ";" << y1 << "} удален" << endl;
    }

    double getx0() const {return x0;}
    double gety0() const {return y0;}
    double getx1() const {return x1;}
    double gety1() const {return y1;}

    void setx0(double var) {x0 = var;}
    void sety0(double var) {y0 = var;}
    void setx1(double var) {x1 = var;}
    void sety1(double var) {y1 = var;}

    void operator >= (double var){
        x1 += var;
        cout << "Сдвинули конец по Х на " << var << endl;
    }
};

ostream& operator << (ostream &os, const MyVector &myvector)
{
    return os << "Вектор с началом " << "{" << myvector.getx0() << ";" << myvector.gety0() << "}" << " и концом" << " {" << myvector.getx1() << ";" << myvector.gety1() << "}" << endl;
}

istream& operator >> (istream& in, MyVector& myvector)
{
    cout << "Введите координаты вектора: ";
    double x0;
    double y0;
    double x1;
    double y1;
    in >> x0 >> y0 >> x1 >> y1;
    myvector.setx0(x0);
    myvector.sety0(y0);
    myvector.setx1(x1);
    myvector.sety1(y1);
    return in;
}

void operator != (MyVector& myvector, double var) {
    myvector.y1 += var;
    cout << "Сдвинули конец по Y на " << var << endl;
}

int main()
{
    MyVector c = MyVector(0, 0, 5, 1);
    cin >> c;
    cout << c;
    cout << endl;

    c >= 3;
    cout << c;
    cout << endl;

    c != 4;
    cout << c;

    cout << endl;

    return 0;
}
