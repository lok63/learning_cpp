//
// Created by Leonidas Constantinou on 09/01/2021.
//

#include "engine.h"

using namespace std;

Engine::Engine () {
    enginesize = "4L";
}

Engine::Engine (string engine) {
    enginesize = engine;
}

void Engine::setSize(string newsize) {
    enginesize = newsize;
}

string Engine::getSize() {
    return enginesize;
}