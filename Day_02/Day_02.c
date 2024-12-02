#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
  int length;
  int ** inputs;
} InputData;

char *
charSplitv2(char * string, char separator)
{
  static char * pString;
  static int index;
  static int prevStart;
  static char end;
  if (string != NULL)
  {
    pString = string;
    index = 0;
    prevStart = 0;
    end = 0;
  }
  prevStart = index;
  while (pString[index] != '\0')
  {
    if (pString[index] == separator)
    {
      pString[index] = '\0';
      index++;
      return &pString[prevStart];
    }
    else
    {
      index++;
    }
  }
  if (end == 0)
  {
    end = 1;
    return &pString[prevStart];
  }
  else
  {
    return NULL;
  }
}

InputData
readInput()
{
  FILE * inputFile = fopen("Input.txt", "r");
  int ** numbers = malloc(sizeof(int *) * 1001);

  char line[64];
  int counter = 0;
  InputData result;

  if (inputFile != NULL)
  {
    while (fgets(line, sizeof(line), inputFile))
    {
      if (line[1] != '\0')
      {
        int * numbers1 = malloc(sizeof(int) * 40);
        for (int i = 0; i < 40; i++)
        {
          numbers1[i] = 0;
        }

        int counter2 = 0;
        char * token = charSplitv2(line, ' ');

        while (token != NULL)
        {
          numbers1[counter2] = atoi(token);
          token = charSplitv2(NULL, ' ');
          counter2++;
        }
        numbers[counter] = numbers1;
        counter++;
      }
    }
    fclose(inputFile);
    printf("Total values: %i\n", counter);
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
  int sum = 0;

  for (int i = 0; i < input.length; i++)
  {
    int * in = input.inputs[i];
    char ascending;
    if (in[0] < in[1] && (in[0] + 3) >= in[1])
    {
      ascending = 1;
    }
    else if (in[1] < in[0] && (in[1] + 3) >= in[0])
    {
      ascending = 0;
    }
    else
    {
      continue;
    }
    for (int j = 2; j < 20; j++)
    {
      if (in[j] == 0)
      {
        sum++;
        break;
      }
      if (ascending == 1)
      {
        if (in[j-1] < in[j] && (in[j-1] + 3) >= in[j])
        {
          continue;
        }
        else
        {
          break;
        }
      }
      else if (ascending == 0)
      {
        if (in[j] < in[j-1] && (in[j] + 3) >= in[j-1])
        {
          continue;
        }
        else
        {
          break;
        }
      }
    }
  }


  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;
  printf("Part 1: %i, Time: %fms\n", sum, time_spent1);

  // Part 1

  clock_t start2 = clock();
  InputData input2 = readInput();
  int sum2 = 0;

  for (int i = 0; i < input2.length; i++)
  {
    int * in = input2.inputs[i];
    char ascending;
    if (in[0] < in[1] && (in[0] + 3) >= in[1])
    {
      ascending = 1;
    }
    else if (in[1] < in[0] && (in[1] + 3) >= in[0])
    {
      ascending = 0;
    }
    else
    {
      continue;
    }
    for (int j = 2; j < 20; j++)
    {
      if (in[j] == 0)
      {
        sum2++;
        break;
      }
      if (ascending == 1)
      {
        if (in[j-1] < in[j] && (in[j-1] + 3) >= in[j])
        {
          continue;
        }
        else
        {
          break;
        }
      }
      else if (ascending == 0)
      {
        if (in[j] < in[j-1] && (in[j] + 3) >= in[j-1])
        {
          continue;
        }
        else
        {
          break;
        }
      }
    }
  }


  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - start2) * 1000 / CLOCKS_PER_SEC;
  printf("Part 2: %i, Time: %fms\n", sum2, time_spent2);

  free(input.inputs);
}
