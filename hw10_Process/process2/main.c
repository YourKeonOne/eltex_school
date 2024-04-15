#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define status_count 5 // тут будет находиться кол-во статусов процессов
#define pid_count 5 // тут будет находиться кол-во процессов

//  строки 20-50 - порождается процесс 2, который создаст в себе процесс 5
//  строки 27-42 - порождается процесс 5
//	строки 59-105 - порождается процесс 1, который создаст в себе процесс 3 и процесс 4
//  строки 68-82 - порождается процесс 3
//  строки 83-97 - порождается процесс 4

int main(){
	
	pid_t process[pid_count]; // массив процессoв
	int status[status_count]; // массив статусов
	
	// порождается pid2, который будет создавать пид5
	switch(process[1]=fork()){ 
		case -1:
			perror("fork == -1");
			exit(1);
		break;
		case 0: 
			// порождаеся pid5
			switch(process[4]=fork()){
			case -1:
				perror("fork == -1");
				exit(1);
			break;
			case 0:
				printf("\n|Дочерний5| pid5 = %d\n", getpid());
				exit(status[4]);
			break;
			default:
				wait(NULL);
				printf("\n|Дочерний2| pid2 = %d \n", getpid());
			break;
			}
			//-----------------------------
			exit(status[1]);
		break;
		default:
			wait(NULL);
			printf("\n|Родитель| pid = %d\n", getpid());
		break;
	}	
    //----------------------------------
	
	
	
	
	printf("\n#############################################################\n");
	
	
	
	// порождается pid1, который будет создавать pid3 и pid4
	switch(process[0]=fork()){ 
		case -1:
			perror("fork == -1");
			exit(1);
		break;
		case 0: 
		    printf("\n|Дочерний1| pid1 = %d \n", getpid());
			
			// порождаеся pid3
			switch(process[2]=fork()){
			case -1:
				perror("fork == -1");
				exit(1);
			break;
			case 0:
				printf("\n|Дочерний3| pid3 = %d\n", getpid());
				exit(status[2]);
			break;
			default:
				wait(NULL);
			break;
			}
			//-----------------------------
			// порождаеся pid4
			switch(process[3]=fork()){
			case -1:
				perror("fork == -1");
				exit(1);
			break;
			case 0:
				printf("\n|Дочерний4| pid4 = %d\n", getpid());
				exit(status[3]);
			break;
			default:
				wait(NULL);
			break;
			}
			//-----------------------------
			exit(status[0]);
		break;
		default:
			wait(NULL);
			printf("\n|Родитель| pid = %d\n", getpid());
		break;
	}	
	//----------------------------


	return 0;
}