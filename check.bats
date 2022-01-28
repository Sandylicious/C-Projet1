dossier_exemples=test_exemples
prog=cesar
usage="Usage: ./cesar [entree.txt] [sortie.txt]"
err_nbr_arg_incorrect="Erreur: Le nombre d'arguments doit equivaloir a 3."
err_depassement_de_80_chars="Erreur: Il y a un depassament de 80 chars sur une ligne du fichier d'entree."

# Cas anormaux

@test "Cas anormal 1 - Avec aucun argument, afficher message d'erreur et usage" {
	run ./$prog
	[ "$status" -eq 1 ]
	[ "${lines[0]}" = "$err_nbr_arg_incorrect" ]
	[ "${lines[1]}" = "$usage" ]
}

@test "Cas anormal 2 - Avec 1 argument (fichier d'entree existant), afficher message d'erreur et usage" {
	run ./$prog $dossier_exemples/ex1.txt
	[ "$status" -eq 1 ]
	[ "${lines[0]}" = "$err_nbr_arg_incorrect" ]
	[ "${lines[1]}" = "$usage" ]
}

@test "Cas anormal 3 - Avec 1 argument (fichier d'entree inexistant), afficher message d'erreur et usage" {
	run ./$prog 12345.txt
	[ "$status" -eq 1 ]
	[ "${lines[0]}" = "$err_nbr_arg_incorrect" ]
	[ "${lines[1]}" = "$usage" ]
}

@test "Cas anormal 4 - Avec 2 arguments (fichier d'entree inexistant), afficher le nom du fichier d'entree invalide et usage" {
	run ./$prog 12345.txt sortie.txt
	[ "$status" -eq 2 ]
	[ "${lines[0]}" = "Erreur: Le fichier \"12345.txt\" n'existe pas." ]
	[ "${lines[1]}" = "$usage" ]
}

@test "Cas anormal 5 - ex0.txt (decryptage d'un extrait ayant une ligne de 80 chars et plus), afficher message d'erreur et usage" {
	run ./$prog $dossier_exemples/ex0.txt sortie.txt
	[ "$status" -eq 3 ]
	[ "${lines[0]}" = "$err_depassement_de_80_chars" ]
	[ "${lines[1]}" = "$usage" ]
}

# Cas normaux

@test "Cas normal 1 - Avec 2 arguments (fichier d'entree existant, fichier de sortie inexistant), afficher le message decrypte du fichier sortie.txt" {
	run rm -f sortie.txt
	run ./$prog $dossier_exemples/ex1.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "$output" = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ]
}

@test "Cas normal 2 - Avec 2 arguments (fichier d'entree et fichier de sortie existants), afficher le message decrypte du fichier sortie.txt" {
	touch sortie.txt
	run ./$prog $dossier_exemples/ex1.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "$output" = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ]
}

@test "Cas normal 3 - ex2.txt (decryptage d'une ligne), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex2.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "$output" = "INF3135-Automne2021-TP2" ]
}

@test "Cas normal 4 - ex3.txt (decryptage de deux lignes ayant respectivement une adresse d'un site web), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex3.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "https://ena01.uqam.ca/my/" ]
	[ "${lines[1]}" = "https://ena01.uqam.ca/course/view.php?id=45041" ]
}

@test "Cas normal 5 - ex4.txt (decryptage de l'extrait d'un roman), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex4.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "The Little Prince" ]
	[ "${lines[1]}" = "Chapter 1" ]
	[ "${lines[2]}" = "Once when I was six years old I saw a magnificent picture in a book," ]
	[ "${lines[3]}" = "called True Stories from Nature, about the primeval forest." ]
	[ "${lines[4]}" = "It was a picture of a boa constrictor in the act of swallowing an animal." ]
	[ "${lines[5]}" = "Here is a copy of the drawing." ]
}
	
@test "Cas normal 6 - ex5.txt (decryptage d'un texte de 10 lignes), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex5.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "Est-ce toujours pertinent aujourd'hui d'apprendre le langage C dans une" ]
	[ "${lines[1]}" = "universite? Je crois que oui. Franchement, il est peu probable que la plupart" ]
	[ "${lines[2]}" = "des etudiants aient une experience professionnelle concrete et significative" ]
	[ "${lines[3]}" = "en langage C une fois gradues. Par contre, le C est la base de tous les" ]
	[ "${lines[4]}" = "langages modernes. La gestion de la memoire, la gestion des erreurs systemes" ]
	[ "${lines[5]}" = "et les pointeurs sont des fondements qu'on retrouve dans toute une gamme de" ]
	[ "${lines[6]}" = "langages de programmation. Ce sont des notions portables dans plusieurs" ]
	[ "${lines[7]}" = "contextes et avec plusieurs technologies. Egalement, c'est toujours bon de" ]
	[ "${lines[8]}" = "savoir comment ca fonctionne en-dessous. Apres tout, nous sommes des" ]
	[ "${lines[9]}" = "informaticiens et informaticiennes, pas juste des utilisateurs d'ordinateurs." ]
}

@test "Cas normal 7 - ex6.txt (decryptage de l'identite d'une personne generee aleatoirement), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex6.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "Randomly Generated Identity" ]
	[ "${lines[1]}" = "Name: Michael G. Williams" ]
	[ "${lines[2]}" = "Gender: M" ]
	[ "${lines[3]}" = "Birthday: October 25, 1994" ]
	[ "${lines[4]}" = "Age: 27 years old" ]
	[ "${lines[5]}" = "Address: 4718 Glory Road, Nashville, TN 37201" ]
	[ "${lines[6]}" = "Phone: 931-902-3801" ]
}

@test "Cas normal 8 - ex7.txt (decryptage de chars, un par ligne), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex7.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "SOME ASCII CHARACTERS" ]
	[ "${lines[1]}" = "!" ]
	[ "${lines[2]}" = "0" ]
	[ "${lines[3]}" = ":" ]
	[ "${lines[4]}" = "A" ]
	[ "${lines[5]}" = "^" ]
	[ "${lines[6]}" = "a" ]
	[ "${lines[7]}" = "~" ]
}

@test "Cas normal 9 - ex8.txt (decryptage de tous les chas de la table ASCII), afficher le message decrypte du fichier sortie.txt" {
	run ./$prog $dossier_exemples/ex8.txt sortie.txt && run cat sortie.txt
	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "!\"#$%&\\'()*+,-./0123456789:;<=>?" ]
	[ "${lines[1]}" = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\\]^_" ]
	[ "${lines[2]}" = "\`abcdefghijklmnopqrstuvwxyz{|}~" ]
}
