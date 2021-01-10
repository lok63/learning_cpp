#include <iostream>
#include "InclusionGuardCar/engine.h"
#include "InclusionGuardCar/car.h"
#include "matrix/matrix.h"

using namespace std;

void run_car_example();
void runMatrixExample();

int main() {
    runMatrixExample();
    return 0;
}

void runMatrixExample(){
    cout << "MATRIX EXAMPLE"  << endl;
    Matrix matrix1(vector2DFloat (2,std::vector<float>(4,1)));
    Matrix matrix2(vector2DFloat { {1,1,1,1},
                                  {2,2,2,2}});

    cout << "matrix1";
    matrix1.printMatrix() ;
    cout << "matrix2";
    matrix2.printMatrix() ;

    cout << "matrix1 + matrix2";
    Matrix matrix3 = matrix1.add(matrix2);
    matrix3.printMatrix();

    cout << "Transpose of Matrix2";
    Matrix matrix2T = matrix2.transpose();
    matrix2T.printMatrix();
}

void run_car_example(){
    Engine enginelarge("4L");
    Engine enginesmall("2.5L");

    Car carone("red", 5);
    Car cartwo("green", 4);


    cout << "Small engine size "  << enginesmall.getSize() << endl;
    cout << "Large engine size " << enginelarge.getSize() << endl;
    cout << "Car one doors " << carone.getDoors() << endl;
    cout << "Car two doors " << cartwo.getDoors() << endl;

    cout << "Car one engine size " << carone.getEngine() << endl;
    carone.setEngine(enginelarge.getSize());
    cout << "Car one engine size new " << carone.getEngine() << endl;

}