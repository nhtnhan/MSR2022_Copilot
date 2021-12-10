/** https://leetcode.com/problems/frog-jump/ */
//A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
//If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.



bool canCross(int* stones, int stonesSize){
    // Write your code here
    int *visited = (int *)malloc(sizeof(int) * stonesSize);
    for(int i = 0; i < stonesSize; i++)
        visited[i] = 0;
    visited[0] = 1;
    for(int i = 0; i < stonesSize; i++){
        if(visited[i] == 1){
            for(int j = i + 1; j < stonesSize; j++){
                if(j - i == 1)
                    visited[j] = 1;
                else if(j - i == 2)
                    visited[j] = visited[j - 1];
                else if(j - i > 2 && visited[j - 1] == 1)
                    visited[j] = 1;
                if(visited[stonesSize - 1] == 1)
                    return true;
            }
        }
    }
    return false;
}
    