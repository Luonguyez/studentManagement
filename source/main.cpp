#include <iostream>
#include "studentList.h"


int main(){


    list<student> studentData;
    int key = 0;
    while(1){
        cout << "---------------" << endl;
        cout << "1: Add student" << endl;
        cout << "2: Update student from ID" << endl;
        cout << "3: Delete student from ID"<<endl;
        cout << "4: Find student's information from name"<<endl;
        cout << "5: Sort student from average score"<<endl;
        cout << "6: Sort students in alphabetical order"<<endl;
        cout << "7: Show list of students"<<endl;
        
        cout << "Press: "; cin>>key;
        switch (key)
        {
        case 1:
            addStudent(studentData);
            break;
        case 2:
            updateStudent(studentData);
            break;
        case 3:
            deleteStudent(studentData);
            listStudent(studentData);
            break;
        case 4:
            findStudent(studentData);
            break;
        case 5:
            sortAverageScore(studentData);
            listStudent(studentData);
            break;
        case 6:
            sortAlphabetName(studentData);
            listStudent(studentData);
            break;
        case 7:
            listStudent(studentData);
            break;
        default:
            cout<<"invalid\n";
            break;
        }

        cout << "\n---------------\n" << endl;
        cout << "1: Return to menu!\n0: Exit" << endl;
        cout << "Press: ";
        cin >> key;
        while (1)
        {
            if (key == 0 || key == 1) break;
            else
            {
                cout << "Error, invalid input!" << endl;
                cout << "Press again: \n";
                cin >> key;
            }
        }
        if (key == 0) break;


    }
}