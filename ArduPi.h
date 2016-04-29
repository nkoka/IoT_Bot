/**************************
bief : fichier d'en-tête 
du protocole arduino <-> RPi
***************************/
#ifndef _ArduPi_h_
#define _ArduPi_h_

#include "SerialFifo.h"

/* Structure d'un message du serveur */
typedef struct SMSG_ARDUPI
{
	unsigned int u16Id;
	unsigned int u16SizeData;
	char * pData;
}sMsgArduPi;

/* Classe server */
class ArduPi {
	
	private:
		sMsgArduPi aBufMsg[MAX_MSG_SERVER]; // buffer de réception
		int s16IndexLectBufferMsg; // index de lecture du buffer de message
		int s16IndexLectBufferMsg; // index d'écriture du buffer de message
	public:
		void ArduPi(sMsgServer * pMsg); // init du protocole
		sMsgServer * GetMsgFifo(); // récupération d'un message de la fifo
		void FlushMsgFifo(); // flush des messages du serveur
		void PushToMsgFifo(sMsgServer *sMsg); // ajout d'un message de la fifo
};
#endif //_ArduPi_h_