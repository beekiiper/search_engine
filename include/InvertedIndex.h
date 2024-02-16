#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

struct Entry
{
    size_t doc_id, count;
    // Required for tests:
    bool operator ==(const Entry& other) const
    {
        return (doc_id == other.doc_id && count == other.count);
    }
};

class InvertedIndex
{
public:
    InvertedIndex() = default;
    void updateDocumentBase(const std::vector<std::string>& input_docs);         // заполнение базы документов
    std::vector<Entry> getWordCount(const std::string& word);                    // вектор слов с расчитанной частатой
    size_t getWordCountInDoc(const std::string& word, const size_t doc_id) const;// вектор слов частатой в документе

private:
    void indexTheFile(const std::string& fileContent, size_t docId);    // индексация файла
    std::map<int, std::string> document_list;                           // список индексированных файлов
    static std::mutex mutexIndexMap;                                    // многопоточность
    std::map<std::string, std::vector<Entry>> frequencyDictionary;      // частота всех файлов
    bool indexingIsOngoing;
};