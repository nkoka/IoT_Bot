/**************************
bief : fichier d'en-tête 
du server du robot
***************************/
#ifndef _SerialFifo_h_
#define _SerialFifo_h_

#define MAX_MSG_SERVER	(unsigned int)20

/* Structure d'un message du serveur */
typedef struct SMSG_SERVER
{
	char * paData;
	unsigned int s16Size;
}sMsgServer;

/* Classe server */
class Fifo {
	
	private:
		sMsgServer aBufMsgServer[MAX_MSG_SERVER]; // buffer de réception
		int s16IndexLectBufferMsg; // index de lecture du buffer de message
		int s16IndexLectBufferMsg; // index d'écriture du buffer de message
	public:
		void Fifo::Fifo(); // init du serveur
		sMsgServer * GetMsgFifo(); // récupération d'un message de la fifo
		void FlushMsgFifo(); // flush des messages du serveur
		void PushToMsgFifo(sMsgServer *sMsg); // ajout d'un message de la fifo
};
#endif //_SerialFifo_h_