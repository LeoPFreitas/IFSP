//
// Created by leonardo on 7/28/20.
//

#ifndef CRUD_SORTER_H
#define CRUD_SORTER_H

#include "student.h"

/*
 * COMPARE FUNCTIONS
 * */

int compareFirstLast(struct Student *a, struct Student *b);

int compareLastFirst(struct Student *a, struct Student *b);

int compareCourse(const void *a, const void *b);

int compareId(const void *a, const void *b);

int compareDate(const void *a, const void *b);

/*
 * SORT
 * */
void sortCourse(Student students[], int nextFreePos, int op);

void sortStudents(Student students[], int *orderBy, int nextFreePosition);

void sortId(Student students[], int nextFreePos, int op);

void sortDate(Student students[], int nextFreePos, int op);

void sortFirstLast(Student students[], int nextFreePos, int op);

void sortLastFirst(Student students[], int nextFreePos, int op);

/*
 * MERGE SORT
 * */
void mergeSort(Student *students, int ini, int fim, int op);

int mergeFirstLastName(Student *students, int ini, int meio, int fim);

int mergeLastFirstName(Student *students, int ini, int meio, int fim);

int mergeDate(Student *students, int ini, int meio, int fim);

int mergeCourse(Student *students, int ini, int meio, int fim);

int mergeId(Student *students, int ini, int meio, int fim);


/*
 * INSERTION SORT
 * */
void insertionSortFirstLast(struct Student *students, int nextFreePos);

void insertionSortLastFirst(struct Student *students, int nextFreePos);

void insertionSortDate(struct Student *students, int nextFreePos);

void insertionSortId(struct Student *students, int nextFreePos);

void insertionCourse(struct Student *students, int nextFreePos);

/*
 * SELECTION SORT
 * */
void selectionSort(struct Student *students, int nextFreePos, int op);

#endif //CRUD_SORTER_H
