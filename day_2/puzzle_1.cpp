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
    int total_score = 0;
    string line;
    while (getline(in, line))
    {
        int score = 0;

        // if(line[2]=='X') score=1;
        // else if(line[2]=='Y') score=2;
        // else score=3;

        if (line[2] == 'X')
        {
            score = 1;
            if (line[0] == 'A')
                score += 3;
            else if (line[0] == 'B')
                score += 0;
            else
                score += 6;
        }
        else if (line[2] == 'Y')
        {
            score = 2;
            if (line[0] == 'B')
                score += 3;
            else if (line[0] == 'C')
                score += 0;
            else
                score += 6;
        }
        else
        {
            score = 3;
            if (line[0] == 'C')
                score += 3;
            else if (line[0] == 'A')
                score += 0;
            else
                score += 6;
        }

        total_score += score;
    }

    // string x;
    // while (in >> x)
    // {
    //     cout << x << endl;
    // }
    in.close();

    cout << total_score << endl;

    return 0;
}