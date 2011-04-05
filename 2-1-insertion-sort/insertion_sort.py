#!/usr/bin/env python
#
# insertion sort implementation in python
#

import unittest

def insertion_sort(input):
    """
        function which performs insertion sort

        Input:
            input -> array of integer keys

        Returns: the sorted array
    """
    for j in xrange(len(input)):
        key = input[j]
        i = j - 1  # second index cursor

        while i >= 0 and input[i] > key:
            input[i + 1] = input[i]
            i -= 1

        input[i + 1] = key

    return input

class TestInsertionSort(unittest.TestCase):

    def test_insertion_sort(self):
        res = insertion_sort([3,5,6,1,2,4])
        self.assertEqual(res, [1,2,3,4,5,6])

if __name__ == '__main__':
    unittest.main()
