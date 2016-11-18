/// ExpQueue.h
/// By: Ibrahim Sardar

#ifndef EXPQUEUE_H_EXISTS
#define EXPQUEUE_H_EXISTS

#include <string>
using std::string;

#include <vector>
using std::vector;



class ExpQueue{

    private:
        vector< string > queue;

    public:
        int maxSize;

        ExpQueue();
        ~ExpQueue();
        void   enqueue( string );
        string dequeue();
        bool   isEmpty();

};//end class



#endif

