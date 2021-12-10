# https://leetcode.com/problems/frog-jump/
#A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
#Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
#If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        if len(stones) == 1:
            return True
        if stones[1] != 1:
            return False
        jumps = set([1])
        for i in range(2, len(stones)):
            for jump in jumps.copy():
                if stones[i] == stones[i - 1] + jump:
                    jumps.add(jump)
                if stones[i] == stones[i - 1] + jump - 1:
                    jumps.add(jump - 1)
                if stones[i] == stones[i - 1] + jump + 1:
                    jumps.add(jump + 1)
        return stones[-1] in jumps