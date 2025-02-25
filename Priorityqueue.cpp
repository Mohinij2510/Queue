#include <iostream>
using namespace std;

class Job {
        public:
        string name;
        int priority;
        Job* next = nullptr;
        Job* prev = nullptr;

};
class DEqueue {
        public:
        Job* front;

        Job* rear;
        DEqueue() {
            front = nullptr;
            rear = nullptr;
        }
        void addFront(string jobName, int jobPriority) {
            Job* newJob = new Job;
            newJob->name = jobName;
            newJob->priority = jobPriority;
            if (front == nullptr) {
            front = newJob;
            rear = newJob;
            } else {
            newJob->next = front;
            front->prev = newJob;
            front = newJob;
            }
        }
        void addRear(string jobName, int jobPriority) {
            Job* newJob = new Job;
            newJob->name = jobName;
            newJob->priority = jobPriority;
            if (rear == nullptr) {
                front = newJob;
                rear = newJob;
            } else {
                rear->next = newJob;
                newJob->prev = rear;
                rear = newJob;
            }
        }
        void removeFront() {
            if (front == nullptr) {
                cout << "\nQueue is empty" << endl;
                return;
            }
        cout << "\nRemoved Job: " << front->name << " with Priority: " <<front->priority <<endl;
        Job* temp = front;
        front = front->next;
        
        if (front != nullptr) {
                front->prev = nullptr;
        } else {
                rear = nullptr; // If the queue becomes empty
        }
        delete temp;
        }

        void removeRear() {
            if (rear == nullptr) {
                    cout << "\nQueue is empty" << endl;
                    return;
            }
            cout << "\nRemoved Job: " << rear->name << " with Priority: " << rear->priority <<endl;
            Job* temp = rear;
            rear = rear->prev;

            if (rear != nullptr) {
                    rear->next = nullptr;
            } else {
                    front = nullptr; // If the queue becomes empty
            }
            delete temp;
            }
        void displayJobs() {
            if (front == nullptr) {
                    cout << "\nQueue is empty" << endl;
                    return;
            }
            cout << "\nDisplaying Jobs:" << endl;
            Job* temp = front;
            
            while (temp != nullptr) {
                    cout << "Job Name: " << temp->name << ", Priority: " << temp->priority << endl;
                    temp = temp->next;
            }
        }
        void findJob(string jobName) {
                Job* temp = front;
                while (temp != nullptr) {
                if (temp->name == jobName) {
                    cout << "\nJob Found: " << temp->name << ", Priority: " <<temp->priority <<endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "\nJob Not Found" << endl;
        }
        void addJob() {
                string jobName;
                int jobPriority;
                cout << "\nEnter the name of the job: ";
                cin >> jobName;
                cout << "Enter the priority of the job: ";
                cin >> jobPriority;

                Job* newJob = new Job;
                newJob->name = jobName;
                newJob->priority = jobPriority;

                if (front == nullptr) {
                        front = newJob;
                        rear = newJob;
                        return;
                }
                Job* temp = front;
                
                while (temp != nullptr && temp->priority < newJob->priority) {
                        temp = temp->next;
                }
                if(temp == nullptr) {
                        addRear(jobName, jobPriority);
                }
                else if(temp == front) {
                        addFront(jobName, jobPriority);
                }
                else {
                        newJob->next = temp;
                        newJob->prev = temp->prev;
                        temp->prev->next = newJob;
                        temp->prev = newJob;
                }
        }
};
int main() {
    DEqueue queue;
    int choice;
    cout << "\nJob Scheduling Using Double Ended Queue" << endl;
    do {
    cout << "\nEnter Your Choice:"<<endl;
    cout<<"1. Add Job \n2. Remove Job from Front\n3. Remove Job from Rear \n4. Display Jobs \n5. Search Job \n6. Exit" << endl;
    cin >> choice;
        switch (choice) {
            case 1:
                    queue.addJob();
                    break;
            case 2:
                    queue.removeFront();
                    break;
            case 3:
                    queue.removeRear();
                    break;
            case 4:
                    queue.displayJobs();
                    break;
            case 5: {
                    string jobName;
                    cout << "\nEnter the name of the job you want to find: ";
                    cin >> jobName;
                    queue.findJob(jobName);
                    break;
                }
            default:
                    cout << "\nPlease enter a valid choice" << endl;
                    break;
            }
        } while (choice != 6);
        
    return 0;
}