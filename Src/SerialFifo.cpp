/*****************************************
brief: fichier source du server
du robot de combat
*****************************************/
#include "SerialFifo.h"

void Fifo::Fifo()
{
	s16IndexLectBufferMsg = 0;
	s16IndexWritBufferMsg = 0;
}

sMsgServer * Fifo::GetMsgFifo()
{
	unsigned int u16IndexTemp = 0;
	/* SI les deux index ne sont pas égaux */
	if(abs(s16IndexLectBufferMsg-s16IndexWritBufferMsg)> 0)
	{
		/* Sauvegarde de l'index courant */
		u16IndexTemp = (unsigned int)s16IndexLectBufferMsg;
		s16IndexLectBufferMsg++;
		/* renvoi le message */
		return &aBufMsgServer[u16IndexTemp];
	}
	/* SI index égaux */
	else
	{
		/* retourne un pointeur NULL */
		return NULL;
	}
}
void Fifo::FlushMsgFifo();
{
	int s16IndexTmp = 0;s16IndexWritBufferMsg;
	for(s16IndexTmp = s16IndexWritBufferMsg;s16IndexTmp>=s16IndexLectBufferMsg;s16IndexTmp--)
	{

		aBufMsgServer[s16IndexTmp].paData = (void*)0;
		aBufMsgServer[s16IndexTmp].s16Size = 0;
	}
}
void Fifo::PushToFifo(sMsgServer *sMsg);
{

	/* SI la différence des indexes n'est pas négatif */
	if( abs(s16IndexLectBufferMsg-s16IndexWriteBufferMsg) <= MAX_MSG_SERVER)
	{
		/* SI index max */
		if(s16IndexWritBufferMsg == (MAX_MSG_SERVER-1) )
		{
			/* on reboucle sur le premier index */
			s16IndexWritBufferMsg = 0;
			/* si les deux index sont égaux */

		}
		if(s16IndexWritBufferMsg == s16IndexLectBufferMsg)
		{
			/* Problème trop de message */
			return;
		}
		(aBufMsgServer + (s16IndexWriteBufferMsg*sizeof(sMsgServer)) = sMsg;
		s16IndexWritBufferMsg++;
	}
}
sMsgServer * Fifo::PrintMsfFifo()
{
	char Buff[100] = " ";
	unsigned int u16Index = 0;
	for(u16Index=s16IndexLectBufferMsg;u16Index>=s16IndexWritBufferMsg;u16Index++)
	{
		sprintf(Buff,"Index:%d -> %s\r\n",u16Index,aBufMsgServer[s16IndexTmp].paData)
		Serial.println(Buff);
		memset(Buff,0,strlen(aBufMsgServer[s16IndexTmp].paData));
	}
}
