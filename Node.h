#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

public:
    // Constructor
    Node(int data, Node* link = nullptr);
    
    // Getters and Setters
    int getData();
    void setData(int data);
    Node* getLink();
    void setLink(Node* link);
};

#endif // NODE_H
