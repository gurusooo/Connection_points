﻿﻿/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
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
#include "CEcoLab1EnumConnectionPoints.h"
#include "CEcoLab1ConnectionPoint.h"
#include "IEcoConnectionPointContainer.h"
#include "IEcoConnectionPoint.h"
#include <stdio.h>

/*
 * Вспомогательные функции для обмена элементов
 */
static void SwapInt32(int32_t* a, int32_t* b) {
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

static void SwapInt64(int64_t* a, int64_t* b) {
    int64_t temp = *a;
    *a = *b;
    *b = temp;
}

static void SwapFloat(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

static void SwapDouble(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Функции генерации событий
 */

static int16_t ECOCALLMETHOD CEcoLab1_Fire_OnSortStart(/* in */ IEcoLab1Ptr_t me, /* in */ uint32_t size) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = pCMe->m_pISinkCP->m_pVTblICP->EnumConnections(&pCMe->m_pISinkCP->m_pVTblICP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnSortStart(pIEvents, size);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

static int16_t ECOCALLMETHOD CEcoLab1_Fire_OnSortCompare(/* in */ IEcoLab1Ptr_t me, /* in */ uint32_t index1, /* in */ uint32_t index2, /* in */ int32_t value1, /* in */ int32_t value2) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = pCMe->m_pISinkCP->m_pVTblICP->EnumConnections(&pCMe->m_pISinkCP->m_pVTblICP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnSortCompare(pIEvents, index1, index2, value1, value2);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

static int16_t ECOCALLMETHOD CEcoLab1_Fire_OnSortSwap(/* in */ IEcoLab1Ptr_t me, /* in */ uint32_t index1, /* in */ uint32_t index2, /* in */ int32_t value1, /* in */ int32_t value2) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = pCMe->m_pISinkCP->m_pVTblICP->EnumConnections(&pCMe->m_pISinkCP->m_pVTblICP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnSortSwap(pIEvents, index1, index2, value1, value2);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

static int16_t ECOCALLMETHOD CEcoLab1_Fire_OnSortComplete(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = pCMe->m_pISinkCP->m_pVTblICP->EnumConnections(&pCMe->m_pISinkCP->m_pVTblICP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnSortComplete(pIEvents);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

/*
 * Функция QueryInterface для интерфейса IEcoLab1
 */
static int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ IEcoLab1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }
    return ERR_ECO_SUCCESES;
}

/*
 * Функция AddRef для интерфейса IEcoLab1
 */
static uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 * Функция Release для интерфейса IEcoLab1
 */
static uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 * Функция сортировки пузырьком для int32_t
 */
static int16_t ECOCALLMETHOD CEcoLab1_BubbleSortInt32(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t* array, /* in */ uint32_t size) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    uint32_t i, j;
    int32_t swapped;

    /* Проверка указателей */
    if (me == 0 || array == 0) {
        return ERR_ECO_POINTER;
    }

    if (size <= 1) {
        return ERR_ECO_SUCCESES;
    }

    /* Событие: начало сортировки */
    CEcoLab1_Fire_OnSortStart(me, size);

    printf("Starting bubble sort for array of size %u\n", size);

    /* Алгоритм сортировки пузырьком */
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            
            /* Событие: сравнение элементов */
            CEcoLab1_Fire_OnSortCompare(me, j, j + 1, array[j], array[j + 1]);
            
            if (array[j] > array[j + 1]) {
                /* Событие: обмен элементов */
                CEcoLab1_Fire_OnSortSwap(me, j, j + 1, array[j], array[j + 1]);
                
                SwapInt32(&array[j], &array[j + 1]);
                swapped = 1;
                
                printf("Swapped elements at positions %u and %u\n", j, j + 1);
            }
        }
        /* Если не было обменов, массив уже отсортирован */
        if (!swapped) {
            break;
        }
    }

    /* Событие: завершение сортировки */
    CEcoLab1_Fire_OnSortComplete(me);

    printf("Sort completed successfully!\n");
    return ERR_ECO_SUCCESES;
}

/*
 * Функция сортировки пузырьком для int64_t
 */
static int16_t ECOCALLMETHOD CEcoLab1_BubbleSortInt64(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t* array, /* in */ uint32_t size) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    uint32_t i, j;
    int32_t swapped;

    /* Проверка указателей */
    if (me == 0 || array == 0) {
        return ERR_ECO_POINTER;
    }

    if (size <= 1) {
        return ERR_ECO_SUCCESES;
    }

    /* Событие: начало сортировки */
    CEcoLab1_Fire_OnSortStart(me, size);

    /* Алгоритм сортировки пузырьком */
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            /* Событие: сравнение элементов */
            CEcoLab1_Fire_OnSortCompare(me, j, j + 1, (int32_t)array[j], (int32_t)array[j + 1]);
            
            if (array[j] > array[j + 1]) {
                /* Событие: обмен элементов */
                CEcoLab1_Fire_OnSortSwap(me, j, j + 1, (int32_t)array[j], (int32_t)array[j + 1]);
                
                SwapInt64(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        /* Если не было обменов, массив уже отсортирован */
        if (!swapped) {
            break;
        }
    }

    /* Событие: завершение сортировки */
    CEcoLab1_Fire_OnSortComplete(me);

    return ERR_ECO_SUCCESES;
}

/*
 * Функция сортировки пузырьком для float
 */
static int16_t ECOCALLMETHOD CEcoLab1_BubbleSortFloat(/* in */ IEcoLab1Ptr_t me, /* in */ float* array, /* in */ uint32_t size) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    uint32_t i, j;
    int32_t swapped;

    /* Проверка указателей */
    if (me == 0 || array == 0) {
        return ERR_ECO_POINTER;
    }

    if (size <= 1) {
        return ERR_ECO_SUCCESES;
    }

    /* Событие: начало сортировки */
    CEcoLab1_Fire_OnSortStart(me, size);

    /* Алгоритм сортировки пузырьком */
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            /* Событие: сравнение элементов */
            CEcoLab1_Fire_OnSortCompare(me, j, j + 1, (int32_t)array[j], (int32_t)array[j + 1]);
            
            if (array[j] > array[j + 1]) {
                /* Событие: обмен элементов */
                CEcoLab1_Fire_OnSortSwap(me, j, j + 1, (int32_t)array[j], (int32_t)array[j + 1]);
                
                SwapFloat(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    /* Событие: завершение сортировки */
    CEcoLab1_Fire_OnSortComplete(me);

    return ERR_ECO_SUCCESES;
}

/*
 * Функция сортировки пузырьком для double
 */
static int16_t ECOCALLMETHOD CEcoLab1_BubbleSortDouble(/* in */ IEcoLab1Ptr_t me, /* in */ double* array, /* in */ uint32_t size) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    uint32_t i, j;
    int32_t swapped;

    /* Проверка указателей */
    if (me == 0 || array == 0) {
        return ERR_ECO_POINTER;
    }

    if (size <= 1) {
        return ERR_ECO_SUCCESES;
    }

    /* Событие: начало сортировки */
    CEcoLab1_Fire_OnSortStart(me, size);

    /* Алгоритм сортировки пузырьком */
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            /* Событие: сравнение элементов */
            CEcoLab1_Fire_OnSortCompare(me, j, j + 1, (int32_t)array[j], (int32_t)array[j + 1]);
            
            if (array[j] > array[j + 1]) {
                /* Событие: обмен элементов */
                CEcoLab1_Fire_OnSortSwap(me, j, j + 1, (int32_t)array[j], (int32_t)array[j + 1]);
                
                SwapDouble(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        /* Если не было обменов, массив уже отсортирован */
        if (!swapped) {
            break;
        }
    }

    /* Событие: завершение сортировки */
    CEcoLab1_Fire_OnSortComplete(me);

    return ERR_ECO_SUCCESES;
}

/*
 * Функция вызова обратного интерфейса
 */
static int16_t ECOCALLMETHOD CEcoLab1_Fire_OnMyCallback(/* in */ IEcoLab1Ptr_t me, /* in */ char_t* Name) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = pCMe->m_pISinkCP->m_pVTblICP->EnumConnections(&pCMe->m_pISinkCP->m_pVTblICP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnMyCallback(pIEvents, Name);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

/*
 * Функция MyFunction
 */
static int16_t ECOCALLMETHOD CEcoLab1_MyFunction(/* in */ IEcoLab1Ptr_t me, /* in */ char_t* Name, /* out */ char_t** copyName) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || Name == 0 || copyName == 0) {
        return ERR_ECO_POINTER;
    }

    /* Подсчет длины строки */
    while(Name[index] != 0) {
        index++;
    }
    
    /* Выделение памяти для копии строки */
    pCMe->m_Name = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, index + 1);
    if (pCMe->m_Name == 0) {
        return ERR_ECO_OUTOFMEMORY;
    }
    
    /* Копирование строки */
    for (int16_t i = 0; i <= index; i++) {
        pCMe->m_Name[i] = Name[i];
    }
    
    *copyName = pCMe->m_Name;

    /* Обратный вызов */
    CEcoLab1_Fire_OnMyCallback(me, pCMe->m_Name);

    return ERR_ECO_SUCCESES;
}

/*
 * Функции интерфейса IEcoConnectionPointContainer
 */

static int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_QueryInterface(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint8_t*)me - offsetof(CEcoLab1, m_pVTblICPC));

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    return CEcoLab1_QueryInterface((IEcoLab1Ptr_t)pCMe, riid, ppv);
}

