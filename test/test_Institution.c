#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include <stdio.h>

LinkedList inList;
LinkedList outList;

Stack stackInstance;

void setUp(void)
{
}

void tearDown(void)
{
}

 void test_explore_InstitutionReverse_given_TARUC_should_return_1_for_reversed_list()
{
	int counter ;
	
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	
	inList.head = &TARUC;
	
	Stack_create_ExpectAndReturn(&stackInstance);
	
	List_removeHead_ExpectAndReturn(&inList,&TARUC);
	Stack_push_Expect(&stackInstance,&TARUC);
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	Stack_pop_ExpectAndReturn(&stackInstance,&TARUC);
	List_addTail_Expect(&outList,&TARUC);
	Stack_pop_ExpectAndReturn(&stackInstance,NULL);
	
	
	counter = Institution_reverse(&inList,&outList);	
	TEST_ASSERT_EQUAL(1,counter);
} 

 void test_explore_InstitutionReverse_given_TARUC_UTAR_should_return_2_for_reversed_list()
{
	int counter ;
	
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	
	Stack_create_ExpectAndReturn(&stackInstance);
	
	List_removeHead_ExpectAndReturn(&inList,&TARUC);
	Stack_push_Expect(&stackInstance,&TARUC);
	
	List_removeHead_ExpectAndReturn(&inList,&UTAR);
	Stack_push_Expect(&stackInstance,&UTAR);
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	Stack_pop_ExpectAndReturn(&stackInstance,&UTAR);
	List_addTail_Expect(&outList,&UTAR);
	
	Stack_pop_ExpectAndReturn(&stackInstance,&TARUC);
	List_addTail_Expect(&outList,&TARUC);
	Stack_pop_ExpectAndReturn(&stackInstance,NULL);
	
	
	counter =Institution_reverse(&inList,&outList);	
	TEST_ASSERT_EQUAL(2,counter);
}   

void test_explore_isUniversityCollege_given_UniversityCollege_should_return_1()
{
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	InstitutionType UCtype = UniversityCollege ;
	
	TEST_ASSERT_EQUAL(1,isUniversityCollege(&TARUC,&UCtype));
}

void test_explore_isUniversityCollege_given_University_should_return_0()
{
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	InstitutionType UCtype = University ;
	
	TEST_ASSERT_EQUAL(0,isUniversityCollege(&TARUC,&UCtype));
}

void test_explore_Institution_select_given_University_and_USM_UTAR_should_return_2()
{
	int selected ;
	InstitutionType UCtype = University ;
	Institution USM = {"USM","Penang",99999,87645612,University,2000};
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	
	List_removeHead_ExpectAndReturn(&inList,&USM);
	List_addTail_Expect(&outList,&USM);
	
	List_removeHead_ExpectAndReturn(&inList,&UTAR);
	List_addTail_Expect(&outList,&UTAR);
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	selected = Institution_select(&inList,&outList,&UCtype,isUniversityCollege);
	TEST_ASSERT_EQUAL(2,selected);
}

void test_explore_Institution_select_given_College_and_USM_UTAR_should_return_0()
{
	int selected ;
	InstitutionType UCtype = College ;
	Institution USM = {"USM","Penang",99999,87645612,University,2000};
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	
	List_removeHead_ExpectAndReturn(&inList,&USM);
	List_removeHead_ExpectAndReturn(&inList,&UTAR);
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	selected = Institution_select(&inList,&outList,&UCtype,isUniversityCollege);
	TEST_ASSERT_EQUAL(0,selected);
}

