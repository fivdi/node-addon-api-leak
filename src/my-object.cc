#include "my-object.h"

class OpenAsyncWorker : public Napi::AsyncWorker {
  public:
    OpenAsyncWorker(Napi::Function& callback)
      : Napi::AsyncWorker(callback) {
    }

    void Execute() {
    }
};

Napi::FunctionReference MyObject::constructor;

Napi::Object MyObject::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "MyObject", {
    InstanceMethod("open", &MyObject::Open)
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("MyObject", func);
  return exports;
}

MyObject::MyObject(const Napi::CallbackInfo& info)
  : Napi::ObjectWrap<MyObject>(info) {
}

void MyObject::Open(const Napi::CallbackInfo& info) {
  Napi::Function cb = info[0].As<Napi::Function>();
  OpenAsyncWorker* worker = new OpenAsyncWorker(cb);
  worker->Queue();
}

