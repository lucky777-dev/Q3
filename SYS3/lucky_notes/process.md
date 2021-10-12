# SYS3

# Process

> `Processus:` Logiciel qui tourne en RAM

## Process table

> La table des processus liste tous les processus ainsi que leurs informations.<br>
`ps` permet de voir la table dans un terminal Linux.

linux@user$: `ps axjf`
- `a` = all
- `x` = même ceux qui ne sont pas lié à un terminal
- `j` = avec parents
- `f` = mode 'graphique' d'affichage

La variable d'environnement `$` du shell contient son identifiant: `echo $$`

Les process sont visibles dans le dossier `/proc/`.<br>
`ls /proc/ PID` affiche les informations du process.<br>
L'appel système `getpid` retourne l'identifiant d'un process. (`getppid` pour parent)

Contenu de la table des process:
- `PID`
- `PPID`
- `Table de pages`
- `RIP (contexte, RAX)`
- `État (bloqué, élu, prêt)`
- `Table des signaux`
- `Table des traitements associés au signaux`

> Les démons sont des processus qui tournent en permanence en arrière plan.

## init

Au lancement du système, le process `init/systemd` est créé par le noyau. Celui-ci est actif en permanence, on ne pourra pas le `kill`. Il initialise le système et les services.

`init/systemd` appartient à l'administrateur (root). Il possède le **PID `1`**.

> `Commande EXTERNE` (-> clonage)<br>
> Fichier exécutable (dans /bin/ par exemple)
>> manuel contenu dans le manuel de la commande `which ls`
>
> `Commande INTERNE` (-> pas de clonage)<br>
> Commande contenue dans le code du shell même<br>
>> manuel contenu dans le manuel de bash `man bash`

## fork()

> Appel système qui dédouble/clone le process appelant.<br>
> - Le fils hérite d'une copie des variables de son père.<br>
> - Les deux process repartent du même **RIP**<br>
> - Les process sont indépendants, l'un ne peut pas modifier l'environnement de l'autre.
- Sauvegarde le contexte du process courant dans la table des process
- Clone le process
    - Dédoublement de l'entrée de la table des process
    - Dédoublement de l'espace d'adressage
    - adaptation de certaines valeurs
- Appel à l'ordonnanceur