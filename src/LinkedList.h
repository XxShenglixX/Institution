#ifndef LinkedList_H
#define LinkedList_H

typedef struct 
{
	void *head;
	void *tail;
}LinkedList;

LinkedList List_create();

void List_addTail(LinkedList *list,void *element);
void *List_removeHead(LinkedList *list);
#endif // LinkedList_H
