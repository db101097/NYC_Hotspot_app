#ifndef __SORTEDLINKLIST_H__
#define __SORTEDLINKLIST_H__
#include <iostream>
#include <fstream>

template <typename T>
class node
{
	public:
	node(){};

	node(T somedata)
	{
		data=somedata;
		next=NULL;
	};
	
	T data;
	node<T> *next;
};

template <typename T>
class Iterator 
{
	public:
	Iterator(){};

	Iterator(node<T> * n)
	{
			current_pointer=n;	
	};

	Iterator & operator=(node<T> * n)
	{
			this->current_pointer=n;
			return *this;
	};

	Iterator & operator++(int)
	{
			if (current_pointer) 
                current_pointer = current_pointer->next; 
            return *this; 
	};

	bool operator != ( const Iterator<T> & itr)
	{
			return current_pointer != itr.current_pointer;
	};

	T operator* ()
	{
			return current_pointer->data;
	};

	
	private:
	node<T> * current_pointer;
};

template<typename T>
class sortedlinklist
{
	public:
	
	sortedlinklist()
	{
		size=0;
		head=NULL;
	};
	
	sortedlinklist(const T & somedata)
	{
		node<T> p;
		p=new node<T>;
		p(somedata);
		if(NULL == p)
		{
			std::cerr<<"Memory is at capacity no more data could be added"<<std::endl;
		}
	
		p->data=somedata;
		p->next=NULL;
	};
	
	~sortedlinklist()
	{
			node<T> * temp;
			while(size>0)
			{
				temp=head;
				head=head->next;
				temp->next=NULL;
				delete temp;
				size--;
			}
	}

	int length()
	{
		return size;
	};
	
	bool is_empty()
	{
		return (size==0 ? 1:0);
	};
	
	bool insert_at(node<T>* &prev , T newdata)
	{
		node<T> * p = new node<T>;
		
		//check if it's a copy or if there is no more space left to allocate a node
		if( p==NULL || (prev!=NULL && prev->data == newdata))
		{

			return false;
		}

		p->data=newdata;
		p->next=prev;
		prev = p;
		size ++;
		return true;

	};

	Iterator<T> begin()
	{
			Iterator<T> itr(head);
			return itr;
	};

	Iterator<T> end()
	{
			Iterator<T> itr (NULL);
			return itr;
	};
	
	bool insert(T newdata)
	{
			
			// list is empty or the data at head is larger therefore newdata cannot be in the list and must be insert at head
			if(head==NULL || head->data > newdata)
			{
					return insert_at(head , newdata);
			}

			// if the head is the same as the data passed then it already exist insert failed
			if(head->data == newdata)
			{
					return false;
			}
			
			node<T> * previous = head;
			node<T> * current = head->next;
		

			while ( current != NULL && current->data < newdata)
			{
				//iterate the pointers because the current element is smaller 
					previous=current;
					current=current->next;	
			}
			
			// exited while loop either larger than everything or a duplicate, insert_at function will check and take necessary action
			return insert_at(previous->next,newdata);		

	};
	
	T find(T wanted)
	{
			if(head == NULL)
			{
				return wanted;
			}
	
			node<T> * current = head;
			
			while ( current != NULL && current->data < wanted)
			{
			   		current=current->next;
			}
				

			 if (current!=NULL && current->data == wanted)
			{
				return current->data;
			}
			
			else		
			return wanted;
	};
	
	void delete_node(T delete_data)
	{
			
			if(head==NULL)
			{
					std::cout<<"Empty cannot delete"<<std::endl;
					return;
			}


			node<T> * previous = NULL;
			node<T> * current = head;
		

			while ( current != NULL && current->data < delete_data)
			{
					previous=current;
					current=current->next;	
			}

				if(previous==NULL)
			{
				previous=current->next;
				delete current;
				head=previous;
				size--;
				return;
			}
			
				if (current!=NULL && current->data == delete_data)
			{
				previous->next=current->next;
				delete current;
				size--;
				return;
			}

			std::cout<<"Could not find requested value and delete failed"<<std::endl;
	};

	void print()
	{
		node<T> * p= head;
		while(p != NULL)
		{
				std::cout<<p->data<<" ";
				p=p->next;
		}
	};
	
	
	private:
	node<T> *head;
	unsigned int size;	
};

#endif
