//
// Created by Leonidas Constantinou on 10/01/2021.
//
#include "matrix.h"

// Default Constructor
// Initialise the 2D grid with a 4x4 matrix with zeros
Matrix::Matrix() {
    vector2DFloat defaultGrid (4,std::vector<float>(4,0));
    grid = defaultGrid;
    rows = defaultGrid.size();
    cols = defaultGrid[0].size();
}

// Constructor which receives a new 2D-vector
Matrix::Matrix(vector2DFloat new2DVector) {
    grid = new2DVector;
    rows = new2DVector.size();
    cols = new2DVector[0].size();
}


// setters
void Matrix::setGrid(vector2DFloat new2DVector){
    grid = new2DVector;
}
// Getters
vector2DFloat Matrix::getGrid() {
    return grid;
}
std::vector<float>::size_type Matrix::getCols() {
    return cols;
}
std::vector<float>::size_type Matrix::getRows() {
    return rows;
}

// Matrix Functions
Matrix Matrix::add(Matrix newMatrix){

    // Check if the 2 grids have the same dimensions
    if ((rows != newMatrix.getRows()) || (cols != newMatrix.getCols())) {
        throw std::invalid_argument( "matrices are not the same size" );
    }
    // Initialise an empty 2D vector with the same dimensions as the original
    vector2DFloat result (grid.size(),std::vector<float>(grid[0].size(),0));

    vector2DFloat gridTwo = newMatrix.getGrid();

    // Adding Two matrices
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            result[i][j] = grid[i][j] + gridTwo[i][j];

    //Initialise the Matrix to be returned
    Matrix sumMatrix(result);
    return sumMatrix;
}

Matrix Matrix::transpose() {
    // Initialiase a 2D vector with the original rows and cols reversed
    vector2DFloat transposedGrid (cols, std::vector<float>(rows));

    for(int i=0; i< transposedGrid.size(); ++i){
        for(int j=0; j<transposedGrid[0].size(); ++j){
            transposedGrid[i][j] = grid[j][i];
        }
    }
    return Matrix(transposedGrid);
}

void Matrix::printMatrix() {
    std::cout << std::endl;

    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

