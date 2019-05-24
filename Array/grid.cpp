int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int min = 0;
    for(int i=0; i<A.size()-1; i++){
        int X_diff = abs(A[i+1]- A[i]);
        int Y_diff = abs(B[i+1]- B[i]);
        min += (X_diff>Y_diff)? X_diff : Y_diff;
    }
    return min;
}