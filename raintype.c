#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if(argc != 2)
  {
    fprintf(stderr, "Invalid number of arguments...\n\nUSAGE:\nraintype [file]\n");
    return 1;
  }
  
  char c;
  int color = 32;
  FILE *fp;
  
  fp = fopen(argv[1], "r");

  if(!fp)
  {
    perror("ERROR");
    return 1;
  }

  srand(time(0));
  
  for(;;) 
  {
    usleep(80000);
    
    c = fgetc(fp);
    if(c == EOF) break;

    if(c == ' ')
    {
      color = ((rand() % ((40 - 30))) + 30);
    }

    fprintf(stderr, "\x1b[%dm%c", color, c);
  }

  fclose(fp);
  
  printf("\n");
  return 0;
}
