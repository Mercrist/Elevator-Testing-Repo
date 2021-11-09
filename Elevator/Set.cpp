#include "Set.h"

Set::Set()
{
    head = NULL;
}

Set::Set(int elem)
{
    head = new Node(elem);
    currSize++;
}

void Set::add(int elem)
{

    if(head == NULL){
        head = new Node(elem);
    }

    else{
        Node* current = head;

        while(current->getNext() != nullptr){
            if(current->getValue() == elem){ //already in list
                return;
            }
            current = current->getNext();
        }
        
        if(current->getValue() != elem){
            current->setNext(new Node(elem)); 
        }
        else{
            return;
        }
    }
    currSize++;
}

bool Set::contains(int elem)
{

    if(head == NULL){
        return false;
    }

    else{
        Node* current = head;

        while(current != nullptr){
            if(current->getValue() == elem){
                return true;
            }
            current = current->getNext();
        }

        return false; 
    }
}

bool Set::remove(int elem){
    Node* toDelete;
     if(head == NULL){
        return false;
    }

    else if(size() == 1 && head->getValue() == elem){ //remove the head
        head = NULL;
        currSize--;
        return true;

    }

    else if(head->getValue() == elem){ //remove head but theres more elements
        toDelete = head;
        head = head->getNext();
        currSize--;
        delete toDelete; //c++ has no garbage collector
        return true;
    }

    else{
        Node* current = head;

        while(current->getNext() != nullptr){
            if(current->getNext()->getValue() == elem){
                toDelete = current->getNext();
                current->setNext(current->getNext()->getNext());
                currSize--;
                delete toDelete;
                return true;
            }
            current = current->getNext();
        }
    }
    return false;
}

int Set::get(int index)
{
    if(size() < 1 || index >= size()) return -1;

    if(index == 0) return head->getValue();
    Node* current = head;

    for(int i = 0; i < index; i++){
        current = current->getNext();
    }
    
    return current->getValue();
}

void Set::clear()
{
    while(size() != 0){
        remove(head->getValue());
    }
}

void Set::print()
{
    Node* current = head;
    int index = 0;

    while(current != NULL){
        cout << "Index: " + to_string(index) + " with value: " + to_string(current->getValue()) << endl;
        index++;
        current = current->getNext();    
    }
}