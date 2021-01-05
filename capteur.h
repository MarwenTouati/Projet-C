#ifndef CAPTEUR_H_
#define CAPTEUR_H_
typedef struct
{
char jour[32];
char mois[13];
char annee[50];
}Date;
typedef struct
{
int heure;
int minute;
}horaire;
typedef struct 
{
char V[1000];
Date Dprise;
horaire h_prise;
}valeur;
typedef struct
{
char Marque[50];
char Type[50];
char ID[50];
char Etat[100];
Date achat;
Date Dpanne;
valeur val[200];
}capteur;


void ajouter_nondefectieux(char Marque[50],char Type[50],char ID[50],char jj[32],char mm[13],char aa[32],char Etat[100]);
void ajouter_defectieux(char Marque[50],char Type[50],char ID[50],char jj[32],char mm[13],char aa[32],char Etat[100],char jjp[32],char mmp[13],char aap[32]);
void ajouter_valeur(char Val[1000],char jjprise[32],char mmprise[13],char aaprise[32],int hhprise,int minprise);
capteur rechercher (char ID[50]);
void modifier_Capteur(capteur C1);
void Supprimer();
//nb_cptr_va
void afficher_capteurs (GtkWidget* list);
void Consulter();


#endif
