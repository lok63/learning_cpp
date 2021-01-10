//
// Created by Leonidas Constantinou on 10/01/2021.
//

#ifndef LEARNING_CPP_MATRIX_H
#define LEARNING_CPP_MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

typedef std::vector < std::vector <float> > vector2DFloat;

class Matrix {

private:

    vector2DFloat grid;
    std::vector<float>::size_type rows;
    std::vector<float>::size_type cols;

public:

    Matrix();                  //1. empty constructor
    Matrix(vector2DFloat);     //2. A constructor function that accepts a 2-dimensional vector

    // Getters and setters
    void setGrid(vector2DFloat);

    vector2DFloat getGrid();
    std::vector<float>::size_type getCols();
    std::vector<float>::size_type getRows();

    // Matrix function declarations
    Matrix transpose();
    Matrix add(Matrix);
    void printMatrix();


};



#endif //LEARNING_CPP_MATRIX_H
