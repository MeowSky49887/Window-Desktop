{
  "targets": [
    {
      "target_name": "window-desktop",
      "sources": [
        "src/bindings.cc",
        "src/wd.cc"
      ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      },
      "defines": [
        "UNICODE"
      ]
    }
  ]
}
