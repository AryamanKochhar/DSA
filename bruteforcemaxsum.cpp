class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force 
        // o(n2)
        int sum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int to=0; 
            for(int j=i;j<nums.size();j++){
                to=nums[j]+to;
                if(to>sum){
                    sum=to;
                }
            }
        }
        return sum;
    }
};