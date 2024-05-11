﻿﻿#pragma execution_character_set("utf-8")

#include<vector>
#include<array>
#include<iostream>
#include<list>
#include<algorithm>

//не работает
//class MyHashSet {
//public:
//    MyHashSet() {
//        arr_.resize(1000000);
//    }
//
//    void add(int key) {
//        size_t index = hash(key);
//        //индекс есть
//        if (std::find(arr_.begin(), arr_.end(), index) != arr_.end())
//        {
//            if (std::find(arr_.at(index).begin(), arr_.at(index).end(), key) != arr_.at(index).end())
//            {
//                return;
//            }
//            arr_.at(index).push_back(key);
//            return;
//        }
//        //индекса нет просто добавляем
//        arr_[index].push_back(key);
//
//    }
//
//    void remove(int key) {
//        size_t index = hash(key);
//
//        //проверяем что индекс есть
//        if (std::find(arr_.begin(), arr_.end(), index) != arr_.end())
//        {
//            auto i_index = std::find(arr_.at(index).begin(), arr_.at(index).end(), key);
//            arr_.at(index).erase(i_index);
//        }
//    }
//
//    bool contains(int key) {
//        size_t index = hash(key);
//        //проверяем что индекс есть
//        if (std::find(arr_.begin(), arr_.end(), index) != arr_.end())
//        {
//            if (std::find(arr_.at(index).begin(), arr_.at(index).end(), key) != arr_.at(index).end())
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//private:
//    
//    std::vector<std::vector<int>> arr_;
//
//
//    size_t hash(int i)
//    {
//        return (i / 3)% arr_.size();
//    }
//};

class MyHashSet {
public:
    MyHashSet() {
        arr_.resize(1000000,0);
    }

    void add(int key) {
        arr_[key] = 1;
    }

    void remove(int key) {
        arr_[key] = 0;
    }

    bool contains(int key) {
        if (arr_[key])
            return true;
        else
            return false;
    }
private:
    std::vector<int> arr_;
};


using namespace std;
int main()
{
    MyHashSet set;
    set.add(1);
    set.add(2);
    cout << set.contains(3)<<" "<<set.contains(2);
    set.remove(2);
    cout << set.contains(2);

    
}
