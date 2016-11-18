/// Evaluator.cpp
/// By: Ibrahim Sardar
/// *** NEEDS FIXING ***

#include <iostream>
using std::cout; using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Evaluator.h"
#include "ExpStack.h"



// constructor
Evaluator::Evaluator(){

    stack = new ExpStack();

}//end construc

// destructor
Evaluator::~Evaluator(){

    delete stack;

    // clear infix, postfix
    infix.clear();
    postfix.clear();

}//end destruc

// get exp
void Evaluator::getExp( vector<string> exp ){

    infix = exp;

}//end func

// infix to postfix
void Evaluator::infix2postfix(){

    // go through infix char-by-char
    for (int i=0; i<infix.size(); i++){

        /// -----------------------------------------------------------||
        ///   POSSIBLE CASES: open(, close), operator, operand, empty* ||
        /// -----------------------------------------------------------||
        //
        // Some cases may be, in a way, redundant
        // only to help clarify the different cases.
        //
        /// CASE1:
        if (infix[i] == "(" || infix[i] == "[" || infix[i] == "{"){

            stack->push( infix[i] );

        }
        /// CASE2:
        else if (infix[i] == ")" || infix[i] == "]" || infix[i] == "}"){

            // (in stack) pop all behind closer "),],}" until opener "(,[,{"
            while (stack->top() != "(" && stack->top() != "[" && stack->top() != "{")
                postfix.push_back( stack->pop() );
            // pop the opener "(,[,{"
            stack->pop();

        }
        /// CASE3:
        else if (infix[i] == "+" || infix[i] == "-" || infix[i] == "*" || infix[i] == "/"){

            // note: can NEVER have more than 2 operators next to each other in stack
            if ( getPrecedence(stack->top()) >= getPrecedence(infix[i]) ){
                postfix.push_back( stack->pop() );

                if ( getPrecedence(stack->top()) >= getPrecedence(infix[i]) ){
                    postfix.push_back( stack->pop() );
                    stack->push( infix[i] );
                }else
                    stack->push( infix[i] );
            }else
                stack->push( infix[i] );

        }
        /// CASE4:
        else
            postfix.push_back( infix[i] );

    }//end huge if

    // empty the rest of the stack into postfix
    while ( stack->isEmpty() == false ){
        postfix.push_back( stack->pop() );
    }


}//end func

// print
void Evaluator::printPostfix() {

    cout << "Postfix:";

    for (int i=0; i<postfix.size(); i++) {

        cout << " " << postfix[i];

    }

}//end func

// evaluate
int Evaluator::eval() {

    int num;

    for (int i=0; i<postfix.size(); i++) {

        //must be at least 2 numbers left in postfix to have operator
        if (postfix[i] == "+"){
            num  = toInt( stack->pop() );
            stack->push(  toString(toInt(stack->pop()) + num)  );

        }else if (postfix[i] == "-"){
            num  = toInt( stack->pop() );
            stack->push(  toString(toInt(stack->pop()) - num)  );

        }else if (postfix[i] == "*"){
            num  = toInt( stack->pop() );
            stack->push(  toString(toInt(stack->pop()) * num)  );

        }else if (postfix[i] == "/"){
            num  = toInt( stack->pop() );
            stack->push(  toString(toInt(stack->pop()) / num)  );

        }else
            stack->push( postfix[i] );

    }

    // stack should have 1 element left
    return toInt(stack->pop());

}//end func

// reset
void Evaluator::reset(){

    infix.clear();
    postfix.clear();

}//end func

// precedence
int Evaluator::getPrecedence( string unit ) {

    if (unit == "*" || unit == "/")
        return 2;
    else if (unit == "+" || unit == "-")
        return 1;
    else
        return 0;

}//end func

// int to string
string Evaluator::toString( int x ){

    stringstream ss;
    ss.clear();

    ss << x;

    return ss.str();

}//end func

// string to int
int Evaluator::toInt( string x ){

    stringstream ss( x );
    ss.clear();

    int i;
    ss >> i;

    return i;

}//end func
