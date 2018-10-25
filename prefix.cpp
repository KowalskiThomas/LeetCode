#include <vector>
#include <string>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    auto number_of_strings = strs.size();
    if (!number_of_strings)
        return "";

    auto min = 9999;
    const char* strings[1000];
    auto temp = 0;
    for(auto i = 0; i < strs.size(); i++)
    {
        temp = strs[i].length();
        min = temp < min ? temp : min;
        strings[i] = strs[i].c_str();
    }

    if (!min || !number_of_strings)
        return "";

    char c;
    char result[1000];

    auto i = 0;
    for (; i < min; i++)
    {
        c = strs[0][i];
        for (auto j = 0; j < number_of_strings; j++)
            if (strings[j][i] != c)
            {
                result[i] = 0;
                return result;
            }
        result[i] = c;
    }

    result[i++] = 0;
    return result;
}

int main()
{
    auto vec = vector<string>({"flower", "flow", "flight"});
    cout << longestCommonPrefix(vec) << endl;
    vec = vector<string>();
    cout << longestCommonPrefix(vec) << endl;
     vec = vector<string>({"flow", "flow", "flow"});
    cout << longestCommonPrefix(vec) << endl;

    return 0;
}