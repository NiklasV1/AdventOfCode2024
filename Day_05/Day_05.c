#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct
{
  int pageNumber;
  int followingPages[100];
  char used;
}
PageNode;

typedef struct
{
  int pages[100];
  int middleNumber;
}
PrintOrder;

typedef struct
{
  PageNode pageNodes[100];
  PrintOrder printOrders[500];
}
InputData;

InputData
readInput()
{
  FILE * inputFile = fopen("./Input.txt", "r");
  char line[1001];

  InputData input;

  PageNode * pageNodes = input.pageNodes;
  for (int i = 0; i < 100; i++)
  {
    PageNode node;
    node.pageNumber = i;
    node.used = 0;
    node.followingPages[0] = 0;
    pageNodes[i] = node;
  }

  PrintOrder * printOrders = input.printOrders;
  for (int i = 0; i < 500; i++)
  {
    PrintOrder order;
    order.pages[0] = 0;
    order.middleNumber = 0;
    printOrders[i] = order;
  }

  if (inputFile == NULL) {
    exit(1);
  }

  char inputPart = 0;
  int printOrderCounter = 0;
  
  // Read input
  while (fgets(line, sizeof(line), inputFile))
  {
    switch (inputPart)
    {
      case 0:
        if (line[2] == '\0')
        {
          inputPart = 1;
          break;
        }

        line[2] = '\0';
        int pageNum = atoi(&line[0]);
        int followingNum = atoi(&line[3]);

        for (int i = 0; i < 100; i++)
        {
          if (pageNodes[pageNum].followingPages[i] == 0) {
            pageNodes[pageNum].followingPages[i] = followingNum;
            pageNodes[pageNum].followingPages[i + 1] = 0;
            break;
          }
        }

        break;

      case 1:
        if (line[1] == '\0')
        {
          break;
        }

        PrintOrder order = printOrders[printOrderCounter];

        int counter = 0;

        char * token = charSplitv2(line, ',');

        while (token != NULL)
        {
          order.pages[counter] = atoi(token);
          counter++;
          token = charSplitv2(NULL, ',');
        }

        order.pages[counter + 1] = 0;

        order.middleNumber = order.pages[counter / 2];

        printOrders[printOrderCounter] = order;
        printOrderCounter++;
        break;
    }
  }

  return input;
}

void
resetPageNodes(PageNode pageNodes[100])
{
  for (int i = 0; i < 100; i++) {
    pageNodes[i].used = 0;
  }
}

int
checkValidOrder(PrintOrder * pOrder, PageNode * pageNodes)
{
  PrintOrder order = *pOrder;
  for (int j = 0; j < 100; j++)
    {
      int currentNumber = order.pages[j];
      if (currentNumber == 0)
      {
        return order.middleNumber;
        break;
      }

      pageNodes[currentNumber].used = 1;

      for (int k = 0; k < 100; k++)
      {
        int followingNum = pageNodes[currentNumber].followingPages[k];
        if (followingNum == 0)
        {
          break;
        }
        if (pageNodes[followingNum].used == 1)
        {
          return 0;
        }
      }
    }
  return 0;
}

int 
main()
{
  // Part 1
  clock_t start1 = clock();

  int sum = 0;
  InputData input = readInput();
  PageNode * pageNodes = input.pageNodes;
  PrintOrder * printOrders = input.printOrders;

  // Calculations
  for (int i = 0; i < 500; i++)
  {
    resetPageNodes(pageNodes);
    PrintOrder order = printOrders[i];

    if (order.middleNumber == 0) {
      break;
    }

    sum += checkValidOrder(&order, pageNodes);
  }

  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - start1) * 1000 / CLOCKS_PER_SEC;

  printf("Part 1: %i, Time: %f\n", sum, time_spent1);

}
