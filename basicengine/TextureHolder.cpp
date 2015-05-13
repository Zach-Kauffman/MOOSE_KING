#include "TextureHolder.h"

using namespace std;

TextureHolder::TextureHolder() {

}

void TextureHolder::addTexture(string path, string name) {
    sf::Texture Temp;
    Temp.loadFromFile(path);
    textureList.push_back(Temp);
    std::map.push_back(textureList.size()-1);
}

sf::Texture& TextureHolder::getTexture(string name) {
    return textureList[Map[name]];
}
