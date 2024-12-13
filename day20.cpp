class Solution {
public:
    // we would be needing sorted  array from which we can get the minimum
    // elemeent and mark that and its adjacent indexs in the marked array then
    // see the next element in the sorted array see if its marked or not if not
    // mark then mark it
    //  from which we can see the unamarked
    // in questions like these where we require the sorted element and its adj
    // or just simply need an element and its index after doing an operation we
    // can use 2d arrays and work it out 1 array can hold the index and the
    // first one can have the old index
    long long findScore(vector<int>& nums) {
        long ans = 0;
        vector<pair<int, int>> sorted(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sorted[i] = make_pair(nums[i], i);
        } // this will map the indexs and the value at that index
        sort(sorted.begin(), sorted.end());
        vector<bool> marked(nums.size(),
                            false); // creating a vector boolean and basically
                                    // setting the default value as false
        for (int i = 0; i < nums.size(); i++) {
            int number = sorted[i].first;
            int index = sorted[i].second;
            if (!marked[index]) {
                ans = ans + number;
                marked[index] = true;
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < nums.size()) {
                    marked[index + 1] = true;
                }
            }
        }
        return ans;
    }
};