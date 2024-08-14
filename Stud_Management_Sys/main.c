/*
 * main.c
 *
 *  Created on: Aug 14, 2024
 *      Author: hp
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLL.h"
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	while(1)
	{
		printMenu();
		handleMenuOption();
	}
}

