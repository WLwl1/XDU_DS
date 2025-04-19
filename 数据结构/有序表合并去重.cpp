#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* createNode() {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    cin >> newNode->value;
    newNode->next = NULL;
    return newNode;
}

void mergeLists(ListNode*& list1, ListNode*& list2, ListNode*& mergedList) {
    ListNode* p1 = list1->next;
    ListNode* p2 = list2->next;
    mergedList = (ListNode*)malloc(sizeof(ListNode));
    ListNode* current = mergedList;

    while (p1 && p2) {
        if (p1->value < p2->value) {
            current->next = p1;
            p1 = p1->next;
        } else if (p1->value > p2->value) {
            current->next = p2;
            p2 = p2->next;
        } else {
            current->next = p2;
            p2 = p2->next;
            ListNode* duplicate = p1;
            p1 = p1->next;
            free(duplicate);
        }
        current = current->next;
    }

    current->next = (p1) ? p1 : p2;
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;

    ListNode* list1 = (ListNode*)malloc(sizeof(ListNode));
    list1->next = NULL;
    ListNode* list2 = (ListNode*)malloc(sizeof(ListNode));
    list2->next = NULL;

    ListNode* tail1 = list1;
    for (int i = 0; i < size1; ++i) {
        tail1->next = createNode();
        tail1 = tail1->next;
    }

    ListNode* tail2 = list2;
    for (int i = 0; i < size2; ++i) {
        tail2->next = createNode();
        tail2 = tail2->next;
    }

    ListNode* mergedList = NULL;
    mergeLists(list1, list2, mergedList);

    ListNode* current = mergedList->next;
    while (current) {
        cout << current->value;
        if (current->next) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;

    current = mergedList->next;
    while (current) {
        ListNode* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free(mergedList);
    free(list1);
    free(list2);

    return 0;
}

