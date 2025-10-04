// Подключите необходимые заголовочные файлы от plib035
#include "k1921vk035.h" 
// #include "k1921vk035_gpio.h" 
// #include "k1921vk035_rcc.h"  // Для управления тактированием, если требуется

// Замените на реальный порт и пин, к которому подключен светодиод
// Например, согласно документации вашей платы, это может быть PC5
#define LED_PORT GPIOC
#define LED_PIN  GPIO_Pin_5

// void LED_Init(void) {
//     // Объявляем структуру для настройки порта. Используйте тип, который требует ваша библиотека.
//     GPIO_Init_TypeDef GPIO_InitStruct; 
    
//     // Заполняем структуру настройками. Конкретные поля и значения уточните в SDK.
//     GPIO_InitStruct.Mode = GPIO_Mode_Out_PP; // Режим: выход, push-pull
//     GPIO_InitStruct.Pin  = LED_PIN;          // Номер пина
    
//     // Применяем настройки к порту
//     GPIO_Init(LED_PORT, &GPIO_InitStruct);
// }

int main(void) {
    // // Инициализация светодиода
    // LED_Init();
    
    // while (1) {
    //     // Включить светодиод (установить вывод в высокий уровень)
    //     GPIO_SetBits(LED_PORT, LED_PIN);
        
    //     // Задержка (используйте функцию из SDK или напишите цикл)
    //     for (volatile uint32_t i = 0; i < 1000000; i++);
        
    //     // Выключить светодиод (установить вывод в низкий уровень)
    //     GPIO_ResetBits(LED_PORT, LED_PIN);
        
    //     // Задержка
    //     for (volatile uint32_t i = 0; i < 1000000; i++);
    // }
}


















// #include "plib035.h"
// // #include "plib035_rcc.h"
// // #include "plib035_gpio.h"


// #include "k1921vk035.h"
// // #include "k1921vk035_can.h"
// // #include "k1921vk035_rcc.h"
// // #include "k1921vk035_gpio.h"

// // Буфер для приема сообщений
// CAN_RxBufferTypeDef rxBuffer;
// CAN_TxBufferTypeDef txBuffer;
// // CAN_RxBufferTypeDef rxBuffer;
// // CAN_TxBufferTypeDef txBuffer;

// // Буферы для данных
// uint8_t txData[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
// uint8_t rxData[8];

// int main(void)
// {
//     // Инициализация тактирования
//     RCC_DeInit();
//     RCC_HSE_Enable();
//     RCC_PLL_Enable();
//     RCC_WaitForPLLReady();
//     RCC_SysClk_SrcSel(RCC_SYSCLK_SRC_PLL);
//     RCC_AHB_ClkEnable(RCC_AHB_CAN | RCC_AHB_GPIOA);

//     // Настройка пинов CAN
//     GPIO_Init_TypeDef gpio;
//     gpio.GPIO_Speed = GPIO_Speed_2MHz;
//     gpio.GPIO_OutType = GPIO_OutType_PP;
//     gpio.GPIO_PuPd = GPIO_PuPd_UP;
//     gpio.GPIO_Func = GPIO_Func_1;

//     // PA12 - CAN_TX, PA11 - CAN_RX
//     gpio.GPIO_Pin = GPIO_Pin_12;
//     GPIO_Init(GPIOA, &gpio);
    
//     gpio.GPIO_Pin = GPIO_Pin_11;
//     GPIO_Init(GPIOA, &gpio);

//     // Инициализация CAN
//     CAN_InitTypeDef can;
//     can.CAN_Prescaler = 16;  // Для 1 Мбит/с при тактовой 16 МГц
//     can.CAN_SJW = CAN_SJW_1tq;
//     can.CAN_BS1 = CAN_BS1_6tq;
//     can.CAN_BS2 = CAN_BS2_3tq;
//     can.CAN_Mode = CAN_Mode_Normal;
//     can.CAN_AutoBusOff = DISABLE;
//     can.CAN_AutoWakeUp = DISABLE;
//     can.CAN_AutoRetransmission = ENABLE;
//     can.CAN_ReceiveFifoLocked = DISABLE;
//     can.CAN_TransmitFifoPriority = DISABLE;

//     CAN_Init(CAN, &can);

//     // Настройка фильтра (прием всех сообщений)
//     CAN_FilterInitTypeDef filter;
//     filter.CAN_FilterId = 0x000;
//     filter.CAN_FilterMaskId = 0x000;
//     filter.CAN_FilterFIFO = CAN_Filter_FIFO0;
//     filter.CAN_FilterNumber = 0;
//     filter.CAN_FilterMode = CAN_FilterMode_IdMask;
//     filter.CAN_FilterScale = CAN_FilterScale_32bit;
//     filter.CAN_FilterActivation = ENABLE;

//     CAN_FilterInit(&filter);

//     // Инициализация буферов
//     CAN_RxBufferInit(&rxBuffer, rxData, 8);
//     CAN_TxBufferInit(&txBuffer, txData, 8);

//     // Основной цикл
//     while(1)
//     {
//         // Отправка сообщения
//         CAN_TxHeaderTypeDef txHeader;
//         txHeader.StdId = 0x123;      // Стандартный ID
//         txHeader.ExtId = 0x00;       // Расширенный ID не используется
//         txHeader.RTR = CAN_RTR_DATA; // Флаг данных
//         txHeader.IDE = CAN_ID_STD;   // Стандартный идентификатор
//         txHeader.DLC = 8;            // Длина данных (8 байт)

//         if(CAN_Transmit(CAN, &txHeader, &txBuffer) == CAN_TxStatus_Ok)
//         {
//             // Успешная отправка
//         }

//         // Проверка приема
//         CAN_RxHeaderTypeDef rxHeader;
//         if(CAN_Receive(CAN, &rxHeader, &rxBuffer) == CAN_RxStatus_NewMessage)
//         {
//             // Обработка принятых данных
//             // rxData содержит принятые байты
//             // rxHeader содержит метаданные сообщения
//         }

//         // Задержка (простая программная)
//         for(volatile uint32_t i = 0; i < 100000; i++);
//     }
// }