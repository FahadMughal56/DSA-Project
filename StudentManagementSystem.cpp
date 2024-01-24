#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

///////////////////////////////////////////////////////
///////////////////Linked List Class//////////////////
/////////////////////////////////////////////////////

class linked_list
{
private:
    struct listNode
    {
        int id, batch_Num;
        string name;
        listNode *next_add;
    };
    listNode *head = NULL;

public:
    void linkedListMenu();
    void load_data();
    void insert_record();
    void search_record();
    void show_record();
    void edit_record();
    void del_record();
    void mainMenu();
} obj;

///////////////////////////////////////////////////////
///////////////////Queue Class////////////////////////
/////////////////////////////////////////////////////

class queue
{
private:
    struct queueNode
    {
        string Stu_id;
        string Stu_name;
        queueNode *next;
    };
    queueNode *head = NULL;
    queueNode *tail = NULL;
    fstream Stu_nameFile;

public:
    void queueMenu();
    void push();
    void display();
    void pop();
} q_obj;

///////////////////////////////////////////////////////
///////////////////Stack Class////////////////////////
/////////////////////////////////////////////////////

class stack
{
private:
    struct stackNode
    {
        string stuID;
        string stuName;
        stackNode *pre;
    };
    stackNode *head = NULL;

public:
    void stackMenu();
    void push();
    void display();
    void pop();
    void top();
    void size();
    void clear();
} stack_obj;

///////////////////////////////////////////////////////
///////////////////Main function//////////////////////
/////////////////////////////////////////////////////

int main()
{
    obj.mainMenu();
    return 0;
}

///////////////////////////////////////////////////////
//////////////Linked List Class def.//////////////////
/////////////////////////////////////////////////////

