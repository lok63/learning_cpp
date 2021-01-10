//
// Created by Leonidas Constantinou on 09/01/2021.
//

#ifndef LEARNING_CPP_CAR_H
#define LEARNING_CPP_CAR_H

#include <string>
#include "engine.h"

class Car
{
private:
    std::string color;
    int doors;
    Engine enginetype;

public:
    Car (std::string, int);

    void setColor(std::string);
    void setDoors(int);
    void setEngine(std::string);

    std::string getColor();
    int getDoors();
    std::string getEngine();

};

#endif //LEARNING_CPP_CAR_H
