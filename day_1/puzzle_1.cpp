#include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <string>
using namespace std;

int solve(vector<vector<int>> calories)
{
    int msf = INT_MIN;
    for (auto const &e : calories)
    {
        int sum = 0;
        for (auto const &f : e)
        {
            sum += f;
        }
        msf = max(msf, sum);
    }

    return msf;
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