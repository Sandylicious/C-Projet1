# Décryption du chiffrement de César

## Description

Ce programme permet de décrypter le chiffrement de César qui se trouve dans un fichier et d’enregistrer le déchiffrement dans un autre. Il doit donc recevoir un fichier ```entree.txt``` contenant le chiffrement au premier argument et un fichier ```sortie.txt```, qui sert à sauvegarder le déchiffrement. Cependant, il est important qu'aucune ligne du fichier dépasse 80 chars.

Le chiffrement de César est une méthode d'encryption par décalage de lettre. Dans ce programme, le décalage sera de trois. 

**Exemples de chiffrement**

* ```A``` devient ```D```
* ```B``` devient ```E```
* ```C``` devient ```F```
* ```a``` devient ```d```
* ```b``` devient ```e```
* ```c``` devient ```f```
* ```&``` devient ```&```

**Exemples de déchiffrement**

* ```A``` devient ```X```
* ```B``` devient ```Y```
* ```C``` devient ```Z```
* ```a``` devient ```x```
* ```b``` devient ```y```
* ```c``` devient ```z```
* ```&``` devient ```&```


## Auteur

Fang, Xin Ran

  
## Fonctionnement

**Guide d'utilisation**

Avant de pouvoir compiler un programme en ```C``` à l'aide de la ligne de commande, il faut s'assurer d'avoir déjà installé GCC ```GNU C Compiler``` sur le système.


**Compilation du programme César**

Pour compiler le programme ```cesar```, il faut utiliser l'une des deux commandes suivantes:

```
$ gcc -Wall -c cesar.c
```

```
$ make build
```


Pour faire l'édition des liens au programme ```cesar```, il faut utiliser l'une des trois commandes suivantes:

```
$ gcc -Wall cesar.c -o cesar
```

```
$ make
```

```
$ make link
```


Pour effacer les fichiers créés, il faut utiliser l'une des deux commandes suivantes:

```
$ rm -f cesar *.o *.txt
```

```
$ make clean
```


**Exécution du programme César**

Pour exécuter le programme ```cesar```, il faut utiliser la commande suivante:

```
$ ./cesar [entree.txt] [sortie.txt]
```

Si le fichier d'entrée s'appelle ```entree.txt``` et ```sortie.txt``` pour le fichier de sortie, il suffit de taper la commande suivante pour lancer le programme:

```
$ make start
```

* ```[entree.txt]``` représente le fichier qui contient le chiffrement, il doit être déjà créé avant de lancer le programme.
* ```[sortie.txt]``` représente le fichier qui sert à enregistrer le déchiffrement, si ce fichier existait avant que le programme soit lancé, son contenu sera effacé et sera remplacé par le déchiffrement.
  

**Cas d'erreur**

* Si tout va bien, le programme s'arrête et retourne le code ```0```.

* Si le nombre d'arguments n'égale pas à trois (exécutable, fichier d'entrée et fichier de sorite), un message d'erreur et le guide d'utilisation seront affichés. Puis le programme s'arrête et retourne le code ```1```.

* Si le fichier d'entrée n'existe pas, un message d'erreur et le guide d'utilisation seront affichés. Puis le programme s'arrête et retourne le code ```2```. 

* S'il y a une ligne du fichier d'entrée qui contient 80 chars et plus, un message d'erreur et le guide d'utilisation seront affichés. Puis le programme s'arrête et retourne le code ```3```. 


## Tests

Pour vérifier le fonctionnement du programme ```cesar```, il faut utiliser l'une des deux commandes afin de lancer une série de tests:

```
$ bats check.bats
```

```
$ make test
```

* Le 1er test vérifie ce qui va passer lorsqu'on lance le programme sans avoir indiqué les fichiers.
* Le 2e test vérifie ce qui va passer lorsqu'on lance le programme avec un fichier existant.
* Le 3e test vérifie ce qui va passer lorsqu'on lance le programme avec un fichier inexistant.
* Le 4e test vérifie ce qui va passer lorsqu'on lance le programme avec deux arguments avec lequel le fichier d'entrée n'existe pas. 
* Le 5e test vérifie ce qui va passer lorsqu'une ligne du fichier d'entrée dépasse 80 caractères.
* Le 6e test vérifie si le programme fonctionne correctement lorsqu'on le lance avec un fichier d'entrée existant et un fichier de sortie inexistant.
* Le 7e test vérifie si le programme décrypte correctement les lettres majuscules.
* Le 8e test vérifie si le programme décrypte correctement un ligne ayant à la fois des lettres majuscules, des lettres minuscules et des caractères.
* Le 9e test vérifie si le programme décrypte correctement deux lignes réprésentant deux sites web.
* Le 10e test vérifie si le programme décrypte correctement l'extrait d'un roman.
* Le 11e test vérifie si le programme décrypte correctement un texte de dix lignes.
* Le 12e test vérifie si le programme décrypte correctement un message compliqué représentant l'identité d'une personne qui est générée aléatoirement.
* Le 13e test vérifie si le programme décrypte correctement le message lorsqu'il n'y a qu'un seul caractère par ligne.
* Le 14e test vérifie si le programme décrypte correctement tous les caractères de la table ASCII.

Il y a 14 tests au total: 14 réussissent, 0 échoue.

## Dépendances

* [GCC](https://gcc.gnu.org/) - The GNU C Compiler
* [Vim](https://www.vimorg/) - The text editor
* [Bats](https://github.com/bats-core/bats-core/) - Bash Automated Testing System
* [GitLab-CI](https://docs.gitlab.com/ee/ci/) - Continuous Integration (CI)
