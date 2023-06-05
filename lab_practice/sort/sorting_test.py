import unittest
from selection_sort import selection_sort
from merge_sort import merge_sort
from insertion_sort import insertion_sort
from quick_sort import quick_sort

class TestSort(unittest.TestCase):

    @staticmethod
    def generate_array() -> list:
        return [4,2,1,5,2,13,2,19,39]

    @staticmethod
    def sorted_array() -> list:
        lst =  [4,2,1,5,2,13,2,19,39]
        lst.sort()
        return lst

    def test_selection(self):
        arr = TestSort.generate_array()
        sorted_arr = TestSort.sorted_array()
        self.assertEqual(selection_sort(arr),sorted_arr)

    def test_merge(self):
        arr = TestSort.generate_array()
        sorted_arr = TestSort.sorted_array()
        self.assertEqual(merge_sort(arr),sorted_arr)

    def test_insertion(self):
        arr = TestSort.generate_array()
        sorted_arr = TestSort.sorted_array()
        self.assertEqual(insertion_sort(arr),sorted_arr)

    def test_quick(self):
        arr = TestSort.generate_array()
        sorted_arr = TestSort.sorted_array()
        self.assertEqual(quick_sort(arr),sorted_arr)

if __name__ == "__main__":
    unittest.main()
