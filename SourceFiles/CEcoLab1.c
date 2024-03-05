/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1_F0B7954C
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1_F0B7954C
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_F0B7954C_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1_F0B7954C* pCMe = (CEcoLab1_F0B7954C*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_F0B7954C_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1_F0B7954C* pCMe = (CEcoLab1_F0B7954C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_F0B7954C_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1_F0B7954C* pCMe = (CEcoLab1_F0B7954C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1_F0B7954C((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}




/*
 *
 * <сводка>
 *   Функция copyByByte
 * </сводка>
 *
 * <описание>
 *   Функция copyByByte - копирует по байтам из from в to
 * </описание>
 *
 */
void copyByByte(char* from, char* to, size_t size) {
	size_t i;
	for (i = 0; i < size; i++) {
		*(to + i) = *(from + i);
	}
}




/*
 *
 * <сводка>
 *   Функция qsort
 * </сводка>
 *
 * <описание>
 *   Функция qsort выполняет сортировку пузырьком (bubble sort), используя сигнатуру qsort
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_F0B7954C_qsort(/* in */ struct IEcoLab1* me, /* in, out */ void* arrayData, /* in */ size_t arraySize, /* in */ size_t elementSize, /* in */ int (__cdecl * compare)(const void*, const void*)) {
	CEcoLab1_F0B7954C* pCMe = (CEcoLab1_F0B7954C*) me;
	int16_t index = 0;
	size_t i, j;
	void *savedValue, *currentElem, *nextElem;
	int isSorted;

    /* Проверка указателей */
    if (me == 0 || arrayData == 0) {
        return -1;
    }

	/* Массив длиной меньше 2 элементов не нуждается в сортировке */
	if (arraySize < 2) {
		return 0;
	}

	/* Bubble sort */	
	isSorted = 0;
	i = arraySize - 1;
	while (isSorted != 1) {
		isSorted = 1;
		currentElem = arrayData;
		for (j = 0; j < i; ++j) {
			nextElem = (char*)currentElem + elementSize;
			if (compare(currentElem, nextElem) > 0) {
				isSorted = 0;
				savedValue = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, elementSize);
				copyByByte((char*)currentElem, (char*)savedValue, elementSize);
				copyByByte((char*)nextElem, (char*)currentElem, elementSize);
				copyByByte((char*)savedValue, (char*)nextElem, elementSize);
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, savedValue);
			}
			currentElem = nextElem;
		}
		i--;
	}

    return 0;
}




/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1_F0B7954C(/*in*/ struct IEcoLab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1_F0B7954C* pCMe = (CEcoLab1_F0B7954C*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_xC495161B587E459C8A223AD67A4B16BEVTbl_F0B7954C = {
    CEcoLab1_F0B7954C_QueryInterface,
    CEcoLab1_F0B7954C_AddRef,
    CEcoLab1_F0B7954C_Release,
    CEcoLab1_F0B7954C_qsort
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1_F0B7954C(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1_F0B7954C* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1_F0B7954C*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1_F0B7954C));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_xC495161B587E459C8A223AD67A4B16BEVTbl_F0B7954C;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1_F0B7954C(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1_F0B7954C* pCMe = (CEcoLab1_F0B7954C*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
