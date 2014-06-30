#include "Institution.h"
#include <stdio.h>
#include <Stack.h>
#include <LinkedList.h>

int Institution_reverse(LinkedList *inputList,LinkedList *outputList)
{
	int counter = 0;
	Institution *input ,*output ;

	Stack *newStack = Stack_create();
	
	do
	{
		input = (Institution *)List_removeHead(inputList);
		if(input!= NULL)	
			Stack_push(newStack,input);
			
	}while (input != NULL);
	
	do
	{
		output = (Institution *)Stack_pop(newStack);
		if(output !=NULL)
			{
				List_addTail(outputList,output);
				counter ++ ;
			}
	}while (output != NULL);
	

	
	return counter ;
}

int isUniversityCollege(void *elem1,void *type)
{
	InstitutionType UCtype = *(InstitutionType *)type ;
	Institution *data = (Institution *)elem1 ;
	
	if ( data->type == UCtype)
		return 1 ;
		
	return 0;
}

int Institution_select(LinkedList *inputList,LinkedList *outputList,void *criterion,
					   int (*compare)(void *,void *))
{					   
	Institution *head ;
	int selected = 0 ,result;
	
	do 
	{
		head = (Institution *)List_removeHead(inputList);
		if (head !=NULL)
			result = compare(head,criterion);
		if (result == 1 && head !=NULL)
			{
				List_addTail(outputList,head);
				selected ++ ;
			}
	}while( head != NULL);
	
	
	return selected;
}				