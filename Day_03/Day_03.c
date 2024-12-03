#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
isNumber(char c)
{
  switch (c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
  }
  return -1;
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
    char char1 = line[0];
    char char2 = line[1];
    char char3 = line[2];
    char char4 = line[3];

    for (int i = 4; i < 5000; i++)
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
      char4 = line[i];
      char3 = line[i - 1];
      char2 = line[i - 2];
      char1 = line[i - 3];
      
    }


  }
  fclose(inputFile);
  

  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;
  printf("Part 1: %i, Time: %fms\n", sum1, time_spent1);


  // Part 2
  clock_t start2 = clock();
  int sum2 = 0;
  
  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - start2) * 1000 / CLOCKS_PER_SEC;

  printf("Part 2: %i, Time: %fms\n", sum2, time_spent2);
}
