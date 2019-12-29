#include "linked_list.h"

int main(void) {
	LinkedList l;
	init(&l);
	print(&l);

	addFirst(&l, 10);
	print(&l);

	addFirst(&l, 20);
	print(&l);
	
	addPost(&l, 1, 30);
	print(&l);

	addPost(&l, 2, 40);
	print(&l);

	addLast(&l, 50);
	print(&l);

	removeItem(&l, 20);
	print(&l);

	removeItem(&l, 10);
	print(&l);

	removeItem(&l, 50);
	print(&l);

	removeItem(&l, 30);
	print(&l);

	addFirst(&l, 90);
	print(&l);

	addPost(&l, 10,  80);
	print(&l);

//	dispose(&l);
	print(&l);
}
