
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;

        while (left < right) {
            int width = right - left;

            int smallerHeight;
            if (height[left] < height[right])
                smallerHeight = height[left];
            else
                smallerHeight = height[right];

            int currentArea = width * smallerHeight;

            if (currentArea > answer)
                answer = currentArea;

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return answer;
    }
};