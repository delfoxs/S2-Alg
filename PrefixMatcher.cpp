#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() : root(new TrieNode()) {}

void PrefixMatcher::insert(const std::string& address, int routerNumber) {
    TrieNode* current = root;
    for (char c : address) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    // Store router number at the leaf node
    current->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(const std::string& networkAddress) {
    TrieNode* node = findLongestPrefixNode(networkAddress);
    return (node != nullptr) ? node->routerNumber : -1;
}

TrieNode* PrefixMatcher::findLongestPrefixNode(const std::string& networkAddress) {
    TrieNode* current = root;
    TrieNode* longestPrefixNode = nullptr;

    for (char c : networkAddress) {
        if (current->children.find(c) == current->children.end()) {
            break; // No more matching prefix
        }
        current = current->children[c];
        if (current->routerNumber != -1) {
            longestPrefixNode = current; // Update longest matching prefix node
        }
    }
    return longestPrefixNode;
}
