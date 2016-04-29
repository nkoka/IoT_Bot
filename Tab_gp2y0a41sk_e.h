/********************************************/
/* ce fichier est utilisé pour faire la     */
/* correspondance entre la valeur numérique */
/* du DAC et la distance réelle en          */
/* centimètre en passant par la tension du  */
/* et un index des deux tableaux décrit     */
/* ci-dessous                               */
/********************************************/
/********************************************/
/* correspondance du capeteur GP2y0a41sk_e  */
/* capteur SHARP                            */
/* 27->350                                  */
/* 25->400                                  */
/* 23->425                                  */
/* 22->520                                  */
/* 21->575                                  */
/* 19->625                                  */
/* 17->720                                  */
/* 15->825                                  */
/* 13->975                                  */
/* 11->1175                                 */
/* 9->1425                                  */
/* 7->1850                                  */
/* 5->2600                                  */
/* 3->4000                                  */
/********************************************/
/********************************************/
/* Tab correspondance index/tension         */
/* Index donne la tension multiplié par 10  */
/* tab[index] = V*10                        */
/********************************************/
const PROGMEM int tabCorrespondanceTabTelemetre[]={27,25,23,22,21,19,17,15,13,11,9,7,5,3};
/********************************************/
/* Tab correspondance index/distance        */
/* Index donne la distance multiplié par 100*/
/* tab[index] = Cm*100                      */
/********************************************/
const PROGMEM int TabTelemeter[]={350,400,425,520,575,625,720,825,975,1175,1425,1850,2600,4000};