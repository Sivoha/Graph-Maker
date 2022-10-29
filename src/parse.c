#include "parse.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *delete_spaces(char *stroka) {
  char *s_no_spaces = malloc(strlen(stroka) * sizeof(char));
  int cur = 0;
  char *space = strchr(stroka, ' ');
  while (space != NULL) {
    space = strchr(stroka, ' ');
    if (space != NULL) {
      for (; stroka != space; stroka++) {
        s_no_spaces[cur++] = *stroka;
      }
      stroka = space + 1;
    }
  }
  while (*stroka != '\0') {
    s_no_spaces[cur++] = *stroka;
    stroka++;
  }
  s_no_spaces[cur] = '\0';
  return s_no_spaces;
}

char *replace_unar_minus(char *stroka) {
  char *res = stroka;
  if (res[0] == '-') {
    res[0] = '~';
  }
  res++;
  for (; (int)*res != '\0'; res++) {
    if ((int)*res == '-') {
      if ((int)*(res - 1) == '(' || (int)*(res - 1) == '^' ||
          (int)*(res - 1) == '/' || (int)*(res - 1) == '+' ||
          (int)*(res - 1) == '-' || (int)*(res - 1) == '*') {
        *res = '~';
      }
    }
  }
  return stroka;
}

char *replace_functions(char *stroka) {
  char *res = malloc(strlen(stroka) * sizeof(char));
  int cur = 0;
  for (size_t i = 0; i < strlen(stroka);) {
    if (i + 2 < strlen(stroka) &&
        (stroka[i] == 's' && stroka[i + 1] == 'i' && stroka[i + 2] == 'n')) {
      res[cur++] = 's';  // sin
      i += 3;
    } else if (i + 2 < strlen(stroka) &&
               (stroka[i] == 'c' && stroka[i + 1] == 'o' &&
                stroka[i + 2] == 's')) {
      res[cur++] = 'c';  // cos
      i += 3;
    } else if (i + 2 < strlen(stroka) &&
               (stroka[i] == 't' && stroka[i + 1] == 'a' &&
                stroka[i + 2] == 'n')) {
      res[cur++] = 't';  // tan
      i += 3;
    } else if (i + 2 < strlen(stroka) &&
               (stroka[i] == 'c' && stroka[i + 1] == 'o' &&
                stroka[i + 2] == 't')) {
      res[cur++] = 'g';  // cot
      i += 3;
    } else if (i + 3 < strlen(stroka) &&
               (stroka[i] == 's' && stroka[i + 1] == 'q' &&
                stroka[i + 2] == 'r' && stroka[i + 3] == 't')) {
      res[cur++] = 'k';  // sqrt
      i += 4;
    } else if (i + 1 < strlen(stroka) &&
               (stroka[i] == 'l' && stroka[i + 1] == 'n')) {
      res[cur++] = 'l';  // ln
      i += 2;
    } else {
      res[cur++] = stroka[i];
      i++;
    }
  }
  res[cur] = '\0';
  return res;
}

char *do_spaces(char *stroka) {
  char *res = malloc(strlen(stroka) * 2 * sizeof(char));
  int cur = 0;
  for (size_t i = 0; i < strlen(stroka); i++) {
    if (stroka[i] == '~') {
      if (stroka[i + 1] >= '0' && stroka[i + 1] <= '9') {
        res[cur++] = '-';
      } else if (stroka[i + 1] == 's' || stroka[i + 1] == 'c' ||
                 stroka[i + 1] == 'g' || stroka[i + 1] == 'l' ||
                 stroka[i + 1] == 'k' || stroka[i + 1] == 't' ||
                 (stroka[i - 1] == '(') || stroka[i + 1] == 'x' ||
                 (i == 0 && stroka[i + 1] == '(')) {
        res[cur++] = stroka[i];
        res[cur++] = ' ';
      } else {
        res[cur++] = '-';
      }
    } else if ((stroka[i] >= '0' && stroka[i] <= '9') || (stroka[i] == '.')) {
      res[cur++] = stroka[i];
      if (i + 1 < strlen(stroka) &&
          (stroka[i + 1] > '9' || stroka[i + 1] < '0') &&
          stroka[i + 1] != '.') {
        res[cur++] = ' ';
      }
    } else {
      res[cur++] = stroka[i];
      res[cur++] = ' ';
    }
  }
  res[cur] = '\0';
  return res;
}

char *ParseExpression(char *stroka, int *error) {
  char *res = delete_spaces(stroka);
  char *tmp = replace_unar_minus(res);
  res = tmp;
  tmp = replace_functions(res);
  res = tmp;
  tmp = do_spaces(res);
  free(res);
  res = tmp;
  *error = validate_data(res);
  return res;
}

int validate_data(const char *stroka) {
  int balance = 0, res = 1;
  for (int i = 0; stroka[i] != '\0'; i++) {
    if (stroka[i] == '(') {
      balance++;
    } else if (stroka[i] == ')') {
      balance--;
      if (balance < 0) {
        res = 0;
      }
    }
  }
  if (balance != 0) {
    res = 0;
  }
  return res;
}
