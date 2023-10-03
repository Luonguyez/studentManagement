#include "studentList.h"
#include <algorithm>

student :: student(string NAME, int AGE, typeGender GENDER, double scoreMATH, double scorePHYS){
    
    static int id = 1000;
    student::ID = id;
    id++;

    this->NAME = NAME;
    this->AGE = AGE;
    this->GENDER = GENDER;
    this->scoreMATH = scoreMATH;
    this->scorePHYS = scorePHYS;
}


void addStudent(list<student>& studentData){
    while (1)
    {
        string NAME;
        while(1){
            cout<<"input name: "; cin>>NAME;
            if (NAME != "") break;
        }

        int AGE;
        while (1)
        {
            cout<<"input age: "; cin>>AGE;
            if (AGE > 18 && AGE < 50) break;
            else cout << "Error, invalid input!" << endl;
        }
        
        typeGender GENDER;
        cout<<"input gender\n 1: MALE\n 2: FEMALE\n"; 
        int key;
        while (1)
        {
            cout<<"Press: "; cin>>key; 
                switch (key)
            {
                case 1:
                    GENDER = MALE;
                     break;
                case 2:
                    GENDER = FEMALE;
                    break;
                default:
                    break;
            }
            if (key == 1 || key == 2) break;
        }
        
        double scoreMATH;
        while (1)
        {
            cout<<"input score Math: "; cin>>scoreMATH;
            if(scoreMATH >= 0 && scoreMATH <= 10) break;
            else cout << "Error, invalid input!" << endl;
        }
        
        double scorePHYS;
        while (1)
        {
            cout<<"input score Phys: "; cin>>scorePHYS;
            if(scorePHYS >= 0 && scorePHYS <= 10) break;
            else cout << "Error, invalid input!" << endl;
        }
        
        student newStudent(NAME, AGE, GENDER, scoreMATH, scorePHYS);
        studentData.push_back(newStudent);
        
        cout<<"Succesfully!\n-------------\n";
        cout<<"0: Exit add name function\n1: Continue ...\n";
        cout<<"Press: ";
        cin>>key;
         while (key != 1 && key != 0)
        {
            cout << "Error, invalid input!\nPress again: " << endl;
            cin >> key;
        }

        if (key == 1) continue;
        else if(key == 0) break;
    }
}

void updateStudent(list<student>& studentData){

    cout<<"-----------\nSelect ID \n";
    int ID;
    cin>>ID;
    for (list<student>::iterator iter = studentData.begin(); iter != studentData.end(); iter++)
    {   
        if(iter->getID() == ID )
        {
        cout<<"Select information to update\n";
        cout<<"1. Name\n2. Age\n3. Gender\n4. Math score\n5. Physics socre\n";
        int key;
        string name;
        cout<<"Press: "; cin>>key;
        switch (key)
        {
            case 1:
                
                cout << "old name: " << iter->getNAME() << endl;
                cout <<"update name: ";
                cin>>name;
                iter->setNAME(name);
                cout<<"Update successfully!\n";
                break;
            
            case 2:
                int age;
                cout << "old age: " << iter->getAGE() << endl;
                        
                while (1)
                {
                    cout << "update age: ";
                    cin >> age;
                    if (age >= 18 && age < 50)
                        {
                            iter->setAGE(age);
                            break;
                        }
                    else cout << "Error, invalid input!" << endl;
                }
                    cout << "Update sucessfully!" << endl;
                    break;
            
            case 3:
                typeGender gender;
                cout << "old gender: ";
                if (iter->getGENDER() == 1) cout << "Male" << endl;
                else cout << "Female" << endl;
                        
                while (1)
                    {
                    cout << "update gender (1-male; 2-female): ";
                    cin >> key;
                    switch (key)
                    {
                        case 1:
                            iter->setGENDER(MALE);
                            break;
                            
                        case 2:
                            iter->setGENDER(FEMALE);
                            break;

                        default:
                            break;
                    }
                    if (key == 1 || key == 2) break;
                    else cout << "Error, invalid input!" << endl;
                    }
                        cout << "Update sucessfully!" << endl;
                break;

            
            case 4:
                int scoreMath;
                cout << "old math score: " << iter->getMATH() << endl;
                while (1)
                {
                    cout << "update math score: ";
                    cin >> scoreMath;
                    if (scoreMath >= 0 && scoreMath <= 10)
                        {
                            iter->setMATH(scoreMath);
                            break;
                        }
                    else cout << "Error, invalid input!" << endl;
                }
                    cout << "Update sucessfully!" << endl;
                    break;
            case 5:
                int scorePhys;
                cout << "old physical score: " << iter->getMATH() << endl;
                while (1)
                {
                    cout << "update physical score: ";
                    cin >> scorePhys;
                    if (scorePhys >= 0 && scorePhys <= 10)
                        {
                            iter->setPHYS(scorePhys);
                            break;
                        }
                    else cout << "Error, invalid input!" << endl;
                }
                    cout << "Update sucessfully!" << endl;
                    break;
            default:
                cout << "Error, invalid input!" << endl;
                break;
            
            }
        }
    }
    cout<<"ID not found!\n";

}

