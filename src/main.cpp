#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/utils/NodeIDs.hpp>

using namespace geode::prelude;

class $modify(FourButtonCommunity, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init())
            return false;

        // NodeIDs provides the IDs before this hook.
        auto hide = [this](const char* id) {
            if (auto* node = this->getChildByIDRecursive(id)) {
                node->setVisible(false);
                node->setEnabled(false);
            }
        };

        // Hide everything except:
        // Featured
        // Search
        // Create
        // Saved

        hide("lists-button");
        hide("paths-button");
        hide("map-packs-button");
        hide("map-button");
        hide("daily-button");
        hide("weekly-button");
        hide("event-button");
        hide("gauntlets-button");
        hide("scores-button");
        hide("quests-button");
        hide("versus-button");

        return true;
    }
};
