class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> diff2idx;
    for(auto it=nums.begin(); it != nums.end(); it++){
        auto index = it - nums.begin();

        if(diff2idx.find(*it) != diff2idx.end()){
            vector<int> res{diff2idx[*it], (int) index};
            return res;
        }else{
            diff2idx.insert(pair<int, int>(target-*it, (int) index));
        }
    }
    vector<int> res{};

    return res;
    }
};