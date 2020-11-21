#include <stdio.h>
#include <stdlib.h>
#include "clinic.h"
#include "STD_TYPES.h"
#include <time.h>

/*****************/
/* Author: Hend and Haitham */
/* Date: 11-11-2020*/
/* version: 1*/
/* Description: Implement of interfaces*/
/*****************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "clinic.h"

uint32 u32DefaultPasswordLoc = 1234;
Patient patient[5];
TIME times[5]= {{-1,"0. From 2pm to 2:30pm"}, {-1,"1. From 2:30pm to 3pm"},{-1,"2. From 3pm to 3:30pm"},{-1,"3. From 4pm to 4:30pm"},{-1,"4. From 4:30pm to 5pm"}};
int index;

/* function for enter password*/
uint8 clinicU8EnterPassword(void)
{
    uint32 u32PasswordLoc;
    uint8  u8Counter;
    printf("Enter Password: \n ");
    fflush(stdin);
    scanf("%d",&u32PasswordLoc);
    fflush(stdin);
    for( u8Counter = 0; u8Counter < 2; u8Counter++)
    {

        if(u32PasswordLoc == u32DefaultPasswordLoc)
        {
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

void clinicVoidAddPatient(Patient * patientCpy,int index)
{
    static char counter;
    static char n[16];
    static int agePatient;
    char gen;
    int id;
    char res;

    for(counter = 0; counter < index ; counter++)
    {
        printf("Enter Name: \n ");
        fflush(stdin);
        gets(n);
        fflush(stdin);
        printf("Enter Age: \n ");
        fflush(stdin);
        scanf("%d",&agePatient);
        fflush(stdin);
        printf("Enter 1 for female or 2 for male : \n ");
        fflush(stdin);
        scanf("%d",&gen);
        fflush(stdin);
        printf("Enter ID: \n ");
        fflush(stdin);
        scanf("%d",&id);
        fflush(stdin);
        res = chechId(id,&patientCpy[0],index);
        if(res)
        {
            printf("id already exist\n");
        }
        else
        {

            copyText(n,patientCpy[counter].name);
            patientCpy[counter].age =agePatient;
            patientCpy[counter].gender = gen;
            patientCpy[counter].ID = id;


        }
        system("cls");
    }


}
char chechId(int idCpy, Patient * p,int index)
{
    char exist = 0 ;
    for(int i = 0; i < index; i++)
    {
        if(p[i].ID == idCpy)
        {
            exist = 1;
            break;
        }
    }
    return exist;
}


/* function for show options for features*/
void clinicVoidShowOptions(void)
{
    int static ID;
    uint8 u8InputOptionLoc2;
    printf("Choose one of the following features: \n");
    printf("*************\n");
    printf("1. Add new patient\n2. Edit patient record\n3. Reserve an appointment with a doctor\n4. Cancel reservation\n5. Switch to user mode\n");
    scanf("%d",&u8InputOptionLoc2);
    switch(u8InputOptionLoc2)
    {
    case 1:     //Add patient
    {

        printf("Enter number of patients: \n");
        fflush(stdin);
        scanf("%d",&index);
        fflush(stdin);
        system("cls");
        clinicVoidAddPatient(&patient[0],index);
        system("cls");
        clinicVoidShowOptions();

        break;
    }
    case 2:     //Edit patient record
    {
        printf("Enter your ID: \n");
        fflush(stdin);
        scanf("%d",&ID);
        fflush(stdin);
        clinicVoidEditPatient(ID,index);
        system("cls");
        clinicVoidShowOptions();
        break;
    }
    case 3:     //reserve appointment
    {

        system("cls");
        showTimeSlots(index,times,patient);
        clinicVoidShowOptions();
        break;
    }
    case 4:  //cancel reservation
    {

        cancelReservation(times,patient,index);

        clinicVoidShowOptions();
        break;
    }
    case 5:  //switch to user mode
    {
        int input;

        printf("***************************\n");
        printf("Choose one of the following options: \n");

        printf("1. View Patient Record.\n2. View today's Reservations.\n");
         fflush(stdin);
         scanf("%d",&input);
         fflush(stdin);
        switch(input)
        {

        case 1:
        {
            userOptions(patient,index);
            clinicVoidShowOptions();
            break;

        }

        case 2:
        {
            viewReservations();
            break;

        }
        default :
        {

            printf("Wrong entery!\n");

        }
        }


    }

    default:
    {
        system("cls");
        printf("Wrong entry, please enter 1, 2, 3, 4 or 5\n");
        clinicVoidShowOptions();
    }


    }
}

void copyText(char txt1[50],char txt2[50])
{
    int i;
    for(i=0; txt1[i]!='\0'; i++)
    {
        txt2[i]=txt1[i];
    }
}
void clinicVoidEditPatient(int IDLoc,int index)
{

    int i,indexOfPatient;
    char result = chechId(IDLoc,&patient,index);
    if(result)
    {
        for(i=0; i<index; i++)
        {
            if(patient[i].ID==IDLoc)
            {
                indexOfPatient=i;
            }
        }
        printf("Enter Name: \n ");
        fflush(stdin);
        gets(patient[indexOfPatient].name);
        fflush(stdin);
        printf("Enter Age: \n ");
        fflush(stdin);
        scanf("%d",&patient[indexOfPatient].age);
        fflush(stdin);
        printf("Enter 1 for female or 2 for male : \n ");
        fflush(stdin);
        scanf("%d",&patient[indexOfPatient].gender);
        fflush(stdin);

        system("cls");


    }
    else
    {
        printf("Incorrect ID\n");
        delay(1.5);
    }


}
void showTimeSlots(int index,TIME*slots, Patient*p)  //reserve appointment
{
    int ID,slot,ind,i;


    char check;
    printf("***********************\n");
    printf("The Available 5 slots are: \n");

    for(i=0; i<5; i++)
    {
        if(slots[i].IDtime==-1)
        {
            printf("%s\n",slots[i].slot);
        }
    }
    printf("***********************\n");
    printf("Enter the patient's ID then the desired slot: \n");
    scanf("%d",&ID);

    scanf("%d",&slot);
    ind = retrunIndexOfPatient(ID,index);

    check= chechId(ID,p,index);


    if(check)
    {
        if(patient[ind].desiredSlot==(void *)0)  //5allet de b 0 3shan hya char w not initialized hatb2a b 0
        {
            slots[slot].IDtime=1;
            //patient[ind].IDcancel=1;


            patient[ind].desiredSlot=slots[slot].slot;
            printf("Appointment Reserved!");
            delay(1.5);


        }
        else
        {
            printf("This patient already has an appointment!\n");
        }


    }
    else
    {
        printf("Wrong ID!!\n");
        delay(1.5);

    }
    system("cls");

}

int retrunIndexOfPatient(int ID2,int index)
{
    int i;
    char result = chechId(ID2,&patient,index);
    if(result)
    {
        for(i=0; i<index; i++)
        {
            if(patient[i].ID==ID2)
            {
                return i;
            }
        }

    }

}

void cancelReservation(TIME*t,Patient*p,int index)
{
    int id,ind1,i;
    char check;
    printf("Enter the patient's ID: \n");
    scanf("%d",&id);

    check= chechId(id,p,index);
    ind1 = retrunIndexOfPatient(id,index);
    if(check)
    {
        printf("Correct ID: \n");
        delay(1.5);
        for(i=0; i<5; i++)
        {
            if(p[ind1].desiredSlot==t[i].slot)
            {
                t[i].IDtime=-1;
                p[ind1].desiredSlot=(void *)0;
                printf("Reservation Canceled Successfully! \n");
                delay(1.5);
                system("cls");
                break;

            }

        }


    }
    else
    {

        printf("Wrong ID!\n");
        delay(1.5);
        system("cls");
    }


}










void userOptions(Patient*p,int index)
{
    int id,ind2;
    char check;
    printf("Enter your ID, Please: \n");
    scanf("%d",&id);

    check= chechId(id,p,index);
    ind2 = retrunIndexOfPatient(id,index);
    if(check)
    {
        printf("The name of the patient is: %s\n",p[ind2].name);
        printf("The age of the patient is: %d\n",p[ind2].age);
        (p[ind2].gender==1)? printf("The Patient is a Female\n") : printf("The Patient is a Male\n");
        (p[ind2].desiredSlot!=(void *)0)? printf("You a Reservation at: %s\n",p[ind2].desiredSlot) : printf("No Reservations found! \n");
        delay(7);

    }
    else
    {
        printf("Wrong ID!!\n");
    }

    system("cls");

}


void viewReservations()
{
    int i;
    for(i=0; i<index; i++)
    {
        (patient[i].desiredSlot!=(void *)0)? printf("[ID= %d]: You a Reservation at: %s\n",patient[i].ID,patient[i].desiredSlot) : printf("[ID= %d]: No Reservations found! \n",patient[i].ID);

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

