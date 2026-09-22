class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        unordered_map<string, int> wordCounts;
        for (const string& word : words) {
            wordCounts[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            int count = 0;
            unordered_map<string, int> currentCounts;

            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCounts.count(word)) {
                    currentCounts[word]++;
                    count++;

                    while (currentCounts[word] > wordCounts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentCounts[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    currentCounts.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};