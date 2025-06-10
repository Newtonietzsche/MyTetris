cmake_minimum_required(VERSION 3.10)  # mis à jour pour éviter l'avertissement
project(MyTetris)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Répertoires personnalisés
set(SRC_DIR ${CMAKE_BINARY_DIR}/../src)
set(INCLUDE_DIR ${CMAKE_BINARY_DIR}/../include)

# Répertoire de sortie de l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Options de compilation
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Wall -Wextra -Wpedantic")

# Inclure les headers
include_directories(${INCLUDE_DIR})

# Trouver tous les fichiers source
file(GLOB_RECURSE srcFiles ${SRC_DIR}/*.cpp)

# Vérifie qu’il y a bien des fichiers source
if(NOT srcFiles)
    message(FATAL_ERROR "Aucun fichier source trouvé dans ${SRC_DIR}")
endif()

# Création de l'exécutable
add_executable(monExe ${srcFiles})
target_link_libraries(monExe ${SDL2_LIBRARIES})



