//
// Created by leonardo on 7/28/20.
//

#include "../headers/sorter.h"
#include "../headers/helpers.h"
#include "string.h"
#include "math.h"

/*
 * COMPARE FUNCTIONS
 * */
int compareFirstLast(struct Student *a, struct Student *b) {

    char s1[100];
    char s2[100];

    int r = strcmp(strcat(strcpy(s1, a->firstName), a->lastName),
                   strcat(strcpy(s2, b->firstName), b->lastName));

    if (r == 0) {
        return 0;
    } else if (r < 0) {
        return -1; // vem antes
    } else {
        return 1; // vem depois
    }
}

int compareLastFirst(struct Student *a, struct Student *b) {

    char s1[100];
    char s2[100];

    int r = strcmp(strcat(strcpy(s1, a->lastName), a->firstName),
                   strcat(strcpy(s2, b->lastName), b->firstName));

    if (r == 0) {
        return 0;
    } else if (r < 0) {
        return -1; // vem antes
    } else {
        return 1; // vem depois
    }
}

int compareId(const void *a, const void *b) {
    if ((*(struct Student *) a).id == (*(struct Student *) b).id) {
        return 0;
    } else {
        if ((*(struct Student *) a).id < (*(struct Student *) b).id) {
            return -1;
        } else {
            return 1;
        }
    }
}

int compareDate(const void *a, const void *b) {

    int y1 = (*(struct Student *) a).date.year;
    int y2 = (*(struct Student *) b).date.year;

    int m1 = (*(struct Student *) a).date.month;
    int m2 = (*(struct Student *) b).date.month;

    int d1 = (*(struct Student *) a).date.day;
    int d2 = (*(struct Student *) b).date.day;

    if (d1 == d2 && m1 == m2 && y1 == y2) {
        return 0;
    } else if (y1 > y2 || y1 == y2 && m1 > m2 ||
               y1 == y2 && m1 == m2 && d1 > d2) {
        return 1;
    } else {
        return -1;
    }
}

int compareCourse(const void *a, const void *b) {
    int r = strcmp((*(struct Student *) a).course, (*(struct Student *) b).course);

    if (r == 0) {
        return 0;
    } else if (r < 0) {
        return -1; // vem antes
    } else {
        return 1; // vem depois
    }
}

/*
 * SORT
 * */
void sortFirstLast(Student students[], int nextFreePos, int op) {

    selectMethodMenu();
    int method = getOp();

    switch (method) {
        case 1:
            qsort(students, nextFreePos, sizeof(struct Student), compareFirstLast);
            break;
        case 2:
            mergeSort(students, 0, nextFreePos - 1, op);
            break;
        case 3:
            insertionSortFirstLast(students, nextFreePos);
            break;
        case 4:
            selectionSort(students, nextFreePos, op);
            break;
        default:
            printf("Opcao inválida.");
            exit(1);
    }
}

void sortLastFirst(Student students[], int nextFreePos, int op) {

    selectMethodMenu();
    int method = getOp();

    switch (method) {
        case 1:
            qsort(students, nextFreePos, sizeof(struct Student), compareLastFirst);
            break;
        case 2:
            mergeSort(students, 0, nextFreePos - 1, op);
            break;
        case 3:
            insertionSortLastFirst(students, nextFreePos);
            break;
        case 4:
            selectionSort(students, nextFreePos, op);
            break;
        default:
            printf("Opcao inválida.");
            exit(1);
    }
}

void sortId(Student students[], int nextFreePos, int op) {

    selectMethodMenu();
    int method = getOp();

    switch (method) {
        case 1:
            qsort(students, nextFreePos, sizeof(struct Student), compareId);
            break;
        case 2:
            mergeSort(students, 0, nextFreePos - 1, op);
            break;
        case 3:
            insertionSortId(students, nextFreePos);
            break;
        case 4:
            selectionSort(students, nextFreePos, op);
            break;
        default:
            printf("Opcao inválida.");
            exit(1);
    }
}

void sortDate(Student students[], int nextFreePos, int op) {

    selectMethodMenu();
    int method = getOp();

    switch (method) {
        case 1:
            qsort(students, nextFreePos, sizeof(struct Student), compareDate);
            break;
        case 2:
            mergeSort(students, 0, nextFreePos - 1, op);
            break;
        case 3:
            insertionSortDate(students, nextFreePos);
            break;
        case 4:
            selectionSort(students, nextFreePos, op);
            break;
        default:
            printf("Opcao inválida.");
            exit(1);
    }
}

void sortCourse(Student students[], int nextFreePos, int op) {

    selectMethodMenu();
    int method = getOp();

    switch (method) {
        case 1:
            qsort(students, nextFreePos, sizeof(struct Student), compareCourse);
            break;
        case 2:
            mergeSort(students, 0, nextFreePos - 1, op);
            break;
        case 3:
            insertionCourse(students, nextFreePos);
            break;
        case 4:
            selectionSort(students, nextFreePos, op);
            break;
        default:
            printf("Opcao inválida.");
            exit(1);
    }
}

