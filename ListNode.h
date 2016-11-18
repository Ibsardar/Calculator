/// ListNode.h
/// By: Ibrahim Sardar

#ifndef LISTNODE_H_EXISTS
#define LISTNODE_H_EXISTS

#include <string>
using std::string;

#include <vector>
using std::vector;



// *** note:  ListNode does not have maxSize like the stack & queue
class ListNode{
    friend class LinkedList;

    private:
        vector<string> element;
        ListNode* next;

    public:
        ListNode( vector<string>,  ListNode* );
        ~ListNode();
        vector<string> getElement();
        void print();

};//end class



#endif

