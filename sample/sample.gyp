{
  'targets' : [
    {
      'dependencies': [  '<(DEPTH)/pcre.gyp:pcre_lib',
      ],
      'type' : 'executable',
      'target_name': 'pcrecpp',
      'sources': [
        'pcrecpp/main.cc',
      ],
    },
  ]
}