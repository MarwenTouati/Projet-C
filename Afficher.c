#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
enum
{
Marque,Type,ID,Jour_d_achat,Mois_d_achat,Annee_d_achat,Etat,Jour_du_panne,Mois_du_panne,Annee_du_panne,Valeur,Jour_du_prise,Mois_du_prise,Annee_du_prise,Heure_du_prise,Minute_du_prise,COLUMNS
};
void afficher_capteurs (GtkWidget* list)
{

  GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;
  capteur C ;
char Dachat[50];
char Dpanne[50];
char Dprise[50];
char Hprise[50];
char hh[10];
char mm[10];
  store = NULL;

  FILE *f;
  store = gtk_tree_view_get_model(list);

  if (store==NULL)
  {
    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",Marque,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",Type,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Jour_d_achat",renderer,"text",Jour_d_achat,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Mois_d_achat",renderer,"text",Mois_d_achat,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Annee_d_achat",renderer,"text",Annee_d_achat,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",Etat,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
/*if(strcmp(Etat,"Defectieux")==0)
{*/
    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Jour_du_panne",renderer,"text",Jour_du_panne,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Mois_du_panne",renderer,"text",Mois_du_panne,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Annee_du_panne",renderer,"text",Annee_du_panne,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",Valeur,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Jour_du_prise",renderer,"text",Jour_du_prise,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Mois_du_prise",renderer,"text",Mois_du_prise,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Annee_du_prise",renderer,"text",Annee_du_prise,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Heure_du_prise",renderer,"text",Heure_du_prise,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Minute_du_prise",renderer,"text",Minute_du_prise,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

    store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f = fopen("Capteur.txt","r");

    if (f==NULL)
    {
      return;
    }
    else{
      while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %d %d \n",C.Marque,C.Type,C.ID,C.achat.jour,C.achat.mois,C.achat.annee,C.Etat,C.Dpanne.jour,C.Dpanne.mois,C.Dpanne.annee,C.val->V,C.val->Dprise.jour,C.val->Dprise.mois,C.val->Dprise.annee,C.val->h_prise.heure,C.val->h_prise.minute)!=EOF)
{

        gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,Marque,C.Marque,Type,C.Type,ID,C.ID,Jour_d_achat,C.achat.jour,Mois_d_achat,C.achat.mois,Annee_d_achat,C.achat.annee,Etat,C.Etat,Jour_du_panne,C.Dpanne.jour,Mois_du_panne,C.Dpanne.mois,Annee_du_panne,C.Dpanne.annee,Valeur,C.val->V,Jour_du_prise,C.val->Dprise.jour,Mois_du_prise,C.val->Dprise.mois,Annee_du_prise,C.val->Dprise.annee,Heure_du_prise,C.val->h_prise.heure,Minute_du_prise,C.val->h_prise.minute, -1);

      }
      fclose(f);
      gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
	g_object_unref(store);

    }
  }




}

