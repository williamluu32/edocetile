#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;
} ListNode;

ListNode *createNode(int data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    if (node != NULL) {
        node->val = data;
        node->next = NULL;
    }

    return node;
}

void traverse(ListNode *head) {
    printf("\nList:");
    while (head != NULL) {
        printf(" %d ->", head->val);
        head = head->next;
    }
    printf(" NULL");
}

//////////////////////////////////////////////////
ListNode *sol1(ListNode *list1, ListNode *list2) {
    ListNode *res = list1;
    ListNode *prevList1 = NULL;

    while (1) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return res;
        }

        if (list2->val < list1->val) {
            ListNode *nextList2 = list2->next;
            list2->next = list1;
            if (prevList1 != NULL) {
                prevList1->next = list2;
            }
            prevList1 = list2;
            if (list2->val < res->val) {
                res = list2;
            }
            list2 = nextList2;
        } else {

            if (list1->next != NULL) {
                if (list2->val < list1->next->val) {
                    ListNode *nextList2 = list2->next;
                    list2->next = list1->next;
                    list1->next = list2;
                    list2 = nextList2;
                } else {

                    list1 = list1->next;
                }
            } else {

                ListNode *nextList2 = list2->next;
                list1->next = list2;
                list2->next = NULL;
                list2 = nextList2;
            }
        }
    }

    return res;
}

int main() {
    ListNode *list1 = NULL;
    ListNode *list2 = NULL;

    ListNode *p11 = createNode(1);
    ListNode *p12 = createNode(3);
    ListNode *p13 = createNode(5);

    ListNode *p21 = createNode(0);
    ListNode *p22 = createNode(2);
    ListNode *p23 = createNode(4);

    list1 = p11;
    p11->next = p12;
    p12->next = p13;

    list2 = p21;
    p21->next = p22;
    p22->next = p23;

    ListNode *res = sol1(list1, list2);
    traverse(res);

    return EXIT_SUCCESS;
}
