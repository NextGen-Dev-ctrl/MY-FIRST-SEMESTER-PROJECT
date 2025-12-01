#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void clearScreen() 
{
    cout << "\033[2J\033[1;1H";
}
struct Student                          //Use for all data of the student
{
    int id;
    string name;
    string className;
    int age;
};
struct Teacher                          //Use for all data of the teacher
{
    int id;
    string name;
    string subject;
};
struct User                             //use for the authentication of the admin
{
    string username;
    string password;
};
vector<Student> students;                   //vector can store all data that we can read form the file
vector<Teacher> teachers;
vector<User> users;
void loadStudent()                       //read data from student file and store it in vector
{
    ifstream fin("student.txt");
    if(!fin)
    {
        cout<<"--------Student Data is not found !--------"<<endl;
        return;
    }
    students.clear();                      //clean all data in the student vector
    int age,id;
    string name, className;
    while (fin >> id >> name >> className >> age)
    {
    Student s;
    s.id = id;
    s.name = name;
    s.className = className;
    s.age = age;
    students.push_back(s);                  //Adding the data last in the vector
    }

    fin.close();
    cout << "Loaded " << students.size() << " students.\n";


}
void loadTeacher()                      //read all data from the teacher file
{
    ifstream fin("teacher.txt");
    if(!fin)
    {
        cout<<"----------Teacher Data is not found !----------"<<endl;
        return;
    }
    teachers.clear();                   //clean all data in the teacher vector
    int id;
    string name,subject;
    while (fin >> id >> name >> subject) 
    {
    Teacher t;
    t.id = id;
    t.name = name;
    t.subject = subject;
    teachers.push_back(t);                  //Adding the data last in the vector
    }

    fin.close();
    cout << "Loaded " << teachers.size() << " teachers.\n";

}
void loadUser()                        //read the file in which the login detail are stored
{
    ifstream fin("user.txt");
    if(!fin)
    {
        cout<<"-----------Login data is not found !------------"<<endl;
        return;
    }
    users.clear();                          //clean all data in the user vector
    string username;
    string password;
    
    while (fin >> username >> password) 
    {
    User u;
    u.username = username;
    u.password = password;
    users.push_back(u);                     //Adding the data last in the vector
    }

    fin.close();
    cout << "Loaded " << users.size() << " users.\n";
}
void saveStudents() {
    ofstream fout("students.txt");
    for (int i = 0; i < students.size(); i++) {                             //save the student when any opereation can do with this
        fout << students[i].id << " "<< students[i].name << " "<< students[i].className << " "<< students[i].age << "\n";
    }
    fout.close();
    cout << "------------Students saved successfully.----------\n";
}
void saveTeachers() {
    ofstream fout("teachers.txt");
    for (int i = 0; i < teachers.size(); i++) {                 //save the teacher when any data can be change
        fout << teachers[i].id << " "<< teachers[i].name << " "<< teachers[i].subject << "\n";
    }
    fout.close();
    cout << "----------Teachers saved successfully.---------\n";
}
void saveUsers() {
    ofstream fout("users.txt");
    for (int i = 0; i < users.size(); i++) {
        fout << users[i].username << " "<< users[i].password << "\n"; //save the user information when updated
    }
    fout.close();
    cout << "----------Users saved successfully.----------\n";
}
bool login()                            //login to access the system
{
    int block=0;
    lable:
    int again;                          //The user can give only 3 attempt after that the code is ended
    string user,pass;
    cout<<"----------Login----------\n";
    cout<<"Enter the username :";
    cin>>user;
    cout<<"Enter the password :";
    cin>>pass;
    for(int i=0;i<users.size();i++)
    {
        if(users[i].username == user && users[i].password == pass)
        {
            clearScreen();
            cout<<"-------Login Successfully!-------\n--------- Welcome "<<user<<"---------"<<endl;
            return true;
        }
    }
    cout<<"----------Invalid Username or password ----------\n";
    if(block == 3)                              //chech the attempts
    return false;
    cout<<"If you want to try again enter '1' and for exit enter '0' :";
    cin>>again;
    block++;
    if(again == 1)
    goto lable;                                 //use for retry
    else
    return false;
    
}
void studentManagement()
{
    while(true)
    {
    int check;
    cout<<"---------Student Management--------\n";
    cout<<"1.Add Student \n";
    cout<<"2.View Students \n";
    cout<<"3.Search Student \n";
    cout<<"4.Update Student \n";
    cout<<"5.Delete Student \n";
    cout<<"6.Back \n";
    cin>>check;
    switch(check)
    {
        case 1:
        {
        clearScreen();
        Student su;
        cout<<"--------Adding Student-------\n";
        cout<<"Enter the student ID :";
        cin>>su.id;
        cout<<"Enter the student Name :";
        cin>>su.name;
        cout<<"Enter the student Class :";
        cin>>su.className;
        cout<<"Enter the student Age :";
        cin>>su.age;
        students.push_back(su);
        saveStudents();
        break;
        }
        case 2:
        clearScreen();
        cout<<"---------All Students----------\n";
        for(int i=0;i<students.size();i++)
        {
            cout<<"Name :"<<students[i].name<<endl;
            cout<<"ID :"<<students[i].id<<endl;
            cout<<"Class :"<<students[i].className<<endl;
            cout<<"Age :"<<students[i].age<<endl;
            cout<<"------------------------------\n";
        }
        break;
        case 3:
        {
        clearScreen();
        int search;
        bool isfind=true;
        cout<<"Enter the ID of the Student :";
        cin>>search;
        for(int i=0;i<students.size();i++)
        {
            if(students[i].id == search)
            {
                cout<<"---------Student Found--------\n";
                cout<<"Name :"<<students[i].name<<endl;
                cout<<"ID :"<<students[i].id<<endl;
                cout<<"Class :"<<students[i].className<<endl;
                cout<<"Age :"<<students[i].age<<endl;
                isfind=false;
            }
        }
        if(isfind)
        {
            cout<<"----------Student Not Found!---------\n";
        }
        break;
        }
        case 4:
        {
        clearScreen();
        int find;
        cout<<"Enter the ID of the Student which you want to change :";
        cin>>find;
        for(int i=0;i<students.size();i++)
        {
            if(students[i].id == find)
            {
                cout<<"---------Student Found--------\n";
                cout<<"Name :";
                cin>>students[i].name;
                cout<<"Class :";
                cin>>students[i].className;
                cout<<"Age :";
                cin>>students[i].age;
            }
        }
        saveStudents();
        break;
        }
        case 5:
        {
        clearScreen();
        int studentId;
        cout << "Enter the ID of the student to delete: ";
        cin >> studentId;
        int index = -1;                 //-1 is not any index so we can use it for checking 
        for (int i = 0; i < students.size(); i++) 
        {
        if (students[i].id == studentId) 
            {
                index = i;              //if the student found we get its index
                break;
            }
        }

        if (index != -1) 
        {
            students.erase(students.begin() + index);           //delete the data in this index
            saveStudents();
        } 
        else 
        {
        cout << "Student with ID " << studentId << " not found.\n";
        }
        break;
        }
        case 6:
        return;
        default:
        cout<<"---------INVALID INPUT---------\n";
    }
    }
}

