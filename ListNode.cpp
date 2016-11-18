/// ListNode.cpp
/// By: Ibrahim Sardar

#include <iostream>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "ListNode.h"



// constructor
ListNode::ListNode(vector<string> elem, ListNode* nxt){

    element = elem;
    next    = nxt;

}//end construc

// destructor
ListNode::~ListNode(){

    // clear element
    element.clear();

}//end destruc

// element (for public use)
vector<string> ListNode::getElement(){

    return element;

}//end func

// prints all elements
void ListNode::print() {

    for (int i=0; i<element.size(); i++){
        std::cout << " " << element[i];
    }

}//end func
