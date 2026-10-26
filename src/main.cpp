
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
            title->setID("gdps-editor-title"_spr);
            addChild(title, 100);
        }

        return true;
    }
};