static uint32_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_AddRef(/* in */ struct IEcoConnectionPointContainer* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint8_t*)me - offsetof(CEcoLab1, m_pVTblICPC));

    if (me == 0 ) {
        return -1;
    }

    return CEcoLab1_AddRef((IEcoLab1Ptr_t)pCMe);
}

static uint32_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_Release(/* in */ struct IEcoConnectionPointContainer* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint8_t*)me - offsetof(CEcoLab1, m_pVTblICPC));

    if (me == 0 ) {
        return -1;
    }

    return CEcoLab1_Release((IEcoLab1Ptr_t)pCMe);
}

static int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints(/* in */ struct IEcoConnectionPointContainer* me, /* out */ struct IEcoEnumConnectionPoints **ppEnum) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint8_t*)me - offsetof(CEcoLab1, m_pVTblICPC));

    if (me == 0 || ppEnum == 0 ) {
        return ERR_ECO_POINTER;
    }

    /* Создание enumerator для точек подключения */
    return createCEcoLab1EnumConnectionPoints((IEcoUnknown*)pCMe->m_pISys, &pCMe->m_pISinkCP->m_pVTblICP, ppEnum);
}

static int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ struct IEcoConnectionPoint **ppCP) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint8_t*)me - offsetof(CEcoLab1, m_pVTblICPC));

    if (me == 0 || ppCP == 0 ) {
        return ERR_ECO_POINTER;
    }

    if ( !IsEqualUGUID(riid, &IID_IEcoLab1Events ) ) {
        *ppCP = 0;
        return ERR_ECO_NOINTERFACE;
    }

    if (pCMe->m_pISinkCP == 0) {
        return ERR_ECO_FAIL;
    }

    pCMe->m_pISinkCP->m_pVTblICP->AddRef(&pCMe->m_pISinkCP->m_pVTblICP);
    *ppCP =  &pCMe->m_pISinkCP->m_pVTblICP;

    return ERR_ECO_SUCCESES;
}

