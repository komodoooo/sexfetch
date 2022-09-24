#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#define RESET "\e[0m"       //reset colors

void get_info(){
    system("cat /etc/issue");  //if it's a Linux distribution, returns the name
    struct utsname s;
    uname(&s);
    printf("System: %s\nVersion: %s\n",s.sysname,s.version);
    printf("Kernel: %s\nCpu Architecture: %s\n",s.release,s.machine);
    printf("Hostname: %s\n",s.nodename);
    system("echo Ram: $(vmstat | awk 'END {printf $4}') Kb"); //get the ram
    system("echo User: $(id -u -n)");          //no whoami
    const char * sexium[]={ 
        "Terminal",
        "Home path",
        "Shell"
    };                                //dirty codes go! brrr
    const char * envs[]={
        getenv("TERM"),
        getenv("HOME"), 
        getenv("SHELL")
    };
    for(int i = 0; i < 3; i++){
        printf("%s: %s\n", sexium[i], envs[i]);
    }
    printf("\nCurrent process id: %d\n\n", getpid());
    RESET;
}

int main(){
    printf("\e[1;93m" "\r\n       ⣿⣿\n"
        "⠀⠀⠀⠀⠀⢀⣀⣿⣿⣀⡀\n""⠀⠀⠀⠀⠀⠈⣹⠟⠻⣏⠁\n"          //very smart logo
    "⠀⠀⠀⠀⠀⣼⣯⣴⣦⣽⣧\n""⢠⣤⠀⢀⣼⡟⠁⢰⡆⠈⢻⣧⡀⠀⣤⡄\n"
    "⠸⠿⢿⡿⠋⠻⢦⣌⣡⡴⠟⠙⢿⡿⠿⠇\n""⠀⢀⣿⣁⣀⣀⣀⣉⣉⣀⣀⣀⣈⣿⡀\n"
    "⠀⠉⠉⠉⠉⣿⠉⠉⠉⠉⢹⡏⠉⠉⠉\n""⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠈⠉⠁\n"
    RESET "\e[1;96m");
    get_info();
    return 0;
}
