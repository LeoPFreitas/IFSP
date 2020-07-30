// Created by leonardo on 7/28/20.

#include "../headers/helpers.h"

/*
 * Menus
 * */
void welcomeMenu() {
    printf("\nOlá, bem vindo ao cadastro.");
    printf("\nEscolha uma das opcoes abaixo\n");

    printMenuOptions();
}

void printMenuOptions() {
    printf("\n1 - Cadastrar novo aluno");
    printf("\n2 - Ordenar cadastro atual");
    printf("\n3 - Buscar aluno");
    printf("\n4 - Remover aluno");
    printf("\n5 - Emprimir cadastro");
    printf("\n0 - Sair.\n");
}

void orderMenu() {
    printf("\nOrdenar por: ");
    printf("\n1. Nome e Sobrenome. ");
    printf("\n2. Sobrenome e Nome. ");
    printf("\n3. Data de nascimento. ");
    printf("\n4. Prontuário. ");
    printf("\n5. Curso. ");
    printf("\n0. Sair. ");
}

void selectMethodMenu() {
    printf("\nEscolha o método: ");
    printf("\n1. Quick Sort. ");
    printf("\n2. Merge Sort. ");
    printf("\n3. Insertion Sort. ");
    printf("\n4. Selection Sort ");
    printf("\n0. Sair. ");
}

void searchMenu() {
    printf("\nBuscar por: ");
    printf("\n1. Nome e Sobrenome. ");
    printf("\n2. Prontuário. ");
    printf("\n0. Sair. ");
    printf("\nEscolha: ");
}

void deleteMenu() {
    printf("\nDeletar por: ");
    printf("\n1. Nome e Sobrenome: ");
    printf("\n2. Nome. ");
    printf("\n3. Sobrenome. ");
    printf("\n4. Prontuário. ");
    printf("\n5. Data de nascimento. ");
    printf("\n6. Curso. ");
    printf("\n0. Sair. ");
    printf("\nEscolha: ");
}


/*
 *
 * */
void goodbye() { printf("Saindo..."); }

int getint() {
    int x;

    while (1 != scanf("%d", &x)) {

        while (getchar() != '\n'); // wasting the buffer till the next new line
        printf("Entrada inválida, por favor escolha um número válido: ");
    }
    flush();
    return x;
}

int getOp() {
    printf("\nEscolha uma opcao: ");
    int i = getint();
    return i;
}

void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void populateStudent(Student students[]) {
    // first student
    Student s0 = {"A", "A", 20, 12, 1997, 3005, "ADS"};
    Student s1 = {"A", "B", 14, 07, 1990, 1405, "ADS"};
    Student s2 = {"B", "BB", 25, 01, 2000, 1305, "INMA"};
    Student s3 = {"A", "C", 30, 5, 1995, 377, "ADS"};
    Student s4 = {"Pietra", "Cortesini", 18, 03, 1980, 1065, "ADS"};
    Student s5 = {"Maria", "Santos", 25, 01, 2010, 135, "INMA"};
    Student s6 = {"Julia", "freitas", 20, 12, 1999, 325, "ADS"};
    Student s7 = {"Joana", "Fernando", 24, 07, 1990, 1005, "ADS"};
    Student s8 = {"Carlos", "Silva", 25, 01, 1970, 454, "INMA"};
    Student s9 = {"Leonardo", "freitas", 24, 07, 1990, 1205, "AD"};
    Student s10 = {"Leonardo", "freitas", 25, 01, 1970, 1305, "INM"};
    Student s11 = {"leoadda", "B", 24, 07, 1990, 1245, "ADS"};
    Student s12 = {"leodada", "B", 25, 01, 1970, 1305, "INA"};


    students[0] = s0;
    students[1] = s1;
    students[2] = s2;
    students[3] = s3;
    students[4] = s4;
    students[5] = s5;
    students[6] = s6;
    students[7] = s7;
    students[8] = s8;
    students[9] = s9;

}

void writeFile(Student students[], int nextFreePos) {
    int i;
    int len_vet = nextFreePos;
    FILE *arq;

    arq = fopen("data.data", "w");

    if (arq != NULL) {

        for (i = 0; i < len_vet; i++) {
            fwrite(&students[i], sizeof(Student), 1, arq);
        }

        fclose(arq);
    } else {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }
}

int readFile(Student students[]) {
    FILE *infile;
    int i = 0;
    struct Student student;

    // Open person.dat for reading
    infile = fopen ("data.data", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&students[i], sizeof(struct Student), 1, infile)){
        i++;
    }

    // close file
    fclose (infile);

    return i;
}
