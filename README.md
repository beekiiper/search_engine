# Search-in-files<br>
Search for words in files |  Поиск слов в файлах.

## Description | Описание
ENG <br>
Application for searching of request words (JSON file requests.json) in resources text files (path to resources files are specified in config.json). Search result is putting into answers.json.<br><br>
RUS <br>
Приложение для поиска запрашиваемых слов (JSON файл requests.json) в текстовых файлах ресурсов (путь к ресурсам указан в config.json). Результат поиска помещается в answers.json.
## Technologies
**C++14**<br>

**CMake-3.24**<br>
https://cmake.org/<br>

**JSON-3.11.2**<br>
https://github.com/nlohmann/json<br>

**GTest-1.12.1**<br>
https://github.com/google/googletest<br>


## Files specification
* config.json<br>
File where specified name and version of application.<br>
Here you can also change the maximal quantity of relevant pages that will be put into answers.json (max_respones).<br>
Default content:<br>
```json
{
    "config": 
    {
        "name": "FileSearchEngine",
        "version": "0.1",
        "max_responses": 5
    },
    "files": 
    [
        "resources/file001.txt",
        "resources/file002.txt"
    ]
}
```

* requests.json<br>
File where specified requests for search.<br>
Each separate request sholud be entered after ',' on new line. Example below.<br>
Example content:<br>
```json
{
    "requests":
    [
        "tiger",
        "wolf",
        "monkey"
    ]
}
```
* answers.json<br>
File where search result will be written in JSON format.<br>
Example content:<br>
```json
{
  "answers": {
    "request0": {
      "relevance": [
        {
          "docid": 1,
          "rank": 1.0
        },
        {
          "docid": 0,
          "rank": 0.6700000166893005
        }
      ],
      "result": true
    },
    "request1": {
      "relevance": [
        {
          "docid": 0,
          "rank": 1.0
        },
        {
          "docid": 1,
          "rank": 1.0
        }
      ],
      "result": true
    },
    "request2": {
      "docid": 1,
      "rank": 1.0,
      "result": true
    }
  }
}
```
<i>NOTE:<br>docid - identificator of a relevant document,<br>rank - relative index,<br>result - true (if relevance is found), or false (if document absolutely not relevant for certain request).</i>
