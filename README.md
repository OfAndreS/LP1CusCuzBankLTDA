
# 🛠️ Estrutura de Projeto com CMake

Este repositório apresenta um **template completo** de projeto C++ utilizando **CMake**, com organização modular de arquivos, suporte a bibliotecas externas e configuração multiplataforma.

---

## 📁 Estrutura de Pastas

```bash
/nomeDoSeuProjeto 
├── CMakeLists.txt        # Arquivo principal de build
├── include/              # Arquivos de cabeçalho (.h)
│   └── meu_arquivo.h
├── src/                  # Código-fonte principal (.cpp)
│   └── main.cpp
├── resources/            # Recursos como imagens, configs, etc.
└── thirdParty/           # Bibliotecas de terceiros (opcional)
```

---

## ⚙️ CMakeLists.txt (raiz)

```cmake
cmake_minimum_required(VERSION 3.13)

project(nomeDoSeuProjeto)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PUBLIC 
    RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/"
)

# Exemplo para adicionar uma biblioteca de terceiros:
# add_subdirectory(thirdParty/minhaLib)
# target_link_libraries(${PROJECT_NAME} PRIVATE minhaLib)

# Configuração para runtime estático no MSVC
if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>$<$<CONFIG:Release>:Release>"
    )
endif()
```

---

## ▶️ Como Compilar e Executar

1. **Abra o terminal no diretório do projeto:**
   ```bash
   cd /caminho/para/nomeDoSeuProjeto
   ```

2. **Crie a pasta de build e acesse-a:**
   ```bash
   mkdir build
   cd build
   ```

3. **Gere os arquivos de build com CMake:**
   - Para Visual Studio:
     ```bash
     cmake ..
     ```
   - Para Visual Studio Code:
     ```
     Ctrl+Shift+P → CMake: Configure
     ```

4. **Compile o projeto:**
   ```bash
   cmake --build .
   ```

5. **Execute o binário gerado:**
   ```bash
   ./nomeDoSeuProjeto
   ```

### 💡 Dica Extra

Recompile automaticamente com múltiplos núcleos:

```bash
cmake --build . --parallel
```

---

## 📄 .gitignore

```gitignore
/build/
/cmake-build-*/
CMakeCache.txt
CMakeFiles/
Makefile
cmake_install.cmake
install_manifest.txt

/cMakeTest
/cMakeTest.exe
*.out
*.obj
*.o
*.a
*.lib
*.dll
*.so
*.dylib

*.log
*.tmp
*.swp
*.swo
*~

.vscode/
.idea/
*.user
*.code-workspace

.DS_Store
Thumbs.db
```

---

## ✅ Requisitos

- CMake >= 3.13
- Compilador C++ com suporte a C++17 (g++, clang++, MSVC, etc.)

---

## 📌 Observações

- Este template é ideal para projetos pequenos a médios.
- Para projetos maiores, considere incluir testes automatizados, modularização de bibliotecas e integração contínua.
