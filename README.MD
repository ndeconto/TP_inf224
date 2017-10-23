
## 4e étape 

Il faut déclarer la méthode play abstraite dans la classe de base.
La classe de base devient donc abstraite et n'est plus instanciable.


## 5e étape

Le polymorphisme permet de traiter les photos ou lse vidéos de manière générique
Le tableau contient des pointeurs vers les objets. Deux choses le montrent.

D'abord on remarque bien l'étoile dans le template :
```c++
std::array<BaseMultimediaBox*, 4> media_array {v1, v2, p1, p2};
```

Ensuite, pour accéder aux éléments du tableau, on utilise la flèche "->" et non pas le  "." .

```c++
media_array[i]->display(std::cout);
```


## 6è étape

Pour respecter le principe d'encapsulation, il faut faire une copie du tableau passé en paramètre à l'initialisation. 
Lorsqu'on renvoie le tableau de la durée des chapitres, on veille à renvoyer un const int*.
On redéfinit également la méthode setDuration, car la durée d'un film doit être égale à la somme des durées des chapitres 

## 7eme étape
A chaque fois qu'on fait un new, il faut ensuite qu'un delete soit fait. De même, si un new[] est fait, il faut faire un delete[].

Pour gérer les copies, on fait deux choses :
    - on redéfinit la copie constructor
    - on redéfinit l'opérateur =

On teste ensuite que les copies sont bien faites, ie que modifier la copie ne modifie pas l'objet initial.


## 8ème étape
Contrairement à Java, il serait possible en C++ de faire une liste d'objet, et non pas une liste de pointeurs d'objets. Toutefois, cela ne serait pas judicieux. D'abord parce que la liste peut contenir des objets de type différent, par exempel des vidéos ou des images. Il faut donc des pointeurs sur la classe de base. De plus, si un objet est dans plusieurs groupe, on veut qu'une modification de l'objet modifie ce que contiennent les groupes. Avec des pointeurs d'objets dans la liste, cela se fera "tout seul". Avec une liste d'objet, il faudrait le faire "manuellement", ce qui est pénible et source d'erreur. En outre, pour mettre un objet dans un groupe, il faudrait le recopier, ce qui est plus couteux que de copier la référence.

## 9ème étape

    



