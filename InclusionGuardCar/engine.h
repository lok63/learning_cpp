//
// Created by Leonidas Constantinou on 09/01/2021.
//

#ifndef LEARNING_CPP_ENGINE_H
#define LEARNING_CPP_ENGINE_H


#include <string>


class Engine
{
private:
    std::string enginesize;

public:

    Engine ();

    Engine (std::string);

    void setSize(std::string);

    std::string getSize();

};


#endif //LEARNING_CPP_ENGINE_H
