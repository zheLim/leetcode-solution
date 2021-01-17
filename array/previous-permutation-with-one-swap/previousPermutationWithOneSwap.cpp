class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(A.size()== 0){
            return A;
        }
        int first = findFirst(A);
        
        if(first==-1){
            return A;
        }
        
        int second = findSecond(A, first);
        swap(A[first], A[second]);
        return A;
    }
    
    int findFirst(vector<int> A){
        int i=A.size()-1;
        for(; i>=1; i--){
            if(A[i-1]>A[i]){
                break;
            }
        }
        return i-1;
    }
    
    int findSecond(vector<int> A, int first){
        int second = first + 1;
        for (int i = first + 2; i < A.size(); i++){
            if (A[i] > A[i-1] && A[i] < A[first]){
                second = i;
            }
        }
        return second;
    }
};