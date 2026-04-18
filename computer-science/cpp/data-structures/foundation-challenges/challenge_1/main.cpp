// Pointers and Structs

/*
Write 3 lines of code that

1: create a Node on the heap with data = 42
2: set its next to nullptr
3: print its data using the pointer (not a copy)
*/

#include <iostream>

struct Node
{
    int data;
    Node* next;
};

int main()
{
    /*
    "->" = "follow the pointer, then get the member"

    Node object; // stack object -> use "." to access members
    Node* pointer; // heap pointer -> use "->" to access members
    */

    // "new" creates a node on the heap
    Node* my_node = new Node();
    // pointer variable "data" to hold it
    my_node->data = 42;
    
    // use -> for accessing members of pointer
    my_node->next = nullptr;

    // printing via pointer (->) to reach inside it
    std::cout << my_node->data << "\n";

    // Free heap memory
    delete my_node;

    /*
    Summary;

    Since my_node is now equal to new Node() (which is on the heap).
    We can access data & next via;
        my_node -> data or next = ....;

        or equivalently 

        (*my_node).data or .next = ....;
    */

    return 0;
}