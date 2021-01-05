#include <gtk/gtk.h>


void
on_radiobuttonNon_Defectieux_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonDefectieux_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAnnuler_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAjout_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAnnul_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonCherche_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAffich_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSave_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnuler_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonOui_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonNon_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Ajout_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Cherche_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Modif_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Return_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewAffichage_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonactiv_cherche_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonok_afficher_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAnnultt_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprim_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);
