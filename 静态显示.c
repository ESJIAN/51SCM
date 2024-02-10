#include<REG51.H>

#define GPIO_bit_choice P0
#define GPIO_segement_choice P1
#define GPIO_key P2

#define uchar unsigned char

uchar GPIO_bit_choice_translation[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar GPIO_segement_choice_translation[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uchar keynum=0;

void Delayms(unsigned int);
uchar keyState;


void main()
{
   GPIO_bit_choice=0x00;
   GPIO_key=0xff;            //共阴数码管，位选给低电平，段选给高电平
   GPIO_segement_choice=0x3f;
    while (1)
    {
        //读取按键状态
        if (GPIO_key!=0x11)
        {
            Delayms(10);
            if (GPIO_key!=0x11)
            {
                uchar keyState=GPIO_key;
                 switch (keyState)                               //k1~k8 is equal to X.7~X.0
                 {
            case 0x7F:    //按下K1
             keynum=1;
             break;
             
            case 0xBF:    //按下K2
             keynum=2;
             break;
            case 0xDF:    //按下K3
             keynum=3;
             break;
            case 0xEF:    //按下K4
             keynum=4;
             break;
            case 0xF7:    //按下K5
             keynum=5;
             break;
            case 0xFB:    //按下K6
             keynum=6;
             break;
            case 0xFD:    //按下K7
             keynum=7;
             break;
            case 0xFE:    //按下K8
             keynum=8;
              break;
            default:
             keynum=0;
             break;
                }
            }          

        }
        
        
       
       
       GPIO_segement_choice= GPIO_segement_choice_translation[keynum];

    }
    
}

 void Delayms(unsigned int xms)
{
   uchar t=0;
   for ( t; t < xms; t++)
	{
      for ( t; t < 110; t++){
			}
	}
}