class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> result;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                count.push(num);
                result.push(curr);
                num = 0;
                curr = "";
            }

            else if (ch == ']') {
                int times = count.top();
                count.pop();

                string temp = result.top();
                result.pop();

                while (times--) {
                    temp += curr;
                }

                curr = temp;
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};