/*
 * Функция инициализации экземпляра
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ IEcoLab1Ptr_t me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = ERR_ECO_POINTER;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Создание точки подключения */
    result = createCEcoLab1ConnectionPoint((IEcoUnknown*)pCMe->m_pISys, &pCMe->m_pVTblICPC, &IID_IEcoLab1Events, (IEcoConnectionPoint**)&pCMe->m_pISinkCP);
    
    /* Освобождение */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_BubbleSortInt32,
    CEcoLab1_BubbleSortInt64,
    CEcoLab1_BubbleSortFloat,
    CEcoLab1_BubbleSortDouble,
    CEcoLab1_MyFunction
};

/* Create Virtual Table IEcoConnectionPointContainer */
IEcoConnectionPointContainerVTbl g_x0000000500000000C000000000000046VTblCPC = {
    CEcoLab1_IEcoConnectionPointContainer_QueryInterface,
    CEcoLab1_IEcoConnectionPointContainer_AddRef,
    CEcoLab1_IEcoConnectionPointContainer_Release,
    CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints,
    CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint
};

/*
 * Функция создания экземпляра
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void **)&pISys);

    /* Проверка */
    if (result != 0 || pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    if (result != 0 || pIMem == 0) {
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));
    if (pCMe == 0) {
        pIMem->pVTbl->Release(pIMem);
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }

    /* Инициализация полей */
    pCMe->m_pISys = pISys;
    pCMe->m_pIMem = pIMem;
    pCMe->m_cRef = 1;
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;
    pCMe->m_pVTblICPC = &g_x0000000500000000C000000000000046VTblCPC;
    pCMe->m_pISinkCP = 0;
    pCMe->m_Name = 0;

    /* Инициализация компонента */
    result = initCEcoLab1((IEcoLab1Ptr_t)pCMe, (IEcoUnknown*)pISys);
    if (result != 0) {
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
}

/*
 * Функция освобождения экземпляра
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        
        /* Освобождение точки подключения */
        if (pCMe->m_pISinkCP != 0) {
            pCMe->m_pISinkCP->m_pVTblICP->Release(&pCMe->m_pISinkCP->m_pVTblICP);
        }
        
        /* Освобождение строки */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        
        /* Освобождение системного интерфейса */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        
        /* Освобождение памяти экземпляра */
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}