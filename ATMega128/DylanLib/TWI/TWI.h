﻿/*
 * TWI.h
 *
 * Created: 2018-04-15 오전 1:28:21
 *  Author: kazam
 */ 


#ifndef TWI_H_
#define TWI_H_

#include "DataQueue.h"

#define NO_ERROR		0
#define TIME_OUT		1

#define MASTER_MODE		0
#define SLAVE_MODE		1

#define BLOCKING		0
#define NON_BLOCKING	1

#define WRITE			0
#define READ			1

#define ACK_READ		0
#define NACK_READ		1

typedef struct TWI_HANDLE {
	uint8_t		Address;
	uint8_t		Mode;			// Blocking / Non-Blocking
	uint8_t		Status;
	uint32_t	System_Clock;	// System Frequency.
	uint32_t	Comm_FRQ;		// Communication Frequency.
	hQueue		hTX_Buf;		// Transmit Buffer Handle.
	hQueue		hRX_Buf;		// Receive Buffer Handle.
} hTWI;

uint8_t SetSCL(hTWI* hKey, uint32_t Comm_FRQ);
uint8_t TWI_Start(hTWI* hKey);
uint8_t TWI_Stop(hTWI* hKey);
uint8_t TWI_Check(hTWI* hKey, uint8_t Status);
uint8_t TWI_Call_Slave(hTWI* hKey, uint8_t RW_Mode);
uint8_t TWI_Call_Master(hTWI* hKey, uint8_t RW_Mode);
uint8_t TWI_MT_Mode(hTWI* hKey, uint8_t data);
uint8_t TWI_MR_Mode(hTWI* hKey, uint8_t* buf, uint8_t Ack_Mode);
uint8_t TWI_ST_Mode(hTWI* hKey, uint8_t data);
uint8_t TWI_SR_Mode(hTWI* hKey, uint8_t* buf, uint8_t Ack_Mode);

uint8_t TWI_MT_Register(hTWI* hKey, uint8_t StartAddr, uint8_t* Buf, uint8_t Length);
uint8_t TWI_MR_Register(hTWI* hKey, uint8_t StartAddr, uint8_t* Buf, uint8_t Length);

uint8_t Init_TWI(hTWI* hKey, uint32_t System_Clock, uint32_t Comm_FRQ, uint8_t Mode, uint8_t Address);

#endif /* TWI_H_ */