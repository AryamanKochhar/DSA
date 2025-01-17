class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int c=nums1[i] ^ nums2[j];
                res.push_back(c);
            }
        }
        int ans=0;
        for(auto k: res){
            ans = ans ^ k;
        }
        return ans;
    }
};