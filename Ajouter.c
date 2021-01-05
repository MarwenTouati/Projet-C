#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"

void ajouter_nondefectieux(char Marque[50],char Type[50],char ID[50],char jj[32],char mm[13],char aa[32],char Etat[100])
{
FILE *f;
f=fopen("Capteur.txt","a+");
fprintf(f,"Marque:%s | Type:%s | ID:%s | Date d'achat: %s / %s / %s | Etat: %s ",Marque,Type,ID,jj,mm,aa,Etat);
fclose(f);
}

void ajouter_defectieux(char Marque[50],char Type[50],char ID[50],char jj[32],char mm[13],char aa[32],char Etat[100],char jjp[32],char mmp[13],char aap[32])
{
FILE *f;
f=fopen("Capteur.txt","a+");
fprintf(f,"Marque:%s | Type:%s | ID:%s | Date d'achat: %s / %s / %s | Etat: %s | Date du panne: %s / %s / %s ",Marque,Type,ID,jj,mm,aa,Etat,jjp,mmp,aap);
fclose(f);
}

void ajouter_valeur(char Val[1000],char jjprise[32],char mmprise[13],char aaprise[32],int hhprise,int minprise)
{
FILE *f;
f=fopen("Capteur.txt","a+");
fprintf(f,"|| Valeur:%s | Date du prise: %s / %s / %s | Heure prise: %d:%d \n",Val,jjprise,mmprise,aaprise,hhprise,minprise);
fclose(f);
}


/*void supprimer_capteur(char*ID)
{
FILE*f=NULL;
FILE*f1=NULL;
capteur C ;
f=fopen("Capteur.txt","r");
f1=fopen("ancienCapteur.txt","w+");
while(!EOF)
{
fscanf(f,"%s %s %s %s %s %s %s \n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat);
if((strcmp(C.Etat,"Defectieux")==0)&&(strcmp(ID,C.ID)!=0))
{
fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee);
fprintf(f1,"Marque:%s | Type:%s | ID:%s | Date d'achat: %s / %s / %s | Etat: %s | Date du panne: %s / %s / %s \n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee);
}
if((strcmp(C.Etat,"Non Defectieux")==0)&&(strcmp(ID,C.ID)!=0))
{
fscanf(f,"%s %s %s %s %s %s %s \n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat);
fprintf(f1,"Marque:%s | Type:%s | ID:%s | Date d'achat: %s / %s / %s | Etat: %s \n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat);
}
}
fclose(f);
fclose(f1);
remove("Capteur.txt");
rename("ancienCapteur.txt","Capteur.txt");
}*/

capteur rechercher (char ID[50])
{
    FILE *f;

capteur C;
    

    f=fopen("Capteur.txt","r");
if(f!=NULL)
{
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %d %d\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee,C.val->V,C.val->Dprise.jour,C.val->Dprise.mois,C.val->Dprise.annee,C.val->h_prise.heure,C.val->h_prise.minute)!=EOF)
    {
        if((strcmp(C.ID,ID)==0))
        {
	 printf("ok \n");
	return C;
fclose(f);
	}
        
		strcpy(C.Marque,"erreur");
		strcpy(C.Type,"erreur");
		strcpy(C.ID,"erreur");
                strcpy(C.Etat,"erreur");
                
                

			    
    }
	
    fclose (f);}
    return C;

}

void modifier_Capteur(capteur C1)
{
    FILE*f;
    FILE*c;
    capteur C;
    char ID[50];
    f=fopen("Capteur.txt","r");
    c=fopen("tmp.txt","a+");

    
    if(f!=NULL)
    { 
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat)!=EOF)
        {
if (strcmp(C.Etat,"Defectieux")==0)
{

if(c!=NULL)
    { 
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee)!=EOF)
        {

		printf("\n %s \n",C1.ID);
            if(strcmp(C.ID,C1.ID)!=0)
            {
                fprintf(c,"%s %s %s %s %s %s %s %s %s %s\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee);	
			printf("\n oki \n");

            }
            else
            { printf("\n oki1 \n");



                fprintf(c,"%s %s %s %s %s %s %s %s %s %s\n",C1.Marque,C1.Type,C1.ID,C1.achat.jour,C1.achat.mois,C1.achat.annee,C1.Etat,C1.Dpanne.jour,C1.Dpanne.mois,C1.Dpanne.annee);
            }
        }
        fclose(f);
        fclose(c);
remove("Capteur.txt");
rename("tmp.txt","Capteur.txt");

    }
    }
}
}
else
{
if(c!=NULL)
    { 
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat)!=EOF)
        {

		printf("\n %s \n",C1.ID);
            if(strcmp(C.ID,C1.ID)!=0)
            {
                fprintf(c,"%s %s %s %s %s %s %s %s %s %s\n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat);	
			printf("\n oki \n");

            }
            else
            { printf("\n oki1 \n");



                fprintf(c,"%s %s %s %s %s %s %s %s %s %s\n",C1.Marque,C1.Type,C1.ID,C1.achat.jour,C1.achat.mois,C1.achat.annee,C1.Etat);
            }
        }
        fclose(f);
        fclose(c);
remove("Capteur.txt");
rename("tmp.txt","Capteur.txt");
}
}


}





