/// ExpQueue.cpp
/// By: Ibrahim Sardar



#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "ExpQueue.h"



// constructor
ExpQueue::ExpQueue(){

    maxSize = 50;

}//end construc

// destructor
ExpQueue::~ExpQueue(){

    queue.clear();

}//end destruc

// enqueue
void ExpQueue::enqueue( string exp ){

    if ( queue.size() < maxSize )
        queue.push_back( exp );
    else
        cout << "ERROR: queue has reached maxSize; too many expressions\n   =>extra expressions will be ignored..." << endl;

}//end func

// dequeue
string ExpQueue::dequeue(){

    string exp;

    if ( queue.size() > 0 ){
        exp = queue[0];
        queue.erase( queue.begin() );
    }else
        return "";

    return exp;

}//end func

bool ExpQueue::isEmpty(){

    return ( queue.size() > 0 ? false : true );

}//end func
