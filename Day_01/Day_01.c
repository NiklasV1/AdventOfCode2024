#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
  int length;
  int ** inputs;
} InputData;

int
comp(const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int
difference(int a, int b)
{
  if (a > b)
  {
    return a - b;
  }
  else if (a < b)
  {
    return b - a;
  }
  else
  {
    return 0;
  }
}

InputData
readInput()
{
  FILE * inputFile = fopen("Input.txt", "r");
  int ** numbers = malloc(sizeof(int *) * 2);
  int * numbers1 = malloc(sizeof(int) * 1001);
  int * numbers2 = malloc(sizeof(int) * 1001);

  char line[32];
  int counter = 0;
  InputData result;

  numbers[0] = numbers1;
  numbers[1] = numbers2;

  if (inputFile != NULL)
  {
    while (fgets(line, sizeof(line), inputFile))
    {
      if (line[1] != '\0')
      {
        line[5] = '\0';
        char * point2 = line + (8 * sizeof(char));

        numbers1[counter] = atoi(line);
        numbers2[counter] = atoi(point2);

        counter++;
      }
    }
    fclose(inputFile);
    // printf("Total values: %i\n", counter);
  }

  result.length = counter;
  result.inputs = numbers;
  return result;
}

int
main()
{
  // Part 1

  clock_t start1 = clock();
  InputData input = readInput();
  
  qsort(input.inputs[0], input.length, sizeof(int), comp); 
  qsort(input.inputs[1], input.length, sizeof(int), comp);
  
  int sum = 0;
  for (int i = 0; i < input.length; i++)
  {
    // printf("val1: %i, val2: %i\n", input.inputs[0][i], input.inputs[1][i]);
    sum += difference(input.inputs[0][i], input.inputs[1][i]);
  }

  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;
  printf("Part 1: %i, Time: %fms\n", sum, time_spent1);


  // Part 2
  clock_t start2 = clock();

  InputData input2 = readInput();
  int sum2 = 0;

  for (int i = 0; i < input.length; i++)
  {
    int number1 = input.inputs[0][i];
    int counter = 0;
    for (int j = 0; j < input.length; j++)
    {
      int number2 = input.inputs[1][j];
      if (number1 == number2)
      {
        counter++;
      }
    }
    sum2 += number1 * counter;
  }

  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - start2) * 1000 / CLOCKS_PER_SEC;

  printf("Part 2: %i, Time: %fms\n", sum2, time_spent2);


  free(input.inputs[0]);
  free(input.inputs[1]);
  free(input.inputs);
}

