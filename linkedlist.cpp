#include <iostream>
using namespace std;
#include <stdlib.h>
int pos, counter, c;
struct node
{
    int info;
    struct node *next;
};
struct node *start, *temp, *newn, *nn, *ptr;
struct node *create(int item)
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->info = item;
    nn->next = NULL;
    return nn;
}
void Display()
{
    temp = start;
    while (temp != NULL)
    {
        cout << temp->info << endl;
        temp = temp->next;
    }
    cout << "End" << endl;
}
int count_nodes()
{
    c = 0;
    temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    cout << "Count is:" << c;
}
void ins_beg()
{
    if (newn == NULL)
    {
        cout << "Failed Memory Allocation";
    }
    else if (start == NULL)
    {
        start = newn;
    }
    else
    {
        newn->next = start;
        start = newn;
    }
}
void ins_pos()
{
    cout << "Enter Position: ";
    cin >> pos;
    counter = 1;
    temp = start;
    while (counter < pos)
    {
        temp = temp->next;
        counter++;
    }
    newn->next = temp->next;
    temp->next = newn;
    cout << "Inserted\n";
}
void ins_last()
{
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
}
void Insert()
{
    int k, ch, pos;
    cout << "Enter value: ";
    cin >> k;
    newn = create(k);
    cout << "1-To insert in begining\n2-To insert in a position\n3-To insert at last\n0-To Exit: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        ins_beg();
        break;
    }
    case 2:
    {
        ins_pos();
        break;
    }
    case 3:
    {
        ins_last();
        break;
    }
    case 0:
    {
        exit(0);
    }
    }
}
void delbeg()
{
    temp = start;
    start = temp->next;
    temp->next = NULL;
    free(temp);
}
void delpos()
{
    cout << "Enter Position: ";
    cin >> pos;
    counter = 1;
    temp = start;
    while (counter < pos)
    {
        ptr = temp;
        temp = temp->next;
        counter++;
    }
    cout << "Deleted: " << temp->info << endl;
    ptr->next = temp->next;
    temp->next = NULL;
    free(temp);
}
void delast()
{
    temp = start;
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    cout << "Deleted: " << temp->info << endl;
    free(temp);
}
void Delete()
{
    int ch;
    cout << "1-To delete in begining\n2-To delete in a position\n3-To delete at last\n0-to exit: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        delbeg();
        break;
    }
    case 2:
    {
        delpos();
        break;
    }
    case 3:
    {
        delast();
        break;
    }
    case 4:
    {
        exit(0);
    }
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout << "1-Display\n2-Insert\n3-Delete\n4-Count nodes\n0-Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Display();
            break;
        }
        case 2:
        {
            Insert();
            break;
        }
        case 3:
        {
            Delete();
            break;
        }
        case 4:
        {
            count_nodes();
            break;
        }
        case 0:
        {
            cout << "Exit" << endl;
            exit(0);
        }
        }
    }
    return 0;
}
