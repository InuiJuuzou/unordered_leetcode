#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
private:
    bool check(unordered_set<char>& board_temp, char number)
    {
        if (board_temp.find(number) != board_temp.end())
        {
            return false;
        }
        else
        {
            board_temp.insert(number);
            return true;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> temp;
        size_t board_size = board.size();
        //строки
        for (size_t i = 0; i < board_size; ++i)
        {
            for (size_t j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.') continue;
                if (!check(temp, board[i][j]))
                {
                    return false;
                }
            }
            temp.clear();
        }
        //столбцы

        for (size_t k = 0; k < board[k].size() && k < board_size; ++k)
        {
            for (size_t m = 0; m < board_size; ++m)
            {
                if (board[m][k] == '.') continue;
                if (!check(temp, board[m][k]))
                {
                    return false;
                }
            }
            temp.clear();
        }
        ////матрица 3х3
        for (size_t i = 0; i < board_size; i += 3)
        {
            for (size_t j = 0; j < board[i].size(); j += 3)
            {
                for (size_t k = 0; k < 3; ++k)
                {
                    for (size_t m = 0; m < 3; ++m)
                    {
                        if (board[i + k][j + m] == '.') continue;
                        if (!check(temp, board[i + k][j + m]))
                        {
                            return false;
                        }
                    }

                }
                temp.clear();
            }
            temp.clear();
        }

        return true;
    }
    //вернуть буквы которые встречаютс€ во всех словах переданного массива, включа€ повторени€
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<unordered_map<char, int>> count_char;

        //проход по всем словам и подсчет их букв
        
        for (string word : words)
        {
            unordered_map<char, int> tmp;
            for (size_t i = 0; i < word.size(); ++i)
            {
                ++tmp[word[i]];
            }
            count_char.push_back(tmp);
        }

        unordered_map<char, int> count;
        for (auto it= count_char[0].begin(); it!=count_char[0].end();++it)
        {
            int min_c = it->second;
            for (size_t j = 1; j < count_char.size(); ++j)
            {
                
                if (count_char[j].find(it->first) != count_char[j].end())
                {
                    min_c = min(min_c, count_char[j].at(it->first));
                }
                else
                {
                    min_c = 0;
                }
            }
            count[it->first] = min_c;
        }
        
        for (auto it = count.begin(); it != count.end(); ++it)
        {
            string tmp;
            if (it->second == 1)
            {
                tmp = it->first;
                
                result.push_back(tmp);
            }
            if (it->second > 1)
            {
                tmp = it->first;
                for (size_t i = 0; i < it->second; ++i)
                {
                    result.push_back(tmp);
                }
            }
        }

        return result;
    }
};

class MyHashSet{
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    vector<list<int>> arr;
    size_t hasher(int key)
    {
        return key/3;
    }
    bool find_elem(int key)
    {
        size_t index = hasher(key);
        if (std::find(arr[index].begin(), arr[index].end(), key) != arr[index].end())
        {
            return true;
        }
        return false;
    }
public:
    MyHashSet() {

    }

    void add(int key) {
        size_t index = hasher(key);
        if(!find_elem(key))
            arr[index].push_back(key);
        
    }

    void remove(int key) {
        size_t index = hasher(key);

    }

    bool contains(int key) {

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

void test_commonChars()
{
    Solution s;
    {
        vector<string> test1 = { "bella","label","roller" };
        vector<string> answer = { "e","l","l" };
        assert(s.commonChars(test1) == answer);


    }
    {
        vector<string> test2 = { "cool","lock","cook" };
        vector<string> answer = { "c","o" };
        assert(s.commonChars(test2) == answer);
        //vector<string> answer = s.commonChars(test2);

        //for (string a : answer)
        //{
        //    cout << a << " ";
        //}
    }

    cout << "DONE" << endl;
}

int main()
{
    test_commonChars();
    cout << 99999 % 3;
}
