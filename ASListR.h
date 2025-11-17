#ifndef ASLISTR_H
#define ASLISTR_H

#include <string>
using namespace std;

struct Team {
    string teamID;
    int W;
    int attendance;
};

class ASListR {
private:
    struct Node {
        Team data;
        Node* next;
        Node(const Team& t) : data(t), next(nullptr) {}
    };

    Node* head;

public:
    ASListR();
    ~ASListR();
    void insert(const Team& t);
    void printAll() const;
    void printGreaterThan(int wins) const; 
};

#endif
