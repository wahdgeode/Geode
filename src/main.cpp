#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GDPSMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto size = CCDirector::sharedDirector()->getWinSize();

        auto title = CCLabelBMFont::create(
            "GDPS EDITOR 2.3",
            "goldFont.fnt"
        );

        if (title) {
            title->setPosition({
                size.width / 2,
                size.height - 25
            });
            title->setScale(0.55f);
            addChild(title, 100);
        }

        auto menu = CCMenu::create();
        menu->setPosition({0, 0});

        const char* names[] = {
            "THE MAP",
            "VERSUS",
            "CREATE"
        };

        for (int i = 0; i < 3; i++) {
            auto label = CCLabelBMFont::create(
                names[i],
                "goldFont.fnt"
            );

            if (!label) continue;

            label->setScale(0.45f);

            auto button = CCMenuItemLabel::create(
                label,
                this,
                menu_selector(GDPSMenu::onButton)
            );

            if (button) {
                button->setPosition({
                    size.width * (0.25f + i * 0.25f),
                    45
                });
                button->setTag(i);
                menu->addChild(button);
            }
        }

        addChild(menu, 100);
        return true;
    }

    void onButton(CCObject* sender) {
        auto item = static_cast<CCNode*>(sender);
        const char* names[] = {
            "The Map",
            "Versus",
            "Create"
        };

        int tag = item->getTag();

        FLAlertLayer::create(
            "GDPS EDITOR 2.3",
            names[tag],
            "OK"
        )->show();
    }
};