void deleteStudent(list<student>& studentData){
    int ID;
    cout<<"\n------------\ndelete student from ID\n";
    cout<<"input ID\n"; cin>>ID;
    for(list<student>::iterator iter = studentData.begin(); iter != studentData.end(); iter++){
        if(iter->getID() == ID){
        iter = studentData.erase(iter);
        }
    }
    cout<<"ID not found!";
}

void findStudent(list<student>& studentData){
    cout << "---------------\nfind student from name\n";
    cout << "input name to find: ";
    string name;
    cin >> name;

    for (list<student>::iterator iter = studentData.begin(); iter != studentData.end(); iter++)
    {
        if (iter->getNAME() == name)
        {
            cout << "\nInformation of " << "<" << name << " >" << ":\n" ;
            cout << "gender: ";
            if(iter->getGENDER() == 1){
                cout << "Male" << endl;
            }
            else cout << "Female" << endl;
            cout << "age: " << iter->getAGE() << endl;
            cout << "Math score: " << iter->getMATH() << endl;
            cout << "Physics score: " << iter->getPHYS() << endl;
            return;
        }
    }

    cout << "Name not found!" << endl;
}

void sortAverageScore(list<student>& studentData)
{
        cout<<"Sort average score!\n";
    for (list<student>::iterator iter = studentData.begin(); iter != studentData.end(); iter++)
    {
        list<student>::iterator temp = iter;
        for (list<student>::iterator iterCompare = iter; iterCompare != studentData.end(); iterCompare++)
        {
            if (iterCompare->getAverageScore() < iter->getAverageScore())
            {
                temp = iterCompare;
            }
        }
        if (temp != iter) iter_swap(iter, temp);
        
    }
}

void sortAlphabetName(list<student>& studentData){
    cout<<"Sort name!\n";
    for (list<student>::iterator iter = studentData.begin(); iter != studentData.end(); iter++)
    {
        list<student>::iterator temp = iter;
        for (list<student>::iterator iterCompare = iter; iterCompare != studentData.end(); iterCompare++)
        {
            if (iterCompare->getNAME() < iter->getNAME())
            {
                temp = iterCompare;
            }
        }
        if (temp != iter) iter_swap(iter, temp);
        
    }
}

void listStudent(list<student> studentData){
    int num = 1;
    cout<<"\n---------------------\nList of students!\n";
    
    for (list<student>::iterator iter = studentData.begin(); iter != studentData.end(); iter++)
    {
        cout << num;
        cout << " | ID: " << iter->getID();
        cout << " | Name: " << iter->getNAME();
        cout << " | Gender: "<< iter->getGENDER();
        cout << " | Math score: " << iter->getMATH();
        cout << " | Physics score: " << iter->getPHYS()<<endl;
        num++;
    }

}