#include <iostream>
#include <fstream>
using namespace std;
class Node
{
private:
  int data;
  Node *Next;
public:
  void set_data(int);
  int get_data();
  void set_Next(Node*);
  Node* get_Next();
  Node(int data)
  {
    this->data=data;
    Next=NULL;
  }
};
void Node::set_data(int data)
{
  this->data=data;
}
int Node::get_data()
{
  return data;
}
void Node::set_Next(Node* ptr)
{
  Next=ptr;
}
Node* Node::get_Next()
{
  return Next;
}
class Link_list
{
private:
  Node *first;
public:
  Link_list()
  {
    first=NULL;
  }
  void add_node_start_list(int);
  void remove_node_for_value(int);
  void find_value(int);
  void display_hash_table();
};
void Link_list::add_node_start_list(int input)
{
  Node *temp2=new Node(input);
  Node *temp;
  temp=first;
  if(first==NULL)
  {
    first=temp2;
  }
  else
  {
   temp2->set_Next(temp);
   first=temp2;
  }
}
void Link_list::remove_node_for_value(int input)
{
  Node *temp;
  temp=first;
  if(first==NULL)
  {
      cout << "No match is found for your value\n";
      return;
  }
  else if(temp->get_data()==input)//for to remove first node
  {
    temp=temp->get_Next();
    first=temp;
    return;
  }
  else
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to remove last node
    {
      temp->set_Next(NULL);
      return;
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for to remove middle node
    {
     Node *temp2;
     temp2=temp;
     temp2=temp2->get_Next()->get_Next();
     temp->set_Next(temp2);
     return;
    }
    temp=temp->get_Next();
    }
  }
  cout << "No match is found for your value\n";
}
void Link_list::find_value(int input)
{
  int counter=1;
  Node *temp;
  temp=first;
  if(first==NULL)
  {
      cout << "Value is not found\n";
  }
  else if(temp->get_data()==input)//for first node
  {
    cout << "Value is found\n";
    return;
  }
  else
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to find last node
    {
      cout << "Value is founded\n";
      break;
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for find middle node
    {
     cout << "Value is founded\n";
     break;
    }
    else if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()!=input)
    {
      cout << "Value is not found\n";
      break;
    }
    temp=temp->get_Next();
    counter++;
    }
  }
}
void Link_list::display_hash_table()
{
  Node *temp;
  temp=first;
  while(temp!=NULL)
  {
    cout << temp->get_data() << endl;
    temp=temp->get_Next();
  }
}
class Hashing
{
  private:
  Link_list object[10];
  public:
  int hashing_function(int);
  void add_value_in_hash_table(int);
  void remove_value_in_hash_table(int);
  void search_value_in_hash_table(int);
  void display();
};
int Hashing::hashing_function(int data)
{
            return data%10;
}
void Hashing::add_value_in_hash_table(int input)
{
    int check;
    check=hashing_function(input);
    object[check].add_node_start_list(input);
    return;
}
void Hashing::remove_value_in_hash_table(int input)
{
    int check;
    check=hashing_function(input);
    object[check].remove_node_for_value(input);
    return;
}
void Hashing::search_value_in_hash_table(int input)
{
    int check;
    check=hashing_function(input);
    object[check].find_value(input);
    return;
}
void Hashing::display()
{
    int a;
    for(a=0;a<10;a++)
    {
        cout << "Ye display ho raha ha index " << a << endl;
        object[a].display_hash_table();
    }
}
int main()
{
  Hashing object;
  int a,input,choice;
  while(true)
  {
  cout << "*********************************************************\n";
  cout << "Enter 1 to add value\n";
  cout << "Enter 2 remove value\n";
  cout << "Enter 3 search value in your list\n";
  cout << "Enter 4 for display\n";
  cout << "**********************************************************\n";
  cin >> input;

  if(input==1)
  {
    int data;
    cout << "Enter value to add at start\n";
    cin >> data;
    object.add_value_in_hash_table(data);
  }
  else if(input==2)
  {
    cout << "Enter value you want to remove from list\n";
    int data;
    cin >> data;
    object.remove_value_in_hash_table(data);
  }
  else if(input==3)
  {
    cout << "Enter value you want to search\n";
    int data;
    cin >> data;
    object.search_value_in_hash_table(data);
  }
  else if(input==4)
  {
    object.display();
  }
  cout << "Enter 1 for to continue use functions for list or 0 to stop\n";
  cin >> choice;

  if(choice!=1)
  {
    break;
  }
 }
}
