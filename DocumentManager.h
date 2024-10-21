#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <tuple>

class DocumentManager {
private:
    std::unordered_map<int, std::tuple<std::string, int, int>> documents;
    std::unordered_map<std::string, int> document_name_to_id;
    std::unordered_set<int> patrons;
    std::unordered_map<int, std::unordered_set<int>> borrowed_documents;

public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};

#endif
