/**
 *  insertion sort as a C function
 */
#include <stdio.h>

/**
 * @brief function to perform insertion sort on an array of integers
 *
 * @param input pointer to an integer array
 *
 * @return 0 on sucess
 */
int insertion_sort(int *input, size_t length)
{
  int i,j;
  for (j=2; j<length; ++j)
  {
    // get current key tp sort in
    int key = input[j];
    // set i to one position lower
    i = j - 1;

    // sort keys below
    while (i >= 0 && input[i] > key)
    {
      input[i+1] = input[i];
      i--;
    }

    // the loop terminates with i one position smaller than the correct
    // position for the key, so enter it there
    input[i+1] = key;
  }

  return 0;
}

int main( int argc, const char* argv[] )
{
  int i;
  size_t length = 6;
  int input[] = { 3, 6, 4, 1, 2, 5};
  insertion_sort(&input[0], length);
  for (i=0; i<length;++i)
  {
    printf("%i", input[i]);
  }
  printf("\n");
  return 0;
}

