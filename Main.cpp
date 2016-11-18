/** FILE:   Main.cpp
    NAME:   Ibrahim Sardar
    PROJ:   Calculator

**/

#include <iostream>

#include "Calculator.h"
// #include .cpp ONLY for compiling in CODE::BLOCKS
/*
#include "Calculator.cpp"
#include "Interpreter.cpp"
#include "Evaluator.cpp"
#include "ExpQueue.cpp"
#include "ExpStack.cpp"
#include "LinkedList.cpp"
#include "ListNode.cpp"
*/

using namespace std;

int main(int argc, char* argv[]){

    Calculator* device = new Calculator(); //verified

    device -> interpretExp();
    device -> eval();

    delete device;

    return 0;

} // end main
