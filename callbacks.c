#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>

#include <stdio.h> 
#include<string.h>
#include<stdlib.h>

#include <gtk/gtkclist.h>


#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
int x;

void
on_buttonAnnuler_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_Capteur, *First_page;
First_page=create_First_page();
gtk_widget_show(First_page);
gtk_widget_hide(Ajouter_Capteur);
}


void
on_buttonAjouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *marquee,*typee,*IDD,*dajour,*damois,*daannee,*dpjour,*dpmois,*dpannee;
GtkWidget *Ajouter_Valeur, *Ajouter_Capteur;
capteur C;
FILE *f;
marquee=lookup_widget(objet_graphique,"entryMarque");
typee=lookup_widget(objet_graphique,"entryType");
IDD=lookup_widget(objet_graphique,"entryID");
dajour=lookup_widget(objet_graphique,"comboboxdajj");
damois=lookup_widget(objet_graphique,"comboboxdamm");
daannee=lookup_widget(objet_graphique,"comboboxdaaa");
strcpy(C.Marque,gtk_entry_get_text(GTK_ENTRY(marquee)));
strcpy(C.Type,gtk_entry_get_text(GTK_ENTRY(typee)));
strcpy(C.ID,gtk_entry_get_text(GTK_ENTRY(IDD)));
strcpy(C.achat.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dajour)));
strcpy(C.achat.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(damois)));
strcpy(C.achat.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(daannee)));
if(x==1)
{
strcpy(C.Etat,"Non Defectieux");
ajouter_nondefectieux(C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat);
}
else
{
dpjour=lookup_widget(objet_graphique,"comboboxdpjj");
dpmois=lookup_widget(objet_graphique,"comboboxdpmm");
dpannee=lookup_widget(objet_graphique,"comboboxdpaa");
strcpy(C.Dpanne.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpjour)));
strcpy(C.Dpanne.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpmois)));
strcpy(C.Dpanne.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpannee)));
strcpy(C.Etat,"Defectieux");
ajouter_defectieux(C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee);
}
f=fopen("ID.txt","a+");
fprintf(f,"%s",C.ID);
fclose(f);
Ajouter_Valeur=create_Ajouter_Valeur();
gtk_widget_show(Ajouter_Valeur);
gtk_widget_hide(Ajouter_Capteur);
}


void
on_buttonAjout_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Vv,*jour,*mois,*annee,*hh,*min;
GtkWidget *Ajouter_Valeur, *First_page;
FILE *f1;
capteur C;
Vv=lookup_widget(objet_graphique,"entryValeur_C");
jour=lookup_widget(objet_graphique,"comboboxPrisejj");
mois=lookup_widget(objet_graphique,"comboboxPrisemm");
annee=lookup_widget(objet_graphique,"comboboxPriseaa");
hh=lookup_widget(objet_graphique,"spinbuttonHeure");
min=lookup_widget(objet_graphique,"spinbuttonMinute");
strcpy(C.val->V,gtk_entry_get_text(GTK_ENTRY(Vv)));
strcpy(C.val->Dprise.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
strcpy(C.val->Dprise.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
strcpy(C.val->Dprise.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(annee)));
C.val->h_prise.heure=gtk_spin_button_get_value_as_int(GTK_COMBO_BOX(hh));
C.val->h_prise.minute=gtk_spin_button_get_value_as_int(GTK_COMBO_BOX(min));
ajouter_valeur(C.val->V,C.val->Dprise.jour,C.val->Dprise.mois,C.val->Dprise.annee,C.val->h_prise.heure,C.val->h_prise.minute);
f1=fopen("Valeur_Capteur.txt","a+");
fprintf(f1," Valeur:%s | Date du prise: %s / %s / %s | Heure prise: %d:%d \n",C.val->V,C.val->Dprise.jour,C.val->Dprise.mois,C.val->Dprise.annee,C.val->h_prise.heure,C.val->h_prise.minute);
fclose(f1);
First_page=create_First_page();
gtk_widget_show(First_page);
gtk_widget_hide(Ajouter_Valeur);
}


void
on_buttonAnnul_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_Capteur, *Ajouter_Valeur;
Ajouter_Capteur=create_Ajouter_Capteur();
gtk_widget_show(Ajouter_Capteur);
gtk_widget_hide(Ajouter_Valeur);
}


void
on_buttonCherche_clicked               (GtkButton      *objet_graphique,
                                        gpointer         user_data)
{
GtkToggleButton *togglebutton,*radiobutton2modif;
GtkWidget *marquee,*typee,*IDD,*dajour,*damois,*daannee,*dpjour,*dpmois,*dpannee,*cherch;
capteur Cr;
char idcher[50];
cherch=lookup_widget(objet_graphique, "entryIDCherche");
strcpy(idcher,gtk_entry_get_text(GTK_ENTRY(cherch)));
Cr=rechercher(idcher);
FILE *f;
f=fopen("Capteur.txt","r");
marquee=lookup_widget(objet_graphique,"entryMarqueModif");
typee=lookup_widget(objet_graphique,"entryTypeModif");
IDD=lookup_widget(objet_graphique,"entryIDModif");
dajour=lookup_widget(objet_graphique,"comboboxdajjModif");
damois=lookup_widget(objet_graphique,"comboboxdammModif");
daannee=lookup_widget(objet_graphique,"comboboxdaaaModif");
gtk_entry_set_text(GTK_ENTRY(marquee),Cr.Marque);
gtk_entry_set_text(GTK_ENTRY(typee),Cr.Type);
gtk_entry_set_text(GTK_ENTRY(IDD),Cr.ID);
gtk_combo_box_set_active(GTK_COMBO_BOX(dajour),atoi(Cr.achat.jour));
gtk_combo_box_set_active(GTK_COMBO_BOX(damois),atoi(Cr.achat.mois));
gtk_combo_box_set_active(GTK_COMBO_BOX(daannee),atoi(Cr.achat.annee));
if(x==2)
{
radiobutton2modif=gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton));
dpjour=lookup_widget(objet_graphique,"comboboxdpjjModif");
dpmois=lookup_widget(objet_graphique,"comboboxdpmmModif");
dpannee=lookup_widget(objet_graphique,"comboboxdpaaModif");
gtk_combo_box_set_active(GTK_COMBO_BOX(dpjour),atoi(Cr.Dpanne.jour));
gtk_combo_box_set_active(GTK_COMBO_BOX(dpmois),atoi(Cr.Dpanne.mois));
gtk_combo_box_set_active(GTK_COMBO_BOX(dpannee),atoi(Cr.Dpanne.annee));
}
fclose(f);
}


