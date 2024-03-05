/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoLab1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECOLAB1_H__
#define __I_ECOLAB1_H__

#include "IEcoBase1.h"

/* IEcoLab1 IID = {C495161B-587E-459C-8A22-3AD67A4B16BE} */
#ifndef __IID_IEcoLab1
static const UGUID IID_IEcoLab1 = {0x01, 0x10, 0xC4, 0x95, 0x16, 0x1B, 0x58, 0x7E, 0x45, 0x9C, 0x8A, 0x22, 0x3A, 0xD6, 0x7A, 0x4B, 0x16, 0xBE};
#endif /* __IID_IEcoLab1 */

typedef struct IEcoLab1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct IEcoLab1* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct IEcoLab1* me);

    /* IEcoLab1 */
    int16_t (ECOCALLMETHOD *qsort)(/* in */ struct IEcoLab1* me, /* in, out */ void* arrayData, /* in */ size_t arraySize, /* in */ size_t elementSize, /* in */ int (__cdecl * compare)(const void*, const void*));

} IEcoLab1VTbl, *IEcoLab1VTblPtr;

interface IEcoLab1 {
    struct IEcoLab1VTbl *pVTbl;
} IEcoLab1;


#endif /* __I_ECOLAB1_H__ */
