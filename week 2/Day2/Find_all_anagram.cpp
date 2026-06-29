class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.length();
        int m = p.length();

        if (m > n)
            return ans;

        vector<int> cntP(26, 0);
        vector<int> cntS(26, 0);

        // Frequency of p and first window of s
        for (int i = 0; i < m; i++) {
            cntP[p[i] - 'a']++;
            cntS[s[i] - 'a']++;
        }

        // Check first window
        if (cntP == cntS)
            ans.push_back(0);

        // Sliding window
        for (int i = m; i < n; i++) {
            cntS[s[i] - 'a']++;       // add new character
            cntS[s[i - m] - 'a']--;  // remove old character

            if (cntP == cntS)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};