void linked_list::linkedListMenu()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t======================================";
    cout << "\n\n\t\t\tSingly Linked List With File Handling";
    cout << "\n\n\t\t\t======================================";
    cout << "\n\n 1. Insert New Student Record";
    cout << "\n 2. Search Student Record";
    cout << "\n 3. Edit Student Record";
    cout << "\n 4.Delete Student Record";
    cout << "\n 5.Show All Records";
    cout << "\n 6.Go to Main menu";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert_record();
        break;
    case 2:
        head = NULL;
        load_data();
        search_record();
        break;
    case 3:
        head = NULL;
        load_data();
        edit_record();
        break;
    case 4:
        head = NULL;
        load_data();
        del_record();
        break;
    case 5:
        head = NULL;
        load_data();
        show_record();
        break;
    case 6:
        obj.mainMenu();
    default:
        cout << "\n\n Invalid choice ....Please Try Again...";
    }
    getch();
    goto p;
}
void linked_list::load_data()
{
    fstream file;
    int stu_id, stu_batch_Num;
    string stu_name;

    file.open("list.txt", ios::in);
    if (file)
    {
        file >> stu_id >> stu_name >> stu_batch_Num;
        while (!file.eof())
        {
            listNode *new_listNode = new listNode;
            new_listNode->id = stu_id;
            new_listNode->name = stu_name;
            new_listNode->batch_Num = stu_batch_Num;
            new_listNode->next_add = NULL;
            if (head == NULL)
            {
                head = new_listNode;
            }
            else
            {
                listNode *ptr = head;
                while (ptr->next_add != NULL)
                {
                    ptr = ptr->next_add;
                }
                ptr->next_add = new_listNode;
            }
            file >> stu_id >> stu_name >> stu_batch_Num;
        }
        file.close();
    }
}
void linked_list::insert_record()
{
    system("cls");
    fstream file;
    int stu_id, stu_batch_Num;
    string stu_name;
    cout << "\n\n\t\t\t=================================";
    cout << "\n\n\t\t\t  Creat new listNode & Insert Record";
    cout << "\n\n\t\t\t=================================";
    cout << "\n\n Student ID : ";
    cin >> stu_id;
    cout << "\n\n Student Name : ";
    cin >> stu_name;
    cout << "\n\n Student batch_Num : ";
    cin >> stu_batch_Num;
    listNode *new_listNode = new listNode;
    new_listNode->id = stu_id;
    new_listNode->name = stu_name;
    new_listNode->batch_Num = stu_batch_Num;
    new_listNode->next_add = NULL;
    if (head == NULL)
    {
        head = new_listNode;
    }
    else
    {
        listNode *ptr = head;
        while (ptr->next_add != NULL)
        {
            ptr = ptr->next_add;
        }
        ptr->next_add = new_listNode;
    }
    file.open("list.txt", ios::app | ios::out);
    file << stu_id << " " << stu_name << " " << stu_batch_Num << endl;
    file.close();
    cout << "\n\n\t\t\tNew listNode Created Successfully....";
}
void linked_list::search_record()
{
    system("cls");
    int t_id, found = 0;
    cout << "\n\n\t\t\t===============================";
    cout << "\n\n\t\t\tSearch specific Record ";
    cout << "\n\n\t\t\t===============================";
    if (head == NULL)
    {
        cout << "\n\nLinked list is stuty..";
    }
    else
    {
        cout << "\n\nStudent ID : ";
        cin >> t_id;
        listNode *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->id == t_id)
            {
                system("cls");
                cout << "\n\n\t\t Student ID :" << ptr->id;
                cout << "\n\t\t Student Name :" << ptr->name;
                cout << "\n\t\t Student batch_Num :" << ptr->batch_Num;
                found++;
            }
            ptr = ptr->next_add;
        }
        if (found == 0)
        {
            cout << "\n\n Student ID Can't Found...";
        }
    }
}
void linked_list::edit_record()
{
    system("cls");
    fstream file, file1;
    int t_id, found = 0, stu_id, stu_batch_Num, id, batch_Num;
    string stu_name, name;
    cout << "\n\n\t\t\t===============================";
    cout << "\n\n\t\t\t Edit Specific Record ";
    cout << "\n\n\t\t\t===============================";
    if (head == NULL)
    {
        cout << "\n\n Linked List is stuty";
    }
    else
    {
        cout << "\n\n Student ID : ";
        cin >> t_id;
        file.open("list.txt", ios::in);
        file1.open("list1.txt", ios::app | ios::out);
        file >> stu_id >> stu_name >> stu_batch_Num;
        while (!file.eof())
        {
            if (t_id == stu_id)
            {
                cout << "\n\n New Student id :";
                cin >> id;
                cout << "\n\n\t\t New Student Name : ";
                cin >> name;
                cout << "\n\n New Student batch_Num : ";
                cin >> batch_Num;
                file1 << id << " " << name << " " << batch_Num << endl;
                cout << "Edit record Successfully ";
                found++;
            }
            else
            {
                file1 << stu_id << " " << stu_name << " " << stu_batch_Num << endl;
            }
            file >> stu_id >> stu_name >> stu_batch_Num;
        }
        file.close();
        file1.close();
        remove("list.txt");
        rename("list1.txt", "list.txt");
        if (found == 0)
        {
            cout << "stuoyee id can't found";
        }
    }
}
void linked_list::del_record()
{

    system("cls");
    fstream file, file1;
    int t_id, found = 0, stu_id, stu_batch_Num;
    string stu_name;
    cout << "\n\n\t\t\t=========================";
    cout << "\n\n\t\t\t Delete Specific Record ";
    cout << "\n\n\t\t\t=========================";
    if (head == NULL)
    {
        cout << "\n\n\n Linked List is stuty";
    }
    else
    {
        cout << "\n\n Student ID : ";
        cin >> t_id;
        file.open("list.txt", ios::in);
        file1.open("list1.txt", ios::app | ios::out);
        file >> stu_id >> stu_name >> stu_batch_Num;
        while (!file.eof())
        {
            if (t_id == stu_id)
            {

                cout << "Delete record Successfully ";
                found++;
            }
            else
            {
                file1 << stu_id << " " << stu_name << " " << stu_batch_Num << endl;
            }
            file >> stu_id >> stu_name >> stu_batch_Num;
        }
        file.close();
        file1.close();
        remove("list.txt");
        rename("list1.txt", "list.txt");
        if (found == 0)
        {
            cout << "stuoyee id can't found";
        }
    }
}
void linked_list::show_record()
{
    system("cls");
    cout << "\n\n\t\t\t================================";
    cout << "\n\n\t\t\t    Show All Record";
    cout << "\n\n\t\t\t================================";
    if (head == NULL)
    {
        cout << "\n\n\nLinked List is stuty";
    }
    else
    {
        cout << "\n\nStudent ID\tStudent Name\tStudent batch_Num";
        listNode *ptr = head;
        while (ptr != NULL)
        {

            cout << "\n"
                 << ptr->id << "\t\t" << ptr->name << "\t\t" << ptr->batch_Num;
            ptr = ptr->next_add;
        }
    }
}

///////////////////////////////////////////////////////
/////////////////Queue Class def./////////////////////
/////////////////////////////////////////////////////

