#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

void get_info(){
    struct utsname s;
    uname(&s);
    printf("System: %s, %s\n",s.sysname,s.version);
    printf("Hostname: %s\n",s.nodename);
    printf("Kernel: %s\nCpu: %s\n",s.release,s.machine);
}

int main(){
    char * banner = "       __\n" "    .-'  |\n" 
                    "   /   <\\|\n" "  /     \\'\n" 
                    "  |_.- o-o\n" "  / C  -._)\\\n"
                    " /',        |\n" "|   `-,_,__,'\n"
                    "(,,)====[_]=|\n" "  '.   ____/\n"
                    "   | -|-|_\n" "   |____)_)";
    printf("%s\n\n", banner);
    system("cat /etc/issue");    //if linux distribution return the name
    get_info();
    const char * sexium[]={
        "",                     
        getenv("USER"),        //get enviroment variables
        getenv("SHELL"),
    };
    for (int i=0; i < 3; i++){     //i do this to avoid segmentation fault
        if (i == 1){
            printf("User: %s\n", sexium[i]);
        }
        if (i == 2){
            printf("Shell: %s\n\n", sexium[i]);
        }   
    }
    return 0;
}
