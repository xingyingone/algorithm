#include<iostream>
#include<string>
using namespace std;
    int lengthOfLongestSubstring(string s) {
       int *map = new int[256]; // map from character's ASCII to its last occured index
        int j = 0;
        int i = 0;
        int ans = 0;
        for (i = 0; i < s.length(); i++) {
            while (j < s.length() && map[s[j]]==0) {
                map[s[j]] = 1;
                ans = max(ans, j-i + 1);
                j++;
            }
            map[s[i]] = 0;
        }
        return ans;
    }
    int main()
    {
        string s="ciridmtxsgaryv";
        cout<<lengthOfLongestSubstring(s)<<endl;
    }