#include "models.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

char monthName[14][50] = {
	"null",
	"january",
	"february",
	"march",
	"april",
	"may",
	"june",
	"july",
	"august",
	"september",
	"october",
	"november",
	"december"};

int setMonthNumber(Patient p){
	for (int i = 1; i <= 12; ++i){
		if (strcmp(monthName[i],p.monthName) == 0){
			p.mm = i;
			return i;
		}
	}
	return 0;
}

long long int getDOB(Patient p){
	long long int dob = (long long int)(p.dd + p.mm*100 + p.yy*10000);
	return dob;
}

Node* createNewNode(Patient p){
	Node* curr = (Node*)malloc(sizeof(Node));
	curr->p.dd = p.dd;
	curr->p.mm = setMonthNumber(p);
	curr->p.yy = p.yy;
	curr->p.dobInNumber = getDOB(p);
	strcpy(curr->p.name, p.name);
	strcpy(curr->p.monthName, p.monthName);
	curr->next = curr->prev = NULL;
	return curr;
}

void insertPatient(Patient p){
	curr = createNewNode(p);
	if (!head){
		head = tail = curr;
		head->next = head->prev = NULL;
	}
	else{
		if (curr->p.dobInNumber < head->p.dobInNumber){
			curr->next = head;
			head->prev = curr;
			head = curr;
			head->prev = NULL;
		}
		else if (curr->p.dobInNumber >= tail->p.dobInNumber){
			tail->next = curr;
			curr->prev = tail;
			tail = curr;
			tail->next = NULL;
		}
		else{
			Node* temp = head;
			while(temp->next->p.dobInNumber <= curr->p.dobInNumber){
				temp = temp->next;
			}
			curr->next = temp->next;
			temp->next->prev = temp->next = curr;
			curr->prev = temp;
		}
	}
}

void dequeuePatient(){
	if (head == tail){
		head = tail = NULL;
		free(head);
	}
	else{
		curr = head;
		head = head->next;
		curr = NULL;
		free(curr);
	}
}

void printPatientsLeft(){
	curr = head;
	while(curr){
		printf("%d %s %d - %s\n", curr->p.dd, curr->p.monthName, curr->p.yy, curr->p.name);
		curr = curr->next;
	}
}

void popAll(){
	while(head){
		dequeuePatient();
	}
}