#include<iostream>

using namespace std; 

class Node{
public:
	int data;
	Node* next;
};
class Linkedlist{
	private: 
		Node* head;
	public:
		Linkedlist();
		Linkedlist(int* A,int size);
		~Linkedlist();

		void Display();
		void Insert(int pos,int x);
		Node* Search(int x);
		int Delete(int index);
		int count();
	
};
Linkedlist::Linkedlist(){
	head = NULL;
}
Linkedlist::Linkedlist(int* A,int size){
	Node *temp,*last;
	head = new Node();
	head->data = A[0];
	head->next = nullptr;
	last = head;
	for(int i=1;i<size;++i){
		temp = new Node();
		temp->data = A[i];
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
}
Linkedlist::~Linkedlist(){
	Node *p = head;
	
	while(head){
		head = head->next;
		delete p;
		p=head;
	}
}
void Linkedlist::Display(){
	Node *p = head;
	while(p){
		cout<<p->data<<"->";
		p=p->next;
	}
}
int Linkedlist::count(){
	Node *p = head;
	int c=0;
	while(p){
		c++;
		p=p->next;
	}
	return c;
}
void Linkedlist::Insert(int pos,int x){
	Node *p;
	Node *temp;
	
	if(pos<0 || pos>count()){
		return;
	}
	temp = new Node();
		temp->data = x;
		temp->next = nullptr;
	if(pos==0){
		
		temp->next = head;
		head = temp;
	}
	else if(pos>0){
		
		 
		for(int i=0;i<pos-1;i++){
			p = p->next;
		}
		
			 
			temp->next = p->next;
			p->next = temp;
		
	    Display();
	}
}
Node* Linkedlist::Search(int x){
	Node *p;
	p=head;
	while(p != nullptr){
		if(x=p->data){
			return p;
		}
		else{
			p=p->next;
		}


	}
	return nullptr;
}
int Linkedlist::Delete(int index){
	Node *p,*q;

	int x;
	if(index<0 || index>count()){
		return -1;
			}
	if(index==1){
		
		x = head->data;
			p=head;
		head = head->next;
		delete p;
		 

	}
	else{
		p=head;
		q=nullptr;
		for(int i=0;i<index-1;++i){
			q=p;
			p=p->next;
		}
		if(p){
			x = p->data;
			q->next = p->next;
			delete p;
			
		}
	}
	return x;
}
int main(){
	cout<<"*****Singly Linked List*****"<<endl;
	cout<<"Enter the number of elements you want insert: - ";
	int size = 0 ;
	cin>>size;
	int A[size];
	cout<<"Enter the elements:- "<<endl;
	for(int i =0 ; i<size;i++){
		cin>>A[i];
	}
	int pin =1;
	Linkedlist myobj(A,size);
	while(pin==1){
		int ch;
	cout<<"\nMenu.";
	cout<<"\n1.Insert.";
	cout<<"\n2.Display.";
	cout<<"\n3.Search.";
	cout<<"\n4.Delete.";
	cout<<"\n5.Lenght of Linked List.";
	cout<<"\n6.Exit.";
    cout<<"\nEnter your Choice:- ";
    cin>>ch;
    switch(ch){
    	case 1:{
    	   int x,pos;	
    	   cout<<"\nEnter the Data and position to be inserted respectively:- ";
    	   cin>>x;	
    	   cin>>pos;
           myobj.Insert(pos,x);
           cout<<"\nData Inserted Successfully :)";
           break;
    	}
    	case 2:{
    		cout<<"\nThe Singly List is:-"<<endl;
    		myobj.Display();
    		break;
    	}
    	case 3:{
    		int x;
    		cout<<"Enter the Data to be Searched:- ";
    		cin>>x;
    		Node *t=myobj.Search(x);
    		if(t){
    			cout<<"\n The Search Node is: "<<t->data;

    		}
    		else{
    			cout<<"Data Not Found!";
    		}
    		break;
    	}
    	case 4:{
    		cout<<"\nEnter the index to be delete from the given Linked List:- \n";
    		myobj.Display();
    		int x;
    		cin>>x;
    		cout<<"The Data "<<myobj.Delete(x)<<" Deleted."<<endl;
    		break;
    	}
    	case 5:{
    		cout<<"\nThe Lenght of the Singly Linked List is: "<<myobj.count();
    		break;
    	}
    	case 6:{
    		cout<<"\nExiting...";
    		pin=0;
    		break;
    	}
    }
}

}