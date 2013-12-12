#include "HelloWorldScene.h"
#include "AppMacros.h"
USING_NS_CC;
#include "CCControlButton.h"
using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

 /*   /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
*/
    /////////////////////////////
    // 3. add your codes below...
    //enable touch
	setTouchEnabled( true );
    //set projection to 2D (default is 3D). if use 3D projection, may cause tiny projection error, in some situation, if the error accumulated across frames, may cause effect wrong.
    CCDirector::sharedDirector()->setProjection(kCCDirectorProjection2D);
    //sinSize
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();//winSize equals to designResolutionSize
    //show frame rate info
    CCDirector::sharedDirector()->setDisplayStats(true);
  /*  //test nPow
    {
        float a=0.3;
        for(int n=0;n<=100;n++){
            CCLOG("----");
            CCLOG("nPow:%f",nPow(a,n));
            CCLOG(" pow:%f",pow(a,n));
        }
    }*/
    
 //   this->scheduleUpdate();
  /*  //back ground
    CCSprite*backGround=CCSprite::create();
    backGround->initWithFile("HelloWorld_iphone5.png");
    addChild(backGround,-1);
    backGround->setPosition(ccp(winSize.width/2,winSize.height/2));
  */ 
    //lightingSprite shader
    ClightingSprite::initProgram();
    
    //
    startPoint=CCPoint(winSize.width/6, winSize.height/2);
    midPoint=CCPoint(winSize.width/2,winSize.height/2);
    endPoint=CCPoint(winSize.width/6*5, winSize.height/2);
    
    isSwingMove=false;
    
  
    //lightingSprit
    {
        lightingSprite=new ClightingSprite();
        lightingSprite->autorelease();
        lightingSprite->init();
        lightingSprite->setStartPoint(startPoint);
        lightingSprite->setEndPoint(midPoint);
        lightingSprite->genLighting();
        this->addChild(lightingSprite);
        lightingSprite->scheduleUpdate();
        lightingSprite->setDOpacity(28);//40//this value do not too big, slow fadeOut lighting looks good
        lightingSprite->setIsDoJitter(true);
    }
   //lightingSprit2
    {
        lightingSprite2=new ClightingSprite();
        lightingSprite2->autorelease();
        lightingSprite2->init();
        lightingSprite2->setStartPoint(startPoint);
        lightingSprite2->setEndPoint(midPoint);
        lightingSprite2->genLighting();
        this->addChild(lightingSprite2);
        lightingSprite2->scheduleUpdate();
        lightingSprite2->setDOpacity(28);//40//this value do not too big, slow fadeOut lighting looks good
        lightingSprite2->setDelay(255.0/lightingSprite2->getDOpacity()/2);
        lightingSprite2->setIsDoJitter(true);

    }
    //lightingSpritB
    {
        lightingSpriteB=new ClightingSprite();
        lightingSpriteB->autorelease();
        lightingSpriteB->init();
        lightingSpriteB->setStartPoint(midPoint);
        lightingSpriteB->setEndPoint(endPoint);
        lightingSpriteB->genLighting();
        this->addChild(lightingSpriteB);
        lightingSpriteB->scheduleUpdate();
        lightingSpriteB->setDOpacity(30);//40//this value do not too big, slow fadeOut lighting looks good
        lightingSpriteB->setIsDoJitter(true);
    }
    //lightingSpritB2
    {
        lightingSpriteB2=new ClightingSprite();
        lightingSpriteB2->autorelease();
        lightingSpriteB2->init();
        lightingSpriteB2->setStartPoint(midPoint);
        lightingSpriteB2->setEndPoint(endPoint);
        lightingSpriteB2->genLighting();
        this->addChild(lightingSpriteB2);
        lightingSpriteB2->scheduleUpdate();
        lightingSpriteB2->setDOpacity(30);//40//this value do not too big, slow fadeOut lighting looks good
        lightingSpriteB2->setDelay(255.0/lightingSpriteB2->getDOpacity()/2);
        lightingSpriteB2->setIsDoJitter(true);
        
    }

