#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class list
{
    private:
        Node* head;

    public:
        list()
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
    void add_to_end(int v)
    {
    	Node* temp = new Node;
    	temp->data = v;
    	temp->next = NULL;
    	if(head == NULL)
    	{
    		head = temp;
		}
		else
		{
			Node* p = head;
		    while(p->next != NULL)
            {
               p = p->next;
            }
            p->next = temp;
        }
        temp = NULL;
        delete temp;
    }
    void add_Spec_Pos(int pos, int v)
    {
    	Node* temp = new Node;
    	temp->data = v;
    	temp->next = NULL;
    	Node* p = head;
    	Node* q = head->next;
    	for(int i=1; i<pos-2; i++)
			{
			    p = p->next;
			    q = q->next;
			}
		temp->prev = p;
		temp->next = q;
		p->next = temp;
		p = NULL;
		delete p;
		q = NULL;
		delete q;
		temp = NULL;
		delete temp;
	}
    void del_by_value(int value)
    {
        Node* p = head;
        Node* q = head;

        while (p->data != value)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }

    void delete_from_head()
    {
        Node* p = new Node;
        p = head;

        head = head->next;
        delete p;
    }

    void delete_from_end()
    {
        Node* p = head;
        Node* q = new Node;
        
        while (p -> next -> next != NULL)
        {
            p = p->next;
        }

        q = p->next;
        delete q;
        p->next = NULL;
    }
    void sorting()
    {
    	Node* p = head;
    	while(p != NULL)
    	{
    		Node* q = head->next;
    		while(q != NULL && p->data > q->data)
    		{
    			p->next = q->next;
    			q->next = head;
    			head = q;
    			q = p->next;
			}
			p = p->next;
		}
	}
    void display()
    {
        Node* ptr = new Node;

        ptr = head;

        while (ptr != NULL)
        {
            cout << '\n' << ptr->data << endl;
           cout << endl << ptr->next << endl;
            ptr = ptr->next;
        }

        ptr = NULL;
        delete ptr;
    }
};

int main()
{
    list l;

    cout << endl << "Displaying list before deletion:" << endl << endl;

    l.add_to_head(3);
    l.add_to_head(4);
    l.add_to_head(5);
    l.add_to_head(6);
    l.add_to_head(7);
    l.add_to_head(9);

    l.display();

    //cout << endl << endl << "Displaying the list after deletion:" << endl<< endl;

    //l.del_by_value(6);
    //l.del_by_value(3);
    //l.delete_from_head();
    //l.delete_from_end();

    //l.display();
}
