//
// Created by Sulav on 11/10/2019.
//
#include <string>

struct ResultType
{
    std::string sentence;
    int frequency;

    ResultType(std::string s, int times)
    {
        this->sentence = s;
        this->frequency = times;
    }
};

/*
 *  A comparator for ResultType. Used by Priority Queue in AutoComplete System.
 */
struct ResultComp
{
    bool operator()(const ResultType& a, const ResultType& b)
    {
        if(a.frequency == b.frequency) return a.sentence < b.sentence;
        return a.frequency > b.frequency;
    }
};