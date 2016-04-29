Title:  Protocole ArduPi

Author: Nicolas BIANCHI        
Date:   28 avril 2016

Introduction
======================

Médium
--------------
Ce protocole d'échange entre un arduino et un raspberry pi permet d'échanger des information sur un lien série  via les ports USB.

Déterminisme
---------------
Il est important de définir une trame type afin de pouvoir définir la taille de la trame max et rendre le système arduino déterministe

Protocole
=========================
Toutes Trames/Messages envoyés doivent être confirmées (ACK)
 
Header
-------------------

Le header de la trame consiste en un octet de start et la taille des données de la trame à envoyer.
La taille des données à envoyer sont écrit sur un octet soit une taille max e 256 octets

**|Start Frame (11)|Size|**

Le header fait donc 2 octets 

Pied de trame
--------------------
Le Pied de trame se constitue du CRC16 de la trame et un octet de fin de trame

**|High CRC|Low CRC|End of Frame (FF)|**

Le Pied de trame fait 3 octets

###CRC16
Nous avons choisi un CRC 16 afin d'avoir peut d'octet de CRC

###fonction CRC16
		unsigned short crc16(const unsigned short* addr, int count)
		{
		    unsigned int sum = 0;
		    while( count > 1 ) {
		         sum += *addr++;
		         count -= 2;
		    }
		    if (count)
		         sum += * (unsigned char *) addr;
		    while (sum>>16)
		         sum = (sum & 0xffff) + (sum >> 16);
		    return (unsigned short) ~sum;
		}

Data
--------------------
Les données de la trame autont le forme suivantes :
1 octet d'identifiant du message
size octet(s) de donnée(s)

**|ID Frame|...Data...|TimeStamp3|TimeStamp2|TimeStamp1|TimeStamp0|**

Le corps de trame fait size octets + 1 + 4

Temps d'envoi et de confirmation trame
---------------------------------------------------
Les trames seront de la forme suivantes:

**|Start Frame (11)|Size|ID Frame|...Data...|TimeStamp3|TimeStamp2|TimeStamp1|TimeStamp0|High Byte CRC|Low Byte CRC|End of Frame (FF)|**

Le calcul du CRC16 est effectué sur la donnée soit :

 - Taille de la trame
 - ID de la trame 
 - la data de la trame

###Temps d'envoi

La taille max de la trame sera de 2 + 1 + 4 + 256 + 3 = 266 octets max

Ainsi pour un baud rate de 9600 baud à valence 1. Le système mettra 266*7/9600s à émettre la trame soit 191.2 ms
Avec un baud rate de 115200 à même valence le système mettra 16ms à envoyer la trame. Ceci reviens à envoyé 10 fois plus vite la trame.

###Temps de confirmation trame

Une trame de confirmation sera de la forme suivante :

**|Start Frame (11)|02|00|ACK/NACK|TimeStamp3|TimeStamp2|TimeStamp1|TimeStamp0||High Byte CRC|Low Byte CRC|End of Frame (FF)|**


Soit 7 octets à transmettre, ceci reviens à un temps d'envoi de 11*7/9600s =  6ms. Avec un baud rate de 115200 bauds, le système enverra le message en 500us

###conclusion temps de transsmission

Afin d'avoir un système de transmission efficace, il est nécessaire d'avoir un baud rate de 115200.

Messages
-----------------------------------

###Message de vie 


###Message Maj RTC


###Message GenericData


###Message de confirmation



