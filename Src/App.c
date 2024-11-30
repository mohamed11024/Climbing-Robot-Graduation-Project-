
#include "App.h"

/**************************************************************************************************************/

/**************************************************************************************************************/



/**************************************************************************************************************/

/**************************************************************************************************************/

static u8 griper_up_right_flag   = Open;
static u8 griper_up_left_flag    = Open;
static u8 griper_down_right_flag = Open;
static u8 griper_down_left_flag  = Open;
static u8 move_up_down_flag      = Open;

/**************************************************************************************************************/

/**************************************************************************************************************/

static void griper_voidOpenRightUp(void);
static void griper_voidOpenLeftUp(void);
static void griper_voidOpenRightDown(void);
static void griper_voidOpenLeftDown(void);
static void griper_voidCloseRightUp(void);
static void griper_voidCloseLeftUp(void);
static void griper_voidCloseRightDown(void);
static void griper_voidCloseLeftDown(void);
static void griper_voidStopRightUp(void);
static void griper_voidStopLeftUp(void);
static void griper_voidStopRightDown(void);
static void griper_voidStopLeftDown(void);

/**************************************************************************************************************/

/**************************************************************************************************************/

static void griper_voidOpenRightUp(void)
{
	/*Open the right up motor*/
	GPIO_voidSetPinValue(GPIOB,PIN3,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN8,LOW);
}
static void griper_voidOpenLeftUp(void)
{
	/*Open the left up motor*/
	GPIO_voidSetPinValue(GPIOB,PIN5,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN10,LOW);
}
static void griper_voidOpenRightDown(void)
{
	/*open the right down motor*/
	GPIO_voidSetPinValue(GPIOB,PIN4,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN9,LOW);
}
static void griper_voidOpenLeftDown(void)
{
	/*open the left down motor*/
	GPIO_voidSetPinValue(GPIOB,PIN6,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN11,LOW);
}
static void Move_voidOpenUpDown(void)
{
	/*Up the Up Down Motor*/
	GPIO_voidSetPinValue(GPIOB,PIN7,HIGH);
	GPIO_voidSetPinValue(GPIOB,PIN8,LOW);
}
static void griper_voidCloseRightUp(void)
{
	/*CLose the right up motor*/
	GPIO_voidSetPinValue(GPIOB,PIN3,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN8,HIGH);
}
static void griper_voidCloseLeftUp(void)
{
	/*Close the left up motor*/
	GPIO_voidSetPinValue(GPIOB,PIN5,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN10,HIGH);
}
static void griper_voidCloseRightDown(void)
{
	/*close the right down motor*/
	GPIO_voidSetPinValue(GPIOB,PIN4,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN9,HIGH);
}
static void griper_voidCloseLeftDown(void)
{
	GPIO_voidSetPinValue(GPIOB,PIN6,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN11,HIGH);
}
static void Move_voidCloseUpDown(void)
{
	/*close the Up Down Motor*/
	GPIO_voidSetPinValue(GPIOB,PIN7,LOW);
	GPIO_voidSetPinValue(GPIOB,PIN8,HIGH);
}
static void griper_voidStopRightUp(void)
{
	/*Stop the right up motor*/
	GPIO_voidSetPinValue(GPIOB,PIN3,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN8,LOW);
}
static void griper_voidStopLeftUp(void)
{
	/*Stop the left up motor*/
	GPIO_voidSetPinValue(GPIOB,PIN5,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN10,LOW);
}
static void griper_voidStopRightDown(void)
{
	/*stop the right down motor*/
	GPIO_voidSetPinValue(GPIOB,PIN4,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN9,LOW);
}
static void griper_voidStopLeftDown(void)
{
	/*stop the left down motor*/
	GPIO_voidSetPinValue(GPIOB,PIN6,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN11,LOW);
}
static void Move_voidStopUpDown(void)
{
	/*Stop the Up Down Motor*/
	GPIO_voidSetPinValue(GPIOB,PIN7,LOW);
	GPIO_voidSetPinValue(GPIOB,PIN8,LOW);
}

