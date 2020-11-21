/***********************************************/
/* Author: Hend and Haitham */
/* Date: 11-11-2020*/
/* version: 1*/
/* Description: Implement of interfaces*/
/***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "STD_Types.h"
#include "clinic.h"


uint16 clinicU16NoOfPatients = 0;
uint32 clinicU32DefaultPassword = 1234;
Patient * patientInstant;
Patient * patientInstant2;
uint8 u8SizeOfSlots = 5;
uint16 u16NoOfCallingFun = 0;
static uint8 u8CounterLoc = 0;
TIMES timesGlo[5] = {{-1, "0. From 2pm to 2:30pm"}, 
					 {-1, "1. From 2:30pm to 3pm"},
					 {-1, "2. From 3pm to 3:30pm"},
					 {-1, "3. From 4pm to 4:30pm"},
					 {-1, "4. From 4:30pm to 5pm"}};
/* function for enter password*/
uint8 clinicU8EnterPassword(void){
	uint32 u32PasswordLoc;
	uint8  u8Counter;
		printf("Enter Password: \n ");
		fflush(stdin);
		scanf("%d",&u32PasswordLoc);
		fflush(stdin);
	for( u8Counter = 0; u8Counter < 2; u8Counter++){
		
		if(u32PasswordLoc == clinicU32DefaultPassword){
			printf("Correct Password.\n");
			break;
		}
		printf("Wrong Password Please Enter Password Again: \n ");
		fflush(stdin);
		scanf("%d",&u32PasswordLoc);
		fflush(stdin);
		
	}
	return u8Counter;
}

