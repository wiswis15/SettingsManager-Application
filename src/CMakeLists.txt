
file(GLOB sourceFiles
    "*.cpp"
)
file(GLOB headerFiles
    "../*.h"
)

add_executable( SettingsManager ../main.cpp ${sourceFiles} ${headerFiles})

target_include_directories(SettingsManager PRIVATE ../headerFiles)


