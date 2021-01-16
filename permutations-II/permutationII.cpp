class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> permutation;
        permute(nums, visited, ans, permutation);
        return ans;
    }
    
    void permute(vector<int> nums, vector<bool>& visited, vector<vector<int>>& ans, vector<int>& permutation){
        if (nums.size()==permutation.size()){
            ans.push_back(permutation);
            return;
        }
        int prev_digit = INT_MAX;
        for (int i=0; i < nums.size(); i++){
            if(prev_digit == nums[i] || visited[i]){
                continue;
            }
            
            visited[i] = true;
            permutation.push_back(nums[i]);
            permute(nums, visited, ans, permutation);
            
            //release
            visited[i] = false;
            permutation.pop_back();
            prev_digit = nums[i];
        }
        return;
    }
    
};