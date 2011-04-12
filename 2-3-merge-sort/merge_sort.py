#!/usr/bin/env python
#
# insertion sort implementation in python
#

import unittest

def merge_sort(input, start, end):
    """
        function which performs merge sort

        Input:
            input -> array of integer keys

        Returns: the sorted array
    """
    if start < end:
        middle = (start + end)/2
        merge_sort(input, start, middle)
        merge_sort(input, middle + 1, end)
        merge(input, start, middle + 1, end)

    return input


def merge(array, left, middle, right):
    """
        function which merges the subarrays array[left...middle] and
        array[middle+1...right] to array[left...right]
    """
    left_subarray = array[left:middle]
    right_subarray = array[middle:right+1]
    left_subarray.append(float('inf'))
    right_subarray.append(float('inf'))
    i = 0 # index for left subarray
    j = 0 # index for right subarray

    for k in xrange(left,right+1):
        if left_subarray[i] <= right_subarray[j]:
            array[k] = left_subarray[i]
            i = i + 1
        elif left_subarray[i] > right_subarray[j]:
            array[k] = right_subarray[j]
            j = j + 1

class TestMergeSort(unittest.TestCase):

    def test_merge_sort(self):
        res = merge_sort([3,5,6,1,2,4], 0, 5)
        self.assertEqual(res, [1,2,3,4,5,6])

    def test_merge_function(self):
        array = [1,3,5,6,2,4,7]
        merge(array, 0,4,6)
        self.assertEqual(array,[1,2,3,4,5,6,7])

if __name__ == '__main__':
    unittest.main()
