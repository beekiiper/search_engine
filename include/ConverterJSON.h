#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
#include <exception>

class ConverterJSON
{
public:
    static ConverterJSON* getInstance();
    void readConfigFile(std::string path = "config.json");                   // чтение конфигурационный файл
    void readRequestFile(std::string path = "requests.json");                // чтение файла запросов
    std::vector<std::string> getRequests();                                  // получение вектора запросов
    std::vector<std::string> getTextDocuments();                             // для перевода источника в строку
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);// запись результаты в файл answers.json
    int getMaxResponses() const;                                             // максимальное количество ответов

private:
    ConverterJSON() = default;
    static ConverterJSON* instance;
    const std::string ANSWERS_FILE_PATH = "answers.json";
    std::string applicationName;
    std::string applicationVersion;
    int maxResponses  {5};
    std::vector<std::string> resourcesPaths;
    std::vector<std::string> textDocuments;
    std::vector<std::string> requests;
};