void
on_buttonAffich_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_buttonAnnuler_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonNon_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_button_Cherche_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Recherche;
Recherche = create_Recherche ();
gtk_widget_show (Recherche);
}


void
on_button_Afficher_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage,*First_page;
Affichage = create_Affichage ();
gtk_widget_show(Affichage);
gtk_widget_hide(First_page);

}


void
on_button_Supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_Modif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *marquee,*typee,*IDD,*dajour,*damois,*daannee,*dpjour,*dpmois,*dpannee,*cherch;
capteur C1;
char idcher[50];
cherch=lookup_widget(objet, "entryIDCherche");
strcpy(idcher,gtk_entry_get_text(GTK_ENTRY(cherch)));
C1=rechercher(idcher);
marquee=lookup_widget(objet_graphique,"entryMarqueModif");
typee=lookup_widget(objet_graphique,"entryTypeModif");
IDD=lookup_widget(objet_graphique,"entryIDModif");
dajour=lookup_widget(objet_graphique,"comboboxdajjModif");
damois=lookup_widget(objet_graphique,"comboboxdammModif");
daannee=lookup_widget(objet_graphique,"comboboxdaaaModif");
strcpy(C1.Marque,gtk_entry_get_text(GTK_ENTRY(marquee)));
strcpy(C1.Type,gtk_entry_get_text(GTK_ENTRY(typee)));
strcpy(C1.ID,gtk_entry_get_text(GTK_ENTRY(IDD)));
strcpy(C1.achat.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dajour)));
strcpy(C1.achat.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(damois)));
strcpy(C1.achat.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(daannee)));
if(x==1)
{
strcpy(C.Etat,"Non Defectieux");
modifier_Capteur(C1);
}
else
{
dpjour=lookup_widget(objet_graphique,"comboboxdpjjModif");
dpmois=lookup_widget(objet_graphique,"comboboxdpmmModif");
dpannee=lookup_widget(objet_graphique,"comboboxdpaaModif");
strcpy(C1.Dpanne.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpjour)));
strcpy(C1.Dpanne.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpmois)));
strcpy(C1.Dpanne.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpannee)));
strcpy(C1.Etat,"Defectieux");
modifier_Capteur(C1);*/
}


void
on_button_Ajout_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_Capteur, *First_page;
gtk_widget_destroy(First_page);
Ajouter_Capteur=create_Ajouter_Capteur();
gtk_widget_show(Ajouter_Capteur);

}


void
on_radiobuttonNon_Defectieux_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobuttonDefectieux_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}

}


void
on_Return_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Affichage,*First_page;
First_page = create_First_page ();
gtk_widget_show(First_page);
gtk_widget_destroy(Affichage);
}


void
on_treeviewAffichage_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}





void
on_buttonok_afficher_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1,*affiche;
affiche = lookup_widget(objet_graphique,"buttonok_afficher");
treeview1 = lookup_widget(affiche,"treeviewAffichage");
afficher_capteurs(treeview1);
}


void
on_radiobutton1modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton2modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonAnnultt_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonSupprim_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonModifier_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *marquee,*typee,*IDD,*dajour,*damois,*daannee,*dpjour,*dpmois,*dpannee,*cherch;
capteur C1;
char idcher[50];
cherch=lookup_widget(objet_graphique, "entryIDCherche");
strcpy(idcher,gtk_entry_get_text(GTK_ENTRY(cherch)));
C1=rechercher(idcher);
marquee=lookup_widget(objet_graphique,"entryMarqueModif");
typee=lookup_widget(objet_graphique,"entryTypeModif");
IDD=lookup_widget(objet_graphique,"entryIDModif");
dajour=lookup_widget(objet_graphique,"comboboxdajjModif");
damois=lookup_widget(objet_graphique,"comboboxdammModif");
daannee=lookup_widget(objet_graphique,"comboboxdaaaModif");
strcpy(C1.Marque,gtk_entry_get_text(GTK_ENTRY(marquee)));
strcpy(C1.Type,gtk_entry_get_text(GTK_ENTRY(typee)));
strcpy(C1.ID,gtk_entry_get_text(GTK_ENTRY(IDD)));
strcpy(C1.achat.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dajour)));
strcpy(C1.achat.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(damois)));
strcpy(C1.achat.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(daannee)));
if(x==1)
{
modifier_Capteur(C1);
}
else
{
dpjour=lookup_widget(objet_graphique,"comboboxdpjjModif");
dpmois=lookup_widget(objet_graphique,"comboboxdpmmModif");
dpannee=lookup_widget(objet_graphique,"comboboxdpaaModif");
strcpy(C1.Dpanne.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpjour)));
strcpy(C1.Dpanne.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpmois)));
strcpy(C1.Dpanne.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dpannee)));
modifier_Capteur(C1);
}
}

