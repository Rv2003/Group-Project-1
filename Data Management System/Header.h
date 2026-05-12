
using namespace std;


class node  {  
public:
    string process; 
    int memory;
    node* next;

    node() {

        process = "FREE";
        next = NULL;   
        memory =0;

    }

    node(string e,int size) {

        process = e;
        next = NULL;  
        memory = size;
    }
};

class singly_linked_list {

private:
    node* head;
    node* tail;
    int storage;
    bool freeAdded = false;  
    
public:
    int max = 16384;
    singly_linked_list() {  

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
   
    // compaction and coalescing function

    void coalescing() {
        if (head == NULL) return;

        node* current = head;
        node* prev = NULL;

        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        if (tail->process != "FREE") {
            node* newFree = new node();
            newFree->process = "FREE";
            newFree->memory = 0;
            newFree->next = NULL;

            tail->next = newFree;
            tail = newFree;
        }

        
        current = head;
        prev = NULL;

        while (current != NULL) {

            if (current != tail && current->process == "FREE") {

                tail->memory += current->memory;

                if (current == head) {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }

            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    void first_fit(string proce, int size) {
        node* current = head;

        while (current != NULL) {

            if (current->process == "FREE" && current->memory >= size) {

                if (current->memory > size) {
                    node* temp = new node("FREE", current->memory - size);

                    temp->next = current->next;
                    current->next = temp;

                    if (current == tail) {
                        tail = temp;
                    }
                }

                current->memory = size;
                current->process = proce;

                cout << "Allocated using First Fit\n";
                return;
            }

            current = current->next;
        }

        cout << "No suitable block (First Fit)\n";

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


    void worst_fit(string proce, int size) {
    node* current = head;
    node* worst = NULL;

    // Step 1: find largest free block
    while (current != NULL) {

        if (current->process == "FREE" && current->memory >= size) {

            if (worst == NULL || current->memory > worst->memory) {
                worst = current;
            }
        }

        current = current->next;
    }

    // Step 2: if no block found
    if (worst == NULL) {
        cout << "No suitable block (Worst Fit)\n";
        return;
    }

    // Step 3: allocate memory
    if (worst->memory > size) {

        node* temp = new node("FREE", worst->memory - size);

        temp->next = worst->next;
        worst->next = temp;

        if (worst == tail) {
            tail = temp;
        }
    }

    worst->memory = size;
    worst->process = proce;

    cout << "Allocated using Worst Fit\n";
}



void free_process(string p) {
    node* curr = head;

    while (curr != NULL) {

        if (curr->process == p) {
            curr->process = "FREE";

            cout << "Process Freed\n";
            return;
        }

        curr = curr->next;
    }

    cout << "Process Not Found\n";
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
    void reset() {

        
        node* current = head;

        while (current != NULL) {
            node* temp = current;
            current = current->next;
            delete temp;
        }

       
        head = NULL;
        tail = NULL;

        max = 16384;
        storage = 0;
        freeAdded = false;

       
        allocate_memory(1024, "FREE");
        allocate_memory(2048, "FREE");
        allocate_memory(3072, "B");
        allocate_memory(1048, "D");
        allocate_memory(800, "FREE");
    }
};