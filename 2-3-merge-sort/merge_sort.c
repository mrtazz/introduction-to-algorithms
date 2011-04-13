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
int merge_sort(int *input, int start, int end)
{
  if (start < end)
  {
    int middle = (start + end ) / 2;
    merge_sort(input, start, middle);
    merge_sort(input, middle+1, end);
    merge(input, start, middle, end);
  }

  return 0;
}

/**
 * @brief function to merge two sorted subarrays
 *
 * @param input array containing the subarrays
 * @param left start of first subarray
 * @param middle mark between to subarrays
 * @param right end of second subarray
 *
 * @return 0
 */
int merge(int *input, int left, int middle, int right)
{
  // determine lenghts
  int length1 = middle - left + 1;
  int length2 = right - middle;
  // create helper arrays
  int subarray1[length1];
  int subarray2[length2];
  // fill helper arrays
  int i;
  for (i=0; i<length1; ++i)
  {
    subarray1[i] = input[left + i];
  }
  for (i=0; i<length2; ++i)
  {
    subarray2[i] = input[middle + 1 + i];
  }
  subarray1[length1] = 100;
  subarray2[length2] = 100;

  int j,k;
  j = 0;
  i = 0;

  // go through subarray and insert into main array
  for (k=left; k<=right; ++k)
  {
    if (subarray1[i] <= subarray2[j])
    {
      input[k] = subarray1[i];
      ++i;
    }
    else if (subarray1[i] > subarray2[j])
    {
      input[k] = subarray2[j];
      ++j;
    }
  }

  return 0;
}

int main( int argc, const char* argv[] )
{
  int i;
  int input[] = { 3, 6, 4, 1, 2, 5};
  merge_sort(&input[0], 0, 5);
  for (i=0; i<6;++i)
  {
    printf("%i", input[i]);
  }
  printf("\n");
  return 0;
}

