#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int routerNumber; // Optional: store router number at leaf nodes

    TrieNode(int router = -1) : routerNumber(router) {}
};

class PrefixMatcher {
public:
    PrefixMatcher();
    void insert(const std::string& address, int routerNumber);
    int selectRouter(const std::string& networkAddress);

private:
    TrieNode* root;

    TrieNode* findLongestPrefixNode(const std::string& networkAddress);
};

#endif // PREFIXMATCHER_H
