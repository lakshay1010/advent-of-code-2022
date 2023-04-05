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
    int n = 1;
    unordered_set<char> st;
    unordered_set<char> common;
    while (getline(in, line))
    {
        if (n == 1)
        {
            st = unordered_set<char>(line.begin(), line.end());
            ++n;
        }
        else if (n == 2)
        {
            for (int i = 0; i < line.size(); ++i)
            {
                if (st.count(line[i]))
                {
                    common.insert(line[i]);
                }
            }
            ++n;
        }
        else if (n == 3)
        {
            for (int i = 0; i < line.size(); ++i)
            {
                if (common.find(line[i]) != common.end())
                {
                    int priority = 0;
                    if (isupper(line[i]))
                        priority = 27 + (line[i] - 'A');
                    else
                        priority = 1 + (line[i] - 'a');
                    priorities += priority;
                    break;
                }
            }
            common.clear();
            st.clear();
            n = 1;
        }
    }
    in.close();
    cout << priorities << endl;
    return 0;
}