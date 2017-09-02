#include <iostream>
#include "data.h"

using namespace std;

class Solution {
public:
    ListNode *reverseBetween(ListNode*head, int m, int n)
    {
        ListNode *f = new ListNode(0);
        f->next = head;
        ListNode *first = f;
        for (int i=1; i<m-1; i++)
            first = first->next;
        ListNode *pre = first == NULL ? NULL : first->next;
        ListNode *post = pre == NULL ? NULL : pre->next;
        if (post == NULL)
            return head;
        for (int i=m; i<n; i++)
        {
            pre->next = post->next;
            post->next = first->next;
            first->next = post;
            post = pre->next;
        }
        return f->next;
    }
};

int main(int argc, char **argv)
{
    return 0;
}