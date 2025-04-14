#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void addevent();
void eventrecords();
void searchevent();
void modifyevent();
void deleteevent();
void myExit();

typedef struct information{
    char first_name[64];
    char last_name[64];
    char catogories[64];
    int year;
    int month;
    int day;
    char time[10];
    char email[50];
    int phone_number;
    int pax;
} event;

void main(){
    int choice = 0;
    while(choice != 6){
        printf("\t\t\t====EVENT MANAGEMENT===\t\t\t");
        printf("\n\n\t\t\t 1. Add new event\n");
        printf("\n\t\t\t 2. Event records\n");
        printf("\n\t\t\t 3. Search event\n");
        printf("\n\t\t\t 4. Modify event\n");
        printf("\n\t\t\t 5. Delete event\n");
        printf("\n\t\t\t 6. Exit\n");
        printf("\t\t\t _______________________\n");
        printf("\n\t\t\t    ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                addevent();
                system("cls");
                break;

            case 2:
                system("cls");
                eventrecords();
                printf("\t\t\t Press any key to exit.\n");
                getch();
                system("cls");
                break;
            
            case 3:
                system("cls");
                searchevent();
                printf("\t\t\t Press any key to exit.\n");
                getch();
                system("cls");
                break;

            case 4:
                system("cls");
                modifyevent();
                printf("\t\t\t Press any key to exit.\n");
                getch();
                system("cls");
                break;
        
            case 5:
                system("cls");
                deleteevent();
                printf("\t\t\t Press any key to exit.\n");
                getch();
                system("cls");
                break;

            case 6:
                system("cls");
                printf("\n\t\t\t Thank you for using this software.\n\n");
                exit(0);
                break;

            default:
                system("cls");
                getch();
                printf("\n\t\t\t Enter a valid number");
                printf("\n\t\t\t Press any key to contunue.\n");
                getch();
                system("cls");
                break;

        }

    }

}

void addevent(){
    char another;
    FILE *fptr;
    event info;
    
    do{
        system("cls");
        printf("\t\t\t\t ==== Add new event ===\n\n\n");
        fptr=fopen("event_info.txt","a+");
        if (fptr == NULL){
            fprintf(stderr, "\t\t\tCannot open file.");
        } else {

            printf("\t\t\t\t First name: ");
            scanf("%s", info.first_name);
            printf("\t\t\t\t Last name: ");
            scanf("%s", info.last_name);
            printf("\t\t\t\t Dinner catogories (Wedding/Birthday/Year-end): ");
            scanf("%s", info.catogories);
            printf("\t\t\t\t Date(yyyy/mm/dd): ");
            scanf("%d/%d/%d", &info.year, &info.month, &info.day);

            while (getchar() != '\n');

            printf("\t\t\t\t Time (hh:mm): "); 
            fgets(info.time, sizeof(info.time), stdin);
            info.time[strcspn(info.time, "\n")] = '\0'; // Remove newline character from the end
            printf("\t\t\t\t Email: ");
            scanf("%s", info.email);
            printf("\t\t\t\t Phone number (+60): ");
            scanf("%d", &info.phone_number);
            printf("\t\t\t\t Pax: ");
            scanf("%d", &info.pax);
            printf("\n\t\t\t____________________\n");
        
            fwrite(&info, sizeof(event), 1, fptr);
            printf("\t\t\tInformation stored succesfully.");
            
            fclose(fptr);
        }
       
        printf("\t\t\tDo you want to add another record?(Y/N)");
        getchar();
        scanf(" %c", &another);
         
    } while (another == 'y' || another == 'Y');

}

void eventrecords(){
    FILE *fptr;
    event info;
    fptr = fopen("event_info.txt", "r");

    printf("\t\t\t\t ==== Event Records ===\n\n\n");

    if(fptr == NULL){
        fprintf(stderr, "\t\t\tCannot open file.");
    } else {
        printf("\t\t\tInformation\n");
        printf("\t\t\t________\n\n");
    }

    int i = 1; //Initialize i outisde the loop

    while(fread(&info, sizeof(event),1 , fptr) == 1){
        printf("\n\t\t\tRecord %d:", i);
        printf("\n\t\t\tName                  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\tDinner catogories     : %s", info.catogories);
        printf("\n\t\t\tDate                  : %d/%d/%d", info.year, info.month, info.day);
        printf("\n\t\t\tTime                  : %s", info.time);
        printf("\n\t\t\tEmail                 : %s", info.email);
        printf("\n\t\t\tPhone number (+60)    : %d", info.phone_number);
        printf("\n\t\t\tPax                   : %d", info.pax);
        printf("\n\t\t\t\t__________________________________\n");
        i++;
    }
    fclose(fptr);
    getch();

}

void searchevent(){
    FILE *fptr;
    event info;
    int phone_number, found = 0;
    fptr = fopen("event_info.txt", "r");
    
        printf("\t\t\t\t ==== Search event ===\n\n\n");
        printf("\t\t\tEnter phone number: ");
        scanf("%d", &phone_number);

        while(fread(&info, sizeof(event), 1, fptr)){
            if(info.phone_number == phone_number){
            found = 1;
            printf("\n\t\t\tName                  : %s %s", info.first_name, info.last_name);
            printf("\n\t\t\tDinner catogories     : %s", info.catogories);
            printf("\n\t\t\tDate                  : %d/%d/%d", info.year, info.month, info.day);
            printf("\n\t\t\tTime                  : %s", info.time);
            printf("\n\t\t\tEmail                 : %s", info.email);
            printf("\n\t\t\tPhone number  (+60)   : %d", info.phone_number);
            printf("\n\t\t\tPax                   : %d", info.pax);
            printf("\n\t\t\t\t__________________________________\n");
            }
        }
            if(!found){
                printf("\t\t\tRecord not found.\n");
            }
            fclose(fptr);
            getch();
}

void modifyevent(){
    FILE *fptr, *fptr1;
    event info;
    int phone_number, found = 0;
    
    printf("\t\t\t\t ===MODIFY EVENT=== \n\n\n");
    fptr = fopen("event_info.txt", "r");
    fptr1 = fopen("temp.txt", "w+");

    if (fptr == NULL){
        fprintf(stderr, "\t\t\tCannont open file.");
        return;
    }

        printf("\t\t\tEnter phone number to search: ");
        scanf("%d", &phone_number);
        int choice = 0; // Initialize choice before the loop
        while (fread(&info, sizeof(event), 1, fptr)){
            if (info.phone_number == phone_number){
                found = 1;
                
                printf("\t\t\t===CURRENT INFORMATION===\n");
                printf("\n\t\t\t[1] First Name            : %s", info.first_name);
                printf("\n\t\t\t[2] Last Name             : %s", info.last_name);
                printf("\n\t\t\t[3] Dinner categories     : %s", info.catogories);
                printf("\n\t\t\t[4] Date                  : %d/%d/%d", info.year, info.month, info.day);
                printf("\n\t\t\t[5] Time                  : %s", info.time);
                printf("\n\t\t\t[6] Email                 : %s", info.email);
                printf("\n\t\t\t[7] Phone number (+60)    : %d", info.phone_number);
                printf("\n\t\t\t[8] Pax                   : %d", info.pax);
                printf("\n\t\t\t[9] Cancel modification");
                printf("\n\t\t\tEnter your choice: ");
                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("\n\t\t\tEnter new First Name: ");
                        scanf("%s", info.first_name);
                        break;
                    case 2:
                        printf("\n\t\t\tEnter new Last Name: ");
                        scanf("%s", info.last_name);
                        break;
                    case 3: 
                        printf("\n\t\t\tEnter new Categories: ");
                        scanf("%s", info.catogories);
                        break;
                    case 4: 
                        printf("\n\t\t\tEnter new Date(yyyy/mm/dd): ");
                        scanf("%d%d%d", &info.year, &info.month, &info.day);
                        break;
                    case 5: 
                        printf("\n\t\t\tEnter new Time: ");
                        scanf("%s", info.time);
                        break;
                    case 6: 
                        printf("\n\t\t\tEnter new Email: ");
                        scanf("%s", info.email);
                        break;
                    case 7: 
                        printf("\n\t\t\tEnter new Phone Number: ");
                        scanf("%d", &info.phone_number);
                        break;
                    case 8: 
                        printf("\n\t\t\tEnter new Categories: ");
                        scanf("%d", &info.pax);
                        break;
                    case 9:
                        // Done modifying
                        break;
                    default:
                        printf("\t\t\tInvalid choice. Please enter a valid number.\n");
                        break;
                }

                //Write modified information to new file
                fwrite(&info, sizeof(event), 1, fptr1);
            } else {
                //Copy unchanged records to the new file
                fwrite(&info, sizeof(event), 1, fptr1);
            }
        }
        fclose(fptr);
        fclose(fptr1);

        if (found && choice != 9){
            //Remove the old file and rename the new file
            remove("event_info.txt");
            rename("temp.txt", "event_info.txt");
            printf("\n\t\t\t Record modified successfully.\n");
        } else if (choice == 9){
            printf("\n\t\t\tModification canceled.\n");
        } else {
            printf("\n\t\t\t Record not found.\n");
        }

    getch();
}

void deleteevent(){
    FILE *fptr, *fptr1;
    event info;
    int phone_number, found = 0;
    
        printf("\t\t\t\t ==== Delete event ===\n\n\n");
        fptr = fopen("event_info.txt", "r");
        fptr1 = fopen("temp.txt", "w+");
        printf("\t\t\tEnter phone number: ");
        scanf("%d", &phone_number);

        if(fptr == NULL){
            fprintf(stderr, "\t\t\tCannot open file.");
        }
        while(fread(&info, sizeof(event),1 , fptr)){
                if(info.phone_number == phone_number){
                found = 1;
            } else {
                fwrite(&info, sizeof(event), 1, fptr1);
            }
        }
        fclose(fptr);
        fclose(fptr1);

        if(found){
            remove("event_info.txt");
            rename("temp.txt", "event_info.txt");
            printf("\n\t\t\t Record deleted succesfully.\n");

        }

        if(!found){
            printf("\n\t\t\t Record not found.\n");
        }
        getch();

}

void myExit(){

    printf("\n\t\t\t Thank you for using this software.\n\n");
    exit(0);

}