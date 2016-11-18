/// ExpQueue.h
/// By: Ibrahim Sardar

#ifndef EXPSTACK_H_EXISTS
#define EXPSTACK_H_EXISTS

#include <string>
using std::string;

#include <vector>
using std::vector;



class ExpStack{

    private:
        vector< string > stack;

    public:
        int maxSize;

        ExpStack();
        ~ExpStack();
        void   push( string );
        string pop();
        bool   isEmpty();
        string top();

};//end class



#endif

