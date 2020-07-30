//
// Created by leonardo on 7/28/20.
//

#ifndef CRUD_HELPERS_H
#define CRUD_HELPERS_H

#include "student.h"
#include "stdio.h"
#include "stdlib.h"

void welcomeMenu();

void goodbye();

int getint();

void printMenuOptions();

int getOp();

void flush();

void populateStudent(Student students[]);

void selectMethodMenu();

void orderMenu();

void searchMenu();

void deleteMenu();

void writeFile(Student students[], int nextFreePos);

int readFile(Student students[]);

#endif //CRUD_HELPERS_H