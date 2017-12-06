#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#define KEY 010600
void create_s(char *N){
  int val;
  val = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0664);
  if(val==-1){
    printf("Semaphore not created. Already exists.\n");
  }
  else{
    int n;
    scanf(N, "%d", &n);
    semctl(val, 0, SETVAL, n);
    printf("Semaphore with ID %d and value %s created. \n", val, N);
  }
}

void remove_s(){
  int val;
  val = semget(KEY,0,0);
  printf("Removed sempahore: %d\n", semctl(val, 0, IPC_RMID));
}
void s_val(){
  int val;
  val = semget(KEY, 0,0);
  printf("Semaphore value is: %d \n", semctl(val,0, GETVAL));
}

int main(int argc, char ** argv){
  if (argc< 2){
    printf("Not enough arguments. Failed.\n");
  }
  else{
    if(strcmp(argv[1], "-r")==0){
      remove_s();
    }
    if(strcmp(argv[1], "-v")==0){
      s_val();
    }
    if(strcmp(argv[1],"-c")==0 && !(argc <3)){
      create_s(argv[2]);
    }
    else {
      printf("Invalid arguments. Failed.\n");
    }
  }
  return 0;
}





