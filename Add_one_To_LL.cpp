#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

Node* addOne(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node* head = new Node( s[0] - '0' );
        Node* tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node( s[i] - '0' );
            tail = tail->next;
        }

        head = addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


//User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
Node* rev(Node*cur , Node* prev)
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
Node* add(Node*head)
{
    Node*res = head;
    Node*temp = NULL, *prev = NULL;
    int carry = 1, sum;
    while (head != NULL)
    {
        sum = carry + head->data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        //carry=(sum>10)?1:0;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = new Node(carry);
    return res;
}
Node* addOne(Node *head)
{
    head = rev(head, NULL);
    head = add(head);
    return  rev(head, NULL);

}