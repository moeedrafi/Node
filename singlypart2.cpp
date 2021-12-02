#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class mainList {
    private:
        Node* head;

    public:
        mainList()
        {
            head = NULL;
        }

        void add_to_head(int v)
        {
            Node* temp = new Node;
            temp->data = v;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }

            temp = NULL;
            delete temp;
        }

        void split()
        {
            mainList l1, l2;
            Node* p = head;

            while (p != NULL)
            {
                if (p->data < 5)
                {
                    l1.add_to_head(p->data);
                }
                else
                {
                    l2.add_to_head(p->data);
                   
                } p = p->next;
            }

            cout << endl << "List 1" << endl;
            l1.display();

            cout << endl << "List 2" << endl;
            l2.display();
        }

        void display()
        {
            Node* ptr = new Node;

            ptr = head;

            while (ptr != NULL)
            {
                cout << '\n' << ptr->data << endl;
               // cout << endl << ptr->next << endl;
                ptr = ptr->next;
            }

            ptr = NULL;
            delete ptr;
        }
};

int main()
{
    mainList l;

    l.add_to_head(1);
    l.add_to_head(2);
    l.add_to_head(3);
    l.add_to_head(4);
    l.add_to_head(5);
    l.add_to_head(6);
    l.add_to_head(7);
    l.add_to_head(8);
    l.add_to_head(9);

    l.split();

}
