/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoLab1
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

#ifndef __ID_ECOLAB1_H__
#define __ID_ECOLAB1_H__

#include "IEcoBase1.h"
#include "IEcoLab1.h"

/* EcoLab1 CID = {A4C83EFF-7E43-4C20-B04D-D452F0B7954C} */
#ifndef __CID_EcoLab1
static const UGUID CID_EcoLab1 = {0x01, 0x10, 0xA4, 0xC8, 0x3E, 0xFF, 0x7E, 0x43, 0x4C, 0x20, 0xB0, 0x4D, 0xD4, 0x52, 0xF0, 0xB7, 0x95, 0x4C};
#endif /* __CID_EcoLab1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_A4C83EFF7E434C20B04DD452F0B7954C;
#endif

#endif /* __ID_ECOLAB1_H__ */
