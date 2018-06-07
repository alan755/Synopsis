#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int ce,cm;
char ec[50],mc[50];
int ccc=0;
struct employee
{
    char username[25];
    char password[25];
    char name[25];
    int age;
    char gen[10];
    char place[25];
    int number;
    int eid;
    char email[50];
    char ldate[50];
    char lreason[70];
    char lresult[25];
    char work[500];
    char target[100];

}emp,e;
struct manager
{
    char username[25];
    char password[25];
    char name[25];
    int age;
    char gen[10];
    int number;
    char place[25];
    int mid;
    char email[50];
}m,man;
void loader()
{

    int i;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t---:--[ Loading ]--:----\n\n\t\t\t\t\t\t");
    for(i=0;i<20;i++)
    {
        Sleep(100);
        printf("%c",219);
    }
}
struct employee empsearch(char user[25],char pass[25],int count)
{
           FILE *p;
           p=fopen("employe.bin","rb");
           fseek(p, 0, SEEK_SET);
           for(int i=1;i<=count;i++)
           {
           fread(&e,sizeof(struct employee),1,p);
           if((strcmp(e.username,user)==0) && (strcmp(e.password,pass)==0))
           {
            fclose(p);
            return e;
           }
           }
           printf("\nInvalid user name or password! ");
           fclose(p);
}
struct manager mansearch(char user[25],char pass[25],int count)
{
           struct manager m;
           FILE *q;
           q=fopen("manager.bin","rb");
           fseek(q, 0, SEEK_SET);
           fread(&m,sizeof(struct manager),1,q);
           if((strcmp(m.username,user)==0) && (strcmp(m.password,pass)==0))
            {
            fclose(q);
            return m;
            }
           printf("\nInvalid user name or password or key!");
           fclose(q);
}
void main()
{// main function
    char ans1,ans2;
    int k,q,cc,ee,eiid,miid,tq,tt,mnm,mem,rr;
    FILE *b,*t,*r,*v,*j,*y;
    b=fopen("numone.txt","r");
    fseek(b,0,SEEK_END);
    k=ftell(b);
    fclose(b);
    if(k==0)
    {
         t=fopen("numone.txt","w");
         ce=0;
         ec[0]='0'+ce;
         fputs(ec,t);
         fclose(t);
    }
    else
    {
    r=fopen("numone.txt","r");
    fgets(ec,10,r);
    ce=ec[0];
    fclose(r);
    }
    int c,ch,i,e,key;
    char user[25],pass[25],name[25],ans;
    loader();
    system("cls");
    printf("n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t---:--[ Loading complete! ]--:----");
    printf("\n\n\t\t\t\t\t\t---:--[ First user(y/n) ]--:---\n\t\t\t\t\t\t");
    char chh;
    chh=getch();
    if(chh=='y'||chh=='Y')
            ccc=0;
    else
            ccc=100;
    system("cls");
    do
    { // first do
    if(ccc> 0)
    printf("-----:--[ Number of employees:%d ]--:-----\n\n\t\t\t\t\t-----:---<SYNOPSIS>----------------------:--\n\t\t\t\t\t-----:---<EMPLOYEE MANAGEMENT SYSTEM>----:--\n",ce/49);
    else
    printf("-------:--[ Number of employees:%d ]--:-------\n\n\t\t\t\t\t-----:---<SYNOPSIS>----------------------:--\n\t\t\t\t\t-----:---<EMPLOYEE MANAGEMENT SYSTEM>----:--\n",ce);
    printf("\n\n\n\n\n\t\t\t\t\t\t      <1.Sign Up>\n\t\t\t\t\t\t      <2.Sign In>\n");
    printf("\n\n\n\n\n\t\t\t\t\t---------:--<Enter your choice>--:---------\n\t\t\t\t\t");
    scanf("%d",&c);
    switch(c)
    {   // main switch
        case 1:
        system("cls");
        printf("\n\n\t\t\t\t\t-----:---<SYNOPSIS>----------------------:--\n\t\t\t\t\t-----:---<EMPLOYEE MANAGEMENT SYSTEM>----:--\n\t\t\t\t\t#sign up");
        printf("\n\n\n\n\n\t\t\t\t\t\t      <1.Employee>\n\t\t\t\t\t\t      <2.Administrator>\n");
        printf("\n\n\n\n\n\t\t\t\t\t---------:--<Enter your choice>--:---------\n\t\t\t\t\t");
        scanf("%d",&ch);
        switch(ch)
        {   //sign up switch
             case 1:
             system("cls");
             printf("-----------:--<EMPLOYEE SIGN UP PAGE>--:---------\n");
             printf("\nUser name:");
             scanf("%s",&emp.username);
             printf("\nPassword:");
             scanf("%s",&emp.password);
             printf("\nName:");
             scanf("%s",&emp.name);
             printf("\nAge:");
             scanf("%d",&emp.age);
             printf("\nPlace:");
             scanf("%s",&emp.place);
             printf("\nGender:");
             scanf("%s",&emp.gen);
             printf("\nMobile number:");
             scanf("%d",&emp.number);
             printf("\nEmail.id:");
             scanf("%s",&emp.email);
             eiid=rand();
             printf("\n:------:--[ Your Employee Id:%d ]--:--------:",eiid);
             emp.eid=eiid;
             printf("\n\n\n-----------------------------------------------------------------------------------------------\nDo you agree with the terms and policies of the company(given earlier) and shall strive to follow it to \nlargest extend(y/n):-\n------------------------------------------------------------------------------------------------\n");
             char tr;
             tr=getch();
             if(tr=='y')
             {
             FILE *r;
             r=fopen("employe.bin","ab");
             fwrite(&emp,sizeof(struct employee),1,r);
             fclose(r);
             printf("\nOne account is created!");
             ce++;
             FILE *l;
             l=fopen("numone.txt","w");
             ec[0]='0'+ce;
             fputs(ec,l);
             fclose(l);
             if(ccc>0)
             printf("\n----:--[ Number of employees:%d ]--:----",ce-48);
             else
             printf("\n----:--[ Number of employees:%d ]--:-----",ce);
             getch();
             }
             break;

             case 2:
             system("cls");
             printf("----------------------:--<ADMINISTRAOR>--:----------------------\n\nThe company is having only one admin(manger).New admin is created only \nwith the retirement of old admin.So do you wish to continue.......\n");
             printf("\nKey:");
             scanf("%d",&key);
             if(key==111234)
             {
             printf("-----------:--<ADMINISTRATOR SIGN UP PAGE>--:---------\n\n");
             printf("Welcome new administrator of synopsis!\n\n");
             printf("User name:");
             scanf("%s",&m.username);
             printf("\nPassword:");
             scanf("%s",&m.password);
             printf("\nName:");
             scanf("%s",&m.name);
             printf("\nAge:");
             scanf("%d",&m.age);
             printf("\nGender:");
             scanf("%s",&m.gen);
             printf("\nPlace:");
             scanf("%s",&m.place);
             printf("\nMobile number:");
             scanf("%d",&m.number);
             printf("\nEmail.id:");
             scanf("%s",&m.email);
             miid=rand();
             printf("\n:--[ Your Manager Id:%d ]--:",miid);
             m.mid=miid;
             FILE *s;
             s=fopen("manager.bin","wb");
             fwrite(&m,sizeof(struct manager),1,s);
             fclose(s);
             printf("\n-------:--[ Admin account is created! ]--:--------");
             getch();
             }
             else
             {
             printf("\n\nWrong key!");
             }

        } // sign up switch closed*/
        break;

        case 2:
        system("cls");            // sign in
        printf("\n\n\t\t\t\t\t-----:---<SYNOPSIS>----------------------:--\n\t\t\t\t\t-----:---<EMPLOYEE MANAGEMENT SYSTEM>----:--\n\t\t\t\t\t#sign in");
        printf("\n\n\n\n\n\t\t\t\t\t\t      <1.Employee>\n\t\t\t\t\t\t      <2.Admin>\n");
        printf("\n\n\n\n\n\t\t\t\t\t---------:--<Enter your choice>--:---------\n\t\t\t\t\t");
        scanf("%d",&e);
        switch(e)
        { // sign in switch
         case 1:
         system("cls");
         printf("-----------:--<EMPLOYEE SIGN IN PAGE>--:---------\n");
         printf("\nUser name:");
         scanf("%s",&user);
         printf("\nPassword:");
         scanf("%s",&pass);
         if(ccc>0)
            rr=ce/49;
         else
            rr=ce;
         emp=empsearch(user,pass,rr);
         if((strcmp(emp.username,user)==0)&&(strcmp(emp.password,pass)==0))
         { //if of employee
         do
         {   // do of employee
         system("cls");
         printf("-----------------------:--<EMPLOYEE>--:------------------------\n--------------------------------------------------------\n\n");
         printf("\n\t\t<1.Account Details>\n\t\t<2.Personal Details>\n\t\t<3.Leave>\n\t\t<4.Work>\n\n\n--------------------------------------------------------------------\n");
         printf("------------------------:-<Enter your choice>--:------------------\n");
         scanf("%d",&tt);
         switch(tt)
         { // employee switch
         case 1:
         system("cls");
         printf("-----------------:--<EMPLOYEE>--:------------------\n");
         printf("#Account\n");
         printf("\n\nUser name:%s",emp.username);
         printf("\nPassword:%s",emp.password);
         break;

         case 2:
         system("cls");
         printf("-----------------:--<EMPLOYEE>--:------------------\n");
         printf("#Personal details\n");
         printf("\nName:%s",emp.name);
         printf("\nAge:%d",emp.age);
         printf("\nGender:%s",emp.gen);
         printf("\nPlace:%s",emp.place);
         printf("\nMobile number:%d",emp.number);
         printf("\nEmail Id:%s",emp.email);
         printf("\nEmployee number:%d",emp.eid);
         break;

         case 3:
         system("cls");
         printf("-----------------:--<EMPLOYEE>--:------------------\n");
         printf("#Leave\n");
         printf("\t\t<1.Apply>\n\t\t<2.View>\n");
         printf("-------------:---<Enter your choice>---:------------\n");
         scanf("%d",&mem);
         switch(mem)
         { // employee leave switch
         case 1:
         system("cls");
         printf("-----------------:--<EMPLOYEE>--:------------------\n");
         printf("#Leave-#Apply\n");
         printf("\nDate:");
         scanf("%s",&emp.ldate);
         printf("\nReason:");
         scanf("%s",&emp.lreason);
         struct employee gtr;
         int el;
         el=emp.eid;
         int elk=0;
         FILE *ptt;
         ptt=fopen("employe.bin","rb");
         fseek(ptt,0,SEEK_SET);
         for(i=1;i<=ce;i++)
         {
         fread(&gtr,sizeof(struct employee),1,ptt);
         if(el==gtr.eid)
         {
         fclose(ptt);
         FILE *ptr;
         ptr=fopen("employe.bin","wb");
         fseek(ptr,i*sizeof(struct employee),SEEK_SET);
         fseek(ptr,-1*sizeof(struct employee),SEEK_CUR);
         fwrite(&emp,sizeof(struct employee),1,ptr);
         fclose(ptr);
         elk=1;
         }
         }
         if(elk==0)
         {
         fclose(ptt);
         }
         printf("\n-----------:--[ Leave successfully applied! ]--:-----");
         printf("\nIt will be sanctioned by any of the managers....");  //dumping to file still to complete
         break;

         case 2:
         system("cls");
         printf("-----------------:--<EMPLOYEE>--:------------------\n");
         printf("#Leave-#View\n");
         printf("\n---:--[ Latest ]--:---\n");
         printf("\nDate:%s",emp.ldate);
         printf("\nReason:%s",emp.lreason);
         printf("\n\nSanctioned/not:%s",emp.lresult);
         } // employee leave switch closed
         break;

         case 4:
         system("cls");
         printf("-----------------:--<EMPLOYEE>--:------------------\n");
         printf("#Work\n");
         printf("\nLatest Work to be done:-\n%s",emp.work);
         printf("\nTarget:%s",emp.target);
         } // employee switch closed
         printf("\n\n<<<---------------:-<<<Log out>>>-:------<<<(y/n)>>>----->>>\n");
         ans1=getch();
         }while(ans1=='N'||ans1=='n');  // do of employee closed
         }
         else
         {
         getch();
         }// if of employee closed
         break;

         case 2:
         system("cls");
         printf("-----------:--<ADMIN SIGN IN PAGE>--:---------\n\n");
         printf("User name:");
         scanf("%s",&user);
         printf("\nPassword:");
         scanf("%s",&pass);
         man=mansearch(user,pass,1);
         if((strcmp(man.username,user)==0)&&(strcmp(man.password,pass)==0))
         { // if of manager
         do
         { // do of manager
         system("cls");
         printf("-----------------:--<ADMINISTRATOR-MANGER>--:------------------\n---------------------------------------------\n\n");
         printf("\n\t\t<1.Account Details>\n\t\t<2.Personal Details>\n\t\t<3.Leave>\n\t\t<4.Work>\n\n\n-----------------------------------------------");
         printf("\n------------:-<Enter your choice>--:----------------\n");
         scanf("%d",&tq);
         switch(tq)
         { // manager switch
         case 1:
         system("cls");
         printf("-----------------:--<ADMINISTRATOR>--:------------------\n");
         printf("#Account\n");
         printf("\n\nUser name:%s",man.username);
         printf("\nPassword:%s",man.password);
         break;

         case 2:
         system("cls");
         printf("-----------------:--<ADMINISTRATOR>--:------------------\n");
         printf("#Personal details\n");
         printf("\n\nName:%s",man.name);
         printf("\nAge:%d",man.age);
         printf("\nGender:%s",man.gen);
         printf("\nPlace:%s",man.place);
         printf("\nMobile number:%d",man.number);
         printf("\nEmail Id:%s",man.email);
         break;

         case 3:
         system("cls");
         printf("-----------------:--<ADMINISTRATOR>--:------------------\n");
         printf("#Leave applied by employees\n\n");
         struct employee ee={"none","none","none",0,"none","none",0,0,"none","none","none","none","none","none"};
         int kk=0;
         FILE *c;
         c=fopen("employe.bin","rb");
         fseek(c,0,SEEK_SET);
         for(i=1;i<=1/*ce/49*/;i++)
         {
         fread(&ee,sizeof(struct employee),1,c);
         if(strcmp(ee.lresult,"none")!=0)
         {
         fclose(c);
         kk=1;
         printf("Employee no:%d",ee.number);
         printf("\nName:%s",ee.name);
         printf("\n\nLeave:-\n");
         printf("Date:%s",ee.ldate);
         printf("\nReason:%s",ee.lreason);
         int hh;
         printf("\n\nSanction Leave(1:sanctioned,2:not sanctioned ):");
         scanf("%d",&hh);
         if(hh==1)
            strcpy(ee.lresult,"sanctioned");
         else
            strcpy(ee.lresult,"not sanctioned");
         // dumping..
         struct employee gte;
         int eth;
         eth=ee.eid;
         int ell=0;
         FILE *pte;
         pte=fopen("employe.bin","rb");
         fseek(pte,0,SEEK_SET);
         for(i=1;i<=1/*ce*/;i++)
         {
         fread(&gte,sizeof(struct employee),1,pte);
         if(eth==gte.eid)
         {
         fclose(pte);
         FILE *pre;
         pre=fopen("employe.bin","wb");
         fseek(pre,i*sizeof(struct employee),SEEK_SET);
         fseek(pre,-1*sizeof(struct employee),SEEK_CUR);
         fwrite(&ee,sizeof(struct employee),1,pre);
         fclose(pre);
         ell=1;
         }
         }
         if(ell==0)
         {
         fclose(pte);
         }
         }
         }
         if(kk==0)
         {
         fclose(c);
         printf("\n\nNo records found!");
         }
         break;

         case 4: // work
         system("cls");
         printf("-----------------:--<MANAGER>--:------------------\n");
         printf("#Work\n\n");
         printf("Search the employee\n");
         printf("\nEmployee id:");
         int num;
         scanf("%d",&num);
         struct employee er;
         int ek=0;
         FILE *ptrr;
         ptrr=fopen("employe.bin","rb");
         fseek(ptrr,0,SEEK_SET);
         for(i=1;i<=1/*ce*/;i++)
         {
         fread(&er,sizeof(struct employee),1,ptrr);
         if(num==er.eid)
         {
         fclose(ptrr);
         printf("\n\nEmployee found!");
         printf("\nName:%s",er.name);
         printf("\nEmployee id:%d",er.eid);
         printf("\n\nEnter the work to be done:-\n");
         scanf("%s",&er.work);
         printf("\nEnter the target(time):");
         scanf("%s",&er.target);
         printf("\n\n-----:--[ Work given! ]--:-------");
         // dumping to employee.bin
         FILE *pp;
         pp=fopen("employe.bin","wb");
         fseek(pp,i*sizeof(struct employee),SEEK_SET);
         fseek(pp,-1*sizeof(struct employee),SEEK_CUR);
         fwrite(&er,sizeof(struct employee),1,pp);
         fclose(pp);
         ek=1;
         }
         }
         if(ek==0)
         {
         printf("\nInvalid employee id!");
         fclose(ptrr);
         }
         break;
         } // manager switch closed
         printf("\n\n<<<---------------:-<<<Log out>>>-:------<<<(y/n)>>>----->>>\n");
         ans2=getch();
         }while(ans2=='n'||ans=='N'); // do of manager closed
         }
         else
         {
          getch();
          }// if of manager closed
         }// sign in switch closed
    } // main switch closed
        system("cls");
        printf("\n<<<---------:--<<<Do you wish to continue(y/n)>>>--:----------->>>\n");
        ans=getch();
        system("cls");
    }while(ans=='y' ||ans=='Y'); // first do closed


} // main fun closed
