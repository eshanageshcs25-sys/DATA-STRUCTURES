#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isValid(char*s){
    int len=strlen(s);
    if(len%2!=0){
        return false;
    }
    char* stack=(char*)malloc(len*sizeof(char));
    int top=-1;
    for(int i=0;i<len;i++){
        char ch=s[i];
        if(ch=='('||ch=='{'||ch=='['){
        stack[++top]=ch;
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if(top==-1){
                free(stack);
                return false;
            }
            char topchar=stack[top];
            if((ch==')'&&topchar!='(') || (ch=='}'&&topchar!='{') || (ch==']'&&topchar!='[')){
                free(stack);
                return false;
            }
            top--;
        }
    }
    bool result=(top==-1);
    free(stack);
    return result;
}
int main(){
    char s1[]="()[]{}";
    char s2[]="(]";
    char s3[]="[)]";
    char s4[]="{[]}";
    printf("\"%s\"->%s\n",s1,isValid(s1)?"true":"false");
    printf("\"%s\"->%s\n",s2,isValid(s2)?"true":"false");
    printf("\"%s\"->%s\n",s3,isValid(s3)?"true":"false");
    printf("\"%s\"->%s\n",s4,isValid(s4)?"true":"false");
    return(0);
}
