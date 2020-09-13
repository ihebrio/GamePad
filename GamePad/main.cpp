#include "linux/joystick.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_BUTTONS 10

struct js_event js[10];

int buttons[MAX_BUTTONS];

using namespace std;    


static void free_all(void)
{   

    printf("exited");
}

int processJoystick(struct js_event joystick[], int size){ 

    int sameTime = 0;
    int stButton[MAX_BUTTONS] = {0}

    printf("timestamp   value   type    button\n");

    for(int i = 0; i < MAX_BUTTONS; i++){
        printf("%d  ", joystick[i].time);
        printf("%d  ", joystick[i].value);
        printf("%d  ", joystick[i].type);
        printf("%d  \n", joystick[i].number);

        if(sameTime == joystick[i].time){
            stButton[joystick[i].number] = 1;
        }
        else{
            sameTime = joystick[i].time;
        }

    }





}


int main(){

    struct js_event myJoystick[MAX_BUTTONS];

    int fd = open("/dev/input/js0", O_RDONLY);
    int rd;


    while(1){
		while (read (fd, &myJoystick, sizeof(myJoystick)) > 0) {
			processJoystick(myJoystick, MAX_BUTTONS);
		}
		/* EAGAIN is returned when the queue is empty */
		if (errno != EAGAIN) {
            printf("Queue is empty\n");
			/* error */
		}    
    }
    atexit(free_all);
}