#pragma once
#include <iostream>
using namespace std;


//TESTED WITH INTS, WORKS
class Set{ //singly linked

    private:
        class Node{
            private:
                int data;
                Node* next;
    
            public:
                Node* getNext(){
                    return next;
                };

                int getValue(){
                    return data;
                };

                void setNext(Node* nextNode){
                    next = nextNode;
                };

                Node(int elem){
                    data = elem;
                    next = nullptr;
                };

                Node(int elem, Node* nextNode){
                    data = elem;
                    next = nextNode;
                };
        };

        Node* head;
        int currSize = 0;

    public:
        Set();
        Set(int elem);

        void add(int elem);
        int get(int index);
        bool contains(int elem);
        bool remove(int elem);
        void clear(); 
        int size(){return currSize;} 
        void print();
};