///Calculator.cpp
///By: Ibrahim Sardar

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include "Calculator.h"
#include "Interpreter.h"
#include "Evaluator.h"
#include "LinkedList.h"



// constructor
Calculator::Calculator(){
    interpreter = new Interpreter();
    evaluator   = new Evaluator();
    expList     = NULL;

}//end construc

// destructor
Calculator::~Calculator(){
    delete interpreter;
    delete evaluator;
    delete expList; // --SEG FAULT HERE FOR SOME REASON--

}//end destruc

// interpret
void Calculator::interpretExp(){
    interpreter -> getExp();
    interpreter -> parse();
    expList = interpreter -> getExpList();
    cout << "SEG FAULT LIST (interpretExp): \n";
    expList -> print();

}//end func

// evaluate
void Calculator::eval(){

    while (expList->isEmpty() == false) {

        // evaluate an expression
        evaluator -> getExp( expList->removeAtHead()->getElement() );
        evaluator -> infix2postfix();
        evaluator -> printPostfix();
        cout << "\nAnswer: " << evaluator -> eval() << endl;
        evaluator -> reset();
    }
    cout << "SEG FAULT LIST (eval): \n";
    expList -> print();
    expList = NULL;

}//end func
