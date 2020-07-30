//
// Created by leonardo on 7/28/20.
//

#include "../headers/student.h"
#include "stdio.h"
#include "string.h"
#include "../headers/helpers.h"
#include "../headers/sorter.h"

void formattedPrint(Student *students, int pos) {
    printf("---------------------------------------------------------------------"
           "------------------------------\n");
    printf("|          Nome        |          Sobrenome        | Dia | Mês |  "
           "Ano  |   Prontuario   |  CURSO  |\n");
    printf("---------------------------------------------------------------------"
           "------------------------------\n");
    for (int i = 0; i < pos; i++) {
        printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-14d | %-7s |\n",
               students[i].firstName, students[i].lastName, students[i].date.day,
               students[i].date.month, students[i].date.year, students[i].id,
               students[i].course);
    }
    printf("---------------------------------------------------------------------"
           "------------------------------\n");
}

void printStudent(Student sf[], int i) {
    printf("---------------------------------------------------------------------"
           "------------------------------\n");
    printf("|          Nome        |          Sobrenome        | Dia | Mês |  "
           "Ano  |   Prontuario   |  CURSO  |\n");
    printf("---------------------------------------------------------------------"
           "------------------------------\n");
    printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-14d | %-7s |\n",
           sf[i].firstName, sf[i].lastName, sf[i].date.day,
           sf[i].date.month, sf[i].date.year, sf[i].id,
           sf[i].course);
    printf("---------------------------------------------------------------------"
           "------------------------------\n");
}

void add(Student students[], int i) {

    printf("Digite o primeiro nome do aluno: ");
    getFirstName(students, i);

    printf("Digite o segundo nome do aluno: ");
    getLastName(students, i);

    printf("Data de nascimento do aluno.");
    getBirthDate(students, i);

    printf("Digite o id do aluno: ");
    getId(students, i);

    printf("Digite o curso do aluno: ");
    getCourse(students, i);

}

void getFirstName(Student students[], int i) {
    fgets(students[i].firstName, sizeof(students[i].firstName), stdin);
    students[i].firstName[strlen(students[i].firstName) - 1] = 0;
    if (strlen(students[i].firstName) >= 48) {
        fflush(stdin);
    }
}

void getLastName(Student students[], int i) {
    fgets(students[i].lastName, sizeof(students[i].lastName), stdin);
    students[i].lastName[strlen(students[i].lastName) - 1] = 0;
    if (strlen(students[i].lastName) >= 48) {
        fflush(stdin);
    }
}

void getBirthDate(Student students[], int i) {
    printf("\nDia: ");
    students[i].date.day = getint();
    printf("Mes: ");
    students[i].date.month = getint();
    printf("Ano: ");
    students[i].date.year = getint();
}

void getId(Student students[], int i) {
    students[i].id = getint();
}

void getCourse(Student students[], int i) {
    fgets(students[i].course, sizeof(students[i].course), stdin);
    students[i].course[strlen(students[i].course) - 1] = 0;
    if (strlen(students[i].course) >= 4) {
        fflush(stdin);
    }
}

/*
 * SEARCH STUDENT
 * */
int binarySearch(Student students[], Student sf, int low, int high, int orderBy) {
    // Repeat until the pointers low and high meet each other

    if (orderBy == 3) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (compareId(&students[mid], &sf) == 0)
                if (compareId(&students[mid], &sf) == 0)
                    return mid;

            if (compareId(&students[mid], &sf) < 0)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    } else {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (strcmp(students[mid].firstName, sf.firstName) == 0 && strcmp(students[mid].lastName, sf.lastName) == 0)
                return mid;

            if (strcmp(students[mid].firstName, sf.firstName) < 0 && strcmp(students[mid].lastName, sf.lastName) < 0)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

}

int linearSearch(Student students[], int nextPos, int op, Student sf) {

    int index = -1;

    if (op == 1) {
        printf("name");
        for (int i = 0; i < nextPos; ++i) {
            if (strcmp(students[i].firstName, sf.firstName) == 0 && strcmp(students[i].lastName, sf.lastName)) {
                index = 1;
            }
        }
    } else {
        for (int i = 0; i < nextPos; ++i) {
            if (students[i].id == sf.id) {
                index = i;
            }
        }
    }

    return index;

}

void search(Student students[], int nextPos, int orderBy) {
    Student sf[1];

    printf("%d", orderBy);

    searchMenu();
    int op = getOp();

    // populate data in student
    if (op == 1) {
        printf("Digite o nome: ");
        getFirstName(sf, 0);
        printf("Digite o sobrenome: ");
        getLastName(sf, 0);
    } else if (op == 2) {
        printf("Digite o prontuário: ");
        getId(sf, 0);
    } else {
        printf("Opcao inválida.");
        exit(1);
    }

    int index = -1;

    if (orderBy == 1 && op == 1) {
        index = binarySearch(students, sf[0], 0, nextPos - 1, orderBy);
    } else if (orderBy == 3 && op == 2) {
        index = binarySearch(students, sf[0], 0, nextPos - 1, orderBy);
    } else {
        index = linearSearch(students, nextPos, op, sf[0]);
    }


    if (index != -1) {
        printStudent(students, index);
    } else {
        printf("Estudante não encontrado.\n");
    }

}

/*
 * REMOVE STUDENT
 * */

int removeById(Student remove, Student students[], int count) {
    int i, j, removed = 0;
    for (i = 0; i < count; i++) {
        if (students[i].id == remove.id) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count = count - 1;
            removed++;
            i--;
        }
    }
    return removed;
}

int removeByCourse(Student remove, Student students[], int count) {
    int i, j, removed = 0;
    for (i = 0; i < count; i++) {
        if (!strcmp(students[i].course, remove.course)) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count = count - 1;
            removed++;
            i--;
        }
    }
    return removed;
}

int removeByBirth(Student remove, Student students[], int count) {
    int i, j, removed = 0;
    for (i = 0; i < count; i++) {
        if (students[i].date.day == remove.date.day &&
            students[i].date.month == remove.date.month &&
            students[i].date.year == remove.date.year) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count = count - 1;
            removed++;
            i--;
        }
    }
    return removed;
}

int removeByFirstName(Student remove, Student students[], int count) {
    int i, j, removed = 0;

    for (i = 0; i < count; i++) {
        if (!strcmp(students[i].firstName, remove.firstName)) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count = count - 1;
            removed++;
            i--;
        }
    }
    return removed;
}

int removeByFirstLastName(Student remove, Student students[], int count) {
    int i, j, removed = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(students[i].firstName, remove.firstName) == 0 &&
            strcmp(students[i].lastName, remove.lastName) == 0) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count = count - 1;
            removed++;
            i--;
        }
    }
    return removed;
}


int removeByLastName(Student remove, Student students[], int count) {
    int i, j, removed = 0;

    for (i = 0; i < count; i++) {
        if (!strcmp(students[i].lastName, remove.lastName)) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count = count - 1;
            removed++;
            i--;
        }
    }
    return removed;
}

int removeStudent(Student students[], int count) {
    deleteMenu();
    int op = getint();
    int countRemoved = 0;

    Student remove[1];

    while (op != 0) {
        switch (op) {
            case 1:
                printf("Digite o primeiro nome: ");
                getFirstName(remove, 0);
                printf("Digite o sobrenome: ");
                getLastName(remove, 0);
                countRemoved = removeByFirstLastName(remove[0], students, count);
                op = 0;
                break;
            case 2:
                printf("Digite o primeiro nome: ");
                getFirstName(remove, 0);
                countRemoved = removeByFirstName(remove[0], students, count);
                op = 0;
                break;
            case 3:
                printf("Digite o sobrenome: ");
                getLastName(remove, 0);
                countRemoved = removeByLastName(remove[0], students, count);
                op = 0;
                break;
            case 4:
                printf("deletar por prontuario: ");
                getId(remove, 0);
                countRemoved = removeById(remove[0], students, count);
                op = 0;
                break;
            case 5:
                printf("deletar por data de nascimento");
                getBirthDate(remove, 0);
                countRemoved = removeByBirth(remove[0], students, count);
                op = 0;
                break;
            case 6:
                printf("deletar por curso");
                getCourse(remove, 0);
                countRemoved = removeByCourse(remove[0], students, count);
                op = 0;
                break;
            default:
                printf("Opcao inválida. Tente outra vez: ");
                op = getint();
                break;
        }

    }

    printf("Quantidade de aluno removidos: %d", countRemoved);

    return countRemoved;
}
