#pragma once
using namespace std;


class node  {  
public:
    string process; // to store the process name
    int memory;
    node* next;

    node() {

        process = "FREE";
        next = NULL;   //constructor
        memory = NULL;

    }

    node(string e,int size) {

        process = e;
        next = NULL;   //overloaded constructor 
        memory = size;
    }
};

class singly_linked_list {
   
private:
    node* head;
    node* tail;
    int storage;

public:
    singly_linked_list() {  //input the size of the memory block
    
        head = NULL;
        tail = NULL;
        storage = 0;
        
    }

void allocate_memory(int mem,string k) {
    node* temp;
    temp = new node(k, mem);
        if (head == NULL) {
            node* temp;
            temp = new node(k,mem);
            head = tail = temp;
            
        }
        else {
            head->next = temp;
            tail = temp;
            temp->next=NULL;
            head->memory = head->memory - mem;
        }
        
}

};