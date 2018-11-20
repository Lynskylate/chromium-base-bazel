// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <iostream>

#include "base/android/jni_generator/sample_for_tests.h"

#include "base/android/jni_android.h"
#include "base/android/jni_string.h"
#include "base/android/scoped_java_ref.h"
// Generated file for JNI bindings from C++ to Java @CalledByNative methods.
// Only to be included in one .cc file.
// Name is based on the java file name: *.java -> jni/*_jni.h
#include "jni/SampleForAnnotationProcessor_jni.h"  // Generated by JNI.
#include "jni/SampleForTests_jni.h"                // Generated by JNI.

using base::android::AttachCurrentThread;
using base::android::ConvertJavaStringToUTF8;
using base::android::ConvertUTF8ToJavaString;
using base::android::ScopedJavaLocalRef;

namespace base {
namespace android {

jdouble CPPClass::InnerClass::MethodOtherP0(
    JNIEnv* env,
    const JavaParamRef<jobject>& caller) {
  return 0.0;
}

CPPClass::CPPClass() {
}

CPPClass::~CPPClass() {
}

// static
void CPPClass::Destroy(JNIEnv* env, const JavaParamRef<jobject>& caller) {
  delete this;
}

jint CPPClass::Method(JNIEnv* env, const JavaParamRef<jobject>& caller) {
  return 0;
}

void CPPClass::AddStructB(JNIEnv* env,
                          const JavaParamRef<jobject>& caller,
                          const JavaParamRef<jobject>& structb) {
  long key = Java_InnerStructB_getKey(env, structb);
  std::string value =
      ConvertJavaStringToUTF8(env, Java_InnerStructB_getValue(env, structb));
  map_[key] = value;
}

void CPPClass::IterateAndDoSomethingWithStructB(
    JNIEnv* env,
    const JavaParamRef<jobject>& caller) {
  // Iterate over the elements and do something with them.
  for (std::map<long, std::string>::const_iterator it = map_.begin();
       it != map_.end(); ++it) {
    long key = it->first;
    std::string value = it->second;
    std::cout << key << value;
  }
  map_.clear();
}

ScopedJavaLocalRef<jstring> CPPClass::ReturnAString(
    JNIEnv* env,
    const JavaParamRef<jobject>& caller) {
  return ConvertUTF8ToJavaString(env, "test");
}

// Static free functions declared and called directly from java.
static jlong JNI_SampleForTests_Init(JNIEnv* env,
                                     const JavaParamRef<jobject>& caller,
                                     const JavaParamRef<jstring>& param) {
  return 0;
}

static jdouble JNI_SampleForTests_GetDoubleFunction(
    JNIEnv*,
    const JavaParamRef<jobject>&) {
  return 0;
}

static jfloat JNI_SampleForTests_GetFloatFunction(JNIEnv*,
                                                  const JavaParamRef<jclass>&) {
  return 0;
}

static void JNI_SampleForTests_SetNonPODDatatype(JNIEnv*,
                                                 const JavaParamRef<jobject>&,
                                                 const JavaParamRef<jobject>&) {
}

static ScopedJavaLocalRef<jobject> JNI_SampleForTests_GetNonPODDatatype(
    JNIEnv*,
    const JavaParamRef<jobject>&) {
  return ScopedJavaLocalRef<jobject>();
}

static ScopedJavaLocalRef<jstring> JNI_SampleForTests_GetNonPODDatatype(
    JNIEnv*,
    const JavaParamRef<jstring>&) {
  return ScopedJavaLocalRef<jstring>();
}

static ScopedJavaLocalRef<jobjectArray> JNI_SampleForTests_GetNonPODDatatype(
    JNIEnv*,
    const JavaParamRef<jobjectArray>&) {
  return ScopedJavaLocalRef<jobjectArray>();
}

static jint JNI_InnerClass_GetInnerIntFunction(JNIEnv*,
                                               const JavaParamRef<jclass>&) {
  return 0;
}

} // namespace android
} // namespace base

// Proxy natives.
static void JNI_SampleForAnnotationProcessor_Foo(
    JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller) {}

static base::android::ScopedJavaLocalRef<jobject>
JNI_SampleForAnnotationProcessor_Bar(
    JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobject>& sample) {
  return JNI_SampleForTests_GetNonPODDatatype(env, sample);
}

static base::android::ScopedJavaLocalRef<jstring>
JNI_SampleForAnnotationProcessor_RevString(
    JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jstring>& stringToReverse) {
  return JNI_SampleForTests_GetNonPODDatatype(env, stringToReverse);
}

static base::android::ScopedJavaLocalRef<jobjectArray>
JNI_SampleForAnnotationProcessor_SendToNative(
    JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobjectArray>& strs) {
  return JNI_SampleForTests_GetNonPODDatatype(env, strs);
}

static base::android::ScopedJavaLocalRef<jobjectArray>
JNI_SampleForAnnotationProcessor_SendSamplesToNative(
    JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobjectArray>& strs) {
  return JNI_SampleForTests_GetNonPODDatatype(env, strs);
}

static jboolean JNI_SampleForAnnotationProcessor_HasPhalange(
    JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller) {
  return jboolean(true);
}

int main() {
  // On a regular application, you'd call AttachCurrentThread(). This sample is
  // not yet linking with all the libraries.
  JNIEnv* env = /* AttachCurrentThread() */ NULL;

  // This is how you call a java static method from C++.
  bool foo = base::android::Java_SampleForTests_staticJavaMethod(env);

  // This is how you call a java method from C++. Note that you must have
  // obtained the jobject somehow.
  ScopedJavaLocalRef<jobject> my_java_object;
  int bar = base::android::Java_SampleForTests_javaMethod(
      env, my_java_object, 1, 2);

  base::android::Java_SampleForTests_methodWithGenericParams(
      env, my_java_object, nullptr, nullptr);

  // This is how you call a java constructor method from C++.
  ScopedJavaLocalRef<jobject> my_created_object =
      base::android::Java_SampleForTests_Constructor(env, 1, 2);

  std::cout << foo << bar;

  for (int i = 0; i < 10; ++i) {
    // Creates a "struct" that will then be used by the java side.
    ScopedJavaLocalRef<jobject> struct_a =
        base::android::Java_InnerStructA_create(
            env, 0, 1, ConvertUTF8ToJavaString(env, "test"));
    base::android::Java_SampleForTests_addStructA(env, my_java_object,
                                                  struct_a);
  }
  base::android::Java_SampleForTests_iterateAndDoSomething(env, my_java_object);
  base::android::Java_SampleForTests_packagePrivateJavaMethod(env,
                                                              my_java_object);
  base::android::Java_SampleForTests_methodThatThrowsException(env,
                                                               my_java_object);
  base::android::Java_SampleForTests_javaMethodWithAnnotatedParam(
      env, my_java_object, 42);

  base::android::Java_SampleForTests_getInnerInterface(env);
  base::android::Java_SampleForTests_getInnerEnum(env);

  return 0;
}