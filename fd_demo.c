/*
 * fd_demo.c
 *
 *  Created on: 2022年7月12日
 *      Author: FeiDao
 */

#include <fd_demo.h>


//-------------------------------------------------------------------------------------------------------------------
//  @brief      例程
//  @return     void
//  @note       基本函数用法见README.txt
//-------------------------------------------------------------------------------------------------------------------
void example(void)
{
    OLED_Init();
    delay(50);
    OLED_Init();
    OLED_Clear();
    OLED_ShowString(20,1,"---example---",12);
    gyroscope_init();                    //陀螺仪开启
    __bis_SR_register(GIE); // Enter LPM0, interrupts enabled
    _EINT();
}



