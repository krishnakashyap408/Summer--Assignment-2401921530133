class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m)
            return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        // Frequency of s1 and first window of s2
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        // Check first window
        if (cnt1 == cnt2)
            return true;

        // Sliding window
        for (int i = n; i < m; i++) {
            cnt2[s2[i] - 'a']++;          // add new character
            cnt2[s2[i - n] - 'a']--;      // remove old character

            if (cnt1 == cnt2)
                return true;
        }

        return false;
    }
};