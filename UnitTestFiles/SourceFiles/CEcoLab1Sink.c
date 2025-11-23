/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1Sink
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1Sink
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "../HeaderFiles/CEcoLab1Sink.h"
#include "IEcoConnectionPointContainer.h"
#include <stdio.h>

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_QueryInterface(/* in */ struct IEcoLab1Events* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoLab1Events ) ) {
        *ppv = me;
        me->pVTbl->AddRef(me);
        return 0;
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        *ppv = me;
        me->pVTbl->AddRef(me);
        return 0;
    }

    *ppv = 0;

    return -1;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1Sink_AddRef(/* in */ struct IEcoLab1Events* me) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    pCMe->m_cRef++;
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1Sink_Release(/* in */ struct IEcoLab1Events* me) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1Sink((IEcoLab1Events*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция OnMyCallback
 * </сводка>
 *
 * <описание>
 *   Функция обратного вызова
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_OnMyCallback(/* in */ struct IEcoLab1Events* me, /* in */ char_t* Name) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    printf("[%s] MyCallback: %s\n", pCMe->m_sinkName, Name);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция OnSortStart
 * </сводка>
 *
 * <описание>
 *   Обработчик события начала сортировки
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_OnSortStart(/* in */ struct IEcoLab1Events* me, /* in */ uint32_t size) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    pCMe->m_stepCount = 0;
    pCMe->m_totalComparisons = 0;
    pCMe->m_totalSwaps = 0;
    
    printf("[%s] Sort started. Array size: %d\n", pCMe->m_sinkName, size);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция OnSortSwap
 * </сводка>
 *
 * <описание>
 *   Обработчик события обмена элементов
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_OnSortSwap(/* in */ struct IEcoLab1Events* me, /* in */ uint32_t index1, /* in */ uint32_t index2, /* in */ int32_t value1, /* in */ int32_t value2) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    pCMe->m_stepCount++;
    pCMe->m_totalSwaps++;
    
    printf("[%s] Step %d: Swapping [%d]=%d <-> [%d]=%d\n", 
           pCMe->m_sinkName, pCMe->m_stepCount, index1, value1, index2, value2);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция OnSortCompare
 * </сводка>
 *
 * <описание>
 *   Обработчик события сравнения элементов
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_OnSortCompare(/* in */ struct IEcoLab1Events* me, /* in */ uint32_t index1, /* in */ uint32_t index2, /* in */ int32_t value1, /* in */ int32_t value2) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    pCMe->m_totalComparisons++;
    
    printf("[%s] Comparing [%d]=%d and [%d]=%d\n", 
           pCMe->m_sinkName, index1, value1, index2, value2);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция OnSortComplete
 * </сводка>
 *
 * <описание>
 *   Обработчик события завершения сортировки
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_OnSortComplete(/* in */ struct IEcoLab1Events* me) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    printf("[%s] Sort completed! Steps: %d, Comparisons: %d, Swaps: %d\n", 
           pCMe->m_sinkName, pCMe->m_stepCount, pCMe->m_totalComparisons, pCMe->m_totalSwaps);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция Advise
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_Advise(/* in */ struct CEcoLab1Sink* me, /* in */IEcoLab1 *pIEcoLab1) {
    IEcoConnectionPointContainer* pCPC = 0;
    IEcoConnectionPoint* pCP = 0;
    int16_t result = 0;

    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoConnectionPointContainer, (void**)&pCPC);

    if (result == 0 && pCPC != 0) {
        result = pCPC->pVTbl->FindConnectionPoint(pCPC, &IID_IEcoLab1Events, &pCP);
        pCPC->pVTbl->Release(pCPC);
        pCPC = 0;
        if (result == 0 && pCP != 0) {

            result = pCP->pVTbl->Advise(pCP, (IEcoUnknown*)me, &me->m_cCookie);
            pCP->pVTbl->Release(pCP);
            pCP = 0;
        }
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция Unadvise
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_Unadvise(/* in */ struct CEcoLab1Sink* me, /* in */IEcoLab1 *pIEcoLab1) {
    IEcoConnectionPointContainer* pCPC = 0;
    IEcoConnectionPoint * pCP = 0;
    int16_t result = 0;

    if (me->m_cCookie) {
        result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoConnectionPointContainer, (void**)&pCPC);
        if (result == 0) {
            result = pCPC->pVTbl->FindConnectionPoint(pCPC, &IID_IEcoLab1Events, &pCP);
            pCPC->pVTbl->Release(pCPC);
            pCPC = 0;
            if (result == 0) {
                result = pCP->pVTbl->Unadvise(pCP, me->m_cCookie);
                pCP->pVTbl->Release(pCP);
                pCP = 0;
            }
        }
    }
    return result;
}

/* Create Virtual Table IEcoLab1VTblEvents */
IEcoLab1VTblEvents g_x2D2E3B9214F248A6A09ECB494B59C795VTblEvents = {
    CEcoLab1Sink_QueryInterface,
    CEcoLab1Sink_AddRef,
    CEcoLab1Sink_Release,
    CEcoLab1Sink_OnMyCallback
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
int16_t ECOCALLMETHOD createCEcoLab1Sink(/* in */ IEcoMemoryAllocator1* pIMem, /* in */ char_t* sinkName, /* out */ IEcoLab1Events** ppIEcoLab1Events) {
    int16_t result = -1;
    CEcoLab1Sink* pCMe = 0;
    int16_t index = 0;

    /* Проверка указателей */
    if (ppIEcoLab1Events == 0 || pIMem == 0 || sinkName == 0) {
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1Sink*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1Sink));

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;
    pCMe->m_pIMem->pVTbl->AddRef(pCMe->m_pIMem);

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1Events */
    pCMe->m_pVTblIEcoLab1Events = &g_x2D2E3B9214F248A6A09ECB494B59C795VTblEvents;

    /* Инициализация данных */
    pCMe->m_stepCount = 0;
    pCMe->m_totalComparisons = 0;
    pCMe->m_totalSwaps = 0;
    pCMe->m_cCookie = 0;

    /* Копирование имени приемника */
    while(sinkName[index] != 0) {
        index++;
    }
    pCMe->m_sinkName = (char_t*)pIMem->pVTbl->Alloc(pIMem, index + 1);
    index = 0;
    while(sinkName[index] != 0) {
        pCMe->m_sinkName[index] = sinkName[index];
        index++;
    }

    *ppIEcoLab1Events = (IEcoLab1Events*)pCMe;

    return 0;
};

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
void ECOCALLMETHOD deleteCEcoLab1Sink(IEcoLab1Events* pIEcoLab1Events) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)pIEcoLab1Events;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1Events != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение имени */
        if (pCMe->m_sinkName != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_sinkName);
        }
        /* Освобождение экземпляра */
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
};