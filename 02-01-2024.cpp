// 2610. Convert an Array Into a 2D Array With Conditions

#include <bits/stdc++.h>
using namespace std;

// TC -> O(n)
// SC -> O(n)
vector<vector<int>> findMatrix(vector<int> nums)
{
    int n = nums.size();

    int colNo = INT_MIN;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
        colNo = max(colNo, m[nums[i]]);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < colNo; i++)
    {
        vector<int> temp;
        for (auto &it : m)
        {
            if (it.second != 0)
            {
                temp.push_back(it.first);
                it.second--;
            }
        }
        if (temp.size() != 0)
            ans.push_back(temp);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 1, 2, 3, 1};

    vector<vector<int>> converted2DArray = findMatrix(nums);
    for (int i = 0; i < converted2DArray.size(); i++)
    {
        for (int j = 0; j < converted2DArray[i].size(); j++)
        {
            cout << converted2DArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}