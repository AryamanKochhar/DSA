class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // Ensure i < j
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int m = str1.size();
        int n = str2.size();

        // Check if str1 is both a prefix and a suffix of str2
        if (m <= n) {
            return str2.substr(0, m) == str1 && str2.substr(n - m) == str1;
        }
        return false;
    }
};
