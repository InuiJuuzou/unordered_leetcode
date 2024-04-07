#include <vector>
#include<iostream>
#include <unordered_map>
#include<unordered_set>
#include<algorithm>
#include <random>
#include <set>
#include<map>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    void sunstrOfS(string s, unordered_set<string>* subs)
    {
        unordered_set<char> substr_char;
        string str;

        // for (const char c : s)
        for (size_t i = 0; i < s.length(); ++i)
        {
            //если что то найдено удаляем все до этого символа

            if (substr_char.find(s[i]) != substr_char.end())
            {
                //substr_char.clear();
                auto index = str.find(s[i]);
                //string tmp = str.substr(0, i + 1);
                string tmp = str.substr(0, index + 1);
                //subs->insert(tmp);
                subs->insert(str);

                for (char t : tmp)
                {
                    substr_char.erase(t);
                }

                //str.erase(0, i + 1);
                str.erase(0, index + 1);
            }
            //если не нашли просто добавляем в сет символ и прибавляем к концу уже имеющейся строки
            substr_char.insert(s[i]);
            str += s[i];
        }
        subs->insert(str);
    }
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) return 0;
        if (s.length() == 1) return 1;

        //unordered_set<char> substr_char;
        unordered_set<string> subs;
        string str = s;
        //reverse(str.begin(), str.end());
        sunstrOfS(s, &subs);
        //sunstrOfS(str, &subs);

        int max_lenght = subs.begin()->length();

        for (const string sub : subs)
        {
            if (sub.length() > max_lenght)
            {
                max_lenght = sub.length();
            }
        }

        return max_lenght;

    }
};

void TestlengthOfLongestSubstring()
{
    Solution s;
    {
        string str = "abcabcbb";
        assert(s.lengthOfLongestSubstring(str) == 3);
    }
    {
        string str = "bbbbbb";
        assert(s.lengthOfLongestSubstring(str) == 1);
    }
    {
        string str = "pwwkew";
        assert(s.lengthOfLongestSubstring(str) == 3);
    }
    {
        string str = "";
        assert(s.lengthOfLongestSubstring(str) == 0);
    }
    {
        string str = " ";
        assert(s.lengthOfLongestSubstring(str) == 1);
    }
    {
        string str = "dvdf";
        assert(s.lengthOfLongestSubstring(str) == 3);
    }
    {
        string str = "ohvhjdml";
        assert(s.lengthOfLongestSubstring(str) == 6);
    }
    {
        string str = "cdd";
        assert(s.lengthOfLongestSubstring(str) == 2);
    }
    {
        string str = "abcb";
        assert(s.lengthOfLongestSubstring(str) == 3);
    }
    {
        string str = "asjrgapa";
        assert(s.lengthOfLongestSubstring(str) == 6);
    }
    cout << "DONE!" << endl;
}

int main()
{
    TestlengthOfLongestSubstring();
}