Mouvement 
-------------------------

Le principe utilisé par le robot est basé sur la logique Flou. Il fonctionne par objectif à atteindre.

Objectif
---------------

Un objectif se constitue d'action à mener à bien
exemple : aller de l'autre coté de la pièce :

Tant que objectif non atteint
 - Déterminer la direction globale
 - Déterminer la direction locale
 -Si nécessaire, éviter obstacle, recalculer direction globale, recalculer direction locale
 
Les actions sont déterminées selon un comportement défini par l'environnement "ROBOT"

Environnement
----------------------------

Les éléments faisant varier l'environnement sont :
- un obstacle (y compris "trou"
- une batterie faible robot
- la visibilité du robot
