/*
 * BIT_MATH.h
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define SET_BIT(PortID , PinID)					((PortID)|=1<<(PinID))
#define CLEAR_BIT(PortID , PinID)				((PortID) &= ~(1<<(PinID)))
#define TOGGLE_BIT(PortID , PinID)				((PortID) ^= 1<<(PinID))
#define GET_BIT(PortID , PinID)					(((PortID)>>(PinID))& 0x01)




#endif /* BIT_MATH_H_ */