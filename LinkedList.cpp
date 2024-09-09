#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    // Create linked list from array
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    // Clean up all nodes
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getLink();
        delete current;
        current = next;
    }
    head = nullptr;
}

void LinkedList::insertPosition(int pos, int newNum) {
    // Handle insertion logic
    Node* newNode = new Node(newNum);
    if (pos <= 1) {
        // Insert at the beginning
        newNode->setLink(head);
        head = newNode;
    } else {
        // Insert at a specific position
        Node* current = head;
        Node* previous = nullptr;
        int index = 1;
        while (current != nullptr && index < pos) {
            previous = current;
            current = current->getLink();
            index++;
        }
        // Insert newNode in the list
        newNode->setLink(current);
        if (previous != nullptr) {
            previous->setLink(newNode);
        } else {
            head = newNode;
        }
    }
}

bool LinkedList::deletePosition(int pos) {
    // Handle deletion logic
    if (pos <= 0) {
        return false;
    }
    
    Node* current = head;
    Node* previous = nullptr;
    int index = 1;
    
    // Find the node at position pos
    while (current != nullptr && index < pos) {
        previous = current;
        current = current->getLink();
        index++;
    }
    
    // If position is out of bounds
    if (current == nullptr) {
        return false;
    }
    
    // Delete the node
    if (previous == nullptr) {
        // Delete head node
        head = current->getLink();
    } else {
        previous->setLink(current->getLink());
    }
    
    delete current;
    return true;
}

int LinkedList::get(int pos) {
    // Handle get logic
    Node* current = head;
    int index = 1;
    
    // Find the node at position pos
    while (current != nullptr && index < pos) {
        current = current->getLink();
        index++;
    }
    
    // If position is out of bounds
    if (current == nullptr) {
        return std::numeric_limits<int>::max();
    }
    
    return current->getData();
}

int LinkedList::search(int target) {
    // Handle search logic
    Node* current = head;
    int index = 1;
    
    // Search for the target value
    while (current != nullptr) {
        if (current->getData() == target) {
            return index;
        }
        current = current->getLink();
        index++;
    }
    
    return -1;
}

void LinkedList::printList() {
    // Handle print logic
    std::cout << "[";
    Node* current = head;
    
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getLink();
    }
    
    std::cout << "]";
}
