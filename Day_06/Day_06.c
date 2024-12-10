#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  int height;
  int width;
  char ** map;
  Position startPosition;
} InputData;

InputData readInput() {
  FILE * inputFile = fopen("Input.txt", "r");
  char line[1001];

  InputData input;

  if (inputFile == NULL) {
    exit(1);
  }

  Position startPosition;
  startPosition.x = -1;
  startPosition.y = -1;

  int width = 0;
  int height = 0;
  char ** map = (char **) malloc(sizeof(char *) * 1001);

  while (fgets(line, sizeof(line), inputFile)) {
    if (line[1] == '\0') {
      break;
    }
    if (width == 0) {
      width = strlen(line);
    }

    map[height] = (char *) malloc(sizeof(char) * 1001);
    strcpy(map[height], line);

    if (startPosition.x == -1) {
      for (int i = 0; i < 1001; i++) {
        if (line[i] == '\0') {
          break;
        }
        if (line[i] == '^') {
          startPosition.x = i;
          startPosition.y = height;
        }
      }
    }

    height++;
  }

  input.startPosition = startPosition;
  input.height = height;
  input.width = width;
  input.map = map;

  return input;
}

int main() {
  // Part 1
  InputData input = readInput();
  char ** map = input.map;
  int width = input.width;
  int height = input.height;
  Position position = input.startPosition;
  char direction = 'u';

  map[position.y][position.x] = 'X';
  int sum1 = 1;

  for (int i = 0; i < 10000; i++) {
    int newX = position.x;
    int newY = position.y;

    switch (direction) {
      case 'u':
        newY--;
        break;
      case 'd':
        newY++;
        break;
      case 'l':
        newX--;
        break;
      case 'r':
        newX++;
        break;
    }

    if (newX < 0 || newY < 0 || newX >= width || newY >= height) {
      break;
    }

    switch (map[newY][newX]) {
      case 'X':
        position.x = newX;
        position.y = newY;
        break;
      case '.':
        map[newY][newX] = 'X';
        sum1++;
        position.x = newX;
        position.y = newY;
        break;
      case '#':
        switch (direction) {
          case 'u':
            direction = 'r';
            break;
          case 'd':
            direction = 'l';
            break;
          case 'l':
            direction = 'u';
            break;
          case 'r':
            direction = 'd';
            break;
        }
        break;
    }
  }

  printf("Part 1: %i\n", sum1);


  // Part 2
  InputData input2 = readInput();
  char ** map2 = input2.map;
  int width2 = input2.width;
  int height2 = input2.height;
  Position position2 = input2.startPosition;
  char direction2 = 'u';

  map2[position2.y][position2.x] = 'X';
  int sum2 = 0;

  for (int i = 0; i < 10000; i++) {
    int newX = position2.x;
    int newY = position2.y;

    switch (direction2) {
      case 'u':
        newY--;
        break;
      case 'd':
        newY++;
        break;
      case 'l':
        newX--;
        break;
      case 'r':
        newX++;
        break;
    }

    if (newX < 0 || newY < 0 || newX >= width2 || newY >= height2) {
      break;
    }

    switch (map2[newY][newX]) {
      case 'X':
        position2.x = newX;
        position2.y = newY;
        sum2++;
        break;
      case '.':
        map2[newY][newX] = 'X';
        position2.x = newX;
        position2.y = newY;
        break;
      case '#':
        switch (direction) {
          case 'u':
            direction = 'r';
            break;
          case 'd':
            direction = 'l';
            break;
          case 'l':
            direction = 'u';
            break;
          case 'r':
            direction = 'd';
            break;
        }
        break;
    }
  }

  printf("Part 2: %i\n", sum2);
}
