Présentation du laboratoire 503
===============================

18 PC numérotés de 1 à 20 reliés en réseau avec une adresse IP fixe : 10.0.255.numéroPC.

Sur les PC du 503 sont installées deux distributions OS 15.2 Leap, une destinée aux cours du Bloc2 l'autre à ceux du Bloc3.

La distribution utilisée au laboratoire du BLOC2 est sur la partition /dev/sda3 et sda4 (ne vous trompez pas d'entrée dans le menu de Grub).

Un seul utilisateur : user0, password user0. 

Internet est accessible depuis les PC du laboratoire. ATTENTION toutefois: internet ne sera pas accessible pendant les examens. Habituez-vous dès à présent à vous servir uniquement des pages de manuel à partir de la console du PC en local.

Sur le bureau, ce fichier README.txt ainsi que les archives .tar des exercices de laboratoire



Quelques "trucs" pour commencer
===============================

1°) Pour éditer un texte, vous disposez de vi ou de kate.
2°) Pour compiler, observez les fichiers Makefile du répertoire SOURCES de chaque exercice. Le fonctionnement de l'outil make est présenté en séance 1.
3°) Pour générer un rapport en latex, voir les Makefile iassociés au chapitre ainsi que les fichiers tex.
4°) Pour les démonstrations des exercices, voir les scripts nommés Demo que vous devrez adapter à votre exercice le jour de l'examen.
5°) Comme navigateur : firefox.


Les travaux de laboratoire
==========================

Les exercices de laboratoires sont fournis sous la forme de fichiers archive au format tar : intro.tar ED.tar, Process.tar, IPC.tar, il est possible de visualiser leur contenu par la commande tar tvf xxx.tar exécutée depuis une console dans le répertoire Bureau.

1°) tar -xvf Nom.tar est la commande qui extrait depuis l'archive un nouveau dossier pour le chapitre d'exercices
2°) la commande make exécutée depuis le répertoire de plus haut niveau pour le chapître de chaque chapitre (intro,ed,process,ipc) génère et affiche le rapport du chapitre de laboratoire.
3°) make dans chaque répertoire SOURCES de chaque sujet de labo compile les sources qui s'y trouvent.
4°) ./Demo dans le répertoire SOURCES fournit une démonstration de la solution de l'exercice résolu (à partir de la deuxième séance de laboratoire).


travailler chez vous
====================

Les outils tar, latex, make et gcc doivent être installés pour le bon fonctionnement


Conseils d'utilisation
======================

1°) en début de chaque séance de laboratoire commencez par extraire le chapitre des exercices. Faites-le même si vous l'avez fait la semaine précédente, car entre temps votre travail a pu être remplacé par celui d'un autre étudiantEn effet, ce dernier peut avoir été modifié par l'étudiant précédent. (tar -xvf Nom.tar)
2°) make dans le répertoire du chapitre affiche un document .pdf. Une copie papier de ce document est à votre disposition
3°) Répéter, pour chaque énoncé
	3.1°) Lire l'énoncé
	3.2°) Imaginer une solution
	3.3°) Comparer votre solution et celle proposée
	3.4°) Lire et comprendre les commentaires
	3.5°) Se déplacer dans le répertoire SOURCES correspondant
	3.6°) Effectuer la compilation des sources (make)
	3.7°) Effectuer et la démonstration (./Demo)
	3.8°) Comprendre les résultats et le script de démonstration Demo
	3.9°) Noter vos remarques 
4°) Choisir un ou plusieurs exercices supplémentaires et les réaliser sans oublier
	4.1°) votre solution  
	4.2°) vos commentaires
	4.3°) votre rapport
	4.4°) un makefile qui affiche le rapport
	4.5°) dans SOURCES, un makefile qui compile et un script de démonstration
	4.6°) ...

Les laboratoires sont découpés en 4 sujets : intro, ED, Process, IPC. Les scripts sont intégrés dans chaque laboratoire. 


Travail en tant qu'administrateur
=================================

Certains laboratoires nécessitent de travailler avec des droits d'administrateur. Le responsable du laboratoire vous communiquera le mot de passe au moment voulu.
Vous veillerez à rester en administrateur le temps nécessaire à l'exercice uniquement. Vous quitterez ce mode à l'exercice suivant si celui-ci ne demande pas de tels droits.
Il est interdit de modifier la configuration des PC (images de fond, clavier, installations)