void queue ::queueMenu()
{
p1:
    
    int choice;
    system("cls");
    cout << "enter 1 to push record:" << endl;
    cout << "enter 2 to dispaly record:" << endl;
    cout << "enetr 3 to pop record:" << endl;
    cout << "enetr 4 to go to Main menu:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        q_obj.push();
        break;
    case 2:
        q_obj.display();
        break;
    case 3:
        q_obj.pop();
        break;
    case 4:
        obj.mainMenu();
        break;
    default:
        cout << "Invalid Selection...!";
    }
    getch();
    goto p1;
}
void queue::push()
{
    string name, id;
    cout << "Enter Student ID :";
    cin >> id;
    cout << "Enter Student name :";
    cin >> name;
    queueNode *new_queueNode = new queueNode;
    new_queueNode->Stu_id = id;
    new_queueNode->Stu_name = name;
    new_queueNode->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = new_queueNode;
        tail = new_queueNode;
    }
    else
    {
        tail->next = new_queueNode;
        tail = new_queueNode;
    }
    cout << endl
         << id << " :: inserted successfully " << endl;
    cout << name << " :: inserted successfully ";
}
void queue::display()
{
    if (head == NULL && tail == NULL)
    {
        cout << "Queue is empty";
    }
    else
    {
        queueNode *ptr = head;
        while (ptr != NULL)
        {
            cout << "\nStudent ID :" << ptr->Stu_id << endl;
            cout << "Student Name :" << ptr->Stu_name << endl;
            ptr = ptr->next;
        }
    }
}
void queue::pop()
{
    if (head == NULL && tail == NULL)
    {
        cout << "queue is empty";
    }
    else
    {
        queueNode *ptr = head;
        head = head->next;
        cout << "\nName :: " << ptr->Stu_name << " deleted successfully " << endl;
        delete ptr;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
}

///////////////////////////////////////////////////////
/////////////////Stack Class def./////////////////////
/////////////////////////////////////////////////////

void stack ::stackMenu()
{
p2:
    system("cls");
    int choice;
    cout << "press 1 to push record " << endl;
    cout << "press 2 to dispaly record " << endl;
    cout << "press 3 to pop record " << endl;
    cout << "press 4 to see top/peek value:  " << endl;
    cout << "press 5 to see the no of elements in the stack:" << endl;
    cout << "press 6 to clear  the stack:" << endl;
    cout << "press 0 to go to Main menu:" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        stack_obj.push();
        break;
    case 2:
        stack_obj.display();
        break;
    case 3:
        stack_obj.pop();
        break;
    case 4:
        stack_obj.top();
        break;
    case 5:
        stack_obj.size();
        break;
    case 6:
        stack_obj.clear();
        break;
    case 0:
        obj.mainMenu();
        break;
    default:
        cout << "Invalid Selection...!";
    }
    getch();
    goto p2;
}
void stack::push()
{
    string _name, _id;
    cout << "Enter Student ID :";
    cin >> _id;
    cout << "Enter Student name :";
    cin >> _name;
    stackNode *new_stackNode = new stackNode;
    new_stackNode->stuID = _id;
    new_stackNode->stuName = _name;
    if (head == NULL)
    {
        head = new_stackNode;
        new_stackNode->pre = NULL;
    }
    else
    {
        new_stackNode->pre = head;
        head = new_stackNode;
    }
}
void stack::display()
{
    if (head == NULL)
    {
        cout << "stack is empty";
    }
    else
    {
        stackNode *ptr = head;
        while (ptr != NULL)
        {
            cout << "\nID : " << ptr->stuID << endl;
            cout << "Name : " << ptr->stuName << endl;
            ptr = ptr->pre;
        }
    }
}
void stack::pop()
{
    if (head == NULL)
    {
        cout << "stack is empty";
    }
    else
    {
        stackNode *ptr = head;
        head = head->pre;
        cout << "\nID : " << ptr->stuID << " deleted successfully" << endl;
        cout << "Name : " << ptr->stuName << " deleted successfully" << endl;
        delete ptr;
    }
}
void stack::top()
{
    cout << "ID : " << head->stuID << endl;
    cout << "Name : " << head->stuName << endl;
}
void stack::size()
{
    if (head == NULL)
    {
        cout << "stack is empty";
    }
    else
    {
        int count = 0;
        stackNode *ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->pre;
        }
        cout << "Total record in stack : " << count << " Records...";
    }
}
void stack::clear()
{
    if (head == NULL)
    {
        cout << "stack is already empty";
    }
    else
    {
        while (head != NULL)
        {
            stackNode *ptr = head;
            head = head->pre;
            delete ptr;
            cout << "stack has been cleared successfully...!";
        }
    }
}

void linked_list :: mainMenu(){
    system("cls");
    char selection;
    cout << "\n\n\t\t\t======================================";
    cout << "\n\n\t\t\t-----Student Management System-----";
    cout << "\n\n\t\t\t======================================";
    cout << "\n\n 1. By Linked List Data Structure";
    cout << "\n 2. By Queue Data Structure";
    cout << "\n 3. By Stack Data Structure";
    cout << "\n 0.Exit program";
    cout << "\n\n Enter Your Choice : ";
    cin >> selection;
    switch (selection)
    {
    case '1':
        obj.load_data();
        obj.linkedListMenu();
        break;
    case '2':
        q_obj.queueMenu();
        break;
    case '3':
        stack_obj.stackMenu();
        break;
    case '0':
        exit(0);
        break;
    default:
        cout << "\nInvalid Selection...!";
    }
}