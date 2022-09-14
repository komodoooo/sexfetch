#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

void get_info(){
    struct utsname s;
    uname(&s);
    printf("System: %s, %s\n",s.sysname,s.version);
    printf("Kernel: %s\nCpu Architecture: %s\n",s.release,s.machine);
    printf("Hostname: %s\n",s.nodename);
    system("echo Ram: $(vmstat | awk 'END {printf $4}') Kb");
}

int main(){
    int pid = getpid();
    char * banner = "       __\n" "    .-'  |\n" 
                    "   /   <\\|\n" "  /     \\'\n" 
                    "  |_.- o-o\n" "  / C  -._)\\\n"
                    " /',        |\n" "|   `-,_,__,'\n"
                    "(,,)====[_]=|\n" "  '.   ____/\n"
                    "   | -|-|_\n" "   |____)_)";

    printf("%s\n\n", banner);
    system("cat /etc/issue");    //if it's a Linux distribution, returns the name
    get_info();
    const char * sexium[]={
        "",                     
        getenv("USER"),        //get enviroment variables
        getenv("SHELL"),
    };
    for (int i=1; i < 3; i++){     
        if (i == 1){
            printf("User: %s\n", sexium[i]);    //Spaghetti code time
        }else{
            printf("Shell: %s\n\n", sexium[i]);
        }   
    }
    printf("Current process id: %d\n\n", pid);
    return 0;
}
