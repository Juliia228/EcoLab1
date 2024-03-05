/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"

#include <stdio.h>
#include <stdlib.h>

/* Фунцкии для сравнения двух чисел */
int __cdecl compareInt(const void *arg1, const void *arg2) {
	return *(int*) arg1 - *(int*) arg2;
}

int __cdecl compareLong(const void *arg1, const void *arg2) {
	if (*(long*) arg1 > *(long*) arg2) {
		return 1;
	}
	if (*(long*) arg1 < *(long*) arg2) {
		return -1;
	}
	return 0;
}

int __cdecl compareFloat(const void *arg1, const void *arg2) {
	if (*(float*) arg1 > *(float*) arg2) {
		return 1;
	}
	if (*(float*) arg1 < *(float*) arg2) {
		return -1;
	}
	return 0;
}

int __cdecl compareDouble(const void *arg1, const void *arg2) {
	if (*(double*) arg1 > *(double*) arg2) {
		return 1;
	}
	if (*(double*) arg1 < *(double*) arg2) {
		return -1;
	}
	return 0;
}

int __cdecl compareLongDouble(const void *arg1, const void *arg2) {
	if (*(long double*) arg1 > *(long double*) arg2) {
		return 1;
	}
	if (*(long double*) arg1 < *(long double*) arg2) {
		return -1;
	}
	return 0;
}

/* Генерация массивов данных */
void generateIntArray(IEcoMemoryAllocator1* pIMem, void** voidArr, void** voidCopiedArr, size_t arraySize) {
	size_t i;
	int element, **arr = (int**)voidArr, **copiedArr = (int**)voidCopiedArr;
	*arr = (int*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(int));
	*copiedArr = (int*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(int));

	for (i = 0; i < arraySize; i++) {
		element = rand() % 2000 - 1000;
        (*arr)[i] = element;
		(*copiedArr)[i] = element;
    }
}

void generateLongArray(IEcoMemoryAllocator1* pIMem, void** voidArr, void** voidCopiedArr, size_t arraySize) {
	size_t i;
	long element, **arr = (long**)voidArr, **copiedArr = (long**)voidCopiedArr;
	*arr = (long*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(long));
	*copiedArr = (long*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(long));

	for (i = 0; i < arraySize; i++) {
		element = rand() % 20000 - 10000;
        (*arr)[i] = element;
		(*copiedArr)[i] = element;
    }
}

void generateFloatArray(IEcoMemoryAllocator1* pIMem, void** voidArr, void** voidCopiedArr, size_t arraySize) {
	size_t i;
	float element, **arr = (float**)voidArr, **copiedArr = (float**)voidCopiedArr;
	*arr = (float*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(float));
	*copiedArr = (float*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(float));

	for (i = 0; i < arraySize; i++) {
		element = (rand() % 2000 + (double) rand() / RAND_MAX) - 1000;
        (*arr)[i] = element;
		(*copiedArr)[i] = element;
    }
}

void generateDoubleArray(IEcoMemoryAllocator1* pIMem, void** voidArr, void** voidCopiedArr, size_t arraySize) {
	size_t i;
	double element, **arr = (double**)voidArr, **copiedArr = (double**)voidCopiedArr;
	*arr = (double*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(double));
	*copiedArr = (double*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(double));

	for (i = 0; i < arraySize; i++) {
		element = (rand() % 2000 + (double) rand() / RAND_MAX) - 1000;
        (*arr)[i] = element;
		(*copiedArr)[i] = element;
    }
}

void generateLongDoubleArray(IEcoMemoryAllocator1* pIMem, void** voidArr, void** voidCopiedArr, size_t arraySize) {
	size_t i;
	long double element, **arr = (long double**)voidArr, **copiedArr = (long double**)voidCopiedArr;
	*arr = (long double*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(long double));
	*copiedArr = (long double*) pIMem->pVTbl->Alloc(pIMem, arraySize * sizeof(long double));

	for (i = 0; i < arraySize; i++) {
		element = (rand() % 20000 + (double) rand() / RAND_MAX) - 10000;
        (*arr)[i] = element;
		(*copiedArr)[i] = element;
    }
}

/* Функции для тестирования сортировки на разных типах данных */
void testForIntArray(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem, FILE* file, size_t arraySize) {
	void *arr, *copiedArr;
	clock_t startTime, endTime;

	/* Создание массивов и заполнение их случайными числами */
	generateIntArray(pIMem, &arr, &copiedArr, arraySize);
	
	/* Подсчет времени выполнения сортировок и запись результатов в файл для сравнения результатов */
	startTime = clock();
	qsort(copiedArr, arraySize, sizeof(int), compareInt);
	endTime = clock();
	fprintf(file, "int,qsort,%d,%lf\n", arraySize, (double) (endTime - startTime));

	startTime = clock();
	pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(int), compareInt);
	endTime = clock();
	fprintf(file, "int,bubble sort,%d,%lf\n", arraySize, (double) (endTime - startTime));
	
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);
}

