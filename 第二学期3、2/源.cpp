#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>*next;
};

template<class T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	void Merge(LinkList<T> &L);
	void printList();
private:
	Node<T>*front;
	Node<T>*r;
};

template<class T>
LinkList<T>::LinkList()
{
	int len, in;
	cin >> len;
	front = new Node<T>;
	r = front;

	for (int i = 0; i < len; i++)
	{
		cin >> in;
		r->next = new Node<T>;
		r = r->next;
		r->data = in;

	}
	r->next = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
	while (r)
	{
		r = front->next;
		delete front;
		front = r;
	}
}

template<class T>
void LinkList<T>::Merge(LinkList<T> &L)
{
	r->next = L.front->next;
	L.front->next = NULL;
	Node<T> *p1 = front->next, *p2 = front->next;

	T count;
	while (p1)
	{

		while (p2 && (p2 = p2->next))
		{
			if (p2->data < p1->data)
			{
				count = p2->data;
				p2->data = p1->data;
				p1->data = count;
			}


		}
		p1 = p1->next;
		p2 = p1;

	}


}

template<class T>
void LinkList<T>::printList()
{
	Node<T> *s = front->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
}


int main()
{
	LinkList<int> L1, L2;
	L1.Merge(L2);
	L1.printList();
	return 0;
}