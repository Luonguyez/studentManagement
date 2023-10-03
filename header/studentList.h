#ifndef studentList_h
#define studentList_h

#include<iostream>
#include<string>
#include<list>

using namespace std;

typedef enum{
    MALE = 1,
    FEMALE = 2,
}typeGender;

class student{
    private:
        int ID;
        string NAME;
        int AGE;
        typeGender GENDER;
        double scoreMATH;
        double scorePHYS;
        
    public:
        student(string NAME, int AGE, typeGender GENDER, double scoreMATH, double scorePHYS);

        int getID() {return ID;};
        
        string getNAME() {return NAME;};
        void setNAME(string NAME) {this->NAME = NAME;};

        int getAGE() {return AGE;};
        void setAGE(int AGE) {this->AGE = AGE;};

        typeGender getGENDER() {return GENDER;};
        void setGENDER(typeGender GENDER) {this-> GENDER = GENDER;};

        double getMATH() {return scoreMATH;};
        void setMATH(double scoreMATH) {this -> scoreMATH = scoreMATH;};

        double getPHYS() {return scorePHYS;};
        void setPHYS(double scorePHYS) {this -> scorePHYS = scorePHYS;};

        double getAverageScore() const {return (scoreMATH + scorePHYS)/2;}

        bool compareStudents(const student& a, const student& b) {
        return a.getAverageScore() < b.getAverageScore();}

};

void addStudent(list<student>& studentData);

void updateStudent(list<student>& studentData);

void deleteStudent(list<student>& studentData);

void findStudent(list<student>& studentData);

void sortAverageScore(list<student>& studentData);

void sortAlphabetName(list<student>& StudentData);

void listStudent(list<student> studentData);




#endif