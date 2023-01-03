#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudRecord {
  char name[50];
  int id;
  int age;
  int major;
};

int main() {
  struct StudRecord *pStudentRecord;
  pStudentRecord = (struct StudRecord *)malloc(sizeof(struct StudRecord));

  strcpy(pStudentRecord->name, "Jane Doe");
  pStudentRecord->id = 903107;
  pStudentRecord->age = 20;
  pStudentRecord->major = 643;

  printf("Name of student: %s\n", pStudentRecord->name);
  printf("Her age: %d\n", pStudentRecord->age);

  return 0;
}

