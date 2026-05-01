
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
    bool freeAdded = false;  // to fix adding free node at the end repetedly each time calling display
    
public:
    int max = 16384;
    singly_linked_list() {  //input the size of the memory block

        head = NULL;
        tail = NULL;
        storage = 0;

    }

    void allocate_memory(int mem, string k) {
        node* temp;
       
        if (max > mem) {
            temp = new node(k, mem);

            if (head == NULL) {
                head = tail = temp;

            }
            else {
                tail->next = temp;
                tail = temp;

            }
            
            max= max - mem;
               
        }
        else {
            cout << "FULL";
        }

    }



    void best_fit(string proce,int size) {
        node* current = head;
        node* temp = head;
        node* best = NULL;
        node* check = head;
       

        while (current != NULL) {
            if (current->process == "FREE" && current->memory >= size) {
                if (best == NULL || current->memory < best->memory) {
                    best = current;
                }
            }
            current = current->next;
        }


        if (best == NULL) {
            cout << "Memory Full" << endl;
            return;
        }


        if (best->memory>size) {
            node* temp = new node("FREE", best->memory - size);
            best->memory = size;
            best->process = proce;
            node* current= best->next;
            best->next=temp;
            temp->next = current;
            if (best == tail) {
                tail = current;
            }
            
            
             
        }
        else {
            best->memory = size;
            best->process = proce;
        
        }

    
    }

    void display() {
        
        if (max > 0 && !freeAdded) {
            node* freeBlock = new node("FREE", max);
            tail->next = freeBlock;
            tail = freeBlock;
            freeAdded = true;
        }
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

        cout << "------------------------------------------" << endl;
      
    }

};