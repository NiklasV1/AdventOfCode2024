#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
  int length;
  char ** inputs;
} InputData;

InputData
readInput()
{
  FILE * inputFile = fopen("Input.txt", "r");
  char ** lines = malloc(sizeof(char *) * 1001);

  char line[1001];
  int counter = 0;
  InputData result;

  if (inputFile == NULL)
  {
    exit(1);
  }

  while (fgets(line, sizeof(line), inputFile))
  {
    if (line[1] == '\0')
    {
      continue;
    }

    char * line1 = malloc(sizeof(char) * 1001);
    strcpy(line1, line);
    lines[counter] = line1;
    counter++;
  }
  fclose(inputFile);

  result.length = counter;
  result.inputs = lines;
  return result;
}

int
main()
{

  // Part 1
  clock_t start1 = clock();
  InputData input = readInput();
  int sum1 = 0;

  // Read horizontals
  for (int i = 0; i < input.length; i++) {
    char * line = input.inputs[i];

    char buf1 = 0;
    char buf2 = 0;
    char buf3 = 0;
    char buf4 = line[0];

    for (int j = 0; j < 1001; j++) {
      if (line[j] == '\0') {
        break;
      }

      if (buf1 == 'X' && buf2 == 'M' && buf3 == 'A' && buf4 == 'S') {
        sum1++;
      }

      if (buf1 == 'S' && buf2 == 'A' && buf3 == 'M' && buf4 == 'X') {
        sum1++;
      }

      buf1 = buf2;
      buf2 = buf3;
      buf3 = buf4;
      buf4 = line[j + 1];
    }
  }

  // Read verticals
  for (int i = 3; i < input.length; i++) {
    char * line1 = input.inputs[i - 3];
    char * line2 = input.inputs[i - 2];
    char * line3 = input.inputs[i - 1];
    char * line4 = input.inputs[i];

    char buf1 = line1[0];
    char buf2 = line2[0];
    char buf3 = line3[0];
    char buf4 = line4[0];

    for (int j = 0; j < 1001; j++) {
      if (line1[j] == '\0') {
        break;
      }

      if (buf1 == 'X' && buf2 == 'M' && buf3 == 'A' && buf4 == 'S') {
        sum1++;
      }

      if (buf1 == 'S' && buf2 == 'A' && buf3 == 'M' && buf4 == 'X') {
        sum1++;
      }

      buf1 = line1[j + 1];
      buf2 = line2[j + 1];
      buf3 = line3[j + 1];
      buf4 = line4[j + 1];
    }
  }

  // Read diagonal 1
  for (int i = 3; i < input.length; i++) {
    char * line1 = input.inputs[i - 3];
    char * line2 = input.inputs[i - 2];
    char * line3 = input.inputs[i - 1];
    char * line4 = input.inputs[i];

    char buf1 = line1[0];
    char buf2 = line2[1];
    char buf3 = line3[2];
    char buf4 = line4[3];

    for (int j = 3; j < 1001; j++) {
      if (line1[j] == '\0') {
        break;
      }

      if (buf1 == 'X' && buf2 == 'M' && buf3 == 'A' && buf4 == 'S') {
        sum1++;
      }

      if (buf1 == 'S' && buf2 == 'A' && buf3 == 'M' && buf4 == 'X') {
        sum1++;
      }

      buf1 = line1[j - 2];
      buf2 = line2[j - 1];
      buf3 = line3[j];
      buf4 = line4[j + 1];
    }
  }

  // Read diagonal 2
  for (int i = 3; i < input.length; i++) {
    char * line1 = input.inputs[i - 3];
    char * line2 = input.inputs[i - 2];
    char * line3 = input.inputs[i - 1];
    char * line4 = input.inputs[i];

    char buf1 = line1[3];
    char buf2 = line2[2];
    char buf3 = line3[1];
    char buf4 = line4[0];

    for (int j = 3; j < 1001; j++) {
      if (line1[j] == '\0') {
        break;
      }

      if (buf1 == 'X' && buf2 == 'M' && buf3 == 'A' && buf4 == 'S') {
        sum1++;
      }

      if (buf1 == 'S' && buf2 == 'A' && buf3 == 'M' && buf4 == 'X') {
        sum1++;
      }

      buf1 = line1[j + 1];
      buf2 = line2[j];
      buf3 = line3[j - 1];
      buf4 = line4[j - 2];
    }
  }

  // Free mallocs
  for (int i = 0; i < input.length; i++) {
    free(input.inputs[i]);
  }
  free(input.inputs);

  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;
  printf("Part 1: %i, Time: %fms\n", sum1, time_spent1);



  // Part 2
  clock_t start2 = clock();
  InputData input2 = readInput();
  int sum2 = 0;


  for (int i = 2; i < input2.length; i++) {
    char * line1 = input2.inputs[i - 2];
    char * line2 = input2.inputs[i - 1];
    char * line3 = input2.inputs[i];

    char buf1 = line1[0];
    char buf2 = line1[2];
    char buf3 = line2[1];
    char buf4 = line3[0];
    char buf5 = line3[2];

    for (int j = 2; j < 1001; j++) {
      if (line1[j] == '\0') {
        break;
      }

      if (buf1 == 'M' && buf2 == 'M' && buf3 == 'A' && buf4 == 'S' && buf5 == 'S') {
        sum2++;
      }
      if (buf1 == 'S' && buf2 == 'M' && buf3 == 'A' && buf4 == 'S' && buf5 == 'M') {
        sum2++;
      }
      if (buf1 == 'M' && buf2 == 'S' && buf3 == 'A' && buf4 == 'M' && buf5 == 'S') {
        sum2++;
      }
      if (buf1 == 'S' && buf2 == 'S' && buf3 == 'A' && buf4 == 'M' && buf5 == 'M') {
        sum2++;
      }

      
      buf1 = line1[j - 1];
      buf2 = line1[j + 1];
      buf3 = line2[j];
      buf4 = line3[j - 1];
      buf5 = line3[j + 1];
    }
  }

  // Free mallocs
  for (int i = 0; i < input2.length; i++) {
    free(input2.inputs[i]);
  }
  free(input2.inputs);

  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - start2) * 1000 / CLOCKS_PER_SEC;
  printf("Part 2: %i, Time: %fms\n", sum2, time_spent2);

}
