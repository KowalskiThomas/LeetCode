#include <string>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

#define DEBUG 1

int lengthOfLongestSubstring(string s)
{
    auto characters = unordered_set<char>();
    int max = 0;
    int count = 0;
    auto begin_ = s.begin();
    auto i = 0;
    // && (s.length() - 1 - i) >= max
    while (begin_ != s.end() )
    {
        #ifdef DEBUG
        cout << "While: " << *begin_ << endl;
        #endif
        for (auto it = begin_; it != s.end(); it++)
        {
            if (characters.find(*it) != characters.end())
            {
                max = max > count ? max : count;
                count = 1;
                characters.clear();
                characters.insert(*it);
                it++;
                begin_ = it;
                break;
            }

            i++;
            count++;
            characters.insert(*it);
        }
    }

    return max;
}

int main()
{
    string test = "aab";
    cout << (2 == lengthOfLongestSubstring("aab")) << endl;
    cout << (3 == lengthOfLongestSubstring("abcabc")) << endl;
    cout << (0 == lengthOfLongestSubstring("")) << endl;
    cout << (1 == lengthOfLongestSubstring("a")) << endl;
    cout << (2 == lengthOfLongestSubstring("dvdf")) << endl;
    return 0;
}