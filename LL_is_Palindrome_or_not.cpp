// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
Node* rev(Node*cur, Node* prev)
{
    if (!cur->next)
    {
        cur->next = prev;
        return cur;

    }
    Node*nx = cur->next;
    cur->next = prev;
    return rev(nx, cur);
}
bool isPalindrome(Node *head)
{
    //Your code here
    Node*slow = head, *fast = head, *sprev = head;
    if (head != NULL && head->next != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            sprev = slow;
            slow = slow->next;
        }
        if (fast != NULL)
            slow = slow->next;

        sprev->next = NULL;
        slow = rev(slow, NULL);
        while (slow != NULL)
        {
            if (head->data != slow->data)
                return false;
            slow = slow->next;
            head = head->next;
        }

    }

    return true;
}

