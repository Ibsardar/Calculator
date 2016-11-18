/// Calculator.h
/// By: Ibrahim Sardar

#ifndef CALCULATOR_H_EXISTS
#define CALCULATOR_H_EXISTS

#include "Interpreter.h"
#include "Evaluator.h"
#include "LinkedList.h"



class Calculator{

    private:
        Interpreter * interpreter;
        Evaluator   * evaluator;
        LinkedList  * expList;

    public:
        Calculator();
        ~Calculator();
        void interpretExp();
        void eval();

};//end class



#endif

