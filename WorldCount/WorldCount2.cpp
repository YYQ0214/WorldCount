#include <stdio.h>
#include <string.h>
#include<malloc.h>
int countw(char *filename);
int countc(char *filename);
 int countl(char *filename); 

int main(int argc,char* argv[]){
	char filname[30];
	char operation;
	int totalline;//???
	int toalchar;//????
	int totalword;//????
      if(!strcmp(argv[1],"-w")) 
        countw(argv[2]);                
        else if(!strcmp(argv[1],"-c"))  
		
        countc(argv[2]);                
        else if(!strcmp(argv[1],"-l"))    
        countl(argv[2]);            
        return 0;
}

int countw(char *filename){
 FILE *fp=NULL;  
 FILE *fp2=NULL;
    char buffer[1003];  
    int bufferLen;  
    int i;  
    char c;  
    int isLastBlank = 0;  
   int totalword=0;
    int wordNum = 0; 
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
   
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  
                !isLastBlank && wordNum++; //????????,???????????+1 
                isLastBlank = 1;//??????
            }else if(c!='\n'&&c!='\r'){  
                  
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  
        isLastBlank = 1;  
        totalword += wordNum;  
        wordNum = 0;
    }
    printf("totalword:%d ",totalword);
	fp2=fopen("result.txt","a");
	if(fp2){
	fprintf(fp2,"????:%d\n",totalword);
	fclose(fp2);
	}
		return 0;
}
	

int countc(char *filename){
	
	 FILE *fp=NULL;
	FILE *fp2=NULL;  
    char buffer[1003];  
    int bufferLen;  
    int i;  
    char c;  
    int isLastBlank = 0; 
	int totalchar=0;
    int charNum = 0;  
      if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
	  }
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  
               isLastBlank = 1;//???????
            }else if(c!='\n'&&c!='\r'){  
                charNum++;  
                isLastBlank = 0;
            }
        }
       
        isLastBlank = 1;  
        
        totalchar += charNum;  
        
        charNum = 0;
        
    }
    printf("totalchar:%d",totalchar);
	fp2=fopen("result.txt","a");
	if(fp2){
	fprintf(fp2,"????:%d\n",totalchar);
	fclose(fp2);
	}
		return 0;
}

int countl(char *filename){
FILE *fp=NULL;  
FILE *fp2=NULL;
    char buffer[1003];  
    int bufferLen;  
    int i;  
    char c;  
    int totalline=-1;
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
   
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        for(i=0; i<bufferLen; i++){
            c=buffer[i];
            if(c=='\n'||c=='\r'){ 
             totalline++;    
            
		  }
		}
	}
        printf("totalline:%d",totalline);
	fp2=fopen("result.txt","a");
	if(fp2){
	fprintf(fp2,"???:%d\n",totalline);
	fclose(fp2);
	}
		return 0;

}

