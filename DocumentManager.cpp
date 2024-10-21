#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    documents[id] = std::make_tuple(name, license_limit, 0);
    document_name_to_id[name] = id;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name) {
    if (document_name_to_id.find(name) != document_name_to_id.end()) {
        return document_name_to_id[name];
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) return false;
    if (documents.find(docid) == documents.end()) return false;
    
    auto& [name, license_limit, borrowed_count] = documents[docid];
    
    if (borrowed_count >= license_limit) return false;
    
    borrowed_documents[docid].insert(patronID);
    borrowed_count++;
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if (borrowed_documents.find(docid) != borrowed_documents.end() &&
        borrowed_documents[docid].find(patronID) != borrowed_documents[docid].end()) {
        borrowed_documents[docid].erase(patronID);
        auto& borrowed_count = std::get<2>(documents[docid]);
        borrowed_count--;
    }
}
