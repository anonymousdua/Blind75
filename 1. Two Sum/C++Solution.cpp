class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
    
            unordered_map<int, int> index;
    
            for(int i = 0; i < nums.size(); i++){
                index[nums[i]] = i;
            }
    
            for(int i = 0; i < nums.size(); i++){
                int diff = target - nums[i];
                if(index.count(diff) && index[diff] != i){
                    return{i, index[diff]};
                }
            }
            return {};
            
        }
    };