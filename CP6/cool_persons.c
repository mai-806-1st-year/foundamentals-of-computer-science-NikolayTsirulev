#include "person.h"

void usage() {
    printf("Usage: program filename\n");
}

void PrintCoolPersons(FILE* file, int c) {
    person p[c];
    uint marks[c][4];
    for (int i = 0; i < c; ++i) {
        fread(&p[i], sizeof(person), 1, file);
        marks[i][0] = 0;
        marks[i][1] = 0;
        marks[i][2] = 0;
        marks[i][3] = 0;
        if((p[i].gender == 'W')) {
            marks[i][0] = p[i].math;
            marks[i][1] = p[i].physics;
            marks[i][2] = p[i].computer_science;
        }
    }
    for (int i = 0; i < c; ++i) {
        int k = 0;
        for (int j = 0; j < c; ++j) {
            if (marks[i][0]!=marks[j][0]&&marks[i][1]!=marks[j][1]&&marks[i][2]!=marks[j][2]&&i!=j) {
                k++;
            }
        }
        if (k==c-1) {
            marks[i][3] = 1;
        }
    }
    for (int i = 0; i < c; ++i) {
        if(marks[i][3]){
            printf("%s math: %u physics: %u computer science: %u\n", p[i].surname, p[i].math, p[i].physics, p[i].computer_science);
        }
    }
}

int main(int argc, char* argv[]) {
    usage();
    if (argc!=2){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Can't open file!\n");
        return 1;
    }
    int c;
    if (fread(&c, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 1;
    }
    PrintCoolPersons(file, c);
    return 0;
}
