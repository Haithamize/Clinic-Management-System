#ifndef CLINIC_H_INCLUDED
#define CLINIC_H_INCLUDED
#include "STD_TYPES.h"
#include <time.h>
typedef struct {
	char name[16];
	int age;
	char gender;
	int ID;
	char*desiredSlot;


}Patient;

typedef struct{
    int IDtime;
    char*slot;

}TIME;
uint8 clinicU8EnterPassword(void);
void clinicVoidAddPatient(Patient * patientCpy,int index);
char chechId(int idCpy, Patient * p,int index);
void clinicVoidShowOptions(void);
void copyText(char txt1[50],char txt2[50]);
void clinicVoidEditPatient(int ID,int index);
void showTimeSlots(index,times,patient);
void userOptions(Patient*p ,int index);
void delay(int number_of_seconds);
void cancelReservation(TIME*t,Patient*p,int index);
void viewReservations(void);

#endif // CLINIC_H_INCLUDED
