#pragma once
#include"utils.h"
#include "datatypes.h"

typedef struct ItemValue {
    DataType type;
    ptr data;
} ItemValue;

typedef struct ItemKey {
    DataType type;
    ptr keyI;
} ItemKey;

typedef struct Item {
    ItemKey* key;
    ItemValue* value;
} ItemMap;

