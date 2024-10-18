#include <stdio.h>
#include <stdlib.h>

void remove_newline(char *s, int maxsize) {
  for (int i = 0; i < maxsize && s[i]; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  const int BUFSIZE = 80;
  char buffer[BUFSIZE];
  FILE *infile = NULL;
long running_number = 0;
long next_number = 0;
char operator = 0;
  if (argc != 2) {
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1;
  }
  infile = fopen(argv[1], "r");
  if (!infile) {
    fprintf(stderr, "input file %s not found\n", argv[1]);
    return 1;
  }
if (fgets(buffer, BUFSIZE, infile)) {
        remove_newline(buffer, BUFSIZE);
        running_number = strtol(buffer, NULL, 10); 
    }
    while (fgets(buffer, BUFSIZE, infile)) {
        remove_newline(buffer, BUFSIZE);
        if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/') {
            operator = buffer[0];
        }
        else {
            next_number = strtol(buffer, NULL, 10);
            if (operator == '+') {
                running_number += next_number;
            } else if (operator == '-') {
                running_number -= next_number;
            } else if (operator == '*') {
                running_number *= next_number;
            } else if (operator == '/') {
                if (next_number == 0) {
                    printf("ERROR\n");
                    fclose(infile);
                    return 0; 
                }
                running_number /= next_number;
            }
        }
    }
    printf("%ld\n", running_number);
    fclose(infile);
    return 0;
}
