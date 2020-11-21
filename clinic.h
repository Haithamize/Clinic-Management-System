/***********************************************/
/* Author: Hend and Haitham */
/* Date: 11-11-2020*/
/* version: 1*/
/* Description: Interfaces*/
/***********************************************/


#include "STD_Types.h"
typedef struct{
    uint32 IDtime;
    uint8 * slot;

}TIMES;
typedef struct {
	uint8 u8IndexOfPatientStruct;
	uint32 u32IdOfPatient;
	
}CheckAndReturnIndex;
typedef struct {
	uint8 u8GenderOfPatient;
	uint8  *u8DesiredSlot;
	uint16 u16AgeOfPatient;
	uint32 u32IdOfPatient;
	uint8 u8NameOfPatient[1000];
	
	
}Patient;

uint8 clinicU8EnterPassword(void);
void clinicVoidShowOptions(void);
uint8 chechId(uint32 u32IdCpy);
void clinicVoidAddPatient();
void clinicVoidEditPatient(uint32 u32IDCpy);
void clinicVoidcopyText(uint8 u8Txt1Cpy[1000],uint8 u8Txt2Cpy[1000]);
uint8 u8GetIndexOfPatient(uint32 u32IdOfPatientCpy);
void clinicVoidShowTimeSlots(TIMES * times, Patient * p);
void clinicVoidCancelReservation(TIMES * time, Patient * p);
void viewPatientRecord(Patient * p);
void viewReservations(Patient * p);
void delay(int number_of_seconds);
