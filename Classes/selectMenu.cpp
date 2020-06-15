#include "selectMenu.h"
#include "VSPlayer.h"
#include "VS_AI.h"
#include "selectPlayer.h"
#include "HelloWorldScene.h"


Scene* selectMenu::createScene()
{
	
	return selectMenu::create();
}
bool selectMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto mainmenu = Menu::create();
	int index = 2;
	auto itemlabel = Label::createWithTTF("VS Player", "fonts/arial.ttf", 48);
	auto itemlabel2= Label::createWithTTF("VS AI", "fonts/arial.ttf",48);
	auto menuItem = MenuItemLabel::create(itemlabel);
	auto menuItem2 = MenuItemLabel::create(itemlabel2);
	//���ò˵�1�ص�
	menuItem->setCallback([&](cocos2d::Ref* sender) {
		Director::getInstance()->replaceScene(selectPlayer::createScene());
		});
	//���ò˵�1λ��
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 50));
	//���ò˵���2�ص�
	menuItem2->setCallback([&](cocos2d::Ref* sender) {
		Director::getInstance()->replaceScene(VS_AI::createScene());
		});
    //���ò˵�2λ��
	menuItem2->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2 ).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 50));
	mainmenu->addChild(menuItem, 2);
	mainmenu->addChild(menuItem2, 2);
	mainmenu->setPosition(Vec2::ZERO);
	
	this->addChild(mainmenu, 1);
	return true;
}
void selectMenu::cleanup()
{
	
	AudioEngine::stopAll();
	// stop background music.
	
}