void clinicVoidAddPatient(){
	
	uint8 u8GenderLoc;
	uint8 u8IsExistLoc;
	uint16 u16AgeLoc;
	uint32 u32IdLoc;
	uint8 u8NameLoc[1000];
	
	for( ; u8CounterLoc < clinicU16NoOfPatients; u8CounterLoc++){
		printf("Enter Name: \n ");
		fflush(stdin);
		//gets(u8NameLoc);
		scanf("%[^\n]",&u8NameLoc);
		fflush(stdin);
		printf("Enter Age: \n ");
		fflush(stdin);
		scanf("%d",&u16AgeLoc);
		fflush(stdin);
		printf("Enter 1 for female or 2 for male : \n ");
		fflush(stdin);
		scanf("%d",&u8GenderLoc);
		fflush(stdin);
		printf("Enter ID: \n ");
		fflush(stdin);
		scanf("%d",&u32IdLoc);
		fflush(stdin);
		u8IsExistLoc = chechId(u32IdLoc);
		if(u8IsExistLoc){
		printf("ID already exist! \n");
		}else{
			if(u16NoOfCallingFun == 0 ){
				patientInstant[u8CounterLoc].u8GenderOfPatient = u8GenderLoc;
				patientInstant[u8CounterLoc].u8DesiredSlot = NULL; 
				patientInstant[u8CounterLoc].u16AgeOfPatient = u16AgeLoc;
				patientInstant[u8CounterLoc].u32IdOfPatient = u32IdLoc;
				clinicVoidcopyText(u8NameLoc, patientInstant[u8CounterLoc].u8NameOfPatient);
								

				
			}else{
				patientInstant2[u8CounterLoc].u8GenderOfPatient = u8GenderLoc;
				patientInstant2[u8CounterLoc].u8DesiredSlot = NULL;
				patientInstant2[u8CounterLoc].u16AgeOfPatient = u16AgeLoc;
				patientInstant2[u8CounterLoc].u32IdOfPatient = u32IdLoc;
				clinicVoidcopyText(u8NameLoc, patientInstant2[u8CounterLoc].u8NameOfPatient);
				
			}
		
		}
		system("cls");
		
	}
	
	u16NoOfCallingFun++;
	
	
	 
}
/* for copy text in another text*/
void clinicVoidcopyText(uint8 u8Txt1Cpy[1000],uint8 u8Txt2Cpy[1000]){
    uint8 u8CounterOfCopyTxt;
    for(u8CounterOfCopyTxt = 0; u8Txt1Cpy[u8CounterOfCopyTxt]!='\0'; u8CounterOfCopyTxt++){
        u8Txt2Cpy[u8CounterOfCopyTxt]=u8Txt1Cpy[u8CounterOfCopyTxt];
    }
}
uint8 chechId(uint32 u32IdCpy){
	
	uint8 u8ExistLoc = 0 ;
	uint8 u8CounterOfCheckId;
	for( u8CounterOfCheckId = 0; u8CounterOfCheckId < clinicU16NoOfPatients ; u8CounterOfCheckId++){
		if(u16NoOfCallingFun == 0 || u16NoOfCallingFun == 1){
			
			if(patientInstant[u8CounterOfCheckId].u32IdOfPatient == u32IdCpy){
				
				u8ExistLoc = 1;
				break;
			}
		}else{
			
			if(patientInstant2[u8CounterOfCheckId].u32IdOfPatient == u32IdCpy){
			u8ExistLoc = 1;
			break;
		}
	}
	}
	return u8ExistLoc;
}
void clinicVoidEditPatient(uint32 u32IDCpy){
	
    uint8 u8Index,u8IndexOfPatient;
    uint8 result = chechId(u32IDCpy);
    if(result){
     u8IndexOfPatient =  u8GetIndexOfPatient(u32IDCpy);
		 if(u16NoOfCallingFun == 1){
		
				printf("Enter 1 for female or 2 for male : \n ");
				fflush(stdin);
				scanf("%d",&patientInstant[u8IndexOfPatient].u8GenderOfPatient);
				fflush(stdin);
				printf("Enter Age: \n ");
				fflush(stdin);
				scanf("%d",&patientInstant[u8IndexOfPatient].u16AgeOfPatient);
				fflush(stdin);
				printf("Enter Name: \n ");
				fflush(stdin);
				gets(patientInstant[u8IndexOfPatient].u8NameOfPatient);
				fflush(stdin);
				system("cls");
				}else{
				
				printf("Enter 1 for female or 2 for male : \n ");
				fflush(stdin);
				scanf("%d",&patientInstant2[u8IndexOfPatient].u8GenderOfPatient);
				fflush(stdin);
				printf("Enter Age: \n ");
				fflush(stdin);
				scanf("%d",&patientInstant2[u8IndexOfPatient].u16AgeOfPatient);
				fflush(stdin);
				printf("Enter Name: \n ");
				fflush(stdin);
				gets(patientInstant2[u8IndexOfPatient].u8NameOfPatient);
				fflush(stdin);
				system("cls");
				}
      
    }else{
    printf("Incorrect ID\n");
    }


}
uint8 u8GetIndexOfPatient(uint32 u32IdOfPatientCpy){
	uint8 u8Index;
	 for(u8Index = 0; u8Index < clinicU16NoOfPatients; u8Index++){
			
			if(u16NoOfCallingFun == 0 ||u16NoOfCallingFun == 1 ){
				if(patientInstant[u8Index].u32IdOfPatient == u32IdOfPatientCpy){
                return u8Index;
				
				}
			}else{
				if(patientInstant2[u8Index].u32IdOfPatient == u32IdOfPatientCpy){
                return u8Index;
				
				}
			}
		 }
}
void clinicVoidShowTimeSlots(TIMES * times, Patient * p){
	uint32 u32IdOfCheckTimes;
	uint8 u8Slot, u8IndexOfPatientTimes;
	uint8 result, u8CounterOfTimes;
    printf("**************************\n");
    printf("The Available slots are: \n");
	for(u8CounterOfTimes = 0; u8CounterOfTimes < 5; u8CounterOfTimes++){
        if(times[u8CounterOfTimes].IDtime == -1){
        printf("%s\n",times[u8CounterOfTimes].slot);
        }
    }
    printf("**************************\n");
    printf("Enter the desired slot then the patient's ID : \n");
	fflush(stdin);
    scanf("%d",&u8Slot);
	fflush(stdin);
	
	fflush(stdin);
    scanf("%d",&u32IdOfCheckTimes);
	fflush(stdin);
	
	result = chechId(u32IdOfCheckTimes);
		u8IndexOfPatientTimes =  u8GetIndexOfPatient(u32IdOfCheckTimes);
    if(result){
			if(p[u8IndexOfPatientTimes].u8DesiredSlot == NULL ) {
							
            times[u8Slot].IDtime = 1;
			p[u8IndexOfPatientTimes].u8DesiredSlot = times[u8Slot].slot;
			printf("Appointment Reserved! \n");
			delay(1.5);
		    }else {
				
                printf("This patient already has an appointment!\n");
            }
        
	}else{
		printf("Id Wrong!\n");
	}
	
	}
void clinicVoidCancelReservation(TIMES * time, Patient * p){
		uint8 check, u8IndexOfPatientCanceling;
		uint32 u32IdForCancel, counterOfSlots;
		printf("Enter the patient's ID: \n");
		fflush(stdin);
		scanf("%d",&u32IdForCancel);
		fflush(stdin);
		check = chechId(u32IdForCancel);
		u8IndexOfPatientCanceling =  u8GetIndexOfPatient(u32IdForCancel);
		if(check){
		 printf("Correct ID: \n");
		 delay(1.5);
        for(counterOfSlots = 0; counterOfSlots < 5; counterOfSlots++)
        {
				
				if(p[u8IndexOfPatientCanceling].u8DesiredSlot == NULL){
					printf("You have not slot! \n");
					delay(2);
					return;
				}
            if(p[u8IndexOfPatientCanceling].u8DesiredSlot == time[counterOfSlots].slot)
            {
                time[counterOfSlots].IDtime=-1;
				p[u8IndexOfPatientCanceling].u8DesiredSlot = NULL;
                printf("Reservation Canceled Successfully! \n");
                delay(1.5);
                system("cls");
                break;

            }

        }
	}else{
		printf("Wrong ID!\n");
        delay(1.5);
        system("cls");
		}


}
void viewPatientRecord(Patient * p){
	uint8 check, u8IndexOfPatientView;
	uint32 u32IdViewRecord;
	printf("Enter your ID, Please: \n");
	fflush(stdin);
    scanf("%d",&u32IdViewRecord);
	fflush(stdin);
	check = chechId(u32IdViewRecord);
	u8IndexOfPatientView =  u8GetIndexOfPatient(u32IdViewRecord);
	if(check)
    {
        printf("The name of the patient is: %s\n",p[u8IndexOfPatientView].u8NameOfPatient);
		
        printf("The age of the patient is: %d\n",p[u8IndexOfPatientView].u16AgeOfPatient);
		
        (p[u8IndexOfPatientView].u8GenderOfPatient == 1)? printf("The Patient is a Female\n") : printf("The Patient is a Male\n");
        (p[u8IndexOfPatientView].u8DesiredSlot != NULL)? printf("You a Reservation at: %s\n",p[u8IndexOfPatientView].u8DesiredSlot) : printf("No Reservations found! \n");
        delay(7);

    }
    else
    {
        printf("Wrong ID!!\n");
    }

    system("cls");
}

