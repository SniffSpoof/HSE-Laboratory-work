#include <iostream>
#include <cmath>

using namespace std;

class VolumeFigure3D{
protected:
    double x, y, z;
public:
    VolumeFigure3D(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}

    void printAnchorPoint(){
        cout << "Точка привязки: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void moveFigure(double newX, double newY, double newZ){
        x = newX;
        y = newY;
        z = newZ;
    }

    virtual double calculateSurfaceArea() = 0;

    virtual void scaleFigure(double factor) = 0;
};

class RegularTetrahedron: public VolumeFigure3D{
private:
    double sideLength;
public:
    RegularTetrahedron(double x, double y, double z, double sideLength): VolumeFigure3D(x, y, z), sideLength(sideLength) {}

    void printParameters(){
        cout << "Основные параметры правильного тетраэдра: " << endl;
        printAnchorPoint();
        cout << "Длина стороны: " << sideLength << endl;
    }

    double calculateSurfaceArea() override {
        return sqrt(3) * sideLength * sideLength;
    }

    void scaleFigure(double x) override {
        sideLength *= x;
    }
};

bool compareSurfaceAreas(VolumeFigure3D* figure1, VolumeFigure3D* figure2){
    return figure1->calculateSurfaceArea() > figure2->calculateSurfaceArea();
}

int main(){

    RegularTetrahedron t1 = RegularTetrahedron(0, 0, 0, 2);
    t1.printParameters();
    t1.calculateSurfaceArea();
    t1.scaleFigure(2);
    t1.moveFigure(1, 1, 1);
    t1.printParameters();

    RegularTetrahedron t2 = RegularTetrahedron(0, 0, 0, 2);
    t2.calculateSurfaceArea();

    cout << compareSurfaceAreas(&t1, &t2);

    return 0;
}
