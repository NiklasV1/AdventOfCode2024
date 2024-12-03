#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
isNumber(char c)
{
  if (c < 48 || c > 57)
  {
      return -1;
  }
  return c - 48;
}

int
main()
{
  // Part 1
  clock_t start1 = clock();
  int sum1 = 0;
  
  FILE * inputFile = fopen("Input.txt", "r");
  char line[5000];

  if (inputFile == NULL)
  {
    exit(1);
  }

  while (fgets(line, sizeof(line), inputFile)) {
    if (line[1] == '\0') {
      continue;
    }
    char char1 = 1;
    char char2 = 1;
    char char3 = 1;
    char char4 = line[0];

    for (int i = 0; i < 5000; i++)
    {
      // check if end of line
      if (char4 == '\0') {
        break;
      }

      // check if "mul(" in buffer
      if (char1 == 'm' && char2 == 'u' && char3 == 'l' && char4 == '(')
      {
        int number1 = 0;
        int number2 = 0;

        int j = i;
        while (isNumber(line[j]) != -1) {
          number1 = (number1 * 10) + isNumber(line[j]);
          j++;
        }

        if (line[j] == ',') {
          j++;
          while (isNumber(line[j]) != -1) {
            number2 = (number2 * 10) + isNumber(line[j]);
            j++;
          }
          if (line[j] == ')' && number1 > 0 && number2 > 0) {
            sum1 += number1 * number2;
          }
        }
      }

      // increment
      char1 = char2;
      char2 = char3;
      char3 = char4;
      char4 = line[i];
      
    }


  }
  fclose(inputFile);
  

  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;
  printf("Part 1: %i, Time: %fms\n", sum1, time_spent1);


  // Part 2
  clock_t start2 = clock();
  int sum2 = 0;

  char enabled = 1;


  FILE * inputFile2 = fopen("Input.txt", "r");
  char line2[5000];

  if (inputFile2 == NULL)
  {
    exit(1);
  }

  while (fgets(line2, sizeof(line2), inputFile2)) {
    if (line2[1] == '\0') {
      continue;
    }
    char char1 = 1;
    char char2 = 1;
    char char3 = 1;
    char char4 = 1;
    char char5 = 1;
    char char6 = 1;
    char char7 = line[0];

    for (int i = 0; i < 5000; i++)
    {
      // check if end of line
      if (char4 == '\0') {
        break;
      }

      // check if "mul(" in buffer
      if (char4 == 'm' && char5 == 'u' && char6 == 'l' && char7 == '(')
      {
        int number1 = 0;
        int number2 = 0;

        int j = i;
        while (isNumber(line2[j]) != -1) {
          number1 = (number1 * 10) + isNumber(line2[j]);
          j++;
        }

        if (line2[j] == ',') {
          j++;
          while (isNumber(line2[j]) != -1) {
            number2 = (number2 * 10) + isNumber(line2[j]);
            j++;
          }
          if (line2[j] == ')' && number1 > 0 && number2 > 0 && enabled == 1) {
            sum2 += number1 * number2;
          }
        }
      }
      else if (char4 == 'd' && char5 == 'o' && char6 == '(' && char7 == ')')
      {
        enabled = 1;
      }
      else if (char1 == 'd' && char2 == 'o' && char3 == 'n' && char4 == '\'' && char5 == 't' && char6 == '(' && char7 == ')') {
        enabled = 0;
      }

      // increment
      char1 = char2;
      char2 = char3;
      char3 = char4;
      char4 = char5;
      char5 = char6;
      char6 = char7;
      char7 = line2[i];
      
    }


  }
  fclose(inputFile);

  
  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - start2) * 1000 / CLOCKS_PER_SEC;

  printf("Part 2: %i, Time: %fms\n", sum2, time_spent2);
}
