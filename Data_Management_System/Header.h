#pragma once
using namespace std;


class node  {  
public:
    string process; // to store the process name
    int memory;
    node* next;

    node() {

        process = "FREE";
        next = NULL;   //default constructor
        memory =0;

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
    int max = 16384;
    singly_linked_list() {  //input the size of the memory block

        head = NULL;
        tail = NULL;
        storage = 0;

    }

    void allocate_memory(int mem, string k) {
        node* temp;
       
        if (max >= mem) {
            temp = new node(k, mem);

            if (head == NULL) {
                head = tail = temp;

            }
            else {
                tail->next = temp;
                tail = temp;

            }
            max= max - mem;
           
            storage = storage + mem;    // to keep track of the used memorys              
        }
        else {
            cout << "FULL";
        }

    }

    void display() {

       // if (max > 0) {
           // node* freeBlock = new node("FREE", max);  // ONE free block at the end
           // tail->next = freeBlock;
           // tail = freeBlock;

           //error fixing to just print without adding a free block at the end,
          


        if (head == NULL) {
            cout << "Memory is empty." << endl;
            return;
        }

        node* curr = head;
        int address = 0;

        cout << "------------------------------------------" << endl;
        cout << "| Start Addr | Process | Size (KB)      |" << endl;
        cout << "------------------------------------------" << endl;

        while (curr != NULL) {
            cout << "| " << address
                << "\t\t| " << curr->process
                << "\t  | " << curr->memory << " KB"
                << "\t\t|" << endl;
            address += curr->memory;
            curr = curr->next;
        }

        // just free block print

            if (max > 0) {
         cout << "| " << address
         << "\t\t| FREE"
         << "\t  | " << max << " KB\t\t|" << endl;
        }


        cout << "------------------------------------------" << endl;
        cout << "Total Used: " << storage << " KB" << endl;
    }

};