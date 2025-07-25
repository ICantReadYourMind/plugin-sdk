/*
    Plugin-SDK (Grand Theft Auto IV) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "grcImage.h"

rage::grcImage::~grcImage() {
    plugin::CallMethodDyn(gpattern("56 8B F1 57 8B 4E 1C 85 C9"), this);
}

rage::grcImage* rage::grcImage::Create(uint32_t width, uint32_t height, uint32_t depth, rage::grcImage::Format format, rage::grcImage::ImageType type, int32_t extraMipmaps, int32_t extraLayers, int32_t unused) {
    return plugin::CallAndReturnDyn<rage::grcImage*>(gpattern("53 8B 5C 24 08 55 8B 6C 24 18"), width, height, depth, format, type, extraMipmaps, extraLayers, unused);
}

rage::grcImage* rage::grcImage::LoadJPEG(const char* path, rage::grcImage* image) {
    return plugin::CallAndReturnDyn<rage::grcImage*>(gpattern("6A 01 6A 01 68 ? ? ? ? FF 74 24 10"), path, image);
}

rage::grcImage* rage::grcImage::LoadJPEG(rage::fiStream* S, rage::grcImage* image) {
    return plugin::CallAndReturnDyn<rage::grcImage*>(gpattern("55 8D 6C 24 90 81 EC ? ? ? ? 53 56 8B 75 78 57 85 F6"), S, image);
}

rage::grcImage* rage::grcImage::LoadDDS(const char* path) {
    return plugin::CallAndReturnDyn<rage::grcImage*>(gpattern("55 8B EC 83 E4 F8 81 EC ? ? ? ? 53 55 56 57 6A 01"), path);
}

rage::grcImage* rage::grcImage::Load(const char* path) {
    return plugin::CallAndReturnDyn<rage::grcImage*>(gpattern("E8 ? ? ? ? 85 C0 75 2F 83 3D"), path);
}
