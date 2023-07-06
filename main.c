#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct user{
    int cin;
    char nom[20];
    char prenom[20];
    char date[20];
    char email[20];
    char gender[10];
    float solde;
}USER;
typedef struct manager{
    int cin;
    char nom[20];
    char prenom[20];
}MANAGER;
typedef struct credit{
    int cin;
    char nom[20];
    char prenom[20];
    float montant;
    int duree;
    float rev_annu;
    int mois_restants;

}CREDIT_CLIENT;
///////////////////////////////////////////////declaration globale
FILE *user_f;
FILE *credit_f;
FILE *tmp_file;
FILE *archive_credit_file; //les clients qui ont finis leurs credits
FILE *manager_file;

USER per;
MANAGER manager;
CREDIT_CLIENT client;
///////////////////////////////////////////////prototype




    void login(void);
        void user_login(void);
            void se_connecter(void);
                void cnx_menu(void);
                    void account_info(void);
                    void effectuer_opperation(void);
                        void tirer(void);
                        void deposer(void);
                        void effectuer_virement(void);
                        void credit(void);
                            void faire_credit(void);
                            void info_credit(void);
                    void modifier_informations(void);
                    void supprimer_compte(void);
            void creer_compte(void);
        void manager_login(void);
            void se_connecter_manager(void);
                void cnx_menu_manager(void);
                    void pointer(void);
                    void display_users(void);
                    void display_clients_credit(void);
                    void display_archive(void);




