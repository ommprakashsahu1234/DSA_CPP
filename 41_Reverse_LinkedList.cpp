#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *curr = head->next;
    ListNode *prev = head;
    head->next = nullptr;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *createList(vector<int> values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << " -> NULL" << endl;
}

int main()
{
    vector<vector<int>> tests = {
        {},
        {1},
        {1, 2},
        {1, 2, 3},
        {1, 2, 3, 4, 5},
        {7, 7, 7}};

    for (const auto &test : tests)
    {
        ListNode *head = createList(test);

        cout << "Input:  ";
        printList(head);

        ListNode *result = reverseList(head);

        cout << "Output: ";
        printList(result);

        cout << "-------------------" << endl;
    }

    return 0;
}