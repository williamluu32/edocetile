#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (node != NULL) {
        node->val = val;
        node->next = NULL;
    }

    return node;
}

void print(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

///////

struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *res = head;

    while (head != NULL) {
        struct ListNode *cur = head->next;

        while (cur != NULL) {
            if (cur->val == head->val) {
                head->next = cur->next;
                free(cur);
                cur = head->next;
            } else {
                head = cur;
                cur = cur->next;
            }
        }
        head = head->next;
    }
    return res;
}

int main() {
    struct ListNode *head = createNode(1);
    struct ListNode *p1 = createNode(1);
    struct ListNode *p2 = createNode(2);
    struct ListNode *p3 = createNode(3);
    struct ListNode *p4 = createNode(3);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    struct ListNode *res = deleteDuplicates(head);
    print(res);

    return 0;
}