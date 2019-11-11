//
// Created by Sulav on 11/10/2019.
//
#include "Trie.cpp"
#include <vector>
#include <string>
#include <queue>

#define TERMINAL_CHAR '#'
#define TOP_MATCH_NUMBER 3

class AutocompleteSystem
{
private:
    Trie* t;
    int numberofTopMatches;
    std::string currentSearch;

public:
    AutocompleteSystem(std::vector<std::string>& sentences, std::vector<int>& times)
    {
        t = new Trie();
        this->numberofTopMatches = TOP_MATCH_NUMBER;
        for(int i=0;i<sentences.size();i++)t->insert(sentences[i],times[i]);
    }

    std::vector<std::string> input(char c)
    {
        if(c==TERMINAL_CHAR)
        {
            t->insert(currentSearch,1);
            currentSearch.clear();
            return {};
        }
        else
        {
            currentSearch+=c;
            auto result = t->findMatches(currentSearch);
            if(result.empty()) return {};
            std::priority_queue<ResultType, std::vector<ResultType>, ResultComp> topMatches;
            for(auto r : result)
            {
                topMatches.push(r);
                if(topMatches.size() > TOP_MATCH_NUMBER) topMatches.pop();
            }
            std::vector<std::string> matches(topMatches.size());
            int index = topMatches.size()-1;
            while(!topMatches.empty())
            {
                matches[index--] = topMatches.top().sentence;topMatches.pop();
            }
            return matches;
        }
    }

};