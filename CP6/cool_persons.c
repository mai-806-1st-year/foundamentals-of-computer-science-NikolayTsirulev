#include "person.h"

void usage() {
    printf("Usage: program filename\n");
}

void PrintCoolPersons(FILE* file) {
    person p;
    while (fread (&p, sizeof(person), 1, file) == 1) {
        if(!p.gender&&p.math!=p.physics&&p.math!=p.computer_science&&p.physics!=p.computer_science){
            printf("%s math: %u physics: %u computer science: %u\n", p.surname, p.math, p.physics, p.computer_science);
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
    PrintCoolPersons(file);
    return 0;
}
