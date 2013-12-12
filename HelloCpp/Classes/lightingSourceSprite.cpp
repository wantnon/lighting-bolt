//
//  lightingSourceSprite.cpp
//  HelloCpp
//
//  Created by ck02-084 on 13-12-6.
//
//

#include "lightingSourceSprite.h"
bool ClightingSourceSprite::init(string texFileName){
    this->initWithFile(texFileName.c_str());
    
    return true;
    
}