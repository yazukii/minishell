### 1. Structure
    - approche top-> down
    - faire une grosse structure?
    - Faire des Enums et des defines
    - apprendre a utiliser errno
    - var explicite

### technical:
    - var_length has a malloc but no free
    - var_val has a malloc but no free

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
    YANI:
    - faire gestion d'erreur (a verifier)
    - pre_tokken, if two spaces in a row
    - verifier la taille des splits quand un espace suivit d'une redirection
    JOSHUA:
    - faire marcher le code    
    - nettoyage des singles_quotes avec la pre_tokkenization (attention a etre dans un double quote)
    - si le pre_tokken est le premier pre_tokken ou le premier apres un pipe c'est typer comme une commande
### DONE:
    - rendre le code compilable
    - expand, check_sep (faire un tableau avec toutes les variables d'environnement)
tricks pour avoir plus de variable global que 1: faire une fonction qui retourne qui retourne une adresse static, au
premier appel de la fonction tu alloue de la memoire a cette adrese et par la suite tu appelles la fonction pour acceder a la memoire.
