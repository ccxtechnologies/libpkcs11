/*
  * Copyright 2017 NXP
  * SPDX-License-Identifier:     BSD-3-Clause
*/

#ifndef ___CRYPTO_H_INC___
#define ___CRYPTO_H_INC___

#include <sessions.h>

#define MAX_RSA_KEYLEN	512
#define MAX_HASH_LEN	64

/* RSA block formatting types */
#define RSA_PKCS_BT_1	1
#define RSA_PKCS_BT_2	2

#define SUPPORTED_EC_CURVES	2

struct ec_curves {
	char *curve;
	uint32_t	curve_len;
	char	*data;
	uint32_t	data_size;
};

extern char P256[], P384[];

/* EC Curve in DER encoding */
extern char prime256[], secp384[];

extern struct ec_curves supported_ec_curves[SUPPORTED_EC_CURVES];

CK_RV mechanism_get_info(CK_SLOT_ID slotID, CK_MECHANISM_TYPE type,
		CK_MECHANISM_INFO_PTR pInfo);

CK_RV sign_init(CK_SESSION_HANDLE hSession, sign_verify_context * ctx,
		CK_MECHANISM * mech, CK_BBOOL recover_mode,
		CK_OBJECT_HANDLE key);

CK_RV sign(CK_SESSION_HANDLE hSession, session *sess, CK_BYTE_PTR pData,
	   CK_ULONG ulDataLen, CK_BYTE_PTR pSignature,
	   CK_ULONG_PTR pulSignatureLen);

CK_RV get_digest(CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen,
		  CK_UTF8CHAR_PTR newPinHash);

#endif
