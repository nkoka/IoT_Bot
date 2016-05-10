Title:  RTC_SoftCtrlCmd

Author: Nicolas BIANCHI        
Date:   28 avril 2016

Introduction
======================

La partie software **SoftCtrlCmd** a besoin d'avoir une horloge pour exécuté des tâches et daté l'envoi des trames vers la partie logiciel **AdminCmd**. 
Le TimeStamp sera fournit par le software **AdminCmd** via un message de mise à jour du TimeStamp. 

Exécution tâches SoftCtrlCmd
===============================

La RTC devra fournit un moyen de fournir une horloge au software **SoftCtrlCmd** afin de permettre l'ordonnancement des tâches de ce software.

Matériel utilisé
--------------------

Le matériel choisi doit se baser sur un DS1307 et une pile bouton. Ce composant a été choisi pour réduire les coût associé. UN shield tous fait pourra être choisi pour plus de simplicité. Le shield choisi devra permettre d'obtenir une horloge dont la plus basse fréquence admissible est de ***1KHz***.

Les RTC actuelles permettre d'avoir une interruption externe sur une des broches du microcontrôleur associé. Ce choix est judicieux pour obtenir une horloge correcte.

Contraintes
-------------------------
Le soft **SoftCtrlCmd** doit maintenir un compteur en milliseconde afin d'exécuté les tâches. La mise à jour de ce compteur se fera par interruption il est nécessaire d'effectuer une protection sur ce compteur de type semaphore. Il est nécessaire de créer un élément logiciel qui permet de faire du synchronise de données. Comme le software **SoftCtrlCmd** est cadencé par timeslice et priorité, il est nécessaire du point de vue de l'horloge de créer un mécanisme de réveil de tâche. Mais aussi de fournir si besoin la date précise en ***timestamp***


Récapitulatif
==================

L'utilisation d'une RTC implique le développement des élements suivants :

 - Mécanisme de protection de donnée de type sémaphore
 - Mécanisme de réveil de tâche par événement
 - Mécanisme de récupération du timestamp



