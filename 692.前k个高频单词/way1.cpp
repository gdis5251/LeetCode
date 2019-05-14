/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        typedef map<std::string, int> CountMap;
        typedef map<std::string, int>::iterator CountMapIterator;
        
        CountMap count_map;
        //先把所有的words插入到map里，并且统计次数
        /*1. 传统统计次数
        for (const auto& e : words)
        {
            //insert 返回 pair<iterator, bool>  
            //插入成功iterator表示插入结点的迭代器，或者插入失败就返回已有结点的迭代器
            //bool表示插入成功或失败
            auto ret = count_map.insert(make_pair(e, 1));
            if (ret.second == flase)
                ret.first->second++;
        }
        */
        
        //现代统计次数
        for (const auto& e : words)
        {
            //operator[] 的参数是key 返回值是value
            //具体实现
            //return (*(this->insert(make_pair(k, mapped_type()))).first).second;
            count_map[e]++;
        }

        std::multimap<int, std::string, greater<int>> sort_map;
        for (const auto& e : count_map)
        {
            sort_map.insert(make_pair(e.second, e.first));
        }

        std::vector<string> ans;
        auto rit = sort_map.begin();
        while (rit != sort_map.end() && k-- != 0)
        {
            ans.push_back(rit->second);
            rit++;
        }
        //std::set<std::pair<std::string, int>, Greater) 
        
        return ans;
    }
};