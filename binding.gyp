{
  "targets": [{
    "target_name": "addon",
    "cflags!": [ "-fno-exceptions" ],
    "cflags_cc!": [ "-fno-exceptions" ],
    "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
    "include_dirs" : [
      "<!@(node -p \"require('node-addon-api').include\")"
    ],
    "dependencies": [
      "<!@(node -p \"require('node-addon-api').gyp\")"
    ],
    "sources": [
      "./src/my-object.cc",
      "./src/addon.cc"
    ]
  }]
}

