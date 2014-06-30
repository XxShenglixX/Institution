#include "Institution.h"
#include <stdio.h>
#include "Stack.h"
#include "LinkedList.h"
#include "CException.h"
#include "ErrorCode.h"

/**
 * Reverse the order of element
 * Input :
 *		inputList	is a list of institution
 *		outputList	is a list of institution in reversed order
 *
 * Return :
 *		the number of element reversed
 */
int Institution_reverse(LinkedList *inputList,LinkedList *outputList)
{
	int counter = 0, firstCount = 1 ;
	Institution *input ,*output ;

	Stack *newStack = Stack_create();
	
	do
	{
		input = (Institution *)List_removeHead(inputList);
		if(firstCount == 1 && input == NULL)
			{
				outputList = NULL ;
				return 0;
			}
		else 
			firstCount = 0 ;
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

/**
 * Select only institution of a particular type
 * Input :
 *		inputList	is a list of institution
 *		outputList	is a list of selected institutions
 *		criterion	is a pointer of the criterion of selection
 *
 * Return :
 *		the number of element reversed
 */
int Institution_select(LinkedList *inputList,LinkedList *outputList,void *criterion,
					   int (*compare)(void *,void *))
{					   
	Institution *head ;
	int selected = 0 ,result;
	
	do 
	{
		head = (Institution *)List_removeHead(inputList);
		if (head !=NULL) // will cause bad memory without this statement
			result = compare(head,criterion);
		if (result == 1 && head !=NULL)
			{
				List_addTail(outputList,head);
				selected ++ ;
			}
	}while( head != NULL);
	
	
	return selected;
}		


/**
 * Compare if institutions are of the same type
 * Input :
 *		elem1	is a pointer to the first institution
 *		type 	is a pointer to UniversityCollege type
 *
 * Return :
 *		1 if institution type is same
 *		0 if otherwise
 */
int isUniversityCollege(void *elem1,void *type)
{
	Institution *data = (Institution *)elem1 ;
	
	if ( data->type == *(InstitutionType *)type)
		return 1 ;
		
	return 0;
}

/**
 * Compare if institutions was established before the specified year
 * Input :
 *		elem1	is a pointer to the first institution
 *		year 	is a pointer to year
 *
 * Return :
 *		1 if institution year is the same
 *		0 if otherwise
 */
int wasEstablishedBefore(void *elem,void *year)
{
	Institution *data = (Institution *)elem ;
	
	if(data->yearEstablished >2014)
		Throw(ERR_INVALID_YEAR);
	
	if (data->yearEstablished == *(int *) year )
		return 1;
		
	return 0 ;
}		