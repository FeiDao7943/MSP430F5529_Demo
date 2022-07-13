/*
 * encoder.c
 *
 *  Created on: 2022��7��13��
 *      Author: FeiDao
 */
#include <encoder.h>

int encoder_count2_4 = 0;       //2_4���ű���������
int encoder_count1_2 = 0;       //1_2���ű���������
int speed_1 = 0;                //2_4���ű�����ʵʱ����
int speed_2 = 0;                //2_4���ű�����ʵʱ����

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��������ʼ��
//  @return     void
//  @note       ����P2_4��1_2
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
//  @brief      ��ʾ����������
//  @return     void
//  @note       speed_1ΪP2_4����
//              speed_2ΪP1_2����
//-------------------------------------------------------------------------------------------------------------------
void encoder_read(void)
{
    OLED_ShowNum(10,1,speed_1,7,12);
    OLED_ShowNum(10,2,speed_2,7,12);//��ʾ��������ֵ
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʱ�������ж�TA0_1
//  @return     void
//  @note       ���ڱ�����P1_2
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
//  @brief      ��ʱ�������ж�TA2_1
//  @return     void
//  @note       ���ڱ�����P2_4
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


