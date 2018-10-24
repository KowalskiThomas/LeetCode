#include <string>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int strStr(string haystack, string needle)
{
    auto needle_length = needle.length();
    if (needle_length == 0)
        return 0;
    
    auto haystack_length = haystack.length();
    if (haystack_length < needle_length)
        return -1;
    
    auto s = haystack.c_str();
    auto sub = needle.c_str();

    int j = 0;
    for (auto i = 0; i < haystack.length() - needle.length() + 1; i++)
    {
        if (haystack[i] == needle[0])
        {
            if (needle_length == 1)
                return i;
                
            j = 1;
            while (haystack[i + j] == needle[j])
            {
                if (j == needle.length() - 1)
                    return i;
                j++;
            }
        }
    }

    return -1;
}

int main()
{
    cout << (-1 == strStr("", "qsjdklqsd")) << endl;
    cout << (0 == strStr("qsdqsdf", "")) << endl;
    cout << (1 == strStr("abcdef", "bcd")) << endl;
    cout << (3 == strStr("abcdef", "def")) << endl;
    cout << (-1 == strStr("abcde", "def")) << endl;
    cout << (2 == strStr("hello", "ll"))  << endl;
    cout << (0 == strStr("a", "a"))  << endl;
    return 0;
}