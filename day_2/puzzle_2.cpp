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
            // lose
            score = 0;
            if (line[0] == 'A') // rock, so scissor
                score += 3;
            else if (line[0] == 'B')
                score += 1;
            else
                score += 2;
        }
        else if (line[2] == 'Y')
        {
            // draw
            score = 3;
            if (line[0] == 'B')
                score += 2;
            else if (line[0] == 'C')
                score += 3;
            else
                score += 1;
        }
        else
        {
            // win
            score = 6;
            if (line[0] == 'C')
                score += 1;
            else if (line[0] == 'A')
                score += 2;
            else
                score += 3;
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