void teacherManagement()
{
    while(true)
{
    int check;
    cout<<"-----------Teacher Management---------\n";
    cout<<"1.Add Teacher \n";
    cout<<"2.Update Teacher \n";
    cout<<"3.Delete Teacher \n";
    cout<<"4.Veiw Teachers \n";
    cout<<"5.Find Teacher \n";
    cout<<"6.Back \n";
    cin>>check;
    switch(check)
    {
        case 1:
        {
        clearScreen();
        Teacher tu;
        cout<<"----------Adding Teacher---------\n";
        cout<<"Enter the Teacher Name :";
        cin>>tu.name;
        cout<<"Enter the Teacher ID :";
        cin>>tu.id;
        cout<<"Enter the Teacher Subject :";
        cin>>tu.subject;
        teachers.push_back(tu);
        saveTeachers();
        break;
        }
        case 2:
        {
        clearScreen();
        int find;
        cout<<"Enter the ID of the Teacher which you want to change :";
        cin>>find;
        for(int i=0;i<teachers.size();i++)
        {
            if(teachers[i].id == find)
            {
                cout<<"---------Teacher Found--------\n";
                cout<<"Name :";
                cin>>teachers[i].name;
                cout<<"Subject :";
                cin>>teachers[i].subject;
            }
        }
        saveTeachers();
        break;
        }
        case 3:
        {
        clearScreen();
        int teacherId;
        cout << "Enter the ID of the teacher to delete: ";
        cin >> teacherId;
        int index = -1;                 //-1 is not any index so we can use it for checking 
        for (int i = 0; i < teachers.size(); i++) 
        {
        if (teachers[i].id == teacherId) 
            {
                index = i;              //if the teacher found we get its index
                break;
            }
        }

        if (index != -1) 
        {
            teachers.erase(teachers.begin() + index);           //delete the data in this index
            saveTeachers();
        } 
        else 
        {
        cout << "Teacher with ID " << teacherId << " not found.\n";
        }
        break;
        }
        case 4:
        clearScreen();
        cout<<"---------All Teachers----------\n";
        for(int i=0;i<teachers.size();i++)
        {
            cout<<"Name :"<<teachers[i].name<<endl;
            cout<<"ID :"<<teachers[i].id<<endl;
            cout<<"Subject :"<<teachers[i].subject<<endl;
            cout<<"------------------------------\n";
        }
        break;
        case 5:
        {
        clearScreen();
        int search;
        bool isfind=true;
        cout<<"Enter the ID of the Teacher :";
        cin>>search;
        for(int i=0;i<teachers.size();i++)
        {
            if(teachers[i].id == search)
            {
                cout<<"---------Teacher Found--------\n";
                cout<<"Name :"<<teachers[i].name<<endl;
                cout<<"ID :"<<teachers[i].id<<endl;
                cout<<"Subject :"<<teachers[i].subject<<endl;
                isfind=false;
            }
        }
        if(isfind)
        {
            cout<<"----------Teacher Not Found!---------\n";
        }
        break;
        }
        case 6:
        return;
        default:
        cout<<"-----------INVALID INPUT!-----------\n";
    }
}

}
bool showMenu()
{
    while(true)
{
    int check;
    cout<<"1.Student Management \n";
    cout<<"2.Teacher Managemnt \n";
    cout<<"3.Save & Exit \n";
    cin>>check;
    switch(check)
    {
        case 1:
        studentManagement();
        break;
        case 2:
        teacherManagement();
        break;
        case 3:
        return true;
    }
}
}
int main()
{
    loadStudent();
    loadTeacher();
    loadUser();
    cout<<"-------------loading completed-----------\n";
    if(!login())                    //if the user are failed to login the program can be ended
    {
        return 0;
    }
    if(showMenu())
    {
        cout<<"-----------Program Ended!----------\n";
        return 0;
    }
}