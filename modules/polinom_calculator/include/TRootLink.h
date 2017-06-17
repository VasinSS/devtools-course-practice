//  Copyright 2017 Ivan Kiselev

#ifndef MODULES_POLINOM_CALCULATOR_INCLUDE_TROOTLINK_H_
#define MODULES_POLINOM_CALCULATOR_INCLUDE_TROOTLINK_H_
#include "Value.h"
#include <iostream>
class TRootLink;
typedef TRootLink *PTRootLink;
typedef Value *PValue;
class TRootLink {
 public:
    ~TRootLink();
    PTRootLink GetNextLink();
    void SetNextLink(PTRootLink pLink);
    void InsNextLink(PTRootLink pLink);
    virtual void SeValue(PValue pVal) = 0;
    virtual PValue GeValue() = 0;
    friend class TDatList;

 protected:
    PTRootLink pNext_;  //  next point
    explicit TRootLink(PTRootLink pN = NULL);
};
#endif  //  MODULES_POLINOM_CALCULATOR_INCLUDE_TROOTLINK_H_
