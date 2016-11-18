/// LinkedList.cpp
/// By: Ibrahim Sardar
///
///
///   Comment Guide:
/// ||^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^||
/// ||  CASE1: LIST = 0, head,tail = NULL     ||
/// ||  CASE2: LIST = 1, head == tail         ||
/// ||  CASE3: LIST > 1, head, ..., tail      ||
/// ||________________________________________||
///
/// *test:
#include <vector>////////////////////////////////
#include <string>/////////////TEST///////////////
#include <iostream>//////////////////////////////

#include "ListNode.h"
#include "LinkedList.h"
//#include "ListNode.cpp"/////////////TEST/////////



// constructor
LinkedList::LinkedList(){

    head = NULL;
    tail = NULL;

}//end construc

// destructor
LinkedList::~LinkedList(){

    std::cout << "\n||||||||| LinkedList D'tor |||||||||" << std::endl;

    // once this is deleted, list will be empty
    print();
    /*
    std::cout << "\n\n --SEG FAULT HERE FOR SOME REASON-- \n"; 7111526
    /// CASE1:
    if ( head == NULL ){ std::cout<<"delete CASE1"; }
        // DO NOTHING!

    /// CASE2:
    else if (head == NULL && tail == NULL) {
        std::cout<<"delete CASE2";
        delete head;
    }

    /// CASE3:
    else {
        std::cout<<"delete CASE3";
        ListNode* node = head;

        while( node != NULL ){
            // traverse & delete list
            head = head -> next;
            delete node; // delete data AT node
            node = head;
        }//end while loop
    }
*/
}//end destruc

// insert
void LinkedList::insert( ListNode* node ){

    /// FOR ALL CASES:
    if ( head == NULL ){
        head = node;
        tail = node;
    } else{
        tail -> next = node;
        tail         = node;
    }

}//end func

// remove
ListNode* LinkedList::removeAtHead(){

    /// CASE1:
    if ( head == NULL ) return NULL;

    /// CASE2:
    else if (head == tail) {
        ListNode* node = head;
        head = NULL;
        tail = NULL;
        return node; // KEEP IN MIND: node -> next == head == NULL
    }

    /// CASE3:
    else {
        ListNode* node = head;
        head = head -> next;
        return node; // KEEP IN MIND: node -> next == head
    }

}//end func

// check empty
bool LinkedList::isEmpty(){

    if ( head == NULL )
        return true;
    return false;

}//end func

// print (TEST FUNCTION) (STATS)
void LinkedList::print(){

    std::cout << "\n||||||||| LinkedList STATS |||||||||" << std::endl;

    ListNode* node = head;
    int n = 0;
    if (node == NULL)
        std::cout << "node is NULL" << std::endl;
    while( node != NULL ){
        n++;
        // traverse & print list data
        node->print(); // delete data AT node
        std::cout << "\n -- node->print() -- " << std::endl;
        std::cout << std::endl;
        node = node -> next;
        std::cout << "\n -- node=node->next -- " << std::endl;
    }//end while loop

    std::cout << "List size: " << n << std::endl;
    std::cout << "\n|||||||||  END List STATS  |||||||||" << std::endl;

}//end TEST func

// clear list
void LinkedList::clear(){

    ListNode* node = head;

    while( node != NULL ){
        // traverse & delete list
        head = head -> next;
        delete node; // delete data AT node
        node = head;
    }//end while loop

}//end func

/*/ *test
int main(){

    LinkedList* list = new LinkedList();

    std::vector<string> vec1;
    vec1.push_back("1 + 32");
    vec1.push_back("1 - 100");
    std::vector<string> vec2;
    vec2.push_back("2 + 3");
    std::vector<string> vec3;
    vec3.push_back("3 * 9");
    vec3.push_back("3 / 1");

    ListNode* a = new ListNode(vec1, NULL);
    ListNode* b = new ListNode(vec2, NULL);
    ListNode* c = new ListNode(vec3, NULL);

    list->insert( a );
    list->insert( b );
    list->insert( c );
    list->print();

    list->removeAtHead();
    list->print();
    list->removeAtHead();
    list->print();
    list->removeAtHead();
    list->print();

    std::cout << "ISEMPTY: " << list->isEmpty() << std::endl;


    delete list;

}
*/
