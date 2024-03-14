
#include <iostream>
using namespace std;

class IsoscelesTriangle;

class Point {
friend class IsoscelesTriangle;
private:
    double x;
    double y;
public:
    Point(){
        x = 0;
        y = 0;
        //cout << "Точка с координатами " << x << " " << y << " создана" << endl;
    }
    Point(double xx, double yy){
        x = xx; y = yy;
        //cout << "Точка с координатами " << x << " " << y << " создана" << endl;
    }
    ~Point(){
        //cout << "Точка с координатами " << x << " " << y << " удалена" << endl;
    }
    void output(){
        //cout << "Точка с координатами " << x << " " << y << endl;
    }
    void input(){
        cout << "Введите координаты для точки: ";
        cin >> x >> y;
    }
};

class IsoscelesTriangle {
private:
    Point a;
    Point b;
    Point c;
public:
    IsoscelesTriangle(){
        a = Point(-1, 0);
        b = Point(1, 0);
        c = Point(0, 2);
        cout << "Равнобедренный треугольник с координатами:\n" << a.x << " " << a.y << endl;
        cout << b.x << " " << b.y << endl;
        cout << c.x << " " << c.y << endl;
        cout << "Успешно создан" << endl;
    }
    IsoscelesTriangle(Point A, Point B, Point C){
        a = A;
        b = B;
        c = C;
        cout << "Равнобедренный треугольник с координатами:\n" << a.x << " " << a.y << endl;
        cout << b.x << " " << b.y << endl;
        cout << c.x << " " << c.y << endl;
        cout << "Успешно создан" << endl;
    }
    ~IsoscelesTriangle(){
        cout << "Равнобедренный треугольник с координатами:\n" << a.x << " " << a.y << endl;
        cout << b.x << " " << b.y << endl;
        cout << c.x << " " << c.y << endl;
        cout << "Успешно удалён" << endl;
    }
    void output(){
        cout << "Равнобедренный треугольник с координатами:\n" << a.x << " " << a.y << endl;
        cout << b.x << " " << b.y << endl;
        cout << c.x << " " << c.y << endl;
    }
    void input(){
        a.input();
        b.input();
        c.input();
    }
};


int main()
{
    IsoscelesTriangle c = IsoscelesTriangle();
    c.input();
    c.output();
    return 0;
}
