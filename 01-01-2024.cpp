// 455. Assign Cookies

#include<bits/stdc++.h>
using namespace std;

// brute force approach
// TC -> O(n * n * nlog(n))
// SC -> O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int contentChild = 0;

        if(s.size() == 0)
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i=0; i<g.size(); i++)
        {
            for(int j=0; j<s.size(); j++)
            {
                if(g[i] <= s[j])
                {
                    contentChild++;
                    s[j] = -1;
                    break;
                }
            }
        }

        return contentChild;
    }
};

// using two pointer approach
// TC -> O(n * nlog(n))
// SC -> O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int contentChild = 0;

        if(s.size() == 0)
            return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int currCooki = s.size()-1;
        int currGreed = g.size()-1;

        while(currCooki>=0 && currGreed>=0)
        {
            if(g[currGreed] <= s[currCooki])
            {
                contentChild++;
                currGreed--;
                currCooki--;
            }
            else
            {
                currGreed--;
            }
        }

        return contentChild;
    }
};