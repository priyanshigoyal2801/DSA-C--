#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingCharacter(string str)
{
    queue<char> q;
    unordered_map<char, int> freq;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        q.push(ch);

        freq[ch]++;

        while (!q.empty())
        {

            if (freq[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                // The front of the queue is the first non-repeating character
                cout << q.front() << " ";
                break;
            }
        }

        if (q.empty())
        {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main()
{
    string str = "aabc";

    firstNonRepeatingCharacter(str);

    return 0;
}
