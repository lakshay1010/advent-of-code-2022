#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream in("../sample_input.txt");
    ifstream in("../input.txt");
    if (!in)
    {
        cout << "Unable to open file!";
        exit(1);
    }
    int priorities = 0;
    string line;
    while (getline(in, line))
    {
        char common;
        int n = line.size();
        // cout << n << endl;
        unordered_set<char> st;
        for (int i = 0; i < n / 2; ++i)
            st.insert(line[i]);
        for (int i = n / 2; i < n; ++i)
            if (st.find(line[i]) != st.end())
            {
                // cout << line[i] << endl;
                common = line[i];
                break;
            }
        // cout << "common char: " << common << endl;
        int priority = 0;
        if (isupper(common))
            priority = 27 + (common - 'A');
        else
            priority = 1 + (common - 'a');
        // cout << "priority: " << priority << endl;
        priorities += priority;
        // cout << endl;
    }

    // string x;
    // while (in >> x)
    // {
    //     cout << x << endl;
    // }
    in.close();

    cout << priorities << endl;
    return 0;
}