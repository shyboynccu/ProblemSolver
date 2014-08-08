#!/usr/local/bin python3

# Question: Given an array A of integers of length n, 
# find the interval indices a and b such that sum of all integers in between i and j are maximized.
# i.e. find the subarray which has the maximum sum.

__author__ = 'Matttk L.'

import sys
import random
import timeit

narray = random.sample(range(-100, 100), 100)

def test(func, b):
    func(b)
    
def main():
    print(timeit.timeit("test(find_maximum_subarray_slow, narray)", setup="from __main__ import test, narray, find_maximum_subarray_slow", number = 1))
    print(timeit.timeit("test(find_maximum_subarray_dp, narray)", setup="from __main__ import test, narray, find_maximum_subarray_dp", number = 1))

def find_maximum_subarray_slow(narray):
    max_value = narray[0]
    begin_idx = 0
    end_idx = 0

    length = len(narray)
    
    for i in range(len(narray)):
        total = 0
        for j, v in enumerate(narray[i:], start = i):
            total += v
            if (total > max_value or (total == max_value and
                j - i < end_idx - begin_idx)):
                max_value = total
                begin_idx = i
                end_idx = j
    
    print("[Brute Force] Maximum subarray is ", narray[begin_idx:end_idx+1], 'with value', max_value)
    
def find_maximum_subarray_dp(narray):
    max_value = narray[0]
    begin_idx = 0
    end_idx = 0

    min_sum = 0
    max_sum = 0
    total = 0
    length = len(narray)
    min_idx = -1

    for i, v in enumerate(narray):
        total += v
        if total <= min_sum:
            min_sum = total
            min_idx = i

        val = total - min_sum
        if (val > max_value or (val == max_value and 
            i - (min_idx + 1) < end_idx - begin_idx)):
            max_value = val
            begin_idx = min_idx + 1
            end_idx = i
            
    print("[DP] Maximum subarray is ", narray[begin_idx:end_idx+1], 'with value', max_value)
    
if __name__ == '__main__':
    main()