/*    //control button
    {
        cocos2d::extension::CCScale9Sprite* btnUp=cocos2d::extension::CCScale9Sprite::create("button.png");
        cocos2d::extension::CCScale9Sprite* btnDn=cocos2d::extension::CCScale9Sprite::create("button_dn.png");
        CCLabelTTF*title=CCLabelTTF::create("bright line", "Helvetica", 30);
        cocos2d::extension::CCControlButton* controlButton=cocos2d::extension::CCControlButton::create(title, btnUp);
        controlButton->setBackgroundSpriteForState(btnDn,cocos2d::extension::CCControlStateHighlighted);
        controlButton->setPreferredSize(CCSize(170,60));
        controlButton->setPosition(ccp(winSize.width/5*4,winSize.height-60));
        controlButton->addTargetWithActionForControlEvents(this, (cocos2d::extension::SEL_CCControlHandler)(&HelloWorld::drawBrightLine), cocos2d::extension::CCControlEventTouchDown);
        addChild(controlButton);
        controlButton->setVisible(true);
        m_controlButton=controlButton;
    }*/
    //control button2
    {
        cocos2d::extension::CCScale9Sprite* btnUp=cocos2d::extension::CCScale9Sprite::create("button.png");
        cocos2d::extension::CCScale9Sprite* btnDn=cocos2d::extension::CCScale9Sprite::create("button_dn.png");
        CCLabelTTF*title=CCLabelTTF::create("swing move", "Helvetica", 30);
        cocos2d::extension::CCControlButton* controlButton=cocos2d::extension::CCControlButton::create(title, btnUp);
        controlButton->setBackgroundSpriteForState(btnDn,cocos2d::extension::CCControlStateHighlighted);
        controlButton->setPreferredSize(CCSize(170,60));
        controlButton->setPosition(ccp(winSize.width/5*4,winSize.height-160));
        controlButton->addTargetWithActionForControlEvents(this, (cocos2d::extension::SEL_CCControlHandler)(&HelloWorld::swingMove), cocos2d::extension::CCControlEventTouchDown);
        addChild(controlButton);
        controlButton->setVisible(true);
        m_controlButton=controlButton;
    }
    
    
/*    //slider
	{
		CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
		CCControlSlider *slider = CCControlSlider::create("sliderTrack.png","sliderProgress.png" ,"sliderThumb.png");
		slider->setAnchorPoint(ccp(0.5f, 0.5f));
		slider->setMinimumValue(0.0f); // Sets the min value of range
		slider->setMaximumValue(1); // Sets the max value of range
		slider->setValue(0);
		slider->setPosition(ccp(screenSize.width / 2.0f, screenSize.height / 4.0f));
		slider->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::sliderAction), CCControlEventValueChanged);
		m_pSliderCtl=slider;
		this->addChild(slider,100);
		//title
		CCLabelTTF* pLabel = CCLabelTTF::create("R ", "Arial", 30);
		pLabel->setPosition(ccp(slider->getPositionX()-slider->getContentSize().width/2-pLabel->getContentSize().width/2, slider->getPositionY()));
        this->addChild(pLabel, 1);
	}
	//slider2
    {
		CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
		CCControlSlider *slider = CCControlSlider::create("sliderTrack.png","sliderProgress.png" ,"sliderThumb.png");
		slider->setAnchorPoint(ccp(0.5f, 0.5f));
		slider->setMinimumValue(0.0f); // Sets the min value of range
		slider->setMaximumValue(1); // Sets the max value of range
		slider->setValue(0);
		slider->setPosition(m_pSliderCtl->getPosition()+ccp(0,-m_pSliderCtl->getContentSize().height));
		slider->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::sliderAction2), CCControlEventValueChanged);
		m_pSliderCtl2=slider;
		this->addChild(slider,100);
		//title
		CCLabelTTF* pLabel = CCLabelTTF::create("brightness ", "Arial", 30);
		pLabel->setPosition(ccp(slider->getPositionX()-slider->getContentSize().width/2-pLabel->getContentSize().width/2, slider->getPositionY()));
        this->addChild(pLabel, 1);
	}*/
    
    // author info
    {
        CCLabelTTF* pLabel = CCLabelTTF::create("by yang chao (wantnon) 2013-12-10", "Arial", 30);
        pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - pLabel->getContentSize().height-60));
        this->addChild(pLabel, 1);
    }
    
    // add a label shows "Hello World"
    // create and initialize a label
 
    CCLabelTTF* pLabel = CCLabelTTF::create("Lighting Bolt Effect", "Arial", 45);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);
  
    
   
    
    return true;
}
void HelloWorld::drawBrightLine(CCObject *senderz, cocos2d::extension::CCControlEvent controlEvent){
    ClightingSprite* lightingSpriteList[4]={lightingSprite,lightingSprite2,lightingSpriteB,lightingSpriteB2};
    for(int i=0;i<4;i++){
        lightingSpriteList[i]->setIsDrawBrightLine(!lightingSpriteList[i]->getIsDrawBrightLine());
    }
}
void HelloWorld::swingMove(CCObject *senderz, cocos2d::extension::CCControlEvent controlEvent){
    isSwingMove=!isSwingMove;
    this->unscheduleUpdate();
    this->scheduleUpdate();
}

