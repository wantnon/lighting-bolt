//
//  lightingSourceSprite.h
//  HelloCpp
//
//  Created by ck02-084 on 13-12-6.
//
//

#ifndef __HelloCpp__lightingSourceSprite__
#define __HelloCpp__lightingSourceSprite__

#include <iostream>
#include "cocos2d.h"
#include "GLProgramWithMyUnifos.h"
#include "myFunc.h"
#include "simpleClasses.h"
using namespace cocos2d;
class ClightingSourceSprite:public CCSprite
{
public:
    bool init(string texFileName);

};
#endif /* defined(__HelloCpp__lightingSourceSprite__) */
