class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            
            // ignore non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            // ignore non-alphanumeric characters
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // compare two characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // move towards the center
            left++;
            right--;
        }

        return true;
    }
};
