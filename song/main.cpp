#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;

struct Student {
    char name[20];
    int classNum;
    int gradeNum;
    char major[20];
    char gender[2];
    double gpa;
    Student * next;
};

Student* list;
int studentNum;

void printMain(){
    cout << "\n [Main Menu]\n";
    cout << "===============================================\n";
    cout << "  1. Add Student\t 2. Delete Student\n";
    cout << "  3. Print Students\n";
    //cout << "  3. Edit Student\t4. Search Student\n";
    //cout << "  5. Group Assignment\n";
    cout << "  0. Exit\n";
    return;
};

void addfile(char* fileName){
    int j = 0;
    ifstream inFile(fileName);
    if(!inFile.is_open()){
        cout << "Error opening file\n";
        return;
    }    
    string line;
    string sub[6];
    while(getline(inFile, line)){
	studentNum++; j++;
	Student * s = (Student*)malloc(sizeof(Student));
	stringstream line_s(line);
	for(int k = 0; k < 6; k++){
	    getline(line_s, sub[k], ' ');
	}
	strcpy(s->name,sub[0].c_str());
	s->classNum = atoi(sub[1].c_str()); 
	s->gradeNum = atoi(sub[2].c_str());
	strcpy(s->major,sub[3].c_str());
    	strcpy(s->gender, sub[4].c_str());
	s->gpa = atof(sub[5].c_str());
	s->next = NULL;
	if(list==NULL){
	    list = s;
	}
	else{
	    s->next = list;
	    list = s;
	}
    }
    cout <<"\n"<< j << " students added\n";
    inFile.close();		
    return;
}

void remove (char* studentName){
    if(list == NULL){
        cout << "Student name is not found\n";
	return;
    }
    if(!strcmp(list->name,studentName)){
	Student * cur = list;
	list = list -> next;
	free(cur);
	cout << "1 student deleted\n";
	return;
    }
    else{
	Student * cur = list->next;
	Student * prev = list;
	while(cur != NULL && strcmp(cur->name,studentName)){
	    prev = cur;
	    cur = cur->next;
	}
	if(cur == NULL){
	    cout << "Student name is not found\n";
	    return;
	}
	prev->next = cur->next;
	free(cur);
	cout << "1 student deleted\n";	
	return;
    }
}

int main(){
    char a, c;
    while (true) {
	printMain();
	cin >> c;
	switch (c) {
	    case '0':{
		exit(0);
	    }
	    case '1': {	
	        cout << "\n [Add Student]\n";
		cout << "===============================================\n";
		cout << "  1) with file\t2) with input\n";
		cin >> a;
		switch(a){
		    case '1':{
			char name[20];
			string line;
			cin.ignore();
			cout << " [With file]\n";
			cout << "Enter the file name: ";
		    	cin >> name;
			addfile(name);
			break;
		    }
		    case '2':{
			string line;
			Student * s = (Student*)malloc(sizeof(Student));
			cout << " [With direct input]\n";
		    	cin.ignore();
			cout << "Enter student's name: ";
			getline(cin, line);
		    	strcpy(s->name,line.c_str());

			cout << "Enter student's class: ";
			getline(cin, line);
			s->classNum = atoi(line.c_str()); 
			
			cout << "Enter student's grade: ";
			getline(cin, line);
			s->gradeNum = atoi(line.c_str());
		
			cout << "Enter student's major: ";
		    	getline(cin, line);
			strcpy(s->major,line.c_str());			

			cout << "Enter student's gender(f/m): ";
			getline(cin,line);
			strcpy(s->gender,line.c_str());
					
			cout << "Enter student's gpa: ";
			getline(cin, line);
		    	s->gpa = atof(line.c_str());
			s->next = NULL;
			if(list == NULL){
			    list = s;
			}
			else{
			    s->next = list;
			    list = s;
			}
			studentNum++;
			cout << "\n1 student added\n";
			break;
		    }
		    default:
			break;
		}
	        break;
	    }
	    case '2': {
		string line;
	    	char name[20];
		cout << "\n [Delete Student]\n";
	    	cout << "===============================================\n";
		cin.ignore();
		cout << "Enter student's name: ";
		cin >> name;
		remove(name);
		break;
	    }
	    case '3': {
	    	cout << "\n [Students]\n";
	    	cout << "===============================================\n";
		cout << "Name\tclass\tgrade\tmajor\tgender\tgpa\n";
		cout << "-----------------------------------------------\n";
		Student * cur = list;
		while(cur != NULL){
		    cout << cur->name << "\t" << cur->classNum << "\t" << cur->gradeNum << "\t" << cur->major << "\t" << cur->gender << "\t" << cur->gpa << endl;
		cur = cur->next;
		}	
	    }
	    default:
	        break;
	}
    }
}
