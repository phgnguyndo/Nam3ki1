
#include<sstream>
bool SoSanhTen(string name1, string name2);
bool SoSanhDuLieu(Node *k,Node *h);
void HoanVi(SV &x,SV &y){
	SV temp;
	temp=x;
	x=y;
	y=temp;
}
void Selection_Sort(List &l){
	Node *min;
	Node *p, *q;
	p = l.first;
	while(p != l.last){
		min = p; q = p->next;
		while(q != NULL){
			if(!SoSanhDuLieu(q,min)){
				min = q;
			}
			q= q->next;
    	}
		HoanVi(min->data, p->data);
		p = p->next; 
	}
}
void BubbleSort(List &l)
{
 Node *k1=l.first;
 Node *k2;
 for(Node *p=l.first;p->next!=NULL;p=p->next)
 {
  while(k1->next!=NULL)
  {
   k2=k1;
   k1=k1->next;
   if(!SoSanhDuLieu(k1,k2))
    HoanVi(k1->data,k2->data);
  }
  k2=l.first;
  k1=l.first;
 }
}


Node *partition(Node* head, Node* end,
                       Node** newHead,
                       Node** newEnd);
Node* QuickSort(Node* head, Node* end);


Node* getTail(Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
static int ThuatToan,Khoa;//arjfvieajojepfv

void XapXep(Node* &head, Node* &tail,List &l){
	Node *temph = head, *tempt = tail;
	switch(ThuatToan){
		case 1: head = QuickSort(temph, tempt);
		        break;
        case 2: BubbleSort(l);
                break;
        case 3: BubbleSort(l);
                break;
		case 4: Selection_Sort(l);
		        break;
	}
//	tail = getTail(tail);
}
bool SoSanhDuLieu(Node *k,Node *h){
	const int DiemTb=1,Name=2,Ma=3,Lop=4;
	switch(Khoa){
		case Name:
			return SoSanhTen(k->data.HoTen,h->data.HoTen);
		case DiemTb:
			return (k->data.DTB>h->data.DTB);
		case Ma:
			return (k->data.MaSo>h->data.MaSo);
		case Lop:
			return SoSanhTen(k->data.Lop,h->data.Lop);
			
	}
}
Node *partition(Node* head, Node* end,
                       Node** newHead,
                       Node** newEnd)
                       
{
    Node* pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot) {
        if (!SoSanhDuLieu(cur,pivot)) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else 
        {
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

Node* QuickSort(Node* head, Node* end)
{
    if (!head || head == end)
        return head;
    Node *newHead = NULL, *newEnd = NULL;
    struct Node* pivot
        = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = QuickSort(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = QuickSort(pivot->next, newEnd);
 
    return newHead;
}

bool SoSanhTen(string name1, string name2){
	stringstream ss1(name1);
	stringstream ss2(name2);
	string n1[5];
	string n2[5];
	int i=0, j=0;
	while (ss1 >> n1[i]) 
        i++;
    while (ss2 >> n2[j]) 
    	j++;
    int x = 0;
    while(x==0&&i>=0&&j>=0){
    	if(j==0||i==0)
    	i=j=0;
    	x = strcmp(n1[i].c_str(), n2[j].c_str());
    	i--;j--;
		}
	if(x > 0)
	return 1;
	else return 0;    
}

