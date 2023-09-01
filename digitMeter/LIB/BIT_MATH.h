#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BITNO)		VAR |= (1 << BITNO)
#define CLR_BIT(VAR, BITNO)		VAR &= ~(1 << BITNO)
#define GET_BIT(VAR, BITNO)		((VAR >> BITNO) & 1)
#define TOG_BIT(VAR, BITNO)		VAR ^= (1 << BITNO)

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif
