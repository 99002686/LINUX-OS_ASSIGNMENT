/**
* @file test.c
*
*/

#include "unity.h"
#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"
#include <string.h>
#include "test.h"
#include <stdio.h>

void setUp(){}

void tearDown(){}


/**
*  function to check test_case 1
*/
void test_factorial (void)
{
  TEST_ASSERT_EQUAL(1, factorial(0));
  TEST_ASSERT_EQUAL(1, factorial(1));
  TEST_ASSERT_EQUAL(120, factorial(5));
  TEST_ASSERT_EQUAL(3628800, factorial(10));
  TEST_ASSERT_EQUAL(5040, factorial(7));
}

void test_isPalindrome()
{
    TEST_ASSERT_EQUAL(1, isPalindrome(12321));
    TEST_ASSERT_EQUAL(1, isPalindrome(121));
    TEST_ASSERT_EQUAL(1, isPalindrome(1221));
    TEST_ASSERT_EQUAL(1, isPalindrome(3));
    TEST_ASSERT_EQUAL(1, isPalindrome(44));
}

void test_isPrime()
{
    TEST_ASSERT_EQUAL(1, isPrime(599));
    TEST_ASSERT_EQUAL(1, isPrime(347));
    TEST_ASSERT_EQUAL(1, isPrime(937));
    TEST_ASSERT_EQUAL(0, isPrime(676));
    TEST_ASSERT_EQUAL(0, isPrime(708));
}

void test_vsum()
{
    TEST_ASSERT_EQUAL(30, vsum(2,10,20));
    TEST_ASSERT_EQUAL(32, vsum(3,2,10,20));
    TEST_ASSERT_EQUAL(32, vsum(3,2,10,20));
    TEST_ASSERT_EQUAL(42, vsum(4,10,2,10,20));
    TEST_ASSERT_EQUAL(60, vsum(4,10,12,18,20));
}

void test_mystrlen (void)
{
  char str1[] = {"Heisenberg"};
  TEST_ASSERT_EQUAL(10, mystrlen(str1));
  char str2[] = {"Nikola Tesla"};
  TEST_ASSERT_EQUAL(12, mystrlen(str2));
  char str3[] = {"JC Bose"};
  TEST_ASSERT_EQUAL(7, mystrlen(str3));
  char str4[] = {"SIR CV Raman"};
  TEST_ASSERT_EQUAL(12, mystrlen(str4));
}

void test_mystrcat()
{
    char str1[] = {"Morgan"}, str2[] = {"Freeman"};
    TEST_ASSERT_EQUAL(0, mystrcmp("Morgan Freeman", mystrcat(str1, str2)));
    char str3[] = {"Carl"}, str4[] = {"Sagan"};
    TEST_ASSERT_EQUAL(-1, mystrcmp("Car Sagan", mystrcat(str3, str4)));
}

void test_mystrcpy (void)
{
  char str1[] = {"asdfg:12345"};
  TEST_ASSERT_EQUAL(1, mystrcmp(str1, mystrcpy("asdfg:12345")));
  char str2[] = {"asdfg:234#$"};
  TEST_ASSERT_EQUAL(1, mystrcmp(str2, mystrcpy("asdfg:234#$")));
  char str3[] = {"asdfg"};
  TEST_ASSERT_EQUAL(1, mystrcmp(str3, mystrcpy("asdfg")));
} 

void test_bitAnalysis()
{
    int bit[8] = {0};
    printf("%d", mystrlen("Kailash"));
    TEST_ASSERT_EQUAL(1, set(2, bit));
    TEST_ASSERT_EQUAL(1, flip(3, bit));
    TEST_ASSERT_EQUAL(0, flip(2, bit));
    TEST_ASSERT_EQUAL(0, reset(3, bit));
    TEST_ASSERT_EQUAL(0, query(3, bit));
}


int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_factorial);
  RUN_TEST(test_vsum);
  RUN_TEST(test_isPalindrome);
  RUN_TEST(test_isPrime);
  RUN_TEST(test_mystrlen);
  RUN_TEST(test_mystrcat);
  RUN_TEST(test_mystrcpy);
  RUN_TEST(test_bitAnalysis);
 
  

  /* Close the Unity Test Framework */
  return UNITY_END();
}
