#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#include "InvertedIndex.h"

struct RelativeIndex
{
    size_t doc_id;
    float rank;
    size_t absoluteIndex = 0; // Added for convenience.

    bool operator ==(const RelativeIndex& other) const
        {return (doc_id == other.doc_id && rank == other.rank);}
    bool operator > (const RelativeIndex& other) const
        {return (rank > other.rank || (rank == other.rank && doc_id < other.doc_id));}
};

class SearchServer
{
public:
    SearchServer(InvertedIndex& idx) : _index(idx){ };              // чтобы сообщить частоты слов
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);
            // обработка поискового запроса, получаем  сортированный список релеваантных ответов
    void setMaxResponses(const int& newMaxResponses); // максимальное количество запросов

private:
    InvertedIndex _index;
    int maxResponses {5};
    std::set<std::string> getUniqueWords(const std::string& request); // уникальные слова из запроса
    std::vector<std::pair<std::string, size_t>> getWordsEntries(const std::set<std::string>& words);
            // вектор записей для набора слов
    void sortWordsAscendingToEntries(std::vector<std::pair<std::string, size_t>>& wordsEntries);
            // сортировка вектора записей
    std::vector<size_t> getAllDocumentsWithWords(const std::vector<std::pair<std::string, size_t>>& words);
            // получение ветора идентификаторов документа, в котором можно найти слово
    size_t getAbsoluteRelevanceForDocument (size_t docId, std::set<std::string>& uniqueWords);
            // вычисление абсалютной релевантности запросов
};