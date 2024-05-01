﻿#pragma execution_character_set("utf-8")

#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<cassert>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> result;
//
//        unordered_map<string, unordered_map<char,int>> container;
//
//        for (string& str : strs)
//        {
//            for (char& c : str)
//            {
//                ++container[str][c];
//            }
//        }
//        vector<string> tmp;
//
//        for (auto elem : container)
//        {
//            if (elem.second.size()==0) continue;
//            for (auto e : container)
//            {
//                if (e.second.size() == 0) continue;
//                if (e.first != elem.first && e.second == elem.second)
//                {
//                    tmp.push_back(e.first);
//                    e.second.clear();
//                }
//            }
//            tmp.push_back(elem.first);
//            elem.second.clear();
//            result.push_back(tmp);
//            tmp.clear();
//        }
//
//        return result;
//    }
//};

class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, unordered_map<char, int>> counter_chars;

        for (string& str : strs)
        {
            unordered_map<char, int> tmp;
            for (size_t i = 0; i < str.size(); ++i)
            {
                ++tmp[str[i]];
            }
            counter_chars[str] = tmp;
        }

        for (string& str : strs)
        {
            if (counter_chars.find(str) == counter_chars.end())
                continue;
            unordered_map<char, int> tmp = counter_chars.at(str);
            vector<string> answer_tmp;
            for (auto t : counter_chars)
            {
                if (t.first != str && t.second==tmp)
                {
                    answer_tmp.push_back(t.first);
                    counter_chars.erase(t.first);
                }
            }
            answer_tmp.push_back(str);
            answer.push_back(answer_tmp);
        }

        return answer;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if (strs.empty())
        {
            return {};
        }
        /*if (strs.size() == 1)
        {
            result.push_back({ strs[0] });
            return result;
        }*/

       unordered_map<string, vector<string>> sorted_word;
        //unordered_map<string, vector<string_view>> sorted_word;
        for (size_t i=0; i<strs.size();++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            sorted_word[tmp].push_back(strs[i]);
        }

        vector<vector<string>> result;
        result.reserve(sorted_word.size());

        for (auto word : sorted_word)
        {
            result.push_back(move(word.second));
            
        }
        return result;
    }
    //решение с гистограммой(не мое)
    vector<vector<string>> groupAnagramsGistogram(vector<string>& strs)
    {
        unordered_map<string, vector<string>> group;
        for (const string& str : strs)
        {
            int histogram[26] = {};
            for (const char& c : str)
            {
                histogram[c - 'a']++;
            }
            string key = "";
            for (char c = 'a'; c <= 'z'; c++)
            {
                int count = histogram[c - 'a'];
                if (count > 0)
                {
                    key += c;
                }
                else if (count > 1)
                {
                    key += to_string(count);
                }
                
            }
            group[key].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(group.size());

        for (auto word : group)
        {
            result.push_back(move(word.second));

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
    Solution s;
    //testGroupAnagrams();
    //vector<char> t1 = { 'e','a','t' };
    vector<string> str = { "eat","tea","tan","ate","nat","bat" };
    vector<vector<string>> t = s.groupAnagramsGistogram(str);
    
    for (auto v : t)
    {
        for (auto vv : v)
        {
            cout << vv << " ";
        }
        cout << endl;
    }
}