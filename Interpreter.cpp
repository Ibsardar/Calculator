/// Interpreter.cpp
/// By: Ibrahim Sardar

#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::getline;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Interpreter.h"
#include "ExpQueue.h"
#include "ExpStack.h"
#include "LinkedList.h"
#include "ListNode.h"



// constructor
Interpreter::Interpreter(){

    expqueue = new ExpQueue();
    expstack = new ExpStack();
    expList  = new LinkedList();

}//end construc

// destructor
Interpreter::~Interpreter(){

    delete expqueue;
    delete expstack;
    delete expList;

}//end destruc

// get exp
void Interpreter::getExp(){

    // vars
    string exp;

    // UI
    cout << "Welcome to the Multiple Expression Calculator!\n" << endl;
    cout << "\nIns: type \"end\" on a seperate line to end your input" << endl;
    cout << "please input your expression:" << endl;
    while(true){
        //input
        getline(cin, exp);
        if (exp == "end")
            break;

        //into queue
        if (exp != "")
            expqueue->enqueue(exp);
    }

}//end func

// parse
void Interpreter::parse(){

    // vars
    string         exp;
    vector<string> units;


    // for each exp in queue
    while(expqueue->isEmpty() == false){

        // get exp(s)
        exp = expqueue->dequeue();

        // tokenize
        units = tokenize( exp );

        // check (),[],{}
        if (isBalanced(units) == true){

            // insert node
            ListNode* node = new ListNode(units, NULL);
            expList->insert( node );
        }

        // error
        else
            cout << "ERROR: un-balanced (parenthesis),[brackets], and/or {braces}" << endl;

    }

}//end func

// tokenize
vector< string > Interpreter::tokenize( string exp ){

    // vars
    stringstream     ss;
    string           token;
    vector< string > units;

    //str into ss
    ss.clear();
    ss.str(exp);

    //break up exp
    while( getline(ss, token, ' '))
        units.push_back(token);

    // return parsed exp
    return units;

}//end func

// balance
bool Interpreter::isBalanced( vector< string > units ){



    // check (),[],{}
    for (int i=0; i<units.size(); i++) {

        // opening
        if ( units[i]=="("  ||  units[i]=="["  ||  units[i]=="{" )
            expstack->push( units[i] );

        else

        // closing
        if ( units[i]==")"  ||  units[i]=="]"  ||  units[i]=="}" ){
            if ( expstack->top() == oppositeFence(units[i]) )
                expstack->pop();
            else
                return false;
        }//end if

    }//end loop



    // check for stray
    if ( expstack->isEmpty() == true )
        return true;
    return false;



}//end func

// fence
string Interpreter::oppositeFence( string fence ) {

    fence == ")" ? fence = "(" :    fence == "]" ? fence = "[" :    fence == "}" ? fence = "{" :    NULL;
    return fence;

}//end func

// exp list ptr
LinkedList* Interpreter::getExpList(){

    return expList;

}//end func
