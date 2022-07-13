/*
 * encoder.c
 *
 *  Created on: 2022年7月13日
 *      Author: FeiDao
 */
#include <encoder.h>

int encoder_count2_4 = 0;       //2_4引脚编码器计数
int encoder_count1_2 = 0;       //1_2引脚编码器计数
int speed_1 = 0;                //2_4引脚编码器实时读数
int speed_2 = 0;                //2_4引脚编码器实时读数

//-------------------------------------------------------------------------------------------------------------------
//  @brief      编码器初始化
//  @return     void
//  @note       引脚P2_4和1_2
//-------------------------------------------------------------------------------------------------------------------
void encoder_init(void)
{
    P2OUT &= ~(BIT4);
    P2SEL |=  BIT4;
    TA2CTL   = TASSEL__SMCLK + ID__8 + MC_2 + TACLR + TAIE;
    TA2CCTL1 = CM_1 + SCS +CAP + CCIE + CCIS_0;


    P1OUT &= ~(BIT2);
    P1SEL |=  BIT2;
    TA0CTL   = TASSEL__SMCLK + ID__8 + MC_2 + TACLR + TAIE;
    TA0CCTL1 = CM_1 + SCS +CAP + CCIE + CCIS_0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      显示编码器读数
//  @return     void
//  @note       speed_1为P2_4读数
//              speed_2为P1_2读数
//-------------------------------------------------------------------------------------------------------------------
void encoder_read(void)
{
    OLED_ShowNum(10,1,speed_1,7,12);
    OLED_ShowNum(10,2,speed_2,7,12);//显示编码器读值
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器输入中断TA0_1
//  @return     void
//  @note       用于编码器P1_2
//-------------------------------------------------------------------------------------------------------------------
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void)
{

    switch(__even_in_range(TA0IV,2))
    {
      case  0:break;
      case  2:
          encoder_count1_2++;
//          OLED_ShowNum(10,6,encoder_count1_2,4,15);
          break;
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器输入中断TA2_1
//  @return     void
//  @note       用于编码器P2_4
//-------------------------------------------------------------------------------------------------------------------
#pragma vector=TIMER2_A1_VECTOR
__interrupt void TIMER2_A1_ISR(void)
{

    switch(__even_in_range(TA2IV,2))
    {
      case  0:break;
      case  2:
          encoder_count2_4++;
//          OLED_ShowNum(10,5,encoder_count2_4,4,15);
          break;
    }
}