/**************************************************************************************************************/

/**************************************************************************************************************/

void Robot_voidInit(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOA_EN);
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOB_EN);
	RCC_voidEnableClock(RCC_APB2,APB2_GPIOC_EN);

	GPIO_voidSetPinDirection(GPIOB,PIN3,OUTPUT_SPEED_10MHZ_PP);//griper right up CW
	GPIO_voidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_10MHZ_PP);//griper right up CCW

	GPIO_voidSetPinDirection(GPIOB,PIN4,OUTPUT_SPEED_10MHZ_PP);//griper right down CW
	GPIO_voidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_PP);//griper right down CCW

	GPIO_voidSetPinDirection(GPIOB,PIN5,OUTPUT_SPEED_10MHZ_PP);//griper left up CW
	GPIO_voidSetPinDirection(GPIOA,PIN10,OUTPUT_SPEED_10MHZ_PP);//griper left up CCW

	GPIO_voidSetPinDirection(GPIOB,PIN6,OUTPUT_SPEED_10MHZ_PP);//griper left down CW
	GPIO_voidSetPinDirection(GPIOA,PIN11,OUTPUT_SPEED_10MHZ_PP);//griper left down CCW

	GPIO_voidSetPinDirection(GPIOB,PIN7,OUTPUT_SPEED_10MHZ_PP);//up down CW
	GPIO_voidSetPinDirection(GPIOB,PIN8,OUTPUT_SPEED_10MHZ_PP);//up down CCW


	GPIO_voidSetPinDirection(GPIOC,PIN13,INPUT_PULL_UP_DOWN);//switch right up close
	GPIO_voidSetPinDirection(GPIOC,PIN14,INPUT_PULL_UP_DOWN);//switch lift up close
	GPIO_voidSetPinDirection(GPIOC,PIN15,INPUT_PULL_UP_DOWN);//switch right down close
	GPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_PULL_UP_DOWN);//switch left down close
	GPIO_voidSetPinDirection(GPIOA,PIN1,INPUT_PULL_UP_DOWN);//switch right up open
	GPIO_voidSetPinDirection(GPIOA,PIN2,INPUT_PULL_UP_DOWN);//switch left up open
	GPIO_voidSetPinDirection(GPIOA,PIN3,INPUT_PULL_UP_DOWN);//switch right down open
	GPIO_voidSetPinDirection(GPIOA,PIN4,INPUT_PULL_UP_DOWN);//switch left down open
	GPIO_voidSetPinDirection(GPIOA,PIN5,INPUT_PULL_UP_DOWN);//switch move up
	GPIO_voidSetPinDirection(GPIOA,PIN6,INPUT_PULL_UP_DOWN);//switch move down



}
/**************************************************************************************************************/

/**************************************************************************************************************/
void Robot_voidCloseGripers(void)
{
	griper_voidCloseLeftDown();
	griper_voidCloseRightDown();
	griper_voidCloseLeftUp();
	griper_voidCloseRightUp();
	if(switch_left_up_close == Pressed)
	{
		griper_voidStopLeftUp();
		griper_up_left_flag = Close ;
	}
	if(switch_right_up_close == Pressed)
	{
		griper_voidStopRightUp();
		griper_up_right_flag = Close ;
	}
	if(switch_left_down_close == Pressed)
	{
		griper_voidStopLeftDown();
		griper_down_left_flag = Close ;
	}
	if(switch_right_down_close == Pressed)
	{
		griper_voidStopRightDown();
		griper_down_right_flag = Close ;
	}
}
/**************************************************************************************************************/

