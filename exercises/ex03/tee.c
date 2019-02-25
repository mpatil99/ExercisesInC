/* implementation of Unix command tee

Manu Patil
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

int main (int argc, char* argv[]){
  char ch;
  int append = 0;
  char in[512];
  FILE *outFile;
  int i = 0;

  while((ch = getopt(argc,argv, "ai")) != EOF){
    switch(ch){
      case 'a':
      append = 1;
      break;

      case 'i':
      //try later

      break;

      default:
      fprintf(stderr, "Unknown option: '%s'\n", optarg);
      return 1;
    }
  }

  argc -= optind;
  argv += optind;


  while(fgets(in, 512, stdin)){
   for(i=0; i<argc; i++){
     if(!append){
       outFile = fopen(argv[i], "w");
       append = 1;
     }
     else{
       outFile = fopen(argv[i], "a");
     }

     fputs(in, outFile);

     fclose(outFile);
   }
   fprintf(stdout, "%s", in);
 }

return 0;
}
