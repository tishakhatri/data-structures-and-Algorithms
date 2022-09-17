/*
A033
DWITI PAREKH
A003
ABHIJEET KUMAR BANTY 
*/


#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

struct node{
    char data[40];
    struct node*next;
    struct node*prev;
};

char temp[40];
struct node*head=NULL;
struct node*current_node=NULL;

void insert(){
    cout<<"Enter Music Name:\n";
    while((getchar())!='\n');
    cin>>temp;
    

    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data,temp);
    ofstream myfile;
  	myfile.open ("songs.txt",ios_base::app);
  	myfile << "song added : "<<" "<<new_node->data;
  	myfile <<endl;
  	
  	myfile.close();
    if(head==NULL){
        new_node->next=new_node->prev=new_node;
        head=current_node=new_node;
        return;
    }
    struct node*last=head->prev;
    new_node->prev=last;
    last->next=new_node;
    new_node->next=head;
    head->prev=new_node;
    
}

void Delete_element(){
    if(head==NULL){
        cout<<"No Music is there to delete!\n";
        return;
    }
    cout<<"Enter Music Name to delete:\n";
    while((getchar())!='\n');
    cin>>temp;
    cout<<"\n";
    
    struct node*ptr=head;
    do{
        if(ptr->next==ptr && strcmp(ptr->data,temp)==0){
            cout<<"One file deleted! Playlist is Empty Now!\n";
            head=NULL;
            free(ptr);
            return;
        }
        else if(strcmp(ptr->data,temp)==0){
            struct node*prev=ptr->prev;
            struct node*next=ptr->next;
            prev->next=next;
            next->prev=prev;
            head=next;
            free(ptr);
            cout<<"Music deleted!\n";
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<"No Music file is there!\n";
}


void show(){
    if(head==NULL){
        cout<<"Playlist is Empty!\n";
        return;
    }
    struct node*show_ptr=head;
    cout<<"\n";
    cout<<"Displaying Playlist :\n";
    int i = 1;
    do{
    	cout<<"Song "<<i<<" : "<<show_ptr->data<<endl;
		i++;
        show_ptr=show_ptr->next;
    }while(show_ptr!=head);
}

void next_node(){
    if(current_node==NULL){
        cout<<"No songs in Playlist!\n";
    }
    else{
        current_node=current_node->next;
        cout<<"Playing Next Song : "<<current_node->data<<endl;
    }
}

void prev_node(){
    if(current_node==NULL){
        cout<<"No songs in Playlist!\n";
    }
    else{
        current_node=current_node->prev;
        cout<<"Playing Previous Song : "<<current_node->data<<endl;
    }
}

void first_node(){
    if(head==NULL){
        cout<<"Playlist is Empty!\n";
    }
    else{
        cout<<"Playing First Music : "<<head->data<<endl;
    }
}

void last_node(){
    if(head==NULL){
        cout<<"Playlist is Empty!\n";
    }
    else{
        cout<<"Playing Last Music : "<<head->prev->data<<endl;
    }
}

void specific_data(){
    if(head==NULL){
       cout<<"No music is there to be searched!\n";
        return;
    }
    cout<<"Enter Music Name to searched :\n";
    while((getchar())!='\n');
    cin>>temp;
    cout<<"\n";
    struct node*ptr=head;
    do{
        if(strcmp(ptr->data,temp)==0){
            cout<<"Music Found!\n";
            cout<<"Playing Music : "<<ptr->data;
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<"There is no Music file with this name!\n";
}




int main() {
  int choice;
  
   

   
  do {
    cout << "\n-----Song Playlist Application-----\n";
    cout << "1. Add Music\n";
    cout << "2. Remove Music\n";
    cout << "3. Show Playlist\n";
    cout << "4. Play next file\n";
    cout << "5. Play previous file,\n";
    cout << "6. Play first file\n";
    cout << "7. Play Last file\n";
    cout << "8. Play specific file.\n";
    cout << "9. Exit\n\n";
    cout << endl << "Enter the choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
    insert();
    break;
    case 2:
    cout << endl;
    Delete_element();
    break;
    case 3:
    cout << endl;
    show();
    break;
    case 4:
	cout<<endl;
    next_node();
    break;
    case 5:
    cout<<endl;
    prev_node();
    break;
    case 6:
    cout<<endl;
	first_node();
    break;
    case 7:
    cout<<endl;
    last_node();
    break;
    case 8:
    cout<<endl;
    specific_data();
    break;
}
    
  } while (choice != 9);
   
  return 0;
}