void testForLongArray(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem, FILE* file, size_t arraySize) {
	void *arr, *copiedArr;
	clock_t startTime, endTime;

	/* Создание массивов и заполнение их случайными числами */
	generateLongArray(pIMem, &arr, &copiedArr, arraySize);

	/* Подсчет времени выполнения сортировок и запись результатов в файл для сравнения результатов */
	startTime = clock();
	qsort(copiedArr, arraySize, sizeof(long), compareLong);
	endTime = clock();
    fprintf(file, "long,qsort,%d,%lf\n", arraySize, (double) (endTime - startTime));

	startTime = clock();
	pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(long), compareLong);
	endTime = clock();
	fprintf(file, "long,bubble sort,%d,%lf\n", arraySize, (double) (endTime - startTime));

	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);
}

void testForFloatArray(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem, FILE* file, size_t arraySize) {
	void *arr, *copiedArr;
	clock_t startTime, endTime;

	/* Создание массивов и заполнение их случайными числами */
	generateFloatArray(pIMem, &arr, &copiedArr, arraySize);

	/* Подсчет времени выполнения сортировок и запись результатов в файл для сравнения результатов */
	startTime = clock();
	qsort(copiedArr, arraySize, sizeof(float), compareFloat);
	endTime = clock();
    fprintf(file, "float,qsort,%d,%lf\n", arraySize, (double) (endTime - startTime));

	startTime = clock();
	pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(float), compareFloat);
	endTime = clock();
	fprintf(file, "float,bubble sort,%d,%lf\n", arraySize, (double) (endTime - startTime));
	
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);
}

void testForDoubleArray(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem, FILE* file, size_t arraySize) {
	void *arr, *copiedArr;
	clock_t startTime, endTime;

	/* Создание массивов и заполнение их случайными числами */
	generateDoubleArray(pIMem, &arr, &copiedArr, arraySize);

	/* Подсчет времени выполнения сортировок и запись результатов в файл для сравнения результатов */
	startTime = clock();
	qsort(copiedArr, arraySize, sizeof(double), compareDouble);
	endTime = clock();
    fprintf(file, "double,qsort,%d,%lf\n", arraySize, (double) (endTime - startTime));

	startTime = clock();
	pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(double), compareDouble);
	endTime = clock();
	fprintf(file, "double,bubble sort,%d,%lf\n", arraySize, (double) (endTime - startTime));
	
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);
}

void testForLongDoubleArray(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem, FILE* file, size_t arraySize) {
	void *arr, *copiedArr;
	clock_t startTime, endTime;

	/* Создание массивов и заполнение их случайными числами */
	generateLongDoubleArray(pIMem, &arr, &copiedArr, arraySize);

	/* Подсчет времени выполнения сортировок и запись результатов в файл для сравнения результатов */
	startTime = clock();
	qsort(copiedArr, arraySize, sizeof(long double), compareLongDouble);
	endTime = clock();
    fprintf(file, "long double,qsort,%d,%lf\n", arraySize, (double) (endTime - startTime));

	startTime = clock();
	pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(long double), compareLongDouble);
	endTime = clock();
	fprintf(file, "long double,bubble sort,%d,%lf\n", arraySize, (double) (endTime - startTime));
	
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);
}




