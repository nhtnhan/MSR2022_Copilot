# https://leetcode.com/problems/super-ugly-number/
#A super ugly number is a positive integer whose prime factors are in the array primes.
#Given an integer n and an array of integers primes, return the nth super ugly number.
#The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        ugly = [1]
        index = [0] * len(primes)
        while len(ugly) < n:
            next_ugly_num = min(primes[i] * ugly[index[i]] for i in range(len(primes)))
            ugly.append(next_ugly_num)
            for i in range(len(primes)):
                if primes[i] * ugly[index[i]] == next_ugly_num:
                    index[i] += 1
        return ugly[-1]