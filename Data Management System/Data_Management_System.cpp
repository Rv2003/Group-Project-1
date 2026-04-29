#include <iostream>
#include "Header.h"
using namespace std;

void pre_allocated() { //used to create currently running process (currently on ram)
	singly_linked_list list;
	
	list.allocate_memory(1024, "A");
	list.allocate_memory(2048, "FREE");  
	list.allocate_memory(3072, "B");
	list.allocate_memory(2048, "FREE");
	list.allocate_memory(3072, "C");
	list.display();
}


int main()
{   
	
	pre_allocated();


	
}

