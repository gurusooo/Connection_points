#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoLab1.h"
#include "IEcoConnectionPointContainer.h"
#include "IEcoConnectionPoint.h"
#include "../HeaderFiles/CEcoLab1Sink.h"
#include <stdio.h>
extern int16_t CreateIEcoSystem1(IEcoSystem1** ppISys);
extern int16_t createCEcoLab1(IEcoUnknown* pIUnkSystem, IEcoUnknown* pIUnkOuter, IEcoLab1** ppIEcoLab1);

/*
 *
 * <сводка>
 *   Основная функция UnitTest
 * </сводка>
 *
 */

int main() {
    int16_t result = 0;
    IEcoSystem1* pISys = 0;
    IEcoLab1* pILab1 = 0;
    IEcoConnectionPointContainer* pICPC = 0;
    IEcoConnectionPoint* pICP = 0;
    IEcoLab1Events* pISink1 = 0;
    IEcoLab1Events* pISink2 = 0;
    IEcoLab1Events* pISink3 = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    uint32_t dwCookie1 = 0, dwCookie2 = 0, dwCookie3 = 0;
    
    int32_t testArray[7];
    uint32_t arraySize;
    char_t* copiedName = 0;
    int32_t testArray2[5]; 
    uint32_t arraySize2;
    char_t* copiedName2 = 0;
    int32_t testArray3[3];
    uint32_t arraySize3;
    uint32_t i;

    printf("=== Eco Lab 1 Unit Test (Many-to-Many Events) ===\n\n");

    /* Создание системного интерфейса */
    result = CreateIEcoSystem1(&pISys);
    if (result != 0 || pISys == 0) {
        printf("Error: Failed to create system interface\n");
        return -1;
    }

    /* Получение интерфейса распределителя памяти */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    if (result != 0 || pIMem == 0) {
        printf("Error: Failed to get memory allocator\n");
        pISys->pVTbl->Release(pISys);
        return -1;
    }

    /* Создание компонента CEcoLab1 */
    result = createCEcoLab1((IEcoUnknown*)pISys, 0, &pILab1);
    if (result != 0 || pILab1 == 0) {
        printf("Error: Failed to create CEcoLab1 component\n");
        pIMem->pVTbl->Release(pIMem);
        pISys->pVTbl->Release(pISys);
        return -1;
    }

    printf("1. CEcoLab1 component created successfully\n");

    /* Получение интерфейса IConnectionPointContainer */
    result = pILab1->pVTbl->QueryInterface(pILab1, &IID_IEcoConnectionPointContainer, (void**)&pICPC);
    if (result != 0 || pICPC == 0) {
        printf("Error: Failed to get IConnectionPointContainer interface\n");
        pILab1->pVTbl->Release(pILab1);
        pIMem->pVTbl->Release(pIMem);
        pISys->pVTbl->Release(pISys);
        return -1;
    }

    printf("2. IConnectionPointContainer interface obtained\n");

    /* Поиск точки подключения для IEcoLab1Events */
    result = pICPC->pVTbl->FindConnectionPoint(pICPC, &IID_IEcoLab1Events, &pICP);
    if (result != 0 || pICP == 0) {
        printf("Error: Failed to find connection point for IEcoLab1Events\n");
        pICPC->pVTbl->Release(pICPC);
        pILab1->pVTbl->Release(pILab1);
        pIMem->pVTbl->Release(pIMem);
        pISys->pVTbl->Release(pISys);
        return -1;
    }

    printf("3. Connection point for IEcoLab1Events found\n\n");

    /* Первый приемник - основной логгер */
    result = createCEcoLab1Sink(pIMem, "MainLogger", &pISink1);
    if (result == 0 && pISink1 != 0) {
        result = pICP->pVTbl->Advise(pICP, (IEcoUnknown*)pISink1, &dwCookie1);
        if (result == 0) {
            printf("4. MainLogger sink connected (Cookie: %d)\n", dwCookie1);
        }
    }

    /* Второй приемник - статистика */
    result = createCEcoLab1Sink(pIMem, "Statistics", &pISink2);
    if (result == 0 && pISink2 != 0) {
        result = pICP->pVTbl->Advise(pICP, (IEcoUnknown*)pISink2, &dwCookie2);
        if (result == 0) {
            printf("5. Statistics sink connected (Cookie: %d)\n", dwCookie2);
        }
    }

    /* Третий приемник - отладчик */
    result = createCEcoLab1Sink(pIMem, "Debugger", &pISink3);
    if (result == 0 && pISink3 != 0) {
        result = pICP->pVTbl->Advise(pICP, (IEcoUnknown*)pISink3, &dwCookie3);
        if (result == 0) {
            printf("6. Debugger sink connected (Cookie: %d)\n", dwCookie3);
        }
    }

    printf("\n=== Starting Sort Test with Multiple Event Sinks ===\n\n");

    /* Инициализация первого массива */
    testArray[0] = 64; testArray[1] = 34; testArray[2] = 25;
    testArray[3] = 12; testArray[4] = 22; testArray[5] = 11; testArray[6] = 90;
    arraySize = 7;

    printf("Original array: ");
    for (i = 0; i < arraySize; i++) {
        printf("%d ", testArray[i]);
    }
    printf("\n\n");

    printf("=== Testing MyFunction with Events ===\n");
    result = pILab1->pVTbl->MyFunction(pILab1, "TestCallback", &copiedName);
    if (result == 0 && copiedName != 0) {
        printf("MyFunction completed. Copied name: %s\n\n", copiedName);
    }

    /* Вызов функции сортировки */
    printf("=== Testing BubbleSort with Events ===\n");
    result = pILab1->pVTbl->BubbleSortInt32(pILab1, testArray, arraySize);
    if (result != 0) {
        printf("Error: BubbleSortInt32 failed with code %d\n", result);
    }

    printf("\nSorted array: ");
    for (i = 0; i < arraySize; i++) {
        printf("%d ", testArray[i]);
    }
    printf("\n\n");

    printf("=== Testing Dynamic Connection Management ===\n\n");

    /* Отключаем один приемник */
    if (dwCookie2 != 0) {
        result = pICP->pVTbl->Unadvise(pICP, dwCookie2);
        if (result == 0) {
            printf("7. Statistics sink disconnected (Cookie: %d)\n", dwCookie2);
            dwCookie2 = 0;
        }
    }

    /* Инициализация второго массива */
    testArray2[0] = 5; testArray2[1] = 2; testArray2[2] = 8;
    testArray2[3] = 1; testArray2[4] = 9;
    arraySize2 = 5;

    printf("\nTesting with 2 sinks (MainLogger and Debugger):\n");
    printf("Original array: ");
    for (i = 0; i < arraySize2; i++) {
        printf("%d ", testArray2[i]);
    }
    printf("\n");

    result = pILab1->pVTbl->BubbleSortInt32(pILab1, testArray2, arraySize2);

    printf("Sorted array: ");
    for (i = 0; i < arraySize2; i++) {
        printf("%d ", testArray2[i]);
    }
    printf("\n\n");

    printf("=== Testing MyFunction with 2 sinks ===\n");
    result = pILab1->pVTbl->MyFunction(pILab1, "SecondCallback", &copiedName2);
    if (result == 0 && copiedName2 != 0) {
        printf("MyFunction completed. Copied name: %s\n\n", copiedName2);
    }

    printf("=== Disconnecting All Sinks ===\n\n");

    if (dwCookie1 != 0) {
        pICP->pVTbl->Unadvise(pICP, dwCookie1);
        printf("8. MainLogger sink disconnected\n");
    }
    if (dwCookie2 != 0) {
        pICP->pVTbl->Unadvise(pICP, dwCookie2);
        printf("9. Statistics sink disconnected\n");
    }
    if (dwCookie3 != 0) {
        pICP->pVTbl->Unadvise(pICP, dwCookie3);
        printf("10. Debugger sink disconnected\n");
    }

    printf("\n=== Testing Without Sinks (No events expected) ===\n");
    testArray3[0] = 3; testArray3[1] = 1; testArray3[2] = 2;
    arraySize3 = 3;
    
    printf("Original array: ");
    for (i = 0; i < arraySize3; i++) {
        printf("%d ", testArray3[i]);
    }
    printf("\n");
    
    result = pILab1->pVTbl->BubbleSortInt32(pILab1, testArray3, arraySize3);
    
    printf("Sorted array: ");
    for (i = 0; i < arraySize3; i++) {
        printf("%d ", testArray3[i]);
    }
    printf("\n");

    printf("\n=== Cleaning Up ===\n");

    if (pISink1 != 0) {
        pISink1->pVTbl->Release(pISink1);
        printf("11. MainLogger sink released\n");
    }
    if (pISink2 != 0) {
        pISink2->pVTbl->Release(pISink2);
        printf("12. Statistics sink released\n");
    }
    if (pISink3 != 0) {
        pISink3->pVTbl->Release(pISink3);
        printf("13. Debugger sink released\n");
    }
    if (pICP != 0) {
        pICP->pVTbl->Release(pICP);
        printf("14. Connection point released\n");
    }
    if (pICPC != 0) {
        pICPC->pVTbl->Release(pICPC);
        printf("15. Connection point container released\n");
    }
    if (pILab1 != 0) {
        pILab1->pVTbl->Release(pILab1);
        printf("16. CEcoLab1 component released\n");
    }
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
        printf("17. Memory allocator released\n");
    }
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
        printf("18. System interface released\n");
    }

    printf("\n=== Unit Test Completed Successfully ===\n");
    printf("=== Scheme: Many-to-Many (3 sinks -> 1 component) ===\n");
    printf("=== Events demonstrated: OnMyCallback ===\n");
    
    return 0;
}