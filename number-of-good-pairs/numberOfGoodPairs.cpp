class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // find combination.
        unordered_map<int, int> n_count;
        for(auto iter=nums.begin(); iter != nums.end(); iter++){
            if(n_count.find(*iter)!=n_count.end()){
                n_count[*iter]++;
            }
            else{
                n_count.insert(make_pair(*iter, 1));
            }
        }
        
        int res = 0;
        for(auto iter=n_count.begin(); iter!=n_count.end(); iter++){
            if(iter->second > 1){
                res += nChoosek(iter->second, 2);
            }
        }
        return res;
        
    }
private:
    int nChoosek( int n, int k )
    {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        int result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }

};