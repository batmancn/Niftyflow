set(SOURCE_LIB cJSON.cpp)

add_library(cJSON STATIC ${SOURCE_LIB})
#add_library(cJSON_static STATIC ${SOURCE_LIB})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
