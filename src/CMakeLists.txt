add_library(report2
  SHARED
    simulate.c
  )
# greetingライブラリのインクルードディレクトリを教えてあげる
# PROJECT_SOURCE_DIRはこのプロジェクトのルートディレクトリの絶対パス
target_include_directories(report2
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  )
