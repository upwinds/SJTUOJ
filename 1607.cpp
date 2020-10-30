#include<iostream>
using namespace std;
template <class elemType>
class linkQueue
{
private:
	struct node
        {
            elemType data;
            node *next;
            int num;
            node(const elemType& x,const int& i, node *N = NULL) {data = x; num = i; next = N;}
            node():next(NULL){}
            ~node(){}
        };
	node*front, *rear;
public:
	linkQueue();
	~linkQueue();
	bool isEmpty()const;
	void enQueue(const elemType& x, const int& i);
	int deQueue();
	elemType getHead()const;
};

template <class elemType>
linkQueue<elemType>::linkQueue() {
	front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue() {
	node*tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

template <class elemType>
bool linkQueue<elemType>::isEmpty()const {
	return (front == NULL);
}

template<class elemType>
void linkQueue<elemType>::enQueue(const elemType& x, const int& i)
{   
    if(rear == NULL)
        {front = rear = new node(x, i);}
    else 
    {   
        node *p = front;
        while(1)
        {
            if(p == rear) {rear->next = new node(x,i); rear = rear->next; break;}
            if(p->data == x && p->next->data != x) {
                node* tmp=new node(x,i);
                tmp->next = p ->next;
                p->next = tmp; break;
                }
            p = p->next;
        }
    }
        
}

template <class elemType>
elemType linkQueue<elemType>::getHead()const {
	return front->data;
}

template <class elemType>
int linkQueue<elemType>::deQueue() {
	node*tmp = front;
	int x = tmp->num;
	front = front->next;
	if (front == NULL) { rear = NULL; }
	delete tmp;
	return x;
}


int main() {
	linkQueue<int> q;
    int m=0, n=0, h=0,i=0,b,k=0; //m为进过队的人数，n为参与排队人数，h为可能发生的事件数
    int *a;     
    cin >> n;
    a = new int[n];
    for(i=0; i < n; ++i) cin >> a[i];
    cin >> h;
    for(i=0; i < h; ++i)
    {	
		cin >> b;
        switch(b)
        {
            case 0: if(m == n) break;
                    else {q.enQueue(a[m],m+1); ++m;++k;printf("\n");break;}
            default: if(k==0) {printf("-1\n");;break;}
                    else {printf("%d\n",q.deQueue()); --k;break;}
        }
    }
    delete []a;
    return 0;
	}
