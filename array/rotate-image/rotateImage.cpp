class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // i-th row
        for (int i=0; i<n-1; i++){
            for(int j=i;j<n-1-i;j++){
                int tmp = matrix[i][j];
                
                int cur_i = i;
                int cur_j = j;
                int prev_i = n-1-j;
                int prev_j = i;
                
                while(prev_i !=i || prev_j!=j){
                    matrix[cur_i][cur_j] = matrix[prev_i][prev_j];
                    cur_i = prev_i;
                    cur_j = prev_j;
                    prev_i = n-1-cur_j;
                    prev_j = cur_i;
                }
                matrix[cur_i][cur_j] = tmp;
            }
            
        }
    }
};