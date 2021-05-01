#pragma once

#include "clientclass.h"
#include <stdbool.h>

typedef enum {
	GET_ALL_CLASSES = 8,
	DISPATCH_USER_MESSAGE = 38
} client_indexes_t;

typedef enum {
	CS_UM_VGUIMENU = 1,
	CS_UM_GEIGER = 2,
	CS_UM_TRAIN = 3,
	CS_UM_HUDTEXT = 4,
	CS_UM_SAYTEXT = 5,
	CS_UM_SAYTEXT2 = 6,
	CS_UM_TEXTMSG = 7,
	CS_UM_HUDMSG = 8,
	CS_UM_RESETHUD = 9,
	CS_UM_GAMETITLE = 10,
	CS_UM_SHAKE = 12,
	CS_UM_FADE = 13,
	CS_UM_RUMBLE = 14,
	CS_UM_CLOSECAPTION = 15,
	CS_UM_CLOSECAPTIONDIRECT = 16,
	CS_UM_SENDAUDIO = 17,
	CS_UM_RAWAUDIO = 18,
	CS_UM_VOICEMASK = 19,
	CS_UM_REQUESTSTATE = 20,
	CS_UM_DAMAGE = 21,
	CS_UM_RADIOTEXT = 22,
	CS_UM_HINTTEXT = 23,
	CS_UM_KEYHINTTEXT = 24,
	CS_UM_PROCESSSPOTTEDENTITYUPDATE = 25,
	CS_UM_RELOADEFFECT = 26,
	CS_UM_ADJUSTMONEY = 27,
	CS_UM_UPDATETEAMMONEY = 28,
	CS_UM_STOPSPECTATORMODE = 29,
	CS_UM_KILLCAM = 30,
	CS_UM_DESIREDTIMESCALE = 31,
	CS_UM_CURRENTTIMESCALE = 32,
	CS_UM_ACHIEVEMENTEVENT = 33,
	CS_UM_MATCHENDCONDITIONS = 34,
	CS_UM_DISCONNECTTOLOBBY = 35,
	CS_UM_PLAYERSTATSUPDATE = 36,
	CS_UM_DISPLAYINVENTORY = 37,
	CS_UM_WARMUPHASENDED = 38,
	CS_UM_CLIENTINFO = 39,
	CS_UM_XRANKGET = 40,
	CS_UM_XRANKUPD = 41,
	CS_UM_CALLVOTEFAILED = 45,
	CS_UM_VOTESTART = 46,
	CS_UM_VOTEPASS = 47,
	CS_UM_VOTEFAILED = 48,
	CS_UM_VOTESETUP = 49,
	CS_UM_SERVERRANKREVEALALL = 50,
	CS_UM_SENDLASTKILLERDAMAGETOCLIENT = 51,
	CS_UM_SERVERRANKUPDATE = 52,
	CS_UM_ITEMPICKUP = 53,
	CS_UM_SHOWMENU = 54,
	CS_UM_BARTIME = 55,
	CS_UM_AMMODENIED = 56,
	CS_UM_MARKACHIEVEMENT = 57,
	CS_UM_MATCHSTATSUPDATE = 58,
	CS_UM_ITEMDROP = 59,
	CS_UM_GLOWPROPTURNOFF = 60,
	CS_UM_SENDPLAYERITEMDROPS = 61
} cstrike15_user_message_t;

typedef struct {
	char pad1[64];
} base_client_dll_t;

client_class_t* client_get_all_classes();
bool client_dispatch_user_message(int message_type, unsigned int arg_1, unsigned int arg_2);