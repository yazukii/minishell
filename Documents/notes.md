### ERROR && WORK LOG:
    JOSHUA:
        - check if there is a redir but nothing behind syntax error
        - dans la nouvelle config de liste comment on gère le heredoc    
        - heredoc:  
            - pendant l'execution on le feed à travers un pipe
        - gestion des signaux:
            - ctrl-c: free tout et retourne le prompt
            - ctrl-d: ferme tout
            - ctrl-\: fait rien
        - gestion des signaux pendant le heredoc aussi
        - gestion d'erreur
### DONE:
        - if only builtin why stuff in arg
        - segfault avec les env
        - arg cassés avec pipe
        - free les lst_env
    - check builtin id (set builtins id at 7, but not sur if code needs refactoring)
    - ajouter liste chainée pour env
    - gestion d'erreur lié à la mémoire toutes les listes 
    - Free:
            - free les listes / ok
            - free les splits / ok
            - free les key /ok
    - refactor avec nouvelles listes (good?)
    - gerer qu'il ai bien le bon nombre de redirection
    - fill_args doit clean les redirections 
    - si on a deux redirections de suite ca casse
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