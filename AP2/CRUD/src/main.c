#include <stdio.h>
#include "../headers/student.h"
#include "../headers/helpers.h"
#include "../headers/sorter.h"

int main() {
    /*
     * Initialize variables
     * */
    struct Student students[1000];
    int nextFreePosition;
    int orderBy = -1; // 1 - first last name ; 2 - last first name; 3 - id; -1 none

    /*
     * Read file and start program
     * */
    nextFreePosition = readFile(students);
//    populateStudent(students);
//    nextFreePosition = 10;

    welcomeMenu();
    int op = getOp();

    while (op != 0) {
        switch (op) {
            case 1:
                add(students, nextFreePosition);
                nextFreePosition++;
                break;
            case 2:
                sortStudents(students, &orderBy, nextFreePosition);
                break;
            case 3:
                search(students, nextFreePosition, orderBy);
                break;
            case 4:
                nextFreePosition -= removeStudent(students, nextFreePosition);
                break;
            case 5:
                formattedPrint(students, nextFreePosition);
                break;
            default:

                break;
        }

        printMenuOptions();
        op = getOp();
    }

    writeFile(students, nextFreePosition);
    goodbye();


    printf("Hello, World!\n");
    return 0;
}

