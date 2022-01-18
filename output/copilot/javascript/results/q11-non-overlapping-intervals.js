/** https://leetcode.com/problems/non-overlapping-intervals/ */
//Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

/**
 * @param {number[][]} intervals
 * @return {number}
 */
 var eraseOverlapIntervals = function(intervals) {
    if (intervals.length === 0) return 0;
intervals.sort((a, b) => a[0] - b[0]);
let count = 0;
let end = intervals[0][1];
for (let i = 1; i < intervals.length; i++) {
   if (intervals[i][0] >= end) {
       end = intervals[i][1];
   } else {
       count++;
   }
}
return count;
};