/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;
	/* Локальные переменные */
	size_t i, arraySize = 10;
	void *arr, *copiedArr;
	FILE *file;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_A4C83EFF7E434C20B04DD452F0B7954C);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }


	/* Тестирование сортировки на разных данных */

	srand((unsigned int)time(0)); // начальное значение для функции rand()

	/* Результаты будут записаны в файл results.csv */
	fopen_s(&file, "results.csv", "w");
    fprintf(file, "ARRAY TYPE,SORT TYPE,ARRAY SIZE,TIME\n");

	/*** INT ***/
	// Тест для наглядной работы сортировки (arraySize = 10)
	generateIntArray(pIMem, &arr, &copiedArr, arraySize);
	/* Вывод неотсортированного массива */
	printf("Int array before sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%d ", ((int*)arr)[i]);
    }
	printf("\n");
	/* Сортировки и вывод отсортированных массивов */
	result = pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(int), compareInt);
	printf("Array after bubble sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%d ", ((int*)arr)[i]);
    }
	printf("\n");

	qsort(copiedArr, arraySize, sizeof(int), compareInt);
    printf("Array after qsort:\n");
	for (i = 0; i < arraySize; ++i) {
        printf("%d ", ((int*)copiedArr)[i]);
    }
    printf("\n\n");
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);

	/* Тесты для разных размеров массивов */
	printf("Testing for int arrays in the process...\n");
	testForIntArray(pIEcoLab1, pIMem, file, 1000);
	testForIntArray(pIEcoLab1, pIMem, file, 5000);
	testForIntArray(pIEcoLab1, pIMem, file, 10000);
	testForIntArray(pIEcoLab1, pIMem, file, 50000);
	printf("Testing for int arrays has been successfully completed\n\n");


	/*** LONG ***/
	// Тест для наглядной работы сортировки (arraySize = 10)
	generateLongArray(pIMem, &arr, &copiedArr, arraySize);
	/* Вывод неотсортированного массива */
	printf("Long array before sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%ld ", ((long*)arr)[i]);
    }
	printf("\n");
	/* Сортировки и вывод отсортированных массивов */
	result = pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(long), compareLong);
	printf("Array after bubble sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%ld ", ((long*)arr)[i]);
    }
	printf("\n");

	qsort(copiedArr, arraySize, sizeof(long), compareLong);
    printf("Array after qsort:\n");
	for (i = 0; i < arraySize; ++i) {
        printf("%ld ", ((long*)copiedArr)[i]);
    }
    printf("\n\n");
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);

	/* Тесты для разных размеров массивов */
	printf("Testing for long arrays in the process...\n");
	testForLongArray(pIEcoLab1, pIMem, file, 1000);
	testForLongArray(pIEcoLab1, pIMem, file, 5000);
	testForLongArray(pIEcoLab1, pIMem, file, 10000);
	testForLongArray(pIEcoLab1, pIMem, file, 50000);
	printf("Testing for long arrays has been successfully completed\n\n");


	/*** FLOAT ***/
	// Тест для наглядной работы сортировки (arraySize = 10)
	generateFloatArray(pIMem, &arr, &copiedArr, arraySize);
	/* Вывод неотсортированного массива */
	printf("Float array before sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%f ", ((float*)arr)[i]);
    }
	printf("\n");
	/* Сортировки и вывод отсортированных массивов */
	result = pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(float), compareFloat);
	printf("Array after bubble sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%f ", ((float*)arr)[i]);
    }
	printf("\n");

	qsort(copiedArr, arraySize, sizeof(float), compareFloat);
    printf("Array after qsort:\n");
	for (i = 0; i < arraySize; ++i) {
        printf("%f ", ((float*)copiedArr)[i]);
    }
    printf("\n\n");
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);

	/* Тесты для разных размеров массивов */
	printf("Testing for float arrays in the process...\n");
	testForFloatArray(pIEcoLab1, pIMem, file, 1000);
	testForFloatArray(pIEcoLab1, pIMem, file, 5000);
	testForFloatArray(pIEcoLab1, pIMem, file, 10000);
	testForFloatArray(pIEcoLab1, pIMem, file, 50000);
	printf("Testing for float arrays has been successfully completed\n\n");


	/*** DOUBLE ***/
	// Тест для наглядной работы сортировки (arraySize = 10)
	generateDoubleArray(pIMem, &arr, &copiedArr, arraySize);
	/* Вывод неотсортированного массива */
	printf("Double array before sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%f ", ((double*)arr)[i]);
    }
	printf("\n");
	/* Сортировки и вывод отсортированных массивов */
	result = pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(double), compareDouble);
	printf("Array after bubble sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%f ", ((double*)arr)[i]);
    }
	printf("\n");

	qsort(copiedArr, arraySize, sizeof(double), compareDouble);
    printf("Array after qsort:\n");
	for (i = 0; i < arraySize; ++i) {
        printf("%f ", ((double*)copiedArr)[i]);
    }
    printf("\n\n");
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);

	/* Тесты для разных размеров массивов */
	printf("Testing for double arrays in the process...\n");
	testForDoubleArray(pIEcoLab1, pIMem, file, 1000);
	testForDoubleArray(pIEcoLab1, pIMem, file, 5000);
	testForDoubleArray(pIEcoLab1, pIMem, file, 10000);
	testForDoubleArray(pIEcoLab1, pIMem, file, 50000);
	printf("Testing for double arrays has been successfully completed\n\n");


	/*** LONG DOUBLE ***/
	// Тест для наглядной работы сортировки (arraySize = 10)
	generateLongDoubleArray(pIMem, &arr, &copiedArr, arraySize);
	/* Вывод неотсортированного массива */
	printf("Long double array before sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%Lf ", ((long double*)arr)[i]);
    }
	printf("\n");
	/* Сортировки и вывод отсортированных массивов */
	result = pIEcoLab1->pVTbl->qsort(pIEcoLab1, arr, arraySize, sizeof(long double), compareLongDouble);
	printf("Array after bubble sort:\n");
    for (i = 0; i < arraySize; ++i) {
        printf("%Lf ", ((long double*)arr)[i]);
    }
	printf("\n");

	qsort(copiedArr, arraySize, sizeof(long double), compareLongDouble);
    printf("Array after qsort:\n");
	for (i = 0; i < arraySize; ++i) {
        printf("%Lf ", ((long double*)copiedArr)[i]);
    }
    printf("\n\n");
	/* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, arr);
	pIMem->pVTbl->Free(pIMem, copiedArr);

	/* Тесты для разных размеров массивов */
	printf("Testing for long double arrays in the process...\n");
	testForLongDoubleArray(pIEcoLab1, pIMem, file, 1000);
	testForLongDoubleArray(pIEcoLab1, pIMem, file, 5000);
	testForLongDoubleArray(pIEcoLab1, pIMem, file, 10000);
	testForLongDoubleArray(pIEcoLab1, pIMem, file, 50000);
	printf("Testing for long double arrays has been successfully completed\n\n");


	/* Закрываем файл с результатами тестирования*/
	fclose(file);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

