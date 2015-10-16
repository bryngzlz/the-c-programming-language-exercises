/* 
 * Exercise 1-17 2nd version 
 * write a program that prints out the lines 
 * that are longer than 80 characters 
 */

#include <stdio.h>
#define MAXLINE 1000

int getline_x(char current[], int max);
void copy(char to[], char from[]); 
int copy_to_longest(char to[], char from[], int from_length, int id); 

/* testing */ 
int main() {
  int id; 
  int len;
  int max; 
  char line[MAXLINE];
  char longest[MAXLINE]; 
  char longer_than[MAXLINE];
  max = 0;
  id = 0; 
  while ((len = getline_x(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line); 
    }
    if (len > 80)
      id = copy_to_longest(longer_than, line, len, id); 
  }
  printf("%s", longer_than);
  if (max > 0)
    printf("\nlongest line: %s", longest);
  return 0; 
}

int getline_x(char current[], int max)
{
  int i, c;
  for (i = 0; i<max-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    current[i] = c;
  if (c == '\n') {
    current[i] = c; 
    ++i; 
  }
  current[i] = '\0';
  return i; 
}

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i])!='\0')
    ++i; 
}
 
 int copy_to_longest(char to[], char from[], int from_length, int id)
{
  int i, c, j; 
  for ((i=id) && (j=0); j<from_length &&(c=from[j])!='\n'; (++i)&&(++j))
    to[i] = c;
  if (c == '\n')
    to[i] = c;
  id = i+1;
  return id; 
}
