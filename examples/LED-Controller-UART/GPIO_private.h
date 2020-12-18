/*
 * GPIO_private.h
 *
 *  Created on: Nov 24, 2020
 *      Author: Mohammed
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*PORT1*/
#define PORT1DIR * ((u16*) 0x0204)
#define PORT1OUT * ((u16*) 0x0202)

/*PORT2*/
#define PORT2DIR * ((u16*) 0x0)
#define PORT2OUT * ((u16*) 0x0)

/*PORT4*/
#define PORT4DIR * ((u16*) 0x0225)
#define PORT4OUT * ((u16*) 0x0223)



#endif /* GPIO_PRIVATE_H_ */
