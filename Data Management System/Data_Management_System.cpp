#include <iostream>
#include "Header.h"
using namespace std;

void pre_allocated() { //used to create currently running process (currently on ram)
	singly_linked_list list;
	
	list.allocate_memory(1024, "FREE");
	list.allocate_memory(2048, "FREE");  
	list.allocate_memory(3072, "B");
	list.allocate_memory(1048, "D");
	list.allocate_memory(800, "FREE");
	list.display();
	list.best_fit("C",8100);
	list.display();
}


int main()
{   
	
	pre_allocated();
    

	
}

