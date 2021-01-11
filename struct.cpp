#include <stdio.h> // buat input output
#include <stdlib.h> // biar bisa strcpy
#include <string.h> //dynamic memory allocation

struct Course{
    char ID[10]; 
    int score; 
};

struct Student {
    char name[255];
    double GPA;
    Course c; 
};

int plus(int a, int b){
    return a+b;
}


//Fungsi ini akan mereturn pointer yang mengarah ke student
//const char *name sama dengan char name[], tapi kalau pake [] ntar di vscode dapet warning
Student *createstudent(const char *name, double gpa, const char *ID, int score){
    //alokasi memori
    Student *newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name); //strcpy((*newStudent).name, name);

    

    newStudent->GPA = gpa;
    strcpy(newStudent->c.ID, ID);
    newStudent->c.score = score;


    return newStudent;
}
//tipe data yang di return :Student*
// nama function : createstudent
//parameter: name, gpa, course (id dan score)

void removeStudent(Student *s){
    free(s);
    s = NULL;
}

void printStudent(Student *s){
    printf("Name: %s\n", s->name);
    printf("GPA: %lf\n", s->GPA);
    printf("Course ID: %s\n", s->c.ID);
    printf("Score: %d\n", s->c.score);
}

int main(){

    
    Student *s1 = createstudent("Budi", 3.90, "COMP6048", 100);
    Student *s2 = createstudent("Abdul", 4.00, "COMP6049", 85);
   
    printf("Before Remove : \n");
    printStudent(s1);
    removeStudent(s1);
    printf("After Remove : \n");
    Student *s3 = createstudent("Bryan", 3.90, "COMP6049", 95);
    printStudent(s1);
    return 0;
}