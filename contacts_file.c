#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
typedef struct{
    char name[100];
    int num;
}profile;
int main()
{
    FILE *fp,*ft;
    int choice;
    char ch,o_name[100],n_name[100];
    profile p1;
    fp=fopen("E:\\contacts.bin","rb+");
    if(fp==NULL)
    {
        printf("invalid file fp");
        exit(1);
    }
    while(1)
    {
        system("cls");
        printf("Enter 1 for entering data: \n");
        printf("Enter 2 for displaying data: \n");
        printf("Enter 3 for updating data: \n");
        printf("Enter 4 for deleting data: \n");
        printf("Enter 5 for exit: ");
        printf("CHOICE: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                ch='y';
                while(ch!='n')
                {
                    fseek(fp,0,SEEK_END);
                    printf("enter the name and num: ");
                    scanf("%s%d",p1.name,&p1.num);
                    fwrite(&p1,sizeof(profile),1,fp);
                    printf("do you want add more?(y/n)");
                    fflush(stdin);
                    scanf("%c",&ch);

                }
                break;
            case 2:
                rewind(fp);
                while(fread(&p1,sizeof(profile),1,fp)==1)
                {
                    printf("%s\t%d\n",p1.name,p1.num);
                }
                getch();
                break;
            case 3:
                ch='y';
                while(ch!='n')
                {
                    printf("enter the old name: ");
                    scanf("%s",o_name);
                    rewind(fp);
                    while(fread(&p1,sizeof(p1),1,fp)==1)
                    {
                    
                        if(strcmp(o_name,p1.name)==0)
                        {
                            printf("enter the new name: ");
                            scanf("%s",p1.name);
                            printf("enter the new number:");
                            scanf("%d",&p1.num);
                            fseek(fp,-sizeof(p1),SEEK_CUR);
                            fwrite(&p1,sizeof(p1),1,fp);
                            break;
                        }
                   

                    
                    }
                    printf("do you want to add more?(y/n)");
                    fflush(stdin);
                    scanf("%c",&ch);
                    
                }
                break;
                case 4:
                    ch='y';
                    while(ch!='n')
                    {
                    ft=fopen("E:\\contacts2.bin","wb");
                    if(ft==NULL)
                    {
                        printf("invalid 4x");
                        exit(1);
                    }
                    rewind(fp);
                    printf("enter the name to delete: ");
                    scanf("%s",o_name);
                    while(fread(&p1,sizeof(p1),1,fp)==1)
                    {
                        if(strcmp(p1.name,o_name)!=0)
                            fwrite(&p1,sizeof(p1),1,ft);
                        
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("E:\\contacts.bin");
                    rename("E:\\contacts2.bin","E:\\contacts.bin");
                    fp=fopen("E:\\contacts.bin","rb+");
                    if(fp==NULL)
                    {
                        printf("invalid 4y");
                    }
                    printf("do you want to delete more?(y/n)");
                    fflush(stdin);
                    scanf("%c",&ch);
                    }
                    break;
                case 5:
                    exit(0);
           
           
    }
    

    }   
}
