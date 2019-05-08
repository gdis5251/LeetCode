<<<<<<< HEAD:151.翻转字符串里的单词/Code.h
#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static void reverse(string& s, int lhs, int rhs)
    {
        while (lhs < rhs)
        {
            swap(s[lhs++], s[rhs--]);
        }
    }
    
    static string reverseWords(string s) {
        if (s.empty())
            return s;
        
        std::reverse(s.begin(), s.end());
        
        size_t space = 0;
        int b = 0;
        int e = -2;
        bool isContinue = true;
        while (isContinue && !s.empty())
        {
            if (space == 0)
                b = 0;
            else
                b = space;
            
            space = s.find(' ', space);
                
            if (space == s.npos)
            {
                isContinue = false;
                e = s.size() - 1;
            }
            else
            {
                e = space - 1;
            }
            
            if (space == 0 || space == s.size() - 1)
            {
                s.erase(space, 1);
                continue;
            }
            else if (s[space + 1] == ' ' && s[space - 1] != ' ')
            {
                s.erase(space, 1);
            }
            else
            {
                space++;
            }
            
            reverse(s, b, e);
        }
        
        return s;
    }
};
=======
class Solution {
public:
    static void reverse(string& s, int lhs, int rhs)
    {
        while (lhs < rhs)
        {
            swap(s[lhs++], s[rhs--]);
        }
    }
    
    string reverseWords(string s) {
        if (s.empty())
            return s;
        
        std::reverse(s.begin(), s.end());
        
        size_t space = 0;
        int b = 0;
        int e = -2;
        bool isContinue = true;
        while (isContinue && !s.empty())
        {
            if (space == 0)
                b = 0;
            else
                b = space;
            
            space = s.find(' ', space);
                
            if (space == s.npos)
            {
                isContinue = false;
                e = s.size() - 1;
            }
            else
            {
                e = space - 1;
            }
            
            if (space == 0 || space == s.size() - 1)
            {
                s.erase(space, 1);
                continue;
            }
            else if (s[space + 1] == ' ' && s[space - 1] != ' ')
            {
                s.erase(space, 1);
            }
            else
            {
                space++;
            }
            
            reverse(s, b, e);
        }
        
        return s;
    }
};
>>>>>>> e2493a505f997ce5bcfd3480b9182ef950900e0f:151.翻转字符串里的单词/Code.cpp
