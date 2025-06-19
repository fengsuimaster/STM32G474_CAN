#include "Stdint_Expand/stdint_Expand.h"

float32_t Super_p_read(Super_p_structre_Typedef v)
{
    switch(v.type)
    {
        case pint8_type:
            return *(int8_t*)v.address;
        case pint16_type:
            return *(int16_t*)v.address;
        case pint32_type:
            return *(int32_t*)v.address;
        case puint8_type:
            return *(uint8_t*)v.address;
        case puint16_type:
            return *(uint16_t*)v.address;
        case puint32_type:
            return *(uint32_t*)v.address;
        case pcint8_type:
            return *(cint8_t*)v.address;
        case pcint16_type:
            return *(cint16_t*)v.address;
        case pcint32_type:
            return *(cint32_t*)v.address;
        case pcuint8_type:
            return *(cuint8_t*)v.address;
        case pcuint16_type:
            return *(cuint16_t*)v.address;
        case pcuint32_type:
            return *(cuint32_t*)v.address;
        case pfloat32_type:
            return *(float32_t*)v.address;
        case pfloat64_type:
            return *(float64_t*)v.address;
        case pcfloat32_type:
            return *(cfloat32_t*)v.address;
        case pcfloat64_type:
            return *(cfloat64_t*)v.address;
        default:
            return 0;
    }
}

void Super_p_add(Super_p_structre_Typedef v, float32_t add_value)
{
    switch(v.type)
    {
        case pint8_type:
            *(int8_t*)v.address += add_value;
            break;
        case pint16_type:
            *(int16_t*)v.address += add_value;
            break;
        case pint32_type:
            *(int32_t*)v.address += add_value;
            break;
        case puint8_type:
            *(uint8_t*)v.address += add_value;
            break;
        case puint16_type:
            *(uint16_t*)v.address += add_value;
            break;
        case puint32_type:
            *(uint32_t*)v.address += add_value;
            break;
        case pfloat32_type:
            *(float32_t*)v.address += add_value;
            break;
        case pfloat64_type:
            *(float64_t*)v.address += add_value;
            break;
    }
}

void Super_p_assign(Super_p_structre_Typedef v, float32_t assign_value)
{
    switch(v.type)
    {
        case pint8_type:
            *(int8_t*)v.address = assign_value;
            break;
        case pint16_type:
            *(int16_t*)v.address = assign_value;
            break;
        case pint32_type:
            *(int32_t*)v.address = assign_value;
            break;
        case puint8_type:
            *(uint8_t*)v.address = assign_value;
            break;
        case puint16_type:
            *(uint16_t*)v.address = assign_value;
            break;
        case puint32_type:
            *(uint32_t*)v.address = assign_value;
            break;
        case pfloat32_type:
            *(float32_t*)v.address = assign_value;
            break;
        case pfloat64_type:
            *(float64_t*)v.address = assign_value;
            break;
    }
}

//获取字符串长度
uint8_t Get_string_length(string_t p)
{
    uint8_t length = 0;
    
    while(*p != '\0')
    {
        p++;
        length++;
    }
    return length;
}
