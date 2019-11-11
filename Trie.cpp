//
// Created by Sulav on 11/10/2019.
//
#include "TrieNode.cpp"
#include "Result.cpp"
#include <string>
#include <vector>

class Trie {
private:
    TrieNode *root;

    void getAllMatches(TrieNode* node, std::string currentMatch, std::vector<ResultType>& matches)
    {
        if(node== nullptr) return;
        if(node->isDictionaryWord())
        {
            ResultType r(currentMatch,node->getTimesOccurred());
            matches.push_back(r);
        }
        for(int i=0;i<LANGUAGE_SIZE;i++) if(node->children()->at(i)!= nullptr) getAllMatches(node->children()->at(i), currentMatch+(char)(i), matches);
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string word, int times)
    {
        if(word.empty()) return;

        TrieNode* currNode = root;
        for(int i=0;i<word.size();i++)
        {
            int index = (int)word[i];
            if(currNode->children()->at(index)== nullptr) currNode->children()->at(index) = new TrieNode();
            currNode = currNode->children()->at(index);
        }
        currNode->setDictionaryWord();
        currNode->incrementTimesOccurred(times);
    }

    std::vector<ResultType> findMatches(std::string prefix)
    {
        if(prefix.empty()) return {};
        TrieNode* currNode = root;
        for(int i=0;i<prefix.size();i++)
        {
            int index = (int)prefix[i];
            if(currNode->children()->at(index)== nullptr) return {};
            currNode = currNode->children()->at(index);
        }
        std::vector<ResultType> matches;
        getAllMatches(currNode, prefix, matches);
        return matches;
    }
};
