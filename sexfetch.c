#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

void get_info(){
    system("cat /etc/issue");  //if it's a Linux distribution, returns the name
    struct utsname s;
    uname(&s);
    printf("System: %s, %s\n",s.sysname,s.version);
    printf("Kernel: %s\nCpu Architecture: %s\n",s.release,s.machine);
    printf("Hostname: %s\n",s.nodename);
    system("echo Ram: $(vmstat | awk 'END {printf $4}') Kb"); //get the ram
    const char * sexium[]={ 
        "User",
        "Home path",
        "Shell"
    };                                //dirty codes go! brrr
    const char * envs[]={
        getenv("USER"),
        getenv("HOME"), 
        getenv("SHELL")
    };
    for(int i = 0; i < 3; i++){
        printf("%s: %s\n", sexium[i], envs[i]);
    }
    printf("\nCurrent process id: %d\n\n", getpid());
}

int main(){ 
    char * banner = "       __\n" "    .-'  |\n" 
                    "   /   <\\|\n" "  /     \\'\n"      //very smart logo
                    "  |_.- o-o\n" "  / C  -._)\\\n"
                    " /',        |\n" "|   `-,_,__,'\n"
                    "(,,)====[_]=|\n" "  '.   ____/\n"
                    "   | -|-|_\n" "   |____)_)";
    printf("\r%s\n\n", banner);  
    get_info();
    return 0;
}
