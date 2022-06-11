#include "interface.h"
#include "actions.h"
#include <CUnit/CUnit.h>
#include <err.h>
#include <CUnit/Basic.h>

void run_tests();
void test_matrix();
void test_random0n();
void test_activate();
void test_kill();
void test_isalive();
void test_clipNeigh();
void test_circNeigh();

int main() {
  srand(time(NULL));
  run_tests();
}

void run_tests() {
  if (CU_initialize_registry() != CUE_SUCCESS)
    printf("%s\n","can't initialize test registry" );

  CU_pSuite suit = CU_add_suite("HelperFunctions", NULL, NULL);

  if (CU_get_error() != CUE_SUCCESS) printf("%s\n","error_1" );

  CU_add_test(suit, "test of random0n function", test_random0n);
  CU_add_test(suit, "test of activate function", test_activate);
  CU_add_test(suit, "test of kill function", test_kill);
  CU_add_test(suit, "test of isalive function", test_isalive);
  CU_add_test(suit, "test of matrix function", test_matrix);
  CU_add_test(suit, "test of clipped function", test_clipNeigh);
  CU_add_test(suit, "test of circular function", test_circNeigh);
  
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
}

void test_clipNeigh(){
  int size = 3;
  int **matrix = allocatedMatrix(size);

  matrix[0][0] = 1;matrix[0][1] = 0;matrix[0][2] = 0;
  matrix[1][0] = 0;matrix[1][1] = 1;matrix[1][2] = 1;
  matrix[2][0] = 1;matrix[2][1] = 0;matrix[2][2] = 0;

  CU_ASSERT(numberOfneighbors_clipped(matrix,1,2,size) == 1);
}

void test_circNeigh(){
  int size = 3;
  int **matrix = allocatedMatrix(size);

  matrix[0][0] = 1;matrix[0][1] = 0;matrix[0][2] = 0;
  matrix[1][0] = 0;matrix[1][1] = 1;matrix[1][2] = 1;
  matrix[2][0] = 1;matrix[2][1] = 0;matrix[2][2] = 0;

  CU_ASSERT(numberOfneighbors_circular(matrix,1,2,size) == 3);
}

void test_matrix(){
  int size = 5;
  int **matrix = allocatedMatrix(size);
  matrix = randomMatrix(matrix,size);
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      CU_ASSERT_TRUE(matrix[i][j]>=0 && matrix[i][j]<=1);
}

void test_random0n() {
  int result;
  for(int i=0;i<5;i++) {
    result = random0n(100);
    CU_ASSERT_TRUE(result>=0 && result<100);
  }
}

void test_activate(){
	int n = activate();
	CU_ASSERT(n==1);
}

void test_kill(){
	int n = kill();
	CU_ASSERT(n==0);
}

void test_isalive(){
	int alive = isalive(1);
	int dead = isalive(0);
	int error = isalive(5);
	CU_ASSERT(alive == 1);
	CU_ASSERT(dead == 0);
	CU_ASSERT(error == -1);
}

