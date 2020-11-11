#include <iostream>
using namespace std;

// int main(int argc, char *argv[])
// {
//     for (int i = 0; i < 10; i++)
//     {
//         cout << rand() % 27 << " ";
//     }
//     cout << endl;
//     srand(time(NULL));
//     for (int i = 0; i < 10; i++)
//     {
//         cout << rand() % 27 << " ";
//     }
//     cout << endl;
//     return 0;
// }
int main(int argc, char *argv[])
{
    srand(time(NULL));
    const char letters[] = "abcdefghijklmnopqrstuvwxyz ";
    // string req = "methinks it is like a weasel";
    string req = "hello";
    char test[28];
    int test_no = 0;
    int max_score = 0;
    while (max_score != req.length())
    {
        int score = 0;

        for (int i = 0; i < req.length(); i++)
        {
            test[i] = letters[rand() % 27];
        }
        for (int i = 0; i < req.length(); i++)
        {
            if (req[i] == test[i])
                score += 1;
        }
        if (score > max_score)
        {
            max_score = score;
        }
        if (++test_no % 1000000 == 0)
        {
            for (int i = 0; i < req.length(); i++)
            {
                cout << test[i];
            }
            cout << endl;
        }
    }
    cout << test << endl;
    return 0;
}