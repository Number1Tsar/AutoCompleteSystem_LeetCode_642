#include <iostream>
#include <vector>
#include "AutoCompleteSystem.cpp"

using namespace std;

int main()
{
    vector<string> sentences = {"i love you", "island","ironman", "i love leetcode"};
    vector<int> times = {5,3,2,2};
    AutocompleteSystem acs(sentences, times);
    string text = "i a#";
    for(char c : text)
    {
        auto list = acs.input(c);
        for(string suggesstions : list)
        {
            cout<<suggesstions<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}