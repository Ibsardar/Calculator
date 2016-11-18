/// LinkedList.h
/// By: Ibrahim Sardar

#ifndef LINKEDLIST_H_EXISTS
#define LINKEDLIST_H_EXISTS

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "ListNode.h"



class LinkedList{

    public:
        ListNode* head;
        ListNode* tail;

        LinkedList();
        ~LinkedList();
        void insert( ListNode* );
        ListNode* removeAtHead();
        bool isEmpty();
        void print();
        void clear();

};//end class



#endif

