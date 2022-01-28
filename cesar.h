/**
 * Cette bibliotheque contient des constantes et des methodes qu'il 
 * faut implementer afin de pouvoir construire un programme permettant 
 * a la decryption du chiffrement de Cesar.
 *
 * @author Xin Ran Fang
 * @version 2021-11-14
 */

#ifndef CESAR_H
#define CESAR_H

#define NBR_MAX_CHAR_PAR_LIGNE 80
#define USAGE "Usage: ./cesar [entree.txt] [sortie.txt]\n"
#define MSG_ERR_NBR_ARG_INCORRECT "Erreur: Le nombre d'arguments doit equivaloir a 3.\n"
#define MSG_ERR_FICHIER_INEXISTANT "Erreur: Le fichier \"%s\" n'existe pas.\n"
#define MSG_ERR_DEPASSEMENT_DE_80_CHARS "Erreur: Il y a un depassament de 80 chars sur une ligne du fichier d'entree.\n"

enum erreur
{
    OK                      = 0, // Tout ok 
    ERR_NBR_ARG_INCORRECT   = 1, // Le nombre d'arguments est incorrect
    ERR_FICHIER_INEXISTANT  = 2, // Le fichier n'existe pas 
    ERR_DEPASSEMENT_80_CHAR = 3  // Le nombre de chars d'une ligne depasse 80 
};

typedef struct fichier
{
    int nbr_chars;
    char *texte;
} fichier;

/**
 * Cette methode s'assure que le nombre d'arguments soit 3 
 * (executable, fichier d'entree et fichier de sortie). 
 * Si ce n'est pas le cas, un message d'erreur et le guide 
 * d'utilisation seront affiches, puis le programme s'arrete.
 * 
 * @param	argc	nombre d'arguments que le programme a recu 
 */
void valider_nbr_arguments(int argc);

/**
 * Cette methode verifie si le fichier saisi par l'utilisateur existe.
 * S'il n'existe pas, un message d'erreur indiquant le nom du fichier 
 * inexistant et le guide d'utilisation seront affiches, puis le 
 * programme s'arrete.
 *
 * @param	nom_fichier	fichier a valider
 */
void valider_fichier(char *nom_fichier);

/**
 * Cette methode verifie s'il y a une ligne qui contient 80 chars et
 * plus. Si c'est le cas, un message d'erreur et le guide 
 * d'utilisation seront affiches, puis le programme s'arrete.
 *
 * @param   nom_fichier     fichier a valider
 */
void verifier_si_depassement_de_80_chars_par_ligne(char *nom_fichier);

/**
 * Cette methode appelle trois autres methodes afin de verifier si tout 
 * ce qui est saisi par l'utilisateur est valide.
 *
 * @param	argc	nombre d'arguments que le programme a recu 
 * @param   nom_fichier     fichier a valider
 */
void valider_arguments(int argc, char *nom_fichier);

/**
 * Cette methode compte le nombre de chars qu'un fichier contient et 
 * enregistre ce chiffre dans un struct fichier.
 *
 * @param	nom_fichier		nom du fichier
 * @param	nouveau_fichier	pointeur du struct fichier
 */
void compter_nbr_chars_du_fichier(char *nom_fichier, struct fichier *nouveau_fichier);

/**
 * Cette methode enregistre le chiffrement (contenu du fichier d'entree) 
 * dans un string qui se trouve a l'interieur d'un struct fichier.
 *
 * @param	nom_fichier		nom du fichier
 * @param	nouveau_fichier	pointeur du struct fichier
 */
void enregistrer_chiffrement_du_fichier_dans_string(char *nom_fichier, struct fichier *nouveau_fichier);

/**
 * Cette methode remplace une lettre par une autre en fonction d'un
 * decalage de 3 (A devient X, B devient Y, C devient Z, D devient A, 
 * E devient B, F devient C, etc). Uniquement les lettres seront 
 * remplacees, la casse sera preservee.
 * 
 * @param	lettre_a_decrypter	lettre a decrypter
 * @return 	lettre_a_decrypter	lettre decryptee 
 */
char decrypter_chiffrement(char lettre_a_decrypter);

/**
 * Cette methode appelle la fonction "decrypter_chiffrement" et enregistre
 * le decryptage dans un string qui se trouve a l'interieur d'un struct fichier.
 * 
 * @param	nouveau_fichier	pointeur du struct fichier
 */
void enregistrer_dechiffrement_dans_string(struct fichier *nouveau_fichier);

/**
 * Cette methode enregistre le dechiffrement dans un fichier.
 * 
 * @param	nom_fichier		nom du fichier
 * @param	nouveau_fichier	struct fichier qui contient le message decrypte
 */
void enregistrer_dechiffrement_dans_fichier(char *nom_fichier, struct fichier *nouveau_fichier);

#endif
