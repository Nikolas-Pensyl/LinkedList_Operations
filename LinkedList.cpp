//Welcome to my Linked List Implementation using structs
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int value;
    Node *next;
};

//Create pointer to header node
Node *head = new Node();

//Since this application is run through the console we have to ensure that the input is actually an integer.
bool isNumber(string input) {
    char digit;
    for(int i = 0; i<input.length(); i++) {
        digit = input[i];
        if(!isdigit(digit)) {
            return false;
        }
    }

    return true;
}

//Checks to makesure that it is both a signle character and an integer
bool isValidEntry(string entry) {
    return !(entry.length()!=1 && !isNumber(entry));

}

//Displays the List in its current state
void displayList(Node *head) {
    Node node = *head;
    cout<<"\nThe elements are: \n";
    for(node = *head; node.next!=nullptr; node=*node.next) {
        cout<<node.value<<"--->";
    }
    cout<<node.value<<"--->NULL\n\n\n";
}

Reverses the linked list
void reverseList(Node* prev, Node* node)
{
    if(node->next==nullptr)
    {
        node->next = prev;
        head = node;
    } else
    {
        reverseList(node, node->next);
        node->next = prev;
    }
}

//Adds a node to the end of the list
void AddNode(Node *node, int val) {
    if(node->next != nullptr) {
        AddNode(node->next, val);
    } else {
        node->next = new Node();
        node->next->value = val;
    }
}

//Adds a node in the list based on user input.
Node* insertList(Node* head) {
    Node *node;
    Node *node_;
    string input;
    bool failedInput = true;
    int in, val;
    while(failedInput) {
        cout<<"Enter the value you want to input: ";
        cin>>input;
        if(isNumber(input)) {
            val = stoi(input);
            failedInput = false;
        } else {
            cout<<"Invalid input try agian.";
        }
    }
    failedInput = true;
    while(failedInput){
        cout<<"Where do you want to insert the element from?\n";
        cout<<"1. At the begining\n2. At the end\n3. At a specific location\n";
        cout<<"Enter your choice: ";
        cin>>input;
        if(isValidEntry(input)) {
            in = stoi(input);
            if(in>0 && in<4) {
                failedInput = false;
            } else {
                cout<<"Invalid option try agian.\n";

            }
        } else {
            cout<<"Invalid option try agian.\n";

        }
    }
    if(in==1) {
        node = new Node();
        node->value = val;
        node->next = head;
        head = node;
    } else if(in==2) {
        node = head;
        if(head!=nullptr) {
            while(node->next!=nullptr) {
                node=node->next;
            }
            node->next = new Node();
            node = node->next;
            node->value = val;
            node->next = nullptr;
        } else {
            node = new Node();
            node->value = val;
            node->next = nullptr;
            head = node;
        }
    } else if(in==3) {
        int count = 0;
        if(head!=nullptr) {
            for(node = head; node->next!=nullptr; node=node->next, count++) {

            }
            count++;
        }
        failedInput = true;
        while(failedInput){
            cout<<"Enter the position at which to insert the node: ";
            cin>>input;
            if(isNumber(input)) {
                in = stoi(input);
                if(in>0 && in<=count+1) {
                    failedInput = false;
                } else {
                    cout<<"Invalid position does not exist, try a different position.\n";

                }
            } else {
                cout<<"Invalid input try agian.\n";

            }
        }
        if(head==nullptr && in==1) {
            node = new Node();
            node->value = val;
            node->next = nullptr;
            head = node;
            return head;
        }
        if(in==1) {
            node = new Node();
            node->value = val;
            node->next = head;
            head = node;
            return head;
        }
        node = head;
        for(int index=1; node!=nullptr; index++, node=node->next) {
            if(index+1==in) {
                node_ = new Node();
                node_->value = val;
                node_->next = node->next;
                node->next = node_;
                break;
            }
        }
    }

    return head;
}

//Deletes a node in the list based on user input
Node* deleteList(Node *head) {
    Node *node = head;
    Node *node_;
    string input;
    bool failedInput = true;
    int in;
    while(failedInput){
        cout<<"Where do you want to delete the element from?\n";
        cout<<"1. At the begining\n2. At the end\n3. At a specific location\n";
        cout<<"Enter your choice: ";
        cin>>input;
        if(isValidEntry(input)) {
            in = stoi(input);
            if(in>0 && in<4) {
                failedInput = false;
            } else {
                cout<<"Invalid option try agian.\n";

            }
        } else {
            cout<<"Invalid option try agian.\n";

        }
    }
    if(in==1) {
        head = head->next;
    } else if(in==2) {
        if(head->next!=nullptr) {
            while(node->next->next!=nullptr) {
                node=node->next;
            }
            node->next = nullptr;
        } else {
            head = nullptr;
        }
    } else if(in==3) {
        int count = 0;
        for(node = head; node->next!=nullptr; node=node->next, count++) {

        }
        count++;
        cout<<count;
        failedInput = true;
        while(failedInput){
            cout<<"Enter the position at which to delete the node: ";
            cin>>input;
            if(isNumber(input)) {
                in = stoi(input);
                if(in>0 && in<=count) {
                    failedInput = false;
                } else {
                    cout<<"Invalid position does not exist, try a different position.\n";

                }
            } else {
                cout<<"Invalid input try agian.\n";

            }
        }
        cout<<"test"<<in;
        if(count==1 && count==in) {
            head = nullptr;
            return head;
        }
        if(in==1) {
            head = head->next;
            return head;
        }
        node = head;
        for(int index=1; index<in; index++) {
            node_= node;
            node = node->next;
        }
        node_->next = node->next;
    }
    return head;
}


int main(int argc, char *argv[])
{
    
    string input;
    int in;
    bool exit = false;
    
    //Intializes list with a few values to start
    head->value = 1;
    AddNode(head, 2);
    AddNode(head, 3);
    
    //Tells user which operations are available then executes operation chosen by user
    while(!exit) {
        cout<<"********* Menu *********\n";
        cout<<"1. Insert\n2. Display\n3. Delete\n4. Reverse List\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>input;
        if(isValidEntry(input)) {
            in = stoi(input);
            if(in==1) {
                head = insertList(head);
                cout<<"**One node Inserted!!**"<<endl;
            } else if(in==2) {
                if(head==nullptr) {
                    cout<<"There are no values to be displayed, insert some first.\n";
                } else {
                    displayList(head);

                }
            } else if(in==3) {
                if(head==nullptr) {
                    cout<<"There are no values to be deleted, insert some first.\n";
                } else {
                    head = deleteList(head);
                    cout<<"**One node Deleted!!**"<<endl;
                }

            } else if(in==4) {
                reverseList(nullptr, head);
            } else if(in==5) {
                 exit = true;
            } else {
                cout<<"Invalid entry, try agian!!"<<endl;
            }
        }
    }
    cout<<"Thanks for playing. The program has exited.";


    return 0;
}
