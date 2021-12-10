# https://leetcode.com/problems/pascals-triangle-ii/

class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1,1]
        else:
            prev = [1,1]
            for i in range(2,rowIndex+1):
                curr = [1]
                for j in range(1,i):
                    curr.append(prev[j-1]+prev[j])
                curr.append(1)
                prev = curr
            return curr