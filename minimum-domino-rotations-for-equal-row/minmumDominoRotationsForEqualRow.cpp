class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        
        int a_0 = A[0];
        int a_A = 1;
        int a_B = 0;
        
        int b_0 = B[0];
        int b_A = 0;
        int b_B = 1;
        auto length = A.size();
        for(auto i=1; i<A.size(); i++){
            if (a_A != -1){
                if (a_0 == A[i] && a_0 == B[i]){
                    continue;
                }
                else if(a_0 == A[i]){
                    a_A += 1;
                }
                else if(a_0 == B[i]){
                    a_B += 1;
                }
                else
                {
                    a_A = a_B = -1;
                }
            }
            if (b_A != -1){
                if (b_0 == A[i] && b_0 == B[i]){
                    continue;
                }
                else if (b_0 == A[i]){
                    b_A += 1;
                }
                else if(b_0 == B[i]){
                    b_B += 1;
                }
                else
                {
                    b_A = b_B = -1;
                }
            }
            
        }
           
        if (a_A == -1){
            return min(b_A, b_B);
        }
        else if (b_A == -1){
            return min(a_A, a_B);
        }
        else{
            return min(min(b_A, b_B), min(a_A, a_B));
        }
    }
};