void sortStudents(Student students[], int *orderBy, int nextFreePosition) {
    orderMenu();
    int op = getOp();

    switch (op) {
        case 1:
            sortFirstLast(students, nextFreePosition, op);
            *orderBy = 1;
            break;
        case 2:
            sortLastFirst(students, nextFreePosition, op);
            *orderBy = 2;
            break;
        case 3:
            sortDate(students, nextFreePosition, op);
            *orderBy = -1;
            break;
        case 4:
            sortId(students, nextFreePosition, op);
            *orderBy = 3;
            break;
        case 5:
            sortCourse(students, nextFreePosition, op);
            *orderBy = -1;
            break;
        default:
            *orderBy = -1;
    }

}

/*
 * MERGE SORT
 * */

int mergeId(Student *students, int ini, int meio, int fim) {
    struct Student *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - ini;

    p1 = ini;
    p2 = meio + 1;

    temp = (struct Student *) malloc(tamanho * sizeof(Student));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {

                // combina e ordena
                if (compareId(&students[p1], &students[p2]) < 0) {
                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }

                // vetor acabou?
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;

            } else {
                // copia o que sobrar
                if (!fim1) {

                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }
            }
        }

        for (j = 0, k = ini; j < tamanho; j++, k++) {
            students[k] = temp[j];
        }
        free(temp);
    }


}

int mergeFirstLastName(Student *students, int ini, int meio, int fim) {
    struct Student *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - ini;

    p1 = ini;
    p2 = meio + 1;

    temp = (struct Student *) malloc(tamanho * sizeof(Student));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {

                // combina e ordena
                if (compareFirstLast(&students[p1], &students[p2]) < 0) {
                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }

                // vetor acabou?
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;

            } else {
                // copia o que sobrar
                if (!fim1) {

                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }
            }
        }

        for (j = 0, k = ini; j < tamanho; j++, k++) {
            students[k] = temp[j];
        }
        free(temp);
    }


}

int mergeLastFirstName(Student *students, int ini, int meio, int fim) {
    struct Student *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - ini;

    p1 = ini;
    p2 = meio + 1;

    temp = (struct Student *) malloc(tamanho * sizeof(Student));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {

                // combina e ordena
                if (compareLastFirst(&students[p1], &students[p2]) < 0) {
                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }

                // vetor acabou?
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;

            } else {
                // copia o que sobrar
                if (!fim1) {

                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }
            }
        }

        for (j = 0, k = ini; j < tamanho; j++, k++) {
            students[k] = temp[j];
        }
        free(temp);
    }


}

int mergeDate(Student *students, int ini, int meio, int fim) {
    struct Student *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - ini;

    p1 = ini;
    p2 = meio + 1;

    temp = (struct Student *) malloc(tamanho * sizeof(Student));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {

                // combina e ordena
                if (compareDate(&students[p1], &students[p2]) < 0) {
                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }

                // vetor acabou?
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;

            } else {
                // copia o que sobrar
                if (!fim1) {

                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }
            }
        }

        for (j = 0, k = ini; j < tamanho; j++, k++) {
            students[k] = temp[j];
        }
        free(temp);
    }


}

int mergeCourse(Student *students, int ini, int meio, int fim) {
    struct Student *temp;
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - ini;

    p1 = ini;
    p2 = meio + 1;

    temp = (struct Student *) malloc(tamanho * sizeof(Student));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {

                // combina e ordena
                if (compareCourse(&students[p1], &students[p2]) < 0) {
                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }

                // vetor acabou?
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;

            } else {
                // copia o que sobrar
                if (!fim1) {

                    temp[i] = students[p1++];
                } else {
                    temp[i] = students[p2++];
                }
            }
        }

        for (j = 0, k = ini; j < tamanho; j++, k++) {
            students[k] = temp[j];
        }
        free(temp);
    }


}

void mergeSort(Student *students, int ini, int fim, int op) {
    int meio;

    switch (op) {
        case 1:
            if (ini < fim) {
                meio = floor((ini + fim) / 2);
                mergeSort(students, ini, meio, op);
                mergeSort(students, meio + 1, fim, op);
                mergeFirstLastName(students, ini, meio, fim);
            }
            break;
        case 2:
            if (ini < fim) {
                meio = floor((ini + fim) / 2);
                mergeSort(students, ini, meio, op);
                mergeSort(students, meio + 1, fim, op);
                mergeLastFirstName(students, ini, meio, fim);
            }
            break;
        case 3:
            if (ini < fim) {
                meio = floor((ini + fim) / 2);
                mergeSort(students, ini, meio, op);
                mergeSort(students, meio + 1, fim, op);
                mergeDate(students, ini, meio, fim);
            }
            break;
        case 4:
            if (ini < fim) {
                meio = floor((ini + fim) / 2);
                mergeSort(students, ini, meio, op);
                mergeSort(students, meio + 1, fim, op);
                mergeId(students, ini, meio, fim);
            }
            break;
        case 5:
            if (ini < fim) {
                meio = floor((ini + fim) / 2);
                mergeSort(students, ini, meio, op);
                mergeSort(students, meio + 1, fim, op);
                mergeCourse(students, ini, meio, fim);
            }
            break;
        default:
            exit(1);
    }
}

/*
 * INSERTION SORT
 * */
void insertionSortFirstLast(struct Student *students, int nextFreePos) {
    int i, j;
    struct Student aux;

    for (i = 1; i < nextFreePos; i++) {
        aux = students[i];
        for (j = i; (j > 0) && (compareFirstLast(&aux, &students[j - 1]) < 0); j--) {
            students[j] = students[j - 1];
        }
        students[j] = aux;
    }
}

void insertionSortLastFirst(struct Student *students, int nextFreePos) {
    int i, j;
    struct Student aux;

    for (i = 1; i < nextFreePos; i++) {
        aux = students[i];
        for (j = i; (j > 0) && (compareLastFirst(&aux, &students[j - 1]) < 0); j--) {
            students[j] = students[j - 1];
        }
        students[j] = aux;
    }
}

void insertionSortDate(struct Student *students, int nextFreePos) {
    int i, j;
    struct Student aux;

    for (i = 1; i < nextFreePos; i++) {
        aux = students[i];
        for (j = i; (j > 0) && (compareDate(&aux, &students[j - 1]) < 0); j--) {
            students[j] = students[j - 1];
        }
        students[j] = aux;
    }
}

void insertionSortId(struct Student *students, int nextFreePos) {
    int i, j;
    struct Student aux;

    for (i = 1; i < nextFreePos; i++) {
        aux = students[i];
        for (j = i; (j > 0) && (compareId(&aux, &students[j - 1]) < 0); j--) {
            students[j] = students[j - 1];
        }
        students[j] = aux;
    }
}

void insertionCourse(struct Student *students, int nextFreePos) {
    int i, j;
    struct Student aux;

    for (i = 1; i < nextFreePos; i++) {
        aux = students[i];
        for (j = i; (j > 0) && (compareCourse(&aux, &students[j - 1]) < 0); j--) {
            students[j] = students[j - 1];
        }
        students[j] = aux;
    }
}

/*
 * SELECTION SORT
 * */
void selectionSort(struct Student *students, int nextFreePos, int op) {
    int i, j, menor;
    struct Student troca;

    switch (op) {
        case 1:
            for (i = 0; i < nextFreePos - 1; i++) {
                menor = i;
                for (j = i + 1; j < nextFreePos; j++) {
                    if (compareFirstLast(&students[j], &students[menor]) < 0) {
                        menor = j;
                    }
                }

                if (i != menor) {
                    troca = students[i];
                    students[i] = students[menor];
                    students[menor] = troca;
                }

            }
            break;
        case 2:
            for (i = 0; i < nextFreePos - 1; i++) {
                menor = i;
                for (j = i + 1; j < nextFreePos; j++) {
                    if (compareLastFirst(&students[j], &students[menor]) < 0) {
                        menor = j;
                    }
                }

                if (i != menor) {
                    troca = students[i];
                    students[i] = students[menor];
                    students[menor] = troca;
                }

            }
            break;
        case 3:
            for (i = 0; i < nextFreePos - 1; i++) {
                menor = i;
                for (j = i + 1; j < nextFreePos; j++) {
                    if (compareDate(&students[j], &students[menor]) < 0) {
                        menor = j;
                    }
                }

                if (i != menor) {
                    troca = students[i];
                    students[i] = students[menor];
                    students[menor] = troca;
                }

            }
            break;
        case 4:
            for (i = 0; i < nextFreePos - 1; i++) {
                menor = i;
                for (j = i + 1; j < nextFreePos; j++) {
                    if (compareId(&students[j], &students[menor]) < 0) {
                        menor = j;
                    }
                }

                if (i != menor) {
                    troca = students[i];
                    students[i] = students[menor];
                    students[menor] = troca;
                }

            }
            break;
        case 5:
            for (i = 0; i < nextFreePos - 1; i++) {
                menor = i;
                for (j = i + 1; j < nextFreePos; j++) {
                    if (compareCourse(&students[j], &students[menor]) < 0) {
                        menor = j;
                    }
                }

                if (i != menor) {
                    troca = students[i];
                    students[i] = students[menor];
                    students[menor] = troca;
                }

            }
            break;
        default:
            exit(1);
    }


}