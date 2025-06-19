#ifndef __MATH_EXPAND_H
#define __MATH_EXPAND_H


#include "Stdint_Expand/stdint_Expand.h"


extern cuint32_t Pow10_uint32_t[10];  //返回10^x
extern cfloat32_t Pow10_float32_t[17];

#define GET_POW10_FLOAT32(x) (Pow10_float32_t[(x)+7])  //输入-7，9

//限幅函数
#define CLAMP(input, upper, lower) (((input) < (lower)) ? (lower) : (((input) > (upper)) ? (upper) : (input)))
//小数点后第一位四舍五入, type为强制类型转换结果类型，输入不要是算式
#define ROUND(x, type) ((x) >= 0 ? (type)((x) + 0.5f) : (type)((x) - 0.5f))


#endif /* __MATH_EXPAND_H */

