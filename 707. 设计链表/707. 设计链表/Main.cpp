#include "List.h"

int main(void)
{
	MyLinkedList a;
	a.addAtHead(1);
	a.addAtTail(3);
	a.addAtIndex(1, 2);
	a.get(1);
	a.deleteAtIndex(1);
	a.get(1);

	return 0;
}