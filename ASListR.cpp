#include "ASListR.h"
#include <iostream>
using namespace std;

ASListR::ASListR() {
    head = nullptr;
}

ASListR::~ASListR() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void ASListR::insert(const Team& t) {
    Node* newNode = new Node(t);

    if (!head || t.W > head->data.W) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next && curr->next->data.W >= t.W) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void ASListR::printAll() const {
    Node* curr = head;
    while (curr) {
        cout << curr->data.teamID << ", "
             << curr->data.W << ", "
             << curr->data.attendance << endl;
        curr = curr->next;
    }
}

void ASListR::printGreaterThan(int wins) const {
    Node* curr = head;
    while (curr) {
        if (curr->data.W >= wins) {
            cout << curr->data.teamID << ", "
                 << curr->data.W << ", "
                 << curr->data.attendance << endl;
        }
        curr = curr->next;
    }
}
