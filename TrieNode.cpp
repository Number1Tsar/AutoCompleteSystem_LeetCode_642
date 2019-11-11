//
// Created by Sulav on 11/10/2019.
//
#include <vector>

#define LANGUAGE_SIZE 128

struct TrieNode
{
private:
    std::vector<TrieNode*>* childrenNodes;
    bool isWord;
    int timesOccurred;

public:
    TrieNode()
    {
        childrenNodes = new std::vector<TrieNode*>(LANGUAGE_SIZE, nullptr);
        isWord = false;
        timesOccurred = 0;
    }

    std::vector<TrieNode*>* children()
    {
        return childrenNodes;
    }

    bool isDictionaryWord(){return isWord;};

    void setDictionaryWord(){this->isWord = true;}

    int getTimesOccurred(){ return this->timesOccurred;};

    void incrementTimesOccurred(int times)
    {
        this->timesOccurred += times;
    }
};