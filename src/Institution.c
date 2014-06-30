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
			{
				Stack_push(newStack,input);
				printf("input :%s\n",input->name);
			}	
	}while (input != NULL);
	
	// output = (Institution *)Stack_pop(newStack);
	// printf("output :%s\n\n",output->name);
	// List_addTail(outputList,output);
	// output = (Institution *)Stack_pop(newStack);
	// printf("output :%s\n\n",output->name);
	// List_addTail(outputList,output);
	
	do
	{
		output = (Institution *)Stack_pop(newStack);
		if(output !=NULL)
			{
				printf("output :%s\n",output->name);
				List_addTail(outputList,output);
				counter ++ ;
			}
	}while (output != NULL);
	

	
	return counter ;
}

int isUniversityCollege(void *elem1,void *type)
{
	InstitutionType UCtype = *(InstitutionType *)type ;
	printf("\ntype :%d\n",UCtype);

	Institution *data = (Institution *)elem1 ;
	printf("data UCtype :%d\n",data->type);
	
	if ( data->type == UCtype)
		return 1 ;
		
	return 0;
}

int Institution_select(LinkedList *inputList,LinkedList *outputList,void *criterion,
					   int (*compare)(void *,void *))
{					   
	Institution *head ,*output ;
	int selected = 0 ,result;
	
	Stack *newStack = Stack_create();
	
	head = (Institution *)List_removeHead(inputList);
	printf("\nInstituteSelect :%s\n",head->name);
	
	result = compare(head,criterion);
	printf("Same ? : %d\n",result);
	
	if (result == 1)
	{
		
	}
	
	return selected;
}				