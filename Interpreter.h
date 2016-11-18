/// Interpreter.h
/// By: Ibrahim Sardar

#ifndef INTERPRETER_H_EXISTS
#define INTERPRETER_H_EXISTS

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "ExpQueue.h"
#include "ExpStack.h"
#include "LinkedList.h"



class Interpreter{

    private:
        ExpQueue* expqueue;
        ExpStack* expstack;

    public:
        LinkedList* expList;

        Interpreter();
        ~Interpreter();
        void getExp();
        void parse();
        vector<string> tokenize(string);
        bool isBalanced( vector<string> );
        string oppositeFence( string );
        LinkedList* getExpList(); // returns a pointer of type LinkedList

};//end class



#endif

