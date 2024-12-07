#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter string: ";
    string str;
    getline(cin, str);

    int count = 0;
    string word;
    
    str += ' ';  // Add a space at the end of the string to handle the last word

    for (char ch : str)  // Iterate over each character in the string
    {
        if (ch != ' ')  // If the character is not a space
        {
            word += ch;  // Append the character to the current word
        }
        else  // If the character is a space
        {
            if (word == "will")  // Check if the current word is "will"
            {
                count++;  // Increment count if the word matches
            }
            word.clear();  // Clear the current word to process the next word
        }
    }

    cout << "The word 'will' appears " << count << " times." << endl;  // Output the result

    return 0;
}