void viewReservations(Patient * p)
{
    uint8 count;
    for(count = 0; count < clinicU16NoOfPatients; count++)
    {
        (p[count].u8DesiredSlot != NULL)? printf("[ID= %d]: You a Reservation at: %s\n",
		p[count].u32IdOfPatient,p[count].u8DesiredSlot) :
		printf("[ID= %d]: No Reservations found! \n",p[count].u32IdOfPatient);

    }
    delay(7);

}
	
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);

}
/* function for show options for features*/
void clinicVoidShowOptions(void){
	uint16 n;
	uint8 u8InputOptionLoc2;
	uint32 u32IDLoc;
    printf("Choose one of the following features: \n");
    printf("*************************************\n");
    printf("1. Add new patient\n2. Edit patient record\n3. Reserve an appointment with a doctor\n4. Cancel reservation\n5. Switch to user mode\n6. Exit Program\n");
	scanf("%d",&u8InputOptionLoc2);
					switch(u8InputOptionLoc2){
						case 1:{/*Add Patient*/
						
							printf("Enter number of patients: \n");
							fflush(stdin);
							scanf("%d",&n);
							fflush(stdin);
							clinicU16NoOfPatients = (clinicU16NoOfPatients + n);
							if(u16NoOfCallingFun == 0){
								
								patientInstant = (Patient *) malloc((clinicU16NoOfPatients ) * sizeof(Patient));
								if(patientInstant == ((void*)0)){
								printf("null pointer\n");
								}
							}else{
								
								patientInstant2 = (Patient *) realloc(patientInstant,(clinicU16NoOfPatients ) * sizeof(Patient));
								
							}
							
							system("cls");
							clinicVoidAddPatient();
							system("cls");
							clinicVoidShowOptions();
							clinicVoidAddPatient(patientInstant);
							
							break;
						}
						case 2:{
							
							printf("Enter your ID: \n");
                            fflush(stdin);
							scanf("%d",&u32IDLoc);
							fflush(stdin);
                            clinicVoidEditPatient(u32IDLoc);
                            system("cls");
                            clinicVoidShowOptions();
							break;
						}
						case 3:{
							
							system("cls");
							if(u16NoOfCallingFun == 0 || u16NoOfCallingFun == 1 ){
								clinicVoidShowTimeSlots(timesGlo,patientInstant);
							}else{
								clinicVoidShowTimeSlots(timesGlo,patientInstant2);
							}
							
							system("cls");
							clinicVoidShowOptions();
							break;
						}
						case 4:{
							system("cls");
							if(u16NoOfCallingFun == 0 || u16NoOfCallingFun == 1 ){
								clinicVoidCancelReservation(timesGlo,patientInstant);
							}else{
								clinicVoidCancelReservation(timesGlo,patientInstant2);
							}
							system("cls");
							clinicVoidShowOptions();
							
							break;
						}case 5:{
							uint8 input;

							printf("************************************\n");
							printf("Choose one of the following options: \n");

							printf("1. View Patient Record.\n2. View today's Reservations.\n");
							printf("************************************\n");
							fflush(stdin);
							scanf("%d",&input);
							fflush(stdin);
								switch(input)
								{

								case 1:{
							    system("cls");
							    if(u16NoOfCallingFun == 0 || u16NoOfCallingFun == 1 ){
								viewPatientRecord(patientInstant);
							    }else{
								viewPatientRecord(patientInstant2);	
								}
							    system("cls");
							    clinicVoidShowOptions();
									break;
                                }case 2:{
									system("cls");
									if(u16NoOfCallingFun == 0 || u16NoOfCallingFun == 1 ){
									viewReservations(patientInstant);
									}else{
									viewReservations(patientInstant2);
									}
								system("cls");
								clinicVoidShowOptions();
									break;

								}
								default :
								{

									printf("Wrong entery!\n");

								}
								}


							}
						default:{
							 system("cls");
							 printf("Wrong entry, please enter 1, 2, 3, 4 or 5\n");
							 printf("Out of program\n");
							 free(patientInstant);
							 free(patientInstant2);
					         return;
						}
					}
	}













