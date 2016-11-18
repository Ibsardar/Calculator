/// Evaluator.h
/// By: Ibrahim Sardar

#ifndef EVALUATOR_H_EXISTS
#define EVALUATOR_H_EXISTS

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "ExpStack.h"



class Evaluator{

    private:
        ExpStack* stack;
        vector< string > infix;
        vector< string > postfix;

        int getPrecedence( string );
        string toString( int );
        int toInt( string );

    public:
        Evaluator();
        ~Evaluator();
        void getExp( vector<string> );
        void infix2postfix();
        void printPostfix();
        int eval();
        void reset();

};//end class



#endif

