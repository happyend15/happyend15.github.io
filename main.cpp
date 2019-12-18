#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int num = 0;
struct Student {
    int classNum;
    int gradeNum;
    double gpa;
    char name[20];
    char major[20];
    char gender[2];
    Student * next;
};

Student* list;
int studentNum;

void printMain(){
    cout << "\n [Main Menu]\n";
    cout << "===============================================\n";
    cout << "  1. Add Student\t 2. Delete Student\n";
    cout << "  3. Print Students\t 4. Edit Student\n";
    cout << "  5. Team Assignment\n";
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


void writefile(){
    ifstream outFile("Team.txt");
    if(!outFile.is_open()){
	cout << "Error opening the file\n";
	return;
    }

    outFile.close();
    return; 
}

void remove_studentname (char* studentName){
    if(list == NULL){
        cout << "Student name is not found\n";
	return;
    }
		if(!strcmp(list->name,studentName)){
		Student * cur = list;
		list = list -> next;
		free(cur);
		studentNum--;
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
	studentNum--;
	cout << "1 student deleted\n";	
	return;
    }
}
bool remove_majorname(char* majorname) { //major deletion
	if (list == NULL) {
		return 0;
	}
	if (!strcmp(list->major, majorname)) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL && strcmp(cur->major, majorname)) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_classnum(int classnum) { //remove by classnumber
	if (list == NULL) {
		return 0;
	}
	if (classnum==list->classNum) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL &&classnum!=cur->classNum) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_gradenum(int gradenum) { //remove by grade number
	if (list == NULL) {
		return 0;
	}
	if (gradenum == list->gradeNum) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL && gradenum != cur->gradeNum) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_gender(char* gender2) {
	if (list == NULL) {
		printf("student with %s is not found",gender2);
		return 0;
	}
	if (!strcmp(list->gender, gender2)) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL && strcmp(cur->gender, gender2)) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_gpa(double GP, int index) {
    switch (index) {
	case(1):
		if (list == NULL) {
			printf("student with gpa in range you've selected is not found");
			return 0;
		}
		if (list->gpa >= GP) {
			Student * cur = list;
			list = list->next;
			free(cur);
			num++;
			return 1;
		}
		else {
			Student * cur = list->next;
			Student * prev = list;
			while (cur != NULL && cur->gpa < GP) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL) {
				return 0;
			}
			prev->next = cur->next;
			free(cur);
			num++;
			return 1;
		}
		break;
	case(2):
		if (list == NULL) {
			printf("student with gpa in range you've selected is not found");
			return 0;
		}
		if (list->gpa <= GP) {
			Student * cur = list;
			list = list->next;
			free(cur);
			num++;
			return 1;
		}
		else {
			Student * cur = list->next;
			Student * prev = list;
			while (cur != NULL && cur->gpa > GP) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL) {
				return 0;
			}
			prev->next = cur->next;
			free(cur);
			num++;
			return 1;
		}
		break;
	default:
		break;
	}
	
}
Student* search(char* name){
	Student *cur = list;
	while(cur!=NULL) {
		if (strcmp(cur->name,name) == 0 ) {
			return cur;
		}
		cur = cur->next;
	}
	return cur;
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
			int number;
			cout << "\n [Delete Student]\n";
			cout << "===============================================\n";
			cout << "Delete by name     : 1 || Delete by classnum : 2\nDelete by gradenum : 3 || Delete by major    : 4\nDelete by gender   : 5 || Delete by gpa      : 6 \n";
			cin >> number;
			switch (number) {
			case 1: 
				char name[20];
				cin.ignore();
				cout << "Enter student's name : ";
				cin >> name;
				remove_studentname(name);
				break;
			case 2: 
				int classnum;
				cin.ignore();
				cout << "Enter class number :";
				cin >> classnum;
				while (remove_classnum(classnum) ) {
				}
				studentNum -= num;
				printf("%d students deleted", num);
				num = 0;
				break;
			case 3: 
				int gradenum;
				cin.ignore();
				cout << "Enter grade number :";
				cin >> gradenum;
				while (remove_gradenum(gradenum)) {
				}
				studentNum -= num;
				printf("%d students deleted", num);
				num = 0;
				break;
			case 4:
				char majorname[20];
				cin.ignore();
				cout << "Enter major :";
				cin >> majorname;
				while (remove_majorname(majorname)) {
				}	
				studentNum -= num;
				printf("%d students deleted", num);
				num = 0;
				break;
			case 5:
				char gender[2];
				cin.ignore();
				cout << "Enter gender :";
				cin >> gender;
				while (remove_gender(gender)) {
				}	
				studentNum -= num;
				printf("%d students deleted", num);
				num = 0;
				break;
			case 6:
				double gpa;
				int index;
				cin.ignore();
				cout << "Enter gpa in your range :";
				cin >> gpa;
				cout << "Which range of student you want to delete? greater(>=GPA): 1   less(<=GPA): 2 ";
				cin >> index;
				while (remove_gpa(gpa,index)) {
				}	
				studentNum -= num;
				printf("%d students deleted", num);
				num = 0;
				break;
			default:
				break;	
			}
			break;
	    }
	    case '3': {
	    	cout << "\n [Students] Total: "<< studentNum <<" students\n";
	    	cout << "===================================================\n";
			cout << "Name\tclass\tgrade\tmajor    \tgender\tgpa\n";
			cout << "---------------------------------------------------\n";
			Student * cur = list;
			while(cur != NULL){
				cout << cur->name << "\t" << cur->classNum << "\t" << cur->gradeNum << "\t" << cur->major << "    \t" << cur->gender << "\t" << cur->gpa << endl;
			cur = cur->next;
		}
			break;	
	    }
	    case '4': {
	    	char stuname[20];
	    	int k;
	    	cout << "Enter student name :";
	    	cin >> stuname;
	    	Student* curr=search(stuname);
	    	if (curr != NULL) {
	    		cout << "Edit by name     : 1 || Edit by classnum : 2\nEdit by gradenum : 3 || Edit by major    : 4\nEdit by gender   : 5 || Edit by gpa      : 6"<< "\n"<<"Enter the number : ";
	    
	    		cin >> k;
	    		switch(k) {
	    		case 1:
	    			char editname[20];
	    			cout << "Enter name to edit : ";
	    			cin >> editname;
	    			strcpy(curr->name,editname);
	    			break;
	    		
	    		case 2:
	    			int editclass;
	    			cout << "Enter classnum to edit : ";
	    			cin >> editclass;
	    			curr->classNum=editclass;
	    			break;
	    		case 3:
	    			int editgrade;
	    			cout << "Enter gradenum to edit : ";
	    			cin >> editgrade;
	    			curr->gradeNum=editgrade;
	    			break;
	    		case 4:
	    			char editmajor[20];
	    			cout << "Enter major to edit : ";
	    			cin >> editmajor;
	    			strcpy(curr->major,  editmajor);					break;
	    		case 5:
	    			char editgender[2];
	    			cout << "Enter gender to edit : ";
	    			cin >> editgender;
	    			strcpy(curr->gender , editgender);
	    			break;
	    		case 6:
	    			double editgpa;
	    			cout << "Enter gpa to edit : ";
	    			cin >> editgpa;
	    			curr -> gpa=editgpa;
	    			break;
	    		default:
	    			break;
	    		}
	    	break;
	    	}
	    	else {
	    		cout << "there is no such student";
	    		break;
	    	}
	    }
	    case '5': {
		int num, index, member;
		cout << "\n [Team Assignment]\n";
		cout << "===============================================\n";
		cout << "Enter the number of teams: ";
		cin >> num;
		member = studentNum / num;
		cout << "Distribute by\n";
		cout << "by class : 1 || by gpa : 2 || by random : 3\n";
		cin >> index;
		char * arr[20][5];
		int arrn[20] = {0};
		char* temp[5][10];
		int n[5] = {0};
		switch(index){
		    case 1 :{
			Student * cur = list;
			while(cur != NULL){
			    temp[19-cur->classNum][n[19-cur->classNum]++]=cur->name;
			    cur = cur->next;
			}
			srand(time(NULL));
			for (int i = 0; i < 5; i++){
			    for(int j = 0; j < n[i]; j++){
				int s = rand() % n[i];
				char* t = temp[i][s];
				temp[i][s] = temp[i][j];
				temp[i][j] = t;
			    }
			}

			int k = 0;
			for(int i = 0; i < 5; i++){
			    for(int j = 0; j < n[i]; j++){
				arr[k%num][arrn[k%num]++] = temp[i][j];
				k++;
			    }
			}
			
			for(int i = 0; i < num; i++){
			    cout << "[Team "<< i+1 << "]\n";
			    cout << "---------------------------------------------------\n";	
			    for(int j = 0; j < arrn[i]; j++){
				cur = search(arr[i][j]);
				cout << cur->name << "\t" << cur->classNum << "\t" << cur->gradeNum << "\t" << cur->major << "    \t" << cur->gender << "\t" << cur->gpa << endl;
			    }

			    cout << endl;
			}
			break;
		    } 
		    case 2 :{
			Student * cur = list;
			while(cur != NULL){
			    int i = ((int)(cur->gpa * 10)-26)/5;
			    temp[i][n[i]++]=cur->name;
			    cur = cur->next;
			}
			srand(time(NULL));
			for (int i = 0; i < 5; i++){
			    for(int j = 0; j < n[i]; j++){
				int s = rand() % n[i];
				char* t = temp[i][s];
				temp[i][s] = temp[i][j];
				temp[i][j] = t;
			    }
			}

			int k = 0;
			for(int i = 0; i < 5; i++){
			    for(int j = 0; j < n[i]; j++){
				arr[k%num][arrn[k%num]++] = temp[i][j];
				k++;
			    }
			}
			
			for(int i = 0; i < num; i++){
			    cout << "[Team "<< i+1 << "]\n";
			    cout << "---------------------------------------------------\n";	
			    for(int j = 0; j < arrn[i]; j++){
				cur = search(arr[i][j]);
				cout << cur->name << "\t" << cur->classNum << "\t" << cur->gradeNum << "\t" << cur->major << "    \t" << cur->gender << "\t" << cur->gpa << endl;
			    }

			    cout << endl;
			}	
			break;
		    }
		    case 3 :{
			Student * cur = list;
			srand(time(NULL));
			while(cur != NULL){
			    int i = rand()%5;
			    temp[i][n[i]++]=cur->name;
			    cur = cur->next;
			}
			int k = 0;
			for(int i = 0; i < 5; i++){
			    for(int j = 0; j < n[i]; j++){
				arr[k%num][arrn[k%num]++] = temp[i][j];
				k++;
			    }
			}
			
			for(int i = 0; i < num; i++){
			    cout << "[Team "<< i+1 << "]\n";
			    cout << "---------------------------------------------------\n";	
			    for(int j = 0; j < arrn[i]; j++){
				cur = search(arr[i][j]);
				cout << cur->name << "\t" << cur->classNum << "\t" << cur->gradeNum << "\t" << cur->major << "    \t" << cur->gender << "\t" << cur->gpa << endl;
			    }

			    cout << endl;
			}	
			break;
		    }

		}
		
		break;		  
	    }
	    default:
	        break;
	}
    }
}
