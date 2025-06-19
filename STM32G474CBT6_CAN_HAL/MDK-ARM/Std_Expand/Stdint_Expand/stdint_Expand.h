/**
  *******************************************************************************************************************
  * @file            stdint_Expand.c
  * @author          Pcc
  * @version         V1.0
  * @Target core     arm
  * @date            2025-6-19
  * @brief           stdint的扩展，包含很多基本类型，加入了类型定义宏，void指针结构体操作方法，共用体转换宏
  *******************************************************************************************************************
  */
#ifndef __STDINT_EXPAND_H
#define __STDINT_EXPAND_H

//用于定义所有类型，看指针应该从右往左看，*右边是指针变量，左边是指针指向的对象
#define Typedef_ALLTYPE(type) typedef type *p##type;     /*指针*/\
                          typedef const type c##type;    /*常量*/\
                          typedef const type *pc##type;  /*指向常量的指针*/\
                          typedef type *const cp##type;  /*常量指针*/\
                          typedef const type *const cpc##type;  /*指向常量的常量指针*/

//用于定义结构体变量及其绑定指针
#define DECLARE_STRUCTRE_AND_P(type, name) type name##_structre = {0};  /*定义结构体*/\
                                   p##type p##name = &name##_structre;  /*定义结构体指针*/

/*********************整型*********************/
#ifndef __stdint_h
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
#endif /*__stdint_h*/

Typedef_ALLTYPE(int8_t)
Typedef_ALLTYPE(int16_t)
Typedef_ALLTYPE(int32_t)
Typedef_ALLTYPE(uint8_t)
Typedef_ALLTYPE(uint16_t)
Typedef_ALLTYPE(uint32_t)

/********************浮点型********************/
#ifndef _ARM_MATH_H
typedef  float float32_t;
typedef double float64_t;
#endif /*_ARM_MATH_H*/

Typedef_ALLTYPE(float32_t)
Typedef_ALLTYPE(float64_t)

/*******************字符串型*******************/
typedef const uint8_t       *string_t;
typedef const uint8_t *const cstring_t;

/******************void函数型******************/
typedef void(*voidf_t)(void);

/**********************PI**********************/
#ifndef PI
#define PI     3.14159265358979f
#endif /*PI*/

#ifndef PI2
#define PI2    6.28318530717958f
#endif /*PI2*/

/*******************uTypedef*******************/
#define U_TYPEDEF
#ifdef  U_TYPEDEF
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
#endif /*U_TYPEDEF*/

/*********************BIT**********************/
#define BYTE_BIT1  (uint8_t)0x01
#define BYTE_BIT2  (uint8_t)0x02
#define BYTE_BIT3  (uint8_t)0x04
#define BYTE_BIT4  (uint8_t)0x08
#define BYTE_BIT5  (uint8_t)0x10
#define BYTE_BIT6  (uint8_t)0x20
#define BYTE_BIT7  (uint8_t)0x40
#define BYTE_BIT8  (uint8_t)0x80

#define HALFWORD_BIT1  (uint16_t)0x0001
#define HALFWORD_BIT2  (uint16_t)0x0002
#define HALFWORD_BIT3  (uint16_t)0x0004
#define HALFWORD_BIT4  (uint16_t)0x0008
#define HALFWORD_BIT5  (uint16_t)0x0010
#define HALFWORD_BIT6  (uint16_t)0x0020
#define HALFWORD_BIT7  (uint16_t)0x0040
#define HALFWORD_BIT8  (uint16_t)0x0080
#define HALFWORD_BIT9  (uint16_t)0x0100
#define HALFWORD_BIT10 (uint16_t)0x0200
#define HALFWORD_BIT11 (uint16_t)0x0400
#define HALFWORD_BIT12 (uint16_t)0x0800
#define HALFWORD_BIT13 (uint16_t)0x1000
#define HALFWORD_BIT14 (uint16_t)0x2000
#define HALFWORD_BIT15 (uint16_t)0x4000
#define HALFWORD_BIT16 (uint16_t)0x8000

#define WORD_BIT1  (uint32_t)0x00000001
#define WORD_BIT2  (uint32_t)0x00000002
#define WORD_BIT3  (uint32_t)0x00000004
#define WORD_BIT4  (uint32_t)0x00000008
#define WORD_BIT5  (uint32_t)0x00000010
#define WORD_BIT6  (uint32_t)0x00000020
#define WORD_BIT7  (uint32_t)0x00000040
#define WORD_BIT8  (uint32_t)0x00000080
#define WORD_BIT9  (uint32_t)0x00000100
#define WORD_BIT10 (uint32_t)0x00000200
#define WORD_BIT11 (uint32_t)0x00000400
#define WORD_BIT12 (uint32_t)0x00000800
#define WORD_BIT13 (uint32_t)0x00001000
#define WORD_BIT14 (uint32_t)0x00002000
#define WORD_BIT15 (uint32_t)0x00004000
#define WORD_BIT16 (uint32_t)0x00008000
#define WORD_BIT17 (uint32_t)0x00010000
#define WORD_BIT18 (uint32_t)0x00020000
#define WORD_BIT19 (uint32_t)0x00040000
#define WORD_BIT20 (uint32_t)0x00080000
#define WORD_BIT21 (uint32_t)0x00100000
#define WORD_BIT22 (uint32_t)0x00200000
#define WORD_BIT23 (uint32_t)0x00400000
#define WORD_BIT24 (uint32_t)0x00800000
#define WORD_BIT25 (uint32_t)0x01000000
#define WORD_BIT26 (uint32_t)0x02000000
#define WORD_BIT27 (uint32_t)0x04000000
#define WORD_BIT28 (uint32_t)0x08000000
#define WORD_BIT29 (uint32_t)0x10000000
#define WORD_BIT30 (uint32_t)0x20000000
#define WORD_BIT31 (uint32_t)0x40000000
#define WORD_BIT32 (uint32_t)0x80000000

//位操作函数
#define BIT_READ(input, BIT)  !!((input) &   (BIT))  //两个!!使返回值为“布偶型”
#define BIT_SET(input, BIT)     ((input) |=  (BIT))
#define BIT_CLEAR(input, BIT)   ((input) &= ~(BIT))

/*******************super_p********************/
typedef enum
{
    pint8_type      ,
    pint16_type     ,
    pint32_type     ,
    puint8_type     ,
    puint16_type    ,
    puint32_type    ,
    pcint8_type     ,
    pcint16_type    ,
    pcint32_type    ,
    pcuint8_type    ,
    pcuint16_type   ,
    pcuint32_type   ,
    pfloat32_type   ,
    pfloat64_type   ,
    pcfloat32_type  ,
    pcfloat64_type  ,
    string_type     ,   //注意这里存放的是参数本身，参数本身就是指针
    cstring_type    ,
    function_type   ,
}Super_p_enum_Typedef;  //超级指针类型标志
typedef struct
{
    void *address;               //无指定类型指针，用于存放参数地址
    Super_p_enum_Typedef  type;  //用于存放指针类别
}Super_p_structre_Typedef;  //超级指针结构体
Typedef_ALLTYPE(Super_p_structre_Typedef);

float32_t Super_p_read(Super_p_structre_Typedef v);                       //获取指针中的值
void Super_p_add(Super_p_structre_Typedef v, float32_t add_value);        //指针中的值加上一个数
void Super_p_assign(Super_p_structre_Typedef v, float32_t assign_value);  //重写指针中的值

/*******************union********************/
typedef union
{
    uint8_t  byte[2];
    uint16_t halfword;
}Halfword_union_Typedef;
//半字共用体类型
typedef union
{
    uint8_t  byte[4];
    uint16_t halfword[2];
    uint32_t word;
}Word_union_Typedef;
//字共用体类型
//使用半字共用体把字节转换为半字
#define BYTE_TO_HALFWORD(Halfword_union, byteH, byteL) (Halfword_union.byte[0]=byteH, Halfword_union.byte[1]=byteL, Halfword_union.halfword)
//使用字共用体把字节转换为字
#define BYTE_TO_WORD(Word_union, byte0, byte1, byte2, byte3) (Word_union.byte[0]=byte0, Word_union.byte[1]=byte1, Word_union.byte[2]=byte2, Word_union.byte[3]=byte3, Halfword_union.word)
//使用字共用体把半字转换为字
#define HALFWORD_TO_WORD(Word_union, halfwordH, halfwordL) (Word_union.halfword[0]=halfwordH, Word_union.halfword[1]=halfwordL, Halfword_union.word)

//参数不使用
#define UNUSE(x) (void)x
//获取字符串长度
uint8_t Get_string_length(string_t p);

#endif /*__STDINT_EXPAND_H*/
