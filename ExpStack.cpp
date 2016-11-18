/// ExpStack.cpp
/// By: Ibrahim Sardar

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include "ExpStack.h"



// constructor
ExpStack::ExpStack(){

    maxSize = 50;

}//end construc

// destructor
ExpStack::~ExpStack(){

    stack.clear();

}//end destruc

// push
void ExpStack::push( string exp ){

    if ( stack.size() < maxSize )
        stack.push_back( exp );
    else
        cout << "ERROR: stack has reached maxSize; too many characters\n   =>extra characters will be ignored..." << endl;

}//end func

// pop
string ExpStack::pop(){

    string exp;

    if ( stack.size() > 0 ){
        exp = stack[ stack.size()-1 ];
        stack.pop_back(); // remove last element
    }else
        return "";

    return exp;

}//end func

bool ExpStack::isEmpty(){

    return ( stack.size() > 0 ? false : true );

}//end func

string ExpStack::top(){

    if ( stack.size() > 0 ){
        return stack[ stack.size()-1 ];
    }else
        return "";

}//end func
