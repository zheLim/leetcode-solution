class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        for(auto iter=nums.begin(); iter != nums.end(); iter++){
            sum = sum + *iter;
            res.push_back(sum);
        }
        return res;
    }
};