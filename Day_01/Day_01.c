#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int length;
  int ** inputs;
} InputData;

InputData
readInput()
{
  FILE * inputFile = fopen("Input.txt", "r");
  int ** numbers = malloc(sizeof(int *) * 2);
  int * numbers1 = malloc(sizeof(int) * 1001);
  int * numbers2 = malloc(sizeof(int) * 1001);

  char line[256];
  int counter = 0;
  InputData result;

  numbers[0] = numbers1;
  numbers[1] = numbers2;

  if (inputFile != NULL)
  {
    while (fgets(line, sizeof(line), inputFile))
    {
      
    }
  }
  return result;
}

int
main()
{
  printf("Hello World!");
}

