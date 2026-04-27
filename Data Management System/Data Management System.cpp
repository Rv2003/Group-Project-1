#include <iostream>
#include "Header.h"
using namespace std;

void pre_allocated(int A,string B) { //used to create currently running process 
	singly_linked_list list;

	list.allocate_memory(1024,"A");
	list.allocate_memory(2048, "FREE");
	list.allocate_memory(3072, "B");

int main()
{
	

	
}

