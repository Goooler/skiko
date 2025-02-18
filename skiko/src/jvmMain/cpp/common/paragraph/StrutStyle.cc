#include <iostream>
#include <jni.h>
#include <vector>
#include "../interop.hh"
#include "interop.hh"
#include "ParagraphStyle.h"

using namespace std;
using namespace skia::textlayout;

static void deleteStrutStyle(StrutStyle* instance) {
    delete instance;
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nGetFinalizer
  (JNIEnv* env, jclass jclass) {
    return static_cast<jlong>(reinterpret_cast<uintptr_t>(&deleteStrutStyle));
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nMake
  (JNIEnv* env, jclass jclass) {
    StrutStyle* instance = new StrutStyle();
    return reinterpret_cast<jlong>(instance);
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nEquals
  (JNIEnv* env, jclass jclass, jlong ptr, jlong otherPtr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    StrutStyle* other = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(otherPtr));
    return *instance == *other;
}

extern "C" JNIEXPORT jlong JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nGetFontFamilies
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));

    std::vector<jlong>* res = new std::vector<jlong>();
    for (auto& fontFamily : instance->getFontFamilies()) {
        res->push_back(reinterpret_cast<jlong>(new SkString(fontFamily)));
    }

    return reinterpret_cast<jlong>(res);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nSetFontFamilies
  (JNIEnv* env, jclass jclass, jlong ptr, jobjectArray familiesArr, jint familiesCount) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setFontFamilies(skStringVector(env, familiesArr));
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nGetFontStyle
  (JNIEnv* env, jclass jclass, jlong ptr, jintArray fontStyleData) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    SkFontStyle fontStyle = instance->getFontStyle();
    jint res[3] = { fontStyle.weight(), fontStyle.width(), fontStyle.slant() };
    env->SetIntArrayRegion(fontStyleData, 0, 3, res);
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nSetFontStyle
  (JNIEnv* env, jclass jclass, jlong ptr, jint style) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setFontStyle(skija::FontStyle::fromJava(style));
}

extern "C" JNIEXPORT jfloat JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nGetFontSize
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    return instance->getFontSize();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nSetFontSize
  (JNIEnv* env, jclass jclass, jlong ptr, jfloat size) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setFontSize(size);
}

extern "C" JNIEXPORT jfloat JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nGetHeight
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    return instance->getHeight();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nSetHeight
  (JNIEnv* env, jclass jclass, jlong ptr, jfloat height) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setHeight(height);
}

extern "C" JNIEXPORT jfloat JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nGetLeading
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    return instance->getLeading();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nSetLeading
  (JNIEnv* env, jclass jclass, jlong ptr, jfloat leading) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setLeading(leading);
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nIsEnabled
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    return instance->getStrutEnabled();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt_StrutStyle_1nSetEnabled
  (JNIEnv* env, jclass jclass, jlong ptr, jboolean value) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setStrutEnabled(value);
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nIsHeightForced
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    return instance->getForceStrutHeight();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nSetHeightForced
  (JNIEnv* env, jclass jclass, jlong ptr, jboolean value) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setForceStrutHeight(value);
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nIsHeightOverridden
  (JNIEnv* env, jclass jclass, jlong ptr) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    return instance->getHeightOverride();
}

extern "C" JNIEXPORT void JNICALL Java_org_jetbrains_skia_paragraph_StrutStyleKt__1nSetHeightOverridden
  (JNIEnv* env, jclass jclass, jlong ptr, jboolean value) {
    StrutStyle* instance = reinterpret_cast<StrutStyle*>(static_cast<uintptr_t>(ptr));
    instance->setHeightOverride(value);
}
