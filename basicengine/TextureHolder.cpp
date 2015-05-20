#include "TextureHolder.h"

using namespace std;

TextureHolder::TextureHolder() {

}

void TextureHolder::addTexture(string path, string name) {
    sf::Texture Temp;
    Temp.loadFromFile(path);
    textureList.push_back(Temp);
    textureMap[name] = (textureList.size() - 1);
}

sf::Texture* TextureHolder::getTexture(string name) {
    return &textureList[textureMap[name]];
}

sf::Texture& TextureHolder::getTextureRef(string name) {
    return textureList[textureMap[name]];
}
