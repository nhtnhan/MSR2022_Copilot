/** https://leetcode.com/problems/non-overlapping-intervals/ */
//Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int i,j;
    int count = 0;
    int *starts = malloc(sizeof(int)*intervalsSize);
    int *ends = malloc(sizeof(int)*intervalsSize);
    for(i=0;i<intervalsSize;i++){
        starts[i] = intervals[i][0];
        ends[i] = intervals[i][1];
    }
    qsort(starts,intervalsSize,sizeof(int),compare);
    qsort(ends,intervalsSize,sizeof(int),compare);
    for(i=0;i<intervalsSize-1;i++){
        if(ends[i]>starts[i+1]){
            count++;
        }
    }
    free(starts);
    free(ends);
    return count;
}

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
    