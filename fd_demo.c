/*
 * fd_demo.c
 *
 *  Created on: 2022��7��12��
 *      Author: FeiDao
 */

#include <fd_demo.h>


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����
//  @return     void
//  @note       ���������÷���README.txt
//-------------------------------------------------------------------------------------------------------------------
void example(void)
{
    OLED_Init();
    delay(50);
    OLED_Init();
    OLED_Clear();
    OLED_ShowString(20,1,"---example---",12);
    gyroscope_init();                    //�����ǿ���
    __bis_SR_register(GIE); // Enter LPM0, interrupts enabled
    _EINT();
}



