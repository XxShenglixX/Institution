#include "Institution.h"
#include <stdio.h>
#include <Stack.h>
#include <LinkedList.h>

int Institution_reverse(LinkedList *inputList,LinkedList *outputList)
{

	Stack *newStack = Stack_create();
	Institution *data = (Institution *)List_removeHead(inputList);
	
	Stack_push(newStack,(Institution *)data);
	
	//Stack_push(newStack,inputList->head);
	
	
}