/**************************************************************************************************************/
void Robot_voidOpenGripers(void)
{
	griper_voidOpenLeftDown();
	griper_voidOpenRightDown();
	griper_voidOpenLeftUp();
	griper_voidOpenRightUp();
	if(switch_left_up_open == Pressed)
	{
		griper_voidStopLeftUp();
		griper_up_left_flag = Open ;
	}
	if(switch_right_up_open == Pressed)
	{
		griper_voidStopRightUp();
		griper_up_right_flag = Open ;
	}
	if(switch_left_down_open == Pressed)
	{
		griper_voidStopLeftDown();
		griper_down_left_flag = Open ;
	}
	if(switch_right_down_open == Pressed)
	{
		griper_voidStopRightDown();
		griper_down_right_flag = Open ;
	}
}
/**************************************************************************************************************/

/**************************************************************************************************************/
void Robot_voidMoveUp(u8 copy_u8NumOfStep)
{
	u8 counter = 0 ;
	for(counter = 0 ; counter < copy_u8NumOfStep ;counter++ )
	{
		/*  close Down griper */
		if(switch_right_down_close == Pressed)
		{
			/*stop the right down motor*/
			griper_voidStopRightDown();
			griper_down_right_flag = Close;
		}
		else if(switch_right_down_close == NotPressed && griper_down_right_flag == Open)
		{
			griper_voidCloseRightDown();
			griper_down_right_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		if(switch_left_down_close == Pressed)
		{
			/*stop the left down motor*/
			griper_voidStopLeftDown();
			griper_down_left_flag  = Close ;
		}
		else if(switch_left_down_close == NotPressed && griper_down_left_flag  == Open)
		{
			/*Close the left down motor*/
			griper_voidCloseLeftDown();
			griper_down_left_flag  = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Open upper griper */
		if(switch_right_up_open == Pressed )
		{
			/*Stop the right up motor*/
			griper_voidStopRightUp();
			griper_up_right_flag  = Open;
		}
		else if(switch_right_up_open == NotPressed && griper_down_left_flag == Close && griper_down_right_flag  == Close && griper_up_right_flag == Close)
		{
			/*Open the right up motor*/
			griper_voidOpenRightUp();
			griper_up_right_flag  = Close;
		}
		else
		{
			//Do Nothing
		}
		if(switch_left_up_open == Pressed)
		{
			/*Stop the left up motor*/
			griper_voidStopLeftUp();
			griper_up_left_flag  = Open;
		}
		else if(switch_left_up_open == NotPressed && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag == Close)
		{
			/*Open the left up motor*/
			griper_voidOpenLeftUp();
			griper_up_left_flag = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Open Move upDown*/
		if(switch_move_up_open == Pressed)
		{
			/*Stop the Up Down Motor*/
			Move_voidStopUpDown();
			move_up_down_flag  = Open;
		}
		else if(switch_right_up_open == NotPressed && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag  == Open && griper_up_right_flag  == Open &&	move_up_down_flag == Close)
		{
			/*Up the Up Down Motor*/
			Move_voidOpenUpDown();
			move_up_down_flag  = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Close upper griper with checking until Upper sensor read true*/
		if(switch_right_up_close == Pressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close)
		{
			/*Stop the right up motor*/
			griper_voidStopRightUp();
			griper_up_right_flag = Close;
		}
		else if(switch_right_up_close == NotPressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_right_flag == Open)
		{
			/*CLose the right up motor*/
			griper_voidCloseRightUp();
			griper_up_right_flag = Open;
		}
		else
		{
			//Do Nothing
		}

		if(switch_left_up_close == Pressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close)
		{
			/*Stop the left up motor*/
			griper_voidStopLeftUp();
			griper_up_left_flag = Close;
		}
		else if(switch_left_up_close == NotPressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag == Open)
		{
			/*Close the left up motor*/
			griper_voidCloseLeftUp();
			griper_up_left_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Open Down griper*/
		if(switch_right_down_open == Pressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open)
		{
			/*stop the right down motor*/
			griper_voidStopRightDown();
			griper_down_right_flag = Open;
		}
		else if(switch_right_down_open == NotPressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open && griper_down_right_flag == Close)
		{
			/*open the right down motor*/
			griper_voidOpenRightDown();
			griper_down_right_flag = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		if(switch_left_down_open == Pressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open)
		{
			/*stop the left down motor*/
			griper_voidStopLeftDown();
			griper_down_left_flag = Open;
		}
		else if(switch_left_down_open == NotPressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open && griper_down_left_flag == Close)
		{
			/*open the left down motor*/
			griper_voidOpenLeftDown();
			griper_down_left_flag = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Close UP Down Motor*/
		if(switch_move_down_close == Pressed && griper_up_right_flag == Close && griper_up_right_flag == Close && griper_down_left_flag == Open && griper_down_right_flag == Open)
		{
			/*Stop the Up Down Motor*/
			Move_voidStopUpDown();
			move_up_down_flag = Close;
		}
		else if(switch_right_up_close == NotPressed && griper_up_right_flag == Close && griper_up_right_flag == Close && griper_down_left_flag == Open && griper_down_right_flag == Open && move_up_down_flag == Open)
		{
			/*close the Up Down Motor*/
			Move_voidCloseUpDown();
			move_up_down_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Close Down griper with checking untill Down sensor read true*/
		if(switch_right_down_close == Pressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close)
		{
			/*stop the right down motor*/
			griper_voidStopRightDown();
			griper_down_right_flag = Close;
		}
		else if(switch_right_down_close == NotPressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close && griper_down_right_flag == Open)
		{
			/*close the right down motor*/
			griper_voidCloseRightDown();
			griper_down_right_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		if(switch_left_down_close == Pressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close)
		{
			/*stop the left down motor*/
			griper_voidStopLeftDown();
			griper_down_left_flag = Close;
		}
		else if(switch_left_down_close == NotPressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close && griper_down_left_flag == Open )
		{
			/*Close the left down motor*/
			griper_voidCloseLeftDown();
			griper_down_left_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
	}
}
/**************************************************************************************************************/

/**************************************************************************************************************/
void Robot_voidMoveDown(u8 copy_u8NumOfStep)
{

	u8 counter = 0 ;
	for(counter = 0 ; counter < copy_u8NumOfStep ;counter++ )
	{
		/*Close upper griper with checking until Upper sensor read true*/
		if(switch_right_up_close == Pressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close)
		{
			/*Stop the right up motor*/
			griper_voidStopRightUp();
			griper_up_right_flag = Close;
		}
		else if(switch_right_up_close == NotPressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_right_flag == Open)
		{
			/*CLose the right up motor*/
			griper_voidCloseRightUp();
			griper_up_right_flag = Open;
		}
		else
		{
			//Do Nothing
		}

		if(switch_left_up_close == Pressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close)
		{
			/*Stop the left up motor*/
			griper_voidStopLeftUp();
			griper_up_left_flag = Close;
		}
		else if(switch_left_up_close == NotPressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag == Open)
		{
			/*Close the left up motor*/
			griper_voidCloseLeftUp();
			griper_up_left_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

		/*Open Down griper*/
		if(switch_right_down_open == Pressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open)
		{
			/*stop the right down motor*/
			griper_voidStopRightDown();
			griper_down_right_flag = Open;
		}
		else if(switch_right_down_open == NotPressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open && griper_down_right_flag == Close)
		{
			/*open the right down motor*/
			griper_voidOpenRightDown();
			griper_down_right_flag = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		if(switch_left_down_open == Pressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open)
		{
			/*stop the left down motor*/
			griper_voidStopLeftDown();
			griper_down_left_flag = Open;
		}
		else if(switch_left_down_open == NotPressed && griper_up_right_flag == Close && griper_up_left_flag == Close && move_up_down_flag == Open && griper_down_left_flag == Close)
		{
			/*open the left down motor*/
			griper_voidOpenLeftDown();
			griper_down_left_flag = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		/**************************************/

		/*Open Move upDown*/
		if(switch_move_up_open == Pressed)
		{
			/*Stop the Up Down Motor*/
			Move_voidStopUpDown();
			move_up_down_flag  = Open;
		}
		else if(switch_right_up_open == NotPressed && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag  == Open && griper_up_right_flag  == Open &&	move_up_down_flag == Close)
		{
			/*Up the Up Down Motor*/
			Move_voidOpenUpDown();
			move_up_down_flag  = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		/*Close Down griper with checking untill Down sensor read true*/
		if(switch_right_down_close == Pressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close)
		{
			/*stop the right down motor*/
			griper_voidStopRightDown();
			griper_down_right_flag = Close;
		}
		else if(switch_right_down_close == NotPressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close && griper_down_right_flag == Open)
		{
			/*close the right down motor*/
			griper_voidCloseRightDown();
			griper_down_right_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		if(switch_left_down_close == Pressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close)
		{
			/*stop the left down motor*/
			griper_voidStopLeftDown();
			griper_down_left_flag = Close;
		}
		else if(switch_left_down_close == NotPressed && griper_up_right_flag == Close && griper_up_right_flag == Close &&move_up_down_flag == Close && griper_down_left_flag == Open )
		{
			/*Close the left down motor*/
			griper_voidCloseLeftDown();
			griper_down_left_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		/**************************************/

		/*Open upper griper */
		if(switch_right_up_open == Pressed )
		{
			/*Stop the right up motor*/
			griper_voidStopRightUp();
			griper_up_right_flag  = Open;
		}
		else if(switch_right_up_open == NotPressed && griper_down_left_flag == Close && griper_down_right_flag  == Close && griper_up_right_flag == Close)
		{
			/*Open the right up motor*/
			griper_voidOpenRightUp();
			griper_up_right_flag  = Close;
		}
		else
		{
			//Do Nothing
		}
		if(switch_left_up_open == Pressed)
		{
			/*Stop the left up motor*/
			griper_voidStopLeftUp();
			griper_up_left_flag  = Open;
		}
		else if(switch_left_up_open == NotPressed && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag == Close)
		{
			/*Open the left up motor*/
			griper_voidOpenLeftUp();
			griper_up_left_flag = Close;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		/*Close UP Down Motor*/
		if(switch_move_down_close == Pressed && griper_up_right_flag == Close && griper_up_right_flag == Close && griper_down_left_flag == Open && griper_down_right_flag == Open)
		{
			/*Stop the Up Down Motor*/
			Move_voidStopUpDown();
			move_up_down_flag = Close;
		}
		else if(switch_right_up_close == NotPressed && griper_up_right_flag == Close && griper_up_right_flag == Close && griper_down_left_flag == Open && griper_down_right_flag == Open && move_up_down_flag == Open)
		{
			/*close the Up Down Motor*/
			Move_voidCloseUpDown();
			move_up_down_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/
		/*Close upper griper with checking until Upper sensor read true*/
		if(switch_right_up_close == Pressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close)
		{
			/*Stop the right up motor*/
			griper_voidStopRightUp();
			griper_up_right_flag = Close;
		}
		else if(switch_right_up_close == NotPressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_right_flag == Open)
		{
			/*CLose the right up motor*/
			griper_voidCloseRightUp();
			griper_up_right_flag = Open;
		}
		else
		{
			//Do Nothing
		}

		if(switch_left_up_close == Pressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close)
		{
			/*Stop the left up motor*/
			griper_voidStopLeftUp();
			griper_up_left_flag = Close;
		}
		else if(switch_left_up_close == NotPressed && move_up_down_flag == Open && griper_down_left_flag  == Close && griper_down_right_flag  == Close && griper_up_left_flag == Open)
		{
			/*Close the left up motor*/
			griper_voidCloseLeftUp();
			griper_up_left_flag = Open;
		}
		else
		{
			//Do Nothing
		}
		/**************************************/

	}
}


