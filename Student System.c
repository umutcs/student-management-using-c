#include<stdio.h>
#include<dirent.h>

struct Student {
    char studentName[10];
    char studentSurname[20];
    int studentNumber;
    int grade;
    int* studentID ;
};

void ListStudents(){

struct dirent *entry;
    DIR *dp = opendir(".");
    
    if (dp == NULL) {
        perror("Error");
        return;
    }

    printf("All students id's':\n");

    while ((entry = readdir(dp))) {
        if (strstr(entry->d_name, ".txt")) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);

}
void KitapListele() {
    
}
void GetStudent() {
    struct Student student;
    
    printf("Enter Student Number: ");
    scanf("%d", &student.studentNumber);
	int* studentID = &student.studentNumber;
	student.studentID = studentID;
    char filename[15];
    sprintf(filename, "%d.txt", student.studentID);

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Dosya bulunamadi!\n");
        return;
    }

    fscanf(fptr, "%s", student.studentName);
    fscanf(fptr, "%s", student.studentSurname);
    fscanf(fptr, "%d", &student.grade);
    fscanf(fptr, "%d", &student.studentNumber);

    fclose(fptr);

    printf("Student Information:\n");
    printf("Name: %s\n", student.studentName);
    printf("Surname: %s\n", student.studentSurname);
    printf("Grade: %d\n", student.grade);
    printf("Student Number: %d\n", student.studentNumber);
}

void AddStudent() {
    struct Student student;
    FILE *fptr;

    printf("Student name: ");
    scanf("%s", student.studentName);

    printf("Student surname: ");
    scanf("%s", student.studentSurname);

    printf("Student Grade: ");
    scanf("%d", &student.grade);

    printf("Student Number: ");
    scanf("%d", &student.studentNumber);

    student.studentID = &student.studentNumber;

    char filename[15];
    sprintf(filename, "%d.txt", student.studentID);

    fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    fprintf(fptr, "%s\n", student.studentName);
    fprintf(fptr, "%s\n", student.studentSurname);
    fprintf(fptr, "%d\n", student.grade);
    fprintf(fptr, "%d\n", student.studentNumber);

    fclose(fptr);
    printf("Student added!\n");
}

int main() {
    
//AddStudent();
GetStudent();
    return 0;
}