void HelloWorld::update(float t){
    if(isSwingMove){
        midPointAniFrameCounter++;
        if(midPointAniFrameCounter>3600000)midPointAniFrameCounter=0;
        
        
        ClightingSprite* lightingSpriteList[2]={lightingSprite,lightingSprite2};
        ClightingSprite* lightingSpriteListB[2]={lightingSpriteB,lightingSpriteB2};
        float dy=170*sinf(midPointAniFrameCounter*0.06);
        for(int i=0;i<2;i++){
            lightingSpriteList[i]->setEndPoint(midPoint+CCPoint(0,dy));
        }
        for(int i=0;i<2;i++){
            lightingSpriteListB[i]->setStartPoint(midPoint+CCPoint(0,dy));
        }
    }
    
}
void HelloWorld::sliderAction(CCObject* sender, CCControlEvent controlEvent)
{
    CCControlSlider* pSlider = (CCControlSlider*)sender;
    float value=pSlider->getValue();
    CCLOG("slider value:%f",value);
    
}
void HelloWorld::sliderAction2(CCObject* sender, CCControlEvent controlEvent)
{
    CCControlSlider* pSlider = (CCControlSlider*)sender;
    float value=pSlider->getValue();
    CCLOG("slider value:%f",value);
    
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}


void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSetIterator it;
    CCTouch* touch;
    
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
        CCPoint loc_winSpace = touch->getLocationInView();
        CCPoint loc_GLSpace = CCDirector::sharedDirector()->convertToGL(loc_winSpace);
        
      /*  lightingSprite->setEndPoint(loc_GLSpace);
        lightingSprite2->setEndPoint(loc_GLSpace);
        break;//because setEndPoint cost, so we should break early*/
        
    }
}
void HelloWorld::ccTouchesMoved(cocos2d::CCSet* touches , cocos2d::CCEvent* event)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSetIterator it;
    CCTouch* touch;
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
        CCPoint loc_winSpace = touch->getLocationInView();
        CCPoint loc_GLSpace = CCDirector::sharedDirector()->convertToGL(loc_winSpace);


      /*  lightingSprite->setEndPoint(loc_GLSpace);
        lightingSprite2->setEndPoint(loc_GLSpace);
        break;//because setEndPoint cost, so we should break early*/
    
        
		
    }
    
}

void HelloWorld::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSetIterator it;
    CCTouch* touch;
	for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if(!touch)
            break;
        
        CCPoint loc_winSpace = touch->getLocationInView();
        CCPoint loc_GLSpace = CCDirector::sharedDirector()->convertToGL(loc_winSpace);
        //CCLOG("loc_GLSpace:%f,%f",loc_GLSpace.x,loc_GLSpace.y);
    /*    lightingSprite->setEndPoint(loc_GLSpace);
        lightingSprite2->setEndPoint(loc_GLSpace);
        break;//because setEndPoint cost, so we should break early*/

        
    }
}

