//
// Created by leonardo on 7/28/20.
//

#ifndef CRUD_STUDENT_H
#define CRUD_STUDENT_H

#define TAM_LAST_NAME 51
#define TAM_FIRST_NAME 52

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Student {
    char firstName[TAM_LAST_NAME];
    char lastName[TAM_FIRST_NAME];
    struct Date date;
    int id;
    char course[6];
} Student;

void formattedPrint(Student *students, int pos);

void printStudent(Student sf[], int i);

void add(Student students[], int i);

void getFirstName(Student students[], int pos);

void getLastName(Student students[], int pos);

void getBirthDate(Student students[], int pos);

void getId(Student students[], int pos);

void getCourse(Student students[], int pos);

/*
 * SEARCH
 * */
int linearSearch(Student students[], int nextPos, int op, Student sf);

void search(Student students[], int nextPos, int orderBy);

/*
 * REMOVE
 * */
int removeById(Student remove, Student students[], int count);

int removeByCourse(Student remove, Student students[], int count);

int removeByBirth(Student remove, Student students[], int count);

int removeByFirstName(Student remove, Student students[], int count);

int removeByLastName(Student remove, Student students[], int count);

int removeByFirstLastName(Student remove, Student students[], int count);

int removeStudent(Student students[], int count);

#endif //CRUD_STUDENT_H
