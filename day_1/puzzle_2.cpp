#include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <string>
using namespace std;

int solve(vector<vector<int>> calories)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto const &e : calories)
    {
        int sum = 0;
        for (auto const &f : e)
        {
            sum += f;
        }
        pq.push(sum);
        if (pq.size() > 3)
            pq.pop();
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}

int main()
{
    // ifstream in("../sample_input.txt");
    ifstream in("../input.txt");
    if (!in)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    vector<vector<int>> calories;
    vector<int> tmp;
    string line;
    while (getline(in, line))
    {
        if (line.empty())
        {
            // calories.push_back(tmp);
            calories.emplace_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.push_back(stoi(line));
        }
    }
    if (!tmp.empty())
        calories.push_back(tmp);
    tmp.clear();

    in.close();

    cout << solve(calories);

    return 0;
}