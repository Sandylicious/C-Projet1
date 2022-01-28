/**
 * Ce programme permet de decrypter le chiffrement de Cesar qui se 
 * trouve dans un fichier et d’enregistrer le dechiffrement dans un 
 * autre fichier. Cependant, il est important qu'aucune ligne du 
 * fichier depasse 80 chars.
 * 
 * Le chiffrement de Cesar est une methode d'encryption par decalage
 * de lettre. Dans ce programme, le decalage sera de trois. Donc, 
 * A devient D, B devient E, C devient F, Z devient C et ainsi de suite. 
 * Seulement les lettres seont decryptees, la casse restera pareille. 
 *
 * De ce fait, apres le dechiffrement, A deviendra X, B deviendra Y, 
 * C deviendra Z, D deviendra A, E deviendra B, F deviendra C, etc.
 *
 * @author Xin Ran Fang
 * @version 2021-11-14
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cesar.h"

void valider_nbr_arguments(int argc)
{
    enum erreur erreur = ERR_NBR_ARG_INCORRECT;

    if (argc != 3)
    {
        fprintf(stderr, MSG_ERR_NBR_ARG_INCORRECT);
        printf(USAGE);
        exit(erreur);
    }
}

void valider_fichier(char *nom_fichier)
{
    enum erreur erreur = ERR_FICHIER_INEXISTANT;

    FILE *fp = fopen(nom_fichier, "r");

    if (fp == NULL)
    {
        fprintf(stderr, MSG_ERR_FICHIER_INEXISTANT, nom_fichier);
        printf(USAGE);
        exit(erreur);
    }

    fclose(fp);
}

void verifier_si_depassement_de_80_chars_par_ligne(char *nom_fichier)
{
    FILE *fp = fopen(nom_fichier, "r");
    char ligne[100];
    enum erreur erreur = ERR_DEPASSEMENT_80_CHAR;
    
    while (fgets(ligne, 100, fp) != NULL) 
    {
        if (strlen(ligne) > NBR_MAX_CHAR_PAR_LIGNE)
        {
            fprintf(stderr, MSG_ERR_DEPASSEMENT_DE_80_CHARS);
            printf(USAGE);
            exit(erreur);
        }
    } 

    fclose(fp);
}

void valider_arguments(int argc, char *nom_fichier)
{
    valider_nbr_arguments(argc);
    valider_fichier(nom_fichier);
    verifier_si_depassement_de_80_chars_par_ligne(nom_fichier);
}

void compter_nbr_chars_du_fichier(char *nom_fichier, struct fichier *nouveau_fichier)
{
    FILE *fp = fopen(nom_fichier, "r");
    int compteur_chars = 0;

    while (fgetc(fp) != EOF)
        compteur_chars++;

    nouveau_fichier->nbr_chars = compteur_chars;

    fclose(fp);
}

void enregistrer_chiffrement_du_fichier_dans_string(char *nom_fichier, struct fichier *nouveau_fichier)
{
    FILE *fp = fopen(nom_fichier, "r");
    int i = 0;

    while((nouveau_fichier->texte[i] = fgetc(fp)) != EOF)
        i++;

    nouveau_fichier->texte[i] = '\0';

    fclose(fp);
}

char decrypter_chiffrement(char lettre_a_decrypter)
{
    if (isalpha(lettre_a_decrypter) && isupper(lettre_a_decrypter))
    {
        lettre_a_decrypter = lettre_a_decrypter - 3;

        if (isalpha(lettre_a_decrypter) == 0)
            lettre_a_decrypter = lettre_a_decrypter + 'Z' - 'A' + 1;
    }
    else if (isalpha(lettre_a_decrypter) && islower(lettre_a_decrypter))
    {
        lettre_a_decrypter = lettre_a_decrypter - 3;

        if (isalpha(lettre_a_decrypter) == 0)
            lettre_a_decrypter = lettre_a_decrypter + 'z' - 'a' + 1;
    }

    return lettre_a_decrypter;
}

void enregistrer_dechiffrement_dans_string(struct fichier *nouveau_fichier)
{
    char lettre_a_decrypter;
    int i;

    for (i = 0; nouveau_fichier->texte[i] != '\0'; i++)
    {
        lettre_a_decrypter = nouveau_fichier->texte[i];

        nouveau_fichier->texte[i] = decrypter_chiffrement(lettre_a_decrypter);
    }
}

void enregistrer_dechiffrement_dans_fichier(char *nom_fichier, struct fichier *nouveau_fichier)
{
    FILE *fp = fopen(nom_fichier, "w");
    char *dechiffrement;
    dechiffrement = nouveau_fichier->texte;
    
    fputs(dechiffrement, fp);

    fclose(fp);
}

int main (int argc, char *argv[])
{
    valider_arguments(argc, argv[1]);

    fichier nouveau_fichier;
    
    compter_nbr_chars_du_fichier(argv[1], &nouveau_fichier);

    nouveau_fichier.texte = malloc(sizeof(char) * nouveau_fichier.nbr_chars + 1);

    enregistrer_chiffrement_du_fichier_dans_string(argv[1], &nouveau_fichier);
    enregistrer_dechiffrement_dans_string(&nouveau_fichier);
    enregistrer_dechiffrement_dans_fichier(argv[2], &nouveau_fichier);

    free(nouveau_fichier.texte);

    enum erreur ok = OK;

    return ok;
}
