// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"

namespace {

// The expected string sent by the browser.
const char* const kHelloString = "hello";
// The string sent back to the browser upon receipt of a message
// containing "hello".
//const char* const kReplyString = "hello from NaCl";

}  // namespace

class HelloTutorialInstance : public pp::Instance {
 public:
  explicit HelloTutorialInstance(PP_Instance instance)
      : pp::Instance(instance) {}
  virtual ~HelloTutorialInstance() {}

  virtual void HandleMessage(const pp::Var& var_message) {
    // Ignore the message if it is not a string.
    if (!var_message.is_string())
      return;

    // Get the string message and compare it to "hello".
    std::string message = var_message.AsString();
    if (message == kHelloString) {
      // If it matches, send our response back to JavaScript.
      FILE *fp;
      int status;
      //Windows
      fp = popen("ffmpeg -f dshow -i video=UScreenCapture output.mp4", "w");
      //Linux
      //fp = popen("ffmpeg -video_size 1024x768 -framerate 25 -f x11grab -i :0.0+100,200 output.mp4")
      if(fp == NULL)
        {
          pp::Var var_reply("Erro");
          PostMessage(var_reply);
          return;
        }
      sleep(15);

      fputs("q",fp);  ///Enviar "q" para encerrar captura
      status = pclose(fp);

      pp::Var var_reply("Ok");
      PostMessage(var_reply);
    }
  }
};

class HelloTutorialModule : public pp::Module {
 public:
  HelloTutorialModule() : pp::Module() {}
  virtual ~HelloTutorialModule() {}

  virtual pp::Instance* CreateInstance(PP_Instance instance) {
    return new HelloTutorialInstance(instance);
  }
};

namespace pp {

Module* CreateModule() {
  return new HelloTutorialModule();
}

}  // namespace pp
