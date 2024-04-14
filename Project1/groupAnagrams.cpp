#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<cassert>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, unordered_map<char,int>> container;

        for (string& str : strs)
        {
            for (char& c : str)
            {
                ++container[str][c];
            }
        }
        vector<string> tmp;

        for (auto elem : container)
        {
            if (elem.second.size()==0) continue;
            for (auto e : container)
            {
                if (e.second.size() == 0) continue;
                if (e.first != elem.first && e.second == elem.second)
                {
                    tmp.push_back(e.first);
                    e.second.clear();
                }
            }
            tmp.push_back(elem.first);
            elem.second.clear();
            result.push_back(tmp);
            tmp.clear();
        }

        return result;
    }
};

void testGroupAnagrams()
{
    Solution s;
    {
        vector<string> str = { "eat","tea","tan","ate","nat","bat" };
        vector<vector<string>> answer = { {"bat"}, { "nat", "tan" }, { "ate", "eat", "tea" } };
        assert(s.groupAnagrams(str) == answer);
    }
}

int main()
{
    testGroupAnagrams();
    //vector<char> t1 = { 'e','a','t' };
    
}