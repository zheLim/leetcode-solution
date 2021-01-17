class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        bool flag = true;

        for(size_t i=0; i<nums.size()-1;i++){
            
            if(nums[i]>nums[i+1]){
                if (flag){
                    if(i!=0 && nums[i+1]<nums[i-1]){
                        nums[i+1] = nums[i];
                    }
                    flag=false;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};