#include "Autocomplete.h"

#include <algorithm>

Autocomplete::Autocomplete() : root(new TrieNode()) {}

void Autocomplete::insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* current = root;

    // Traverse to the node representing the last character of the partial word
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            // No suggestions if prefix not found
            return suggestions;
        }
        current = current->children[c];
    }

    // Traverse all paths under the current node to collect suggestions
    std::string prefix = partialWord;
    traverse(current, prefix, suggestions);
    return suggestions;
}

void Autocomplete::traverse(TrieNode* node, std::string& prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& pair : node->children) {
        prefix.push_back(pair.first);
        traverse(pair.second, prefix, suggestions);
        prefix.pop_back();
    }
}
