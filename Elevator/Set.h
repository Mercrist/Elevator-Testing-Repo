#pragma once
#include <iostream>
using namespace std;


/**
* @file Set.h
*
* @brief A set implemented with a singly linked list. Utilized to store the requested floors.
*        The set's properties prevent a floor from being requested multiple times.
*
* @author Yariel Mercado
*/
class Set{ 
    private:
        /**
        *
        * @brief The node class, the building blocks of the singly linked list. Stores
        *        data, in this class the requested floor, and a reference to the next
        *        node in the singly linked list.
        *
        * @author Yariel Mercado
        */
        class Node{
            private:
                /* The data to be stored in the node, in this case, each floor number. */
                int data;
                /* A reference to the next node in the singly linked list. */
                Node* next;
    
            public:
                /**
                * Gets the next node in the singly linked list.
                * 
                * @return The next node object in the linked list. NULL if it's the last item
                *         in the singly linked list.
                */ 
                Node* getNext(){
                    return next;
                };

                /**
                * Retrieves the current node's value.
                * 
                * @return The current value of the node, in other words, its floor number.
                */ 
                int getValue(){
                    return data;
                };

                /**
                * Sets a reference to the next node in the singly linked list.
                * 
                * @param nextNode The node object of the next node in the list.
                */ 
                void setNext(Node* nextNode){
                    next = nextNode;
                };


                /**
                * Node constructor. Creates a node with the specified data. The next node in the list
                * isn't specified and has a default value of null.
                * 
                * @param elem The value given to the created node.
                */ 
                Node(int elem){
                    data = elem;
                    next = nullptr;
                };

                /**
                * Node constructor. Creates a node with the specified data and the next element in the list.
                * 
                * @param elem The value given to the created node.
                * @param nextNode The node object of the next node in the list.
                */ 
                Node(int elem, Node* nextNode){
                    data = elem;
                    next = nextNode;
                };

                /**
                * Default node constructor. Creates a node with no set data and no references to the next element
                * in the list.
                */ 
                ~Node(){
                    next = NULL;
                }
        };

        /* A node object specifying the head of the singly linked list. */
        Node* head;
        /* The current size of the singly linked list. */
        int currSize = 0;

    public:
        Set();
        Set(int elem);
        ~Set();
        
        void add(int elem);
        int get(int index);
        bool contains(int elem);
        bool remove(int elem);
        void clear(); 
        int size();
        void print();
};