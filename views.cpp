#include <stdio.h>
#include "controllers.h"

int patient, cure;

void takeInput();
void processOutput();

int main(){
	takeInput();
	
	return 0;
}

void takeInput(){
	scanf("%d %d", &patient, &cure); getchar();
	Patient p;
	for (int i = 0; i < patient; ++i){
		scanf("%d %s %d - %[^\n]", &p.dd, &p.monthName, &p.yy, &p.name);
		getchar();
		insertPatient(p);
	}
	processOutput();
}

void processOutput(){
	if (cure >= patient){
		printf("All patients get the cure, %d cure left\n", cure-patient);
		return;
	}
	printf("Need %d more cure\n", patient-cure);
	for (int i = 0; i < cure; ++i){
		dequeuePatient();
	}
	printPatientsLeft();
	popAll();
}
