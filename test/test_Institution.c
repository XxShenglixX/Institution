#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include <stdio.h>

LinkedList inList ;
LinkedList outList;

Stack stackInstance;

void setUp(void)
{
	inList.head = NULL ;
	inList.tail = NULL ;
}

void tearDown(void)
{
}

void test_InstitutionReverse_explore()
{
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	
	inList.head = &TARUC;
	
	Stack_create_ExpectAndReturn(&stackInstance);
	
	List_removeHead_ExpectAndReturn(&inList,&TARUC);
	Stack_push_Expect(&stackInstance,&TARUC);
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	//Stack_pop_ExpectAndReturn(&stackInstance,&TARUC);
	//List_addTail(&outList,&TARUC);
	
	Institution_reverse(&inList,&outList);
	
	
}

/* void test_InstitutionReverse_explore()
{
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	
	inList.head = &TARUC;
	inList.tail = &UTAR;
	
	Stack_create_ExpectAndReturn(&stackInstance);
	Stack_push_Expect(&stackInstance,&TARUC);
	Stack_push_Expect(&stackInstance,&UTAR);
	
	List_create_ExpectAndReturn(&outList);
	
	Stack_pop_ExpectAndReturn(&stackInstance,&UTAR);
	List_addTail(&outList,&UTAR);
	
	Stack_pop_ExpectAndReturn(&stackInstance,&TARUC);
	List_addTail(&outList,&TARUC);
	
	Institution_reverse(&inList,&outList);
	
	
}
 */