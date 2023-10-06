### 1. Structure
    - apprendre a utiliser errno

### 2. technical:

### 3. Parsing:
    - single quote:
             - does not expand
    - double quote:
             - if inside expand
             - if inside keep the spaces and single quote
    - pipes
    - redirections:
             - heredoc en cas de << with first word as delimiter
             - >> append to file after the operator
             - < use the file name to the right of this operator as input
             - > use the file name to the right as the output (overwrites)
    - commandes
    - expand
    - $?

### 4. Execution:
    - avoir une gestion d'erreur pour tout les builtins
    - Coder les builtins
    - gerer les signaux (pipe?) (ctrl-*)
    - Regarder le path des executables
    - redirections
    - pipes

### 5. Historique:
    - Setup
    - update
    - acces pour old_dir (cd -) etc

### ERROR && WORK LOG:
    LES DEUX:
        - comprendre les redirections etc
        - expand $?
    YANI:
        - faire gestion d'erreur (a verifier)
        - pre_tokken, if two spaces in a row
        - verifier la taille des splits quand un espace suivit d'une redirection
    JOSHUA:
        - heredoc: 
            - pendant l'execution on le feed à travers un pipe
        - gerer qu'il ai bien le bon nombre de redirection
        - verifier que les arg qui sont free disparaissent pas du tableau d'args quand on free les instances

### DONE:

    - stdout redir : creer le fichier avant de le remplir donc revoir condition erreur 
    - append: comme stdout redir
    - les redirections: le fd modifié doit etre associe a une command en particulier
    - heredoc: 
        - clean les simple et double du EOF
        - garde les simples et double de l'input
        - on met tout dans un seul char *heredoc
    - nettoyer aussi les doubles quotes
    - voir comment push sur l'intra
    - faire marcher le code 
    - rendre le code compilable
    - expand, check_sep (faire un tableau avec toutes les variables d'environnement)
    - nettoyage des singles_quotes avec la pre_tokkenization (attention a etre dans un double quote)
    - si le pre_tokken est le premier pre_tokken ou le premier apres un pipe c'est typer comme une commande

tricks pour avoir plus de variable global que 1: faire une fonction qui retourne qui retourne une adresse static, au
premier appel de la fonction tu alloue de la memoire a cette adrese et par la suite tu appelles la fonction pour acceder a la memoire.

t_list{
    char *commande;
    bool built_or_cmd;
    char **args;
    int fd_input;
    int fd_output;
}