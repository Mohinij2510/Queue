#include <iostream>
using namespace std;
const int capacity=100;

class waitlist {
    public:
    string queue[capacity];
    int front = -1;
    int rear =-1;
   
    bool isFull(){
       return rear==capacity-1;

    }
    bool isEmpty(){
         return rear==-1;

    }

    void addparty(string name){
        if(isFull() && front==0){
           
            return ;            
        }
       if(isEmpty()){
           
            rear=0;
            queue[rear]=name;
            front=0;
                     
        }else{
            rear++;
            queue[rear]=name;
        }

       
       
    }

    void seatparty(){
        if(front>rear){
            cout<< "Waitlist Empty."<< endl;
            return ;            
        }
        cout<<"Party "<<queue[front] << " removed from list."<<endl;
        front++;
       
       
       
    }

    void display(){
        if(front>rear){
            cout<< "Waitlist Empty."<< endl;
            return ;            
        }
       for(int i= front; i<=rear;i++){
        cout<<queue[i]<<endl;

       }
       
    }

   

};

int main()
{
    waitlist wlist;
    int choice;
    string name;

    char con = 'y';

    while (con == 'y' || con == 'Y')
    {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add party" << endl;
        cout << "2. Display Waitlist" << endl;
        cout << "3. Seat Party" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout<<"Enter Party Name: ";
                cin>>name;
                wlist.addparty(name);
                break;
            case 2:
                wlist.display();
                break;
            case 3:
               
                wlist.seatparty();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to continue? (Y/N): ";
        cin >> con;
    }

    return 0;
}