class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> aheap(gifts.begin(),gifts.end());
       // perform the operation k times
        for(int i=0;i<k;i++){
            int maxeele=aheap.top();
            aheap.pop();
            aheap.push(sqrt(maxeele));
        }
        long long number=0;
        while(!aheap.empty()){
            number += aheap.top();
            aheap.pop();
        }
        return number;
    }
};