///////////////////////////////////////////////main
int main()
{
    login();
    return 0;
}
///////////////////////////////////////////////defenition des fcts
void login(){
    int choix1,ligne=3,colonne=12;
    clrscr();

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(14,ligne++); cprintf("        MENU PRINCIPAL ");
    gotoxy(14,ligne++); cprintf("         --------------");
    gotoxy(colonne,ligne++);  printf("����������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�    1- CONNEXION D'UTILISATEUR    �");
    gotoxy(colonne,ligne++);  printf("����������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�    2- CONNEXION  DE  MANAGER     �");
    gotoxy(colonne,ligne++);  printf("����������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�           3- QUITTER             �");
    gotoxy(colonne,ligne++);  printf("����������������������������������ͼ");

    choisir:             //on retourne ici si un nombre choisi est different de 1,2 et 3
    gotoxy(colonne+=6,ligne++);  printf("�����������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�    ENTREZ UN CHOIX    �");
    gotoxy(colonne,ligne);       printf("�����������������������ͼ");
    gotoxy(colonne+=7,ligne++);      printf("���������ͻ");
    gotoxy(colonne,ligne++);         printf("�         �");
    gotoxy(colonne,ligne--);         printf("���������ͼ");
    textcolor(14);
    gotoxy(colonne+=5,ligne++); scanf("%d",&choix1);


    switch(choix1){
        case 1: {clrscr();
                 user_login();
                 break;}
        case 2: {clrscr();
                 manager_login();
                 break;}
        case 3: {clrscr();
                 textcolor(0);
                 textbackground(15);
                 gotoxy(18,3);cprintf("      AU REVOIR      ");
                 getch();getch();
                 break;}
        default:{
                 login();
                 break;
                 }
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************
void user_login(){

    int choix2=0,ligne=3,colonne=15;
    clrscr();


    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(12,ligne++); cprintf("        Menu d'Utilisateur ");
    gotoxy(12,ligne++); cprintf("         ------------------");
    gotoxy(colonne,ligne++);  printf("���������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�     1- SE CONNECTER       �");
    gotoxy(colonne,ligne++);  printf("���������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     2- CREER UN COMPTE    �");
    gotoxy(colonne,ligne++);  printf("���������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     3- RETOUR             �");
    gotoxy(colonne,ligne++);  printf("���������������������������ͼ");

    choisir:             //on retourne ici si un nombre choisi est different de 1,2 et 3
    gotoxy(colonne+=4,ligne++);  printf("�������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�  ENTREZ UN CHOIX  �");
    gotoxy(colonne,ligne);       printf("�������������������ͼ");
    gotoxy(colonne+=5,ligne++);      printf("���������ͻ");
    gotoxy(colonne,ligne++);         printf("�         �");
    gotoxy(colonne,ligne--);         printf("���������ͼ");
    textcolor(14);
    gotoxy(colonne+5,ligne++); scanf("%d",&choix2);

    switch(choix2){
        case 1: clrscr();
                se_connecter();
                break;
        case 2: clrscr();
                creer_compte();
                break;
        case 3: clrscr();
                login();
                break;
        default:
                user_login();
                break;
        }

}
//*********************************************
void se_connecter(){
    int code,found,ligne=3,colonne=5;
    char nom[20],prenom[20];

    textcolor(11);
    gotoxy(colonne,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(colonne,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(15,ligne++); cprintf("        SE CONNECTER ");
    gotoxy(12,ligne++); cprintf("          ----------------");
    gotoxy(10,ligne++); printf("");
    textcolor(14);
    gotoxy(10,ligne++); cprintf("Entrez Votre Informations de Connexion");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�     1- CIN           �                         �");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     2- PRENOM        �                         �");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     3- NOM           �                         �");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������ͼ");

    user_f=fopen("userInformation.txt","rt");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier");
        exit(1);
    }
    textcolor(14);
    gotoxy(35,ligne-=6);cscanf("%d",&code);
    gotoxy(35,ligne+=2);cscanf("%s",&prenom);
    gotoxy(35,ligne+=2);cscanf("%s",&nom);


    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin==code && strcmp(per.prenom,prenom)==0 && strcmp(per.nom,nom)==0){
            found=1;
            break;
        }
    }
    fclose(user_f);
    if(found==1){
        textcolor(10);
        gotoxy(18,ligne+=3);cprintf("���������������������Ŀ");
        gotoxy(18,ligne+=1);cprintf("�CONNEXION AVEC SUCCES�");
        gotoxy(18,ligne+=1);cprintf("�����������������������");
        textcolor(14);
        gotoxy(11,ligne+=2);cprintf("Taperz un boutton pour plus d'options");
        getch();
        getch();
        clrscr();
        cnx_menu();
    }
    else{
        textcolor(12);
        gotoxy(16,ligne+=3);cprintf("������������������������Ŀ");
        gotoxy(16,ligne+=1);cprintf("�Informations Incorrectes�");
        gotoxy(16,ligne+=1);cprintf("��������������������������");
        textcolor(14);
        gotoxy(2,ligne+=2);cprintf("Tapez un boutton pour retourner vers le Menu Principal");
        getch();
        getch();
        user_login();
    }
}
//*********************************************
void cnx_menu(){

    int choix3,ligne=3,colonne=12;
    clrscr();

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(14,ligne++); cprintf("      Menu Des Services ");
    gotoxy(14,ligne++); cprintf("       -----------------");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�  1- INFORMATIONS DU COMPTE     �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�  2- EFFECTUER UNE OPPERATION   �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�  3- MODIFIER LES INFORMATIONS  �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�  4- SUPPRIMER LE COMPTE        �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�           5- RETOUR            �");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͼ");

    choisir:             //on retourne ici si un nombre choisi est different de 1,2 et 3
    gotoxy(colonne+=7,ligne++);  printf("�������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�  ENTREZ UN CHOIX  �");
    gotoxy(colonne,ligne);       printf("�������������������ͼ");
    gotoxy(colonne+=5,ligne++);  printf("���������ͻ");
    gotoxy(colonne,ligne++);     printf("�         �");
    gotoxy(colonne,ligne--);     printf("���������ͼ");
    textcolor(14);
    gotoxy(colonne+=5,ligne++); scanf("%d",&choix3);

    switch(choix3){
        case 1: {clrscr();
                 account_info();
                 break;}
        case 2: {clrscr();
                 effectuer_opperation();
                 break;}
        case 3: {clrscr();
                 modifier_informations();
                 getch();
                 break;}
        case 4: {clrscr();
                 supprimer_compte();
                 getch();
                 break;}
        case 5: {clrscr();
                 user_login();
                 getch();
                 break;}
        default:{goto choisir;}
    }

}
//*********************************************
void creer_compte(){


    int code,found=0,ligne=3,colonne=5;

    textcolor(11);
    gotoxy(colonne,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(colonne,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(12,ligne++); cprintf("        CREATION DU COMPTE ");
    gotoxy(12,ligne++); cprintf("         ------------------");
    gotoxy(10,ligne++); printf("");
    textcolor(14);
    gotoxy(15,ligne++); cprintf("Remplisser les donnees suivantes");
    gotoxy(5,ligne++);  printf("������������������������������������������������ͻ");
    gotoxy(5,ligne++);  printf("�   1- CIN             �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�   2- PRENOM          �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�   3- NOM             �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�   4- DATE_NAISSANCE  �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�   5- GENRE           �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�   6- EMAIL           �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������ͼ");

    user_f=fopen("userInformation.txt","a+");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier");
        exit(1);
    }
    gotoxy(35,ligne-=12);cscanf("%d",&code);
    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.nom,per.prenom,per.date,per.gender,per.email,&per.solde);
        if(per.cin==code){
            found=1;
            break;
        }
    }

    if(found==1){
        textcolor(12);
        gotoxy(11,ligne+=13);cprintf("������������������������������������Ŀ");
        gotoxy(11,ligne+=1); cprintf("�         cin  existe deja!          �");
        gotoxy(11,ligne+=1); cprintf("�vous pouvez pas creer un 2eme compte�");
        gotoxy(11,ligne+=1); cprintf("��������������������������������������");
        textcolor(14);
        gotoxy(1,ligne+=2);cprintf("Tapez un boutton pour retourner vers le Menu d'Utilisateur");
        getch();
        getch();
        user_login();
    }
    else{
        per.cin = code;
        textcolor(14);
        gotoxy(35,ligne+=2);cscanf("%s",&per.prenom);
        gotoxy(35,ligne+=2);cscanf("%s",&per.nom);
        gotoxy(35,ligne+=2);cscanf("%s",&per.date);
        gotoxy(35,ligne+=2);cscanf("%s",&per.gender);
        gotoxy(30,ligne+=2);cscanf("%s",&per.email);
        per.solde=0;
        fprintf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
    }
    fclose(user_f);
    textcolor(10);
    gotoxy(14,ligne+=3);cprintf("������������������������������Ŀ");
    gotoxy(14,ligne+=1);cprintf("�creation de compte avec succes�");
    gotoxy(14,ligne+=1);cprintf("��������������������������������");
    textcolor(14);
    getch();

    gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour retourner vers le Menu");

    getch();
    user_login();
}
//*********************************************
void account_info(){

    int code,ligne=3,colonne=19;
    float solde;
    char nom[20],prenom[20],date[20],gender[20],email[20];
    clrscr();

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(10,ligne++); cprintf("        Information Du Compte ");
    gotoxy(10,ligne++); cprintf("         ---------------------");
    gotoxy(10,ligne++); printf("");

    user_f=fopen("userInformation.txt","r");
    rewind(user_f);
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier");
        exit(1);
    }
    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&code,prenom,nom,date,gender,email,&solde);
        if(per.cin==code){
            break;
        }
    }
    fclose(user_f);
    gotoxy(colonne,++ligne); printf("CIN       :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%d",code);
    gotoxy(colonne,++ligne); printf("PRENOM    :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%s",prenom);
    gotoxy(colonne,++ligne); printf("NOM       :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%s",nom);
    gotoxy(colonne,++ligne); printf("NAISSANCE :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%s",date);
    gotoxy(colonne,++ligne); printf("GENRE     :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%s",gender);
    gotoxy(colonne,++ligne); printf("EMAIL     :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%s",email);
    gotoxy(colonne,++ligne); printf("SOLDE     :");gotoxy(colonne+13,ligne); textcolor(14);cprintf("%.2f",solde);
    getch();

    textcolor(14);
    gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour retourner vers le Menu");
    getch();
    getch();
    cnx_menu();

}
//*********************************************
void effectuer_opperation(){

    int choix4,ligne=3,colonne=12;
    clrscr();

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(12,ligne++); cprintf("      Effectuer_Opperation ");
    gotoxy(12,ligne++); cprintf("       ---------------------");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�    1- TIRER L'ARGENT           �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�    2- DEPOSER L'ARGENT         �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�    3- EFFECTUER UN VIREMENT    �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�    4- SERVICE CREDIT           �");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͼ");

    choisir:             //on retourne ici si un nombre choisi est different de 1,2 et 3
    gotoxy(colonne+=7,ligne++);  printf("�������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�  ENTREZ UN CHOIX  �");
    gotoxy(colonne,ligne);       printf("�������������������ͼ");
    gotoxy(colonne+=5,ligne++);  printf("���������ͻ");
    gotoxy(colonne,ligne++);     printf("�         �");
    gotoxy(colonne,ligne--);     printf("���������ͼ");
    textcolor(14);
    gotoxy(colonne+=5,ligne++); scanf("%d",&choix4);


    switch(choix4){
        case 1: {clrscr();
                 tirer();
                 break;}
        case 2: {clrscr();
                 deposer();
                 break;}
        case 3: {clrscr();
                 effectuer_virement();
                 getch();
                 break;}
        case 4: {clrscr();
                 credit();
                 getch();
                 break;}
        default:effectuer_opperation();
                 break;
    }

}
//*********************************************
void tirer(){
    int code=per.cin,ligne=3,colonne=16;
    float solde;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(17,ligne++); cprintf("      TIRER L'ARGENT ");
    gotoxy(17,ligne++); cprintf("       --------------");

    user_f=fopen("userInformation.txt","r");
    tmp_file=fopen("tmpFile.txt","wt");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpFile");
        exit(1);
    }

    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin!=code){
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
        else{
            textcolor(14);
            gotoxy(colonne,ligne+=3);cprintf("����������������������������Ŀ");
            gotoxy(colonne,ligne+=1);cprintf("�combien voullez vous tirer ?�");
            gotoxy(colonne,ligne+=1);cprintf("������������������������������");
            gotoxy(colonne+6,ligne+=1);cprintf("����������������Ŀ");
            gotoxy(colonne+6,ligne+=1);cprintf("�                �");
            gotoxy(colonne+6,ligne+=1);cprintf("������������������");
            gotoxy(colonne+13,ligne-=1);cscanf("%f",&solde);
            per.solde=per.solde-solde;
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
            textcolor(10);
            gotoxy(colonne+5,ligne+=3);cprintf("������������������Ŀ");
            gotoxy(colonne+5,ligne+=1);cprintf("�Tirage Avec Succes�");
            gotoxy(colonne+5,ligne+=1);cprintf("��������������������");
            getch();

            textcolor(14);
            gotoxy(6,ligne+=3);cprintf("Tapez un boutton pour retourner vers le Menu");
            getch();
            getch();
            cnx_menu();
        }
    }
    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpFile.txt","userInformation.txt");


}
//*********************************************
void deposer(){
    int code=per.cin,ligne=3,colonne=15;
    float solde;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(15,ligne++); cprintf("      DEPOSER L'ARGENT ");
    gotoxy(15,ligne++); cprintf("       ----------------");

    user_f=fopen("userInformation.txt","rt+");
    tmp_file=fopen("tmpFile.txt","wt");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpFile");
        exit(1);
    }

    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin!=code){
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
        else{
            textcolor(14);
            gotoxy(colonne,ligne+=3);cprintf("������������������������������Ŀ");
            gotoxy(colonne,ligne+=1);cprintf("�combien voullez vous deposer ?�");
            gotoxy(colonne,ligne+=1);cprintf("��������������������������������");
            gotoxy(colonne+7,ligne+=1);cprintf("����������������Ŀ");
            gotoxy(colonne+7,ligne+=1);cprintf("�                �");
            gotoxy(colonne+7,ligne+=1);cprintf("������������������");
            gotoxy(colonne+12,ligne-=1);cscanf("%f",&solde);
            per.solde=per.solde+solde;
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
            textcolor(10);
            gotoxy(colonne+6,ligne+=3);cprintf("������������������Ŀ");
            gotoxy(colonne+6,ligne+=1);cprintf("�Depot Avec Succes �");
            gotoxy(colonne+6,ligne+=1);cprintf("��������������������");

        }
    }
    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpFile.txt","userInformation.txt");

    textcolor(14);
    gotoxy(5,ligne+=3);cprintf("Tapez un boutton pour retourner vers le Menu");
    getch();
    getch();
    cnx_menu();

}
//*********************************************
void effectuer_virement(){
    int code=per.cin , code_recevoir,ligne=3,colonne=15;
    float solde;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(14,ligne++); cprintf("      EFFECTUER VIREMENT ");
    gotoxy(14,ligne++); cprintf("       ------------------");

    textcolor(14);
    gotoxy(8,ligne++);printf("entrz le code du compte qui va recu le solde:");
    gotoxy(30,ligne++);cscanf("%d",&code_recevoir);
    gotoxy(8,ligne+=2);printf("quel est le solde que voullez vous envoyer:");
    gotoxy(30,ligne+=1);cscanf("%f",&solde);

    user_f=fopen("userInformation.txt","rt+");
    tmp_file=fopen("tmpVirement.txt","wt");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpVirement");
        exit(1);
    }

    while(!feof(user_f)){

        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin==code){
            per.solde=per.solde - solde;
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
        else if(per.cin==code_recevoir){
            per.solde=per.solde + solde;

            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
        else{
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
    }

    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpVirement.txt","userInformation.txt");

    textcolor(10);
    gotoxy(colonne+4,ligne+=3);cprintf("����������������������Ŀ");
    gotoxy(colonne+4,ligne+=1);cprintf("� Virement Avec Succes �");
    gotoxy(colonne+4,ligne+=1);cprintf("������������������������");
    getch();

    textcolor(14);
    gotoxy(2,ligne+=3);cprintf("Tapez un boutton pour retourner vers le Menu");
    getch();
    getch();
    cnx_menu();
}
//*********************************************
void credit(){
    int choix5,ligne=3,colonne=13;

    clrscr();
    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(16,ligne++); cprintf("      MENU DU CREDIT ");
    gotoxy(16,ligne++); cprintf("       --------------");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�     1- DEMANDER CREDIT         �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     2- INFOS DU CREDIT         �");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͼ");

    choisir:
    gotoxy(colonne+=7,ligne++);  printf("�������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�  ENTREZ UN CHOIX  �");
    gotoxy(colonne,ligne);       printf("�������������������ͼ");
    gotoxy(colonne+=5,ligne++);  printf("���������ͻ");
    gotoxy(colonne,ligne++);     printf("�         �");
    gotoxy(colonne,ligne--);     printf("���������ͼ");
    textcolor(14);
    gotoxy(colonne+=5,ligne++); scanf("%d",&choix5);


    switch(choix5){
        case 1: {clrscr();
                 faire_credit();
                 break;}
        case 2: {clrscr();
                 info_credit();
                 getch();
                 break;}
        default:credit();
                 break;
    }

}
//*********************************************
void faire_credit(){
    float montant,rev_ann,tier_sal_mois,mensualite;
    int duree,ligne=3,colonne=13;
    client.cin=per.cin;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(15,ligne++); cprintf("      DEMANDE DU CREDIT ");
    gotoxy(15,ligne++); cprintf("       -----------------");
    textcolor(14);
    gotoxy(11,ligne++); cprintf("verification de votre demande de credit");
    gotoxy(5,ligne++);  printf("������������������������������������������������ͻ");
    gotoxy(5,ligne++);  printf("�  1- MONTANT SOUHAITE �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�  2- DUREE            �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������͹");
    gotoxy(5,ligne++);  printf("�  3- REVENU ANNUEL    �                         �");
    gotoxy(5,ligne++);  printf("������������������������������������������������ͼ");

    gotoxy(34,ligne-=6);  cscanf("%f",&montant);
    gotoxy(34,ligne+=2);  cscanf("%d",&duree);
    gotoxy(34,ligne+=2);  cscanf("%f",&rev_ann);

    tier_sal_mois = (rev_ann/12)/3 ;  //le 1/3 du salaire par mois
    mensualite = montant/duree ;      //combien il faut rendre chaque mois
    client.mois_restants=duree;
    if(tier_sal_mois >= mensualite){
        textcolor(10);
        gotoxy(colonne,ligne+=3);cprintf("�������������������������������Ŀ");
        gotoxy(colonne,ligne+=1);cprintf("�  Votre Demande Est Confirmee  �");
        gotoxy(colonne,ligne+=1);cprintf("���������������������������������");

        credit_f=fopen("credit.txt","a");
        fprintf(credit_f,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",per.cin,per.prenom,per.nom,montant,duree,rev_ann,client.mois_restants);
        fclose(credit_f);
        textcolor(14);
        gotoxy(3,ligne+=2);cprintf("Tapez un boutton pour voir les INFOS de votre CREDIT");
        getch();
        getch();
        info_credit();


    //ajouter le mantant au solde dans user-file
    user_f=fopen("userInformation.txt","rt+");
    tmp_file=fopen("tmpVirement.txt","wt");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpVirement");
        exit(1);
    }

    while(!feof(user_f)){

        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin==client.cin){
            per.solde=per.solde + montant;
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
        else{
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
    }

    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpVirement.txt","userInformation.txt");

    }
    else{
        printf("l'offre que vous choisissez vous ne convient pas");
    }

}
//*********************************************
void info_credit(){

    int found=0,ligne=3,colonne=17;
    clrscr();

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(10,ligne++); cprintf("        Information Du Credit ");
    gotoxy(10,ligne++); cprintf("         ---------------------");

    credit_f=fopen("credit.txt","r");
    if(credit_f==NULL){
        printf("impossible d'ouvrir le fichier:credit");
        exit(1);
    }

    while(!feof(credit_f)){
        fscanf(credit_f,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",&client.cin,&client.prenom,&client.nom,&client.montant,&client.duree,&client.rev_annu,&client.mois_restants);
        if(client.cin==per.cin){
            found=1;
            break;
        }
    }
    fclose(credit_f);

    if(found==1){
        gotoxy(colonne,ligne); printf("MONTANT         :");gotoxy(colonne+18,ligne); textcolor(14);cprintf("%.2f",client.montant);
        gotoxy(colonne,++ligne); printf("DUREE           :");gotoxy(colonne+18,ligne); textcolor(14);cprintf("%d",client.duree);
        gotoxy(colonne,++ligne); printf("MOIS RESTANT    :");gotoxy(colonne+18,ligne); textcolor(14);cprintf("%d",client.mois_restants);
        gotoxy(colonne,++ligne); printf("MONTANT PAYE    :");gotoxy(colonne+18,ligne); textcolor(14);cprintf("%.2f",client.montant-(client.mois_restants*(client.montant/client.duree)));
        gotoxy(colonne,++ligne); printf("MONTANT RESTANT :");gotoxy(colonne+18,ligne); textcolor(14);cprintf("%.2f",client.mois_restants*(client.montant/client.duree));
        textcolor(14);
        gotoxy(8,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU ");
        getch();
        getch();
        cnx_menu();

    }
    else{
        textcolor(12);
        gotoxy(11,ligne+=3);cprintf("������������������������������������Ŀ");
        gotoxy(11,ligne+=1);cprintf("� Vous n'avez effectuer aucun credit �");
        gotoxy(11,ligne+=1);cprintf("��������������������������������������");
        textcolor(14);
        gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU du CREDIT");
        getch();
        getch();
        credit();

    }

}
//*********************************************
void modifier_informations(){
    int code=per.cin,ligne=3,colonne=37;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(10,ligne++); cprintf("      MODIFCATION D'INFORMATIONS ");
    gotoxy(10,ligne++); cprintf("       --------------------------");

    user_f=fopen("userInformation.txt","r");
    tmp_file=fopen("tmpFile.txt","w");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpFile");
        exit(1);
    }

    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin!=code){
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);

        }
        else{
            textcolor(14);
            gotoxy(15,ligne);printf("modifier le prenom :");
            gotoxy(colonne,ligne++);cscanf("%s",per.prenom);
            gotoxy(15,ligne);printf("modifier le nom    :");
            gotoxy(colonne,ligne++);cscanf("%s",per.nom);
            gotoxy(15,ligne);printf("modifier l'email   :");
            gotoxy(colonne,ligne++);cscanf("%s",per.email);
            gotoxy(15,ligne);printf("date de naissance  :");
            gotoxy(colonne,ligne++);cscanf("%s",per.date);

            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
    }
    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpFile.txt","userInformation.txt");

    textcolor(10);
    gotoxy(11,ligne+=2);cprintf("������������������������������������Ŀ");
    gotoxy(11,ligne+=1);cprintf("� Modification Des Infos Avec Succes �");
    gotoxy(11,ligne+=1);cprintf("��������������������������������������");

    textcolor(14);
    gotoxy(7,ligne+=3);cprintf("Tapez un boutton pour retourner vers le Menu");
    getch();
    getch();
    cnx_menu();
}
//*********************************************
void supprimer_compte(){
    int code=per.cin,ligne=3,colonne=12;
    int status;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(13,ligne++); cprintf("      SUPPRESSION DE COMPTE ");
    gotoxy(13,ligne++); cprintf("       ---------------------");

    user_f=fopen("userInformation.txt","r");
    tmp_file=fopen("tmpFileSupp.txt","w");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpFileSupp");
        exit(1);
    }

    while(!feof(user_f)){
        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        if(per.cin!=code){
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);

        }
    }
    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpFileSupp.txt","userInformation.txt");

    textcolor(10);
    gotoxy(colonne,ligne+=2);cprintf("������������������������������������Ŀ");
    gotoxy(colonne,ligne+=1);cprintf("� Suppression du comptet Avec Succes �");
    gotoxy(colonne,ligne+=1);cprintf("��������������������������������������");
    textcolor(14);
    gotoxy(7,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU ");
    getch();
    getch();
    user_login();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************
void manager_login(){
    int choix6,ligne=3,colonne=15;

    clrscr();
    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(12,ligne++); cprintf("        Menu de Manager ");
    gotoxy(12,ligne++); cprintf("         ------------------");
    gotoxy(colonne,ligne++);  printf("���������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�      1- SE CONNECTER      �");
    gotoxy(colonne,ligne++);  printf("���������������������������͹");
    gotoxy(colonne,ligne++);  printf("�      2- RETOUR            �");
    gotoxy(colonne,ligne++);  printf("���������������������������ͼ");

    gotoxy(colonne+=4,ligne++);  printf("�������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�  ENTREZ UN CHOIX  �");
    gotoxy(colonne,ligne);       printf("�������������������ͼ");
    gotoxy(colonne+=5,ligne++);      printf("���������ͻ");
    gotoxy(colonne,ligne++);         printf("�         �");
    gotoxy(colonne,ligne--);         printf("���������ͼ");
    gotoxy(colonne+=5,ligne++); scanf("%d",&choix6);

    switch(choix6){
        case 1: clrscr();
                se_connecter_manager();
                break;
        case 2: clrscr();
                login();
                break;
        default:manager_login();
                break;
    }

}
//*********************************************
void se_connecter_manager(){

    int code,found,ligne=3,colonne=5;
    char nom[20],prenom[20];

    textcolor(11);
    gotoxy(colonne,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(colonne,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(15,ligne++); cprintf("      Connexion Manager ");
    gotoxy(12,ligne++); cprintf("          -----------------");
    gotoxy(10,ligne++); printf("");
    textcolor(14);
    gotoxy(10,ligne++); cprintf("Entrez Votre Informations de Connexion");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�     1- CIN           �                         �");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     2- PRENOM        �                         �");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�     3- NOM           �                         �");
    gotoxy(colonne,ligne++);  printf("������������������������������������������������ͼ");



    manager_file=fopen("managerInformation.txt","r");
    if(manager_file==NULL){
        printf("impossible d'ouvrir le fichier");
        exit(1);
    }
    textcolor(14);
    gotoxy(35,ligne-=6); fflush(stdin);cscanf("%d",&code);
    gotoxy(35,ligne+=2); fflush(stdin);cscanf("%s",&prenom);
    gotoxy(35,ligne+=2); fflush(stdin); cscanf("%s",&nom);

    while(!feof(manager_file)){
        fscanf(manager_file,"%d\n%s\n%s\n",&manager.cin,manager.prenom,manager.nom);
        if(manager.cin==code && strcmp(manager.prenom,prenom)==0 && strcmp(manager.nom,nom)==0){
            found=1;
            break;
        }
    }
    fclose(manager_file);
    if(found==1){
        textcolor(10);
        gotoxy(18,ligne+=3);cprintf("���������������������Ŀ");
        gotoxy(18,ligne+=1);cprintf("�CONNEXION AVEC SUCCES�");
        gotoxy(18,ligne+=1);cprintf("�����������������������");
        textcolor(14);
        gotoxy(11,ligne+=2);cprintf("Taperz un boutton pour plus d'options");
        getch();
        getch();
        clrscr();
        cnx_menu_manager();
    }
    else{
        textcolor(12);
        gotoxy(16,ligne+=3);cprintf("������������������������Ŀ");
        gotoxy(16,ligne+=1);cprintf("�Informations Incorrectes�");
        gotoxy(16,ligne+=1);cprintf("��������������������������");
        textcolor(14);
        gotoxy(2,ligne+=2);cprintf("Tapez un boutton pour retourner vers le Menu Principal");
        getch();
        getch();
        login();
    }

}
//*********************************************
void cnx_menu_manager(){

    int choix7,ligne=3,colonne=12;
    clrscr();
    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(colonne,ligne++); cprintf("");
    gotoxy(colonne,ligne++); cprintf("");
    textcolor(13);
    gotoxy(14,ligne++); cprintf("      Menu Des Services ");
    gotoxy(14,ligne++); cprintf("       -----------------");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͻ");
    gotoxy(colonne,ligne++);  printf("�   1- POINTER APRES UN MOIS     �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�   2- INFORMATION UTILISATEURS  �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�   3- INFORMATION CREDITS       �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�   4- ARCHIVE DES CREDITS       �");
    gotoxy(colonne,ligne++);  printf("��������������������������������͹");
    gotoxy(colonne,ligne++);  printf("�           5- RETOUR            �");
    gotoxy(colonne,ligne++);  printf("��������������������������������ͼ");

    choisir:
    gotoxy(colonne+=7,ligne++);  printf("�������������������ͻ");
    gotoxy(colonne,ligne++);     printf("�  ENTREZ UN CHOIX  �");
    gotoxy(colonne,ligne);       printf("�������������������ͼ");
    gotoxy(colonne+=5,ligne++);  printf("���������ͻ");
    gotoxy(colonne,ligne++);     printf("�         �");
    gotoxy(colonne,ligne--);     printf("���������ͼ");
    textcolor(14);
    gotoxy(colonne+=5,ligne++); scanf("%d",&choix7);



    switch(choix7){
        case 1: {clrscr();
                 pointer();
                 break;}
        case 2: {clrscr();
                 display_users();
                 break;}
        case 3: {clrscr();
                 display_clients_credit();
                 getch();
                 break;}
        case 4: {clrscr();
                 display_archive();
                 getch();
                 break;}
        case 5: {clrscr();
                 manager_login();
                 getch();
                 break;}
        default:{cnx_menu_manager();
                 break;}
    }

}
//*********************************************
//apres un mois on modifie le solde = solde- mensualite(credit)
void pointer(){
    int found=0,ligne=3,colonne=17;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(16,ligne++); cprintf("        pointage ");
    gotoxy(16,ligne++); cprintf("         --------");

    //decrementer le nbre de mois restant du credit
    credit_f=fopen("credit.txt","r");
    tmp_file=fopen("tmpFile.txt","w");

    if(credit_f==NULL){
        printf("impossible d'ouvrir le fichier:credit");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpCreditFile");
        exit(1);
    }

    while(!feof(credit_f)){
        fscanf(credit_f,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",&client.cin,&client.prenom,&client.nom,&client.montant,&client.duree,&client.rev_annu,&client.mois_restants);
        client.mois_restants--;
        fprintf(tmp_file,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",client.cin,client.prenom,client.nom,client.montant,client.duree,client.rev_annu,client.mois_restants);
    }

    fclose(credit_f);
    fclose(tmp_file);
    remove("credit.txt");
    rename("tmpFile.txt","credit.txt");



    //modification du solde pour les personnes qui ont fait un credit
    user_f=fopen("userInformation.txt","r");
    tmp_file=fopen("tmpFile.txt","w");

    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:userInformation");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpFile");
        exit(1);
    }

    while(!feof(user_f)){

        fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
        //ouvrir credit_file pour voir si cette personne a un credit ou non
        credit_f=fopen("credit.txt","r");
        while(!feof(credit_f)){
            fscanf(credit_f,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",&client.cin,&client.prenom,&client.nom,&client.montant,&client.duree,&client.rev_annu,&client.mois_restants);
            if(per.cin==client.cin){
                per.solde=per.solde - (client.montant/client.duree);
                fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
                found=1;
                break;
            }
        }
        fclose(credit_f);
        if(found!=1){
            fprintf(tmp_file,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",per.cin,per.prenom,per.nom,per.date,per.gender,per.email,per.solde);
        }
        found=0;
    }

    fclose(user_f);
    fclose(tmp_file);
    remove("userInformation.txt");
    rename("tmpFile.txt","userInformation.txt");


    //supprimer les clients qui ont une duree restante egale a 0 mois du credit file
    credit_f=fopen("credit.txt","r");
    tmp_file=fopen("tmpFile.txt","w");
    archive_credit_file=fopen("archiveCreditFile.txt","a");

    if(credit_f==NULL){
        printf("impossible d'ouvrir le fichier:credit");
        exit(1);
    }
    if(tmp_file==NULL){
        printf("impossible d'ouvrir le fichier:tmpCreditFile");
        exit(1);
    }
    if(archive_credit_file==NULL){
        printf("impossible d'ouvrir le fichier:archiveCreditFile");
        exit(1);
    }

    while(!feof(credit_f)){
        fscanf(credit_f,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",&client.cin,&client.prenom,&client.nom,&client.montant,&client.duree,&client.rev_annu,&client.mois_restants);
        if(client.mois_restants!=0){
            fprintf(tmp_file,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",client.cin,client.prenom,client.nom,client.montant,client.duree,client.rev_annu,client.mois_restants);
        }
        //pour else on ajoute ce qui ont fini leurs credit dans un fichier d'archive
        else{
            fprintf(archive_credit_file,"%d\n%s\n%s\n%f\n%d\n",client.cin,client.prenom,client.nom,client.montant,client.duree);
        }
    }

    fclose(credit_f);
    fclose(tmp_file);
    fclose(archive_credit_file);
    remove("credit.txt");
    rename("tmpFile.txt","credit.txt");

    textcolor(10);
    gotoxy(18,ligne+=3);cprintf("����������������������Ŀ");
    gotoxy(18,ligne+=1);cprintf("� Pointage Avec Succes �");
    gotoxy(18,ligne+=1);cprintf("������������������������");
    textcolor(14);
    gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU du MANAGER");
    getch();
    getch();
    cnx_menu_manager();


}
//*********************************************
void display_users(){

    int ligne=3;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(5,ligne++); cprintf("        Les Informations des Utilisateurs ");
    gotoxy(5,ligne++); cprintf("         ---------------------------------");
    textcolor(1);
    gotoxy(1,ligne++); cprintf("��������������������������������������������������������ͻ");
    gotoxy(1,ligne++); cprintf("�   cin   �    prenom     �      nom      �    solde     �");
    gotoxy(1,ligne++); cprintf("��������������������������������������������������������ͼ");

    user_f=fopen("userInformation.txt","r");
    if(user_f==NULL){
        printf("impossible d'ouvrir le fichier:credit");
        exit(1);
    }
    while(!feof(user_f)){
            fscanf(user_f,"%d\n%s\n%s\n%s\n%s\n%s\n%f\n",&per.cin,per.prenom,per.nom,per.date,per.gender,per.email,&per.solde);
            textcolor(1);
            gotoxy(1,ligne++);cprintf(" �������������������������������������������������������� ");
            gotoxy(1,ligne);cprintf("�         �               �               �              �");
            textcolor(14);
            gotoxy(4,ligne);cprintf("%d",per.cin);
            gotoxy(13,ligne);cprintf("%s",per.prenom);
            gotoxy(29,ligne);cprintf("%s",per.nom);
            gotoxy(45,ligne++);cprintf("%.2f",per.solde);
    }
    textcolor(1);
    gotoxy(1,ligne++);cprintf(" �������������������������������������������������������� ");

    fclose(user_f);

    textcolor(14);
    gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU du CREDIT");
    getch();
    getch();
    cnx_menu_manager();
}
//*********************************************
void display_clients_credit(){
    int ligne=3;
    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(5,ligne++); cprintf("           Infos Des Credits Des Clients ");
    gotoxy(5,ligne++); cprintf("            -----------------------------");
    textcolor(1);
    gotoxy(1,ligne++); cprintf("��������������������������������������������������������ͻ");
    gotoxy(1,ligne++); cprintf("�  cin   �  Montant    � Duree �rev_annuelle�moisRestants�");
    gotoxy(1,ligne++); cprintf("��������������������������������������������������������ͼ");
    credit_f=fopen("credit.txt","r");
    if(credit_f==NULL){
        printf("impossible d'ouvrir le fichier:credit");
        exit(1);
    }

    while(!feof(credit_f)){
            fscanf(credit_f,"%d\n%s\n%s\n%f\n%d\n%f\n%d\n",&client.cin,&client.prenom,&client.nom,&client.montant,&client.duree,&client.rev_annu,&client.mois_restants);
            gotoxy(1,ligne++);cprintf(" �������������������������������������������������������� ");
            gotoxy(1,ligne);  cprintf("�        �             �       �            �            �");
            textcolor(14);
            gotoxy(4,ligne);   cprintf("%d",client.cin);
            gotoxy(13,ligne);  cprintf("%.2f",client.montant);
            gotoxy(27,ligne);  cprintf("%.d",client.duree);
            gotoxy(34,ligne);  cprintf("%.2f",client.rev_annu);
            gotoxy(51,ligne++);cprintf("%d",client.mois_restants);
    }
    textcolor(1);
    gotoxy(1,ligne++);cprintf(" �������������������������������������������������������� ");

    fclose(credit_f);

    textcolor(14);
    gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU du CREDIT");
    getch();
    getch();
    cnx_menu_manager();
}
//*********************************************
void display_archive(){

    int ligne=3;

    textcolor(11);
    gotoxy(5,ligne++); cprintf("     BIENVENUE DANS VOTRE BANQUE EN LIGNE  ");
    gotoxy(5,ligne++); cprintf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(5,ligne++); cprintf("");
    gotoxy(5,ligne++); cprintf("");
    textcolor(13);
    gotoxy(5,ligne++); cprintf("           Archives Des Credits ");
    gotoxy(5,ligne++); cprintf("            --------------------");
    textcolor(1);
    gotoxy(1,ligne++); cprintf("��������������������������������������������������������ͻ");
    gotoxy(1,ligne++); cprintf("�  cin   �   prenom   �    nom     �   Montant   � Duree �");
    gotoxy(1,ligne++); cprintf("��������������������������������������������������������ͼ");

    archive_credit_file=fopen("archiveCreditFile.txt","r");
    if(archive_credit_file==NULL){
        printf("impossible d'ouvrir le fichier:credit");
        exit(1);
    }

    while(!feof(archive_credit_file)){
            fscanf(archive_credit_file,"%d\n%s\n%s\n%f\n%d\n",&client.cin,client.prenom,client.nom,&client.montant,&client.duree);
            gotoxy(1,ligne++);cprintf(" �������������������������������������������������������� ");
            gotoxy(1,ligne);  cprintf("�        �            �            �             �       �");
            textcolor(14);
            gotoxy(4,ligne);   cprintf("%d",client.cin);
            gotoxy(12,ligne);  cprintf("%s",client.prenom);
            gotoxy(25,ligne);  cprintf("%s",client.nom);
            gotoxy(38,ligne);cprintf("%.2f",client.montant);
            gotoxy(52,ligne++);cprintf("%d",client.duree);
    }
    textcolor(1);
    gotoxy(1,ligne++);cprintf(" �������������������������������������������������������� ");

    fclose(archive_credit_file);

    textcolor(14);
    gotoxy(5,ligne+=2);cprintf("Tapez un boutton pour aller vers le MENU du CREDIT");
    getch();
    getch();
    cnx_menu_manager();
}
