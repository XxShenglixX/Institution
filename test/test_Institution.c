#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include <stdio.h>
#include "CException.h"
#include "ErrorCode.h"

LinkedList inList;
LinkedList outList;

Stack stackInstance;

void setUp(void)
{
}

void tearDown(void)
{
}

/* Institution Reverse */
 void test_explore_InstitutionReverse_given_NULL_should_return_0_and_empty_list()
{
	int counter ;
	
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	
	Stack_create_ExpectAndReturn(&stackInstance);
	
	List_removeHead_ExpectAndReturn(&inList,NULL);

	counter = Institution_reverse(&inList,outList);	
	//TEST_ASSERT_EQUAL(NULL,&outList);
	TEST_ASSERT_EQUAL(0,counter);
}


 void test_explore_InstitutionReverse_given_TARUC_should_return_1_for_reversed_list()
{
	int counter ;
	
	Institution TARUC = {"TARUC","KL",53300,12345678,UniversityCollege,1950};
	
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



/*isUniversityCollege */
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

/*Institution select by type */
void test_explore_Institutionselect_bytype_given_University_and_USM_UTAR_should_return_2()
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

void test_explore_Institutionselect_bytype_given_College_and_USM_UTAR_should_return_0()
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


/*wasEstablishedBefore */
void test_explore_wasEstablishedBefore_given_year_1988_UTAR_year2000_should_return_0()
{
	int result , year = 1998;
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	CEXCEPTION_T err ;
	
	Try
	{
		result = wasEstablishedBefore(&UTAR,&year);
	}
	Catch(err)
	{
		TEST_FAIL_MESSAGE("Should not generate any error");
	}
	
	TEST_ASSERT_EQUAL(0,result);
}

void test_explore_wasEstablishedBefore_given_year_2000_UTAR_year2014_should_return_1()
{
	int result , year = 2014;
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2014};
	CEXCEPTION_T err ;
	
	Try
	{
		result = wasEstablishedBefore(&UTAR,&year);
	}
	Catch(err)
	{
		TEST_FAIL_MESSAGE("Should not generate any error");
	}
	
	TEST_ASSERT_EQUAL(1,result);
}

void test_explore_wasEstablishedBefore_given_year_2000_UTAR_year2015_should_throw_err()
{
	int result , year = 2000;
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2015};
	CEXCEPTION_T err ;
	
	Try
	{
		result = wasEstablishedBefore(&UTAR,&year);
		TEST_FAIL_MESSAGE("Should generate error due to invalid year");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_INVALID_YEAR,err);
		printf("Error [%d] : Year is larger than 2014 ",err);
	}
	
}

/*Institution Select by year */
void test_explore_Institutionselect_byyear_given_2000_and_INTI_USM_UTAR__KDU_should_return_3()
{
	int selected = 0;
	int year = 2000 ;
	Institution INTI = {"INTI","Penang",99999,87645612,College,1994};
	Institution USM = {"USM","Penang",99999,87645612,University,2000};
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	Institution KDU = {"KDU","Penang",99999,87645612,College,2000};
	
	List_removeHead_ExpectAndReturn(&inList,&INTI);

	List_removeHead_ExpectAndReturn(&inList,&USM);
	List_addTail_Expect(&outList,&USM);
	
	List_removeHead_ExpectAndReturn(&inList,&UTAR);
	List_addTail_Expect(&outList,&UTAR);
	
	List_removeHead_ExpectAndReturn(&inList,&KDU);
	List_addTail_Expect(&outList,&KDU);
	
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	selected = Institution_select(&inList,&outList,&year,wasEstablishedBefore);
	TEST_ASSERT_EQUAL(3,selected);
}

void test_explore_Institutionselect_byyear_given_1994_and_INTI_USM_UTAR__KDU_should_return_1()
{
	int selected = 0;
	int year = 1994 ;
	Institution INTI = {"INTI","Penang",99999,87645612,College,1994};
	Institution USM = {"USM","Penang",99999,87645612,University,2000};
	Institution UTAR = {"UTAR","KAMPAR",99999,87645612,University,2000};
	Institution KDU = {"KDU","Penang",99999,87645612,College,2000};
	
	List_removeHead_ExpectAndReturn(&inList,&INTI);
	List_addTail_Expect(&outList,&INTI);
	
	List_removeHead_ExpectAndReturn(&inList,&USM);
	List_removeHead_ExpectAndReturn(&inList,&UTAR);
	List_removeHead_ExpectAndReturn(&inList,&KDU);
	List_removeHead_ExpectAndReturn(&inList,NULL);
	
	selected = Institution_select(&inList,&outList,&year,wasEstablishedBefore);
	TEST_ASSERT_EQUAL(1,selected);
}

void test_explore_Institutionselect_byyear_given_1994_and_MyUniversity_should_return_0_and_err()
{
	int selected = 0;
	int year = 1994 ;
	CEXCEPTION_T err;
	
	Institution MyUniverisity = {"MyUniversity","Penang",99999,87645612,University,2020};

	Try
	{
		List_removeHead_ExpectAndReturn(&inList,&MyUniverisity);
		selected = Institution_select(&inList,&outList,&year,wasEstablishedBefore);
		TEST_FAIL_MESSAGE("Should generate error due to invalid year");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_INVALID_YEAR,err);
		printf("Error [%d] : The year of establishment is larger than 2014 ",err);
	}
	
	TEST_ASSERT_EQUAL(0,selected);
}