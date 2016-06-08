# Aika 3d engine

Aika is a simple 3d engine, written in C++ back at 2007. The main proposal of the engine was to create a portable and easy of use framework to create multimedia content, e.g. games.

## Features

```
- Clean, generic and simple API for math, io, utils, etc
- Platform agnostic
- OpenGL renderer
- Mesh and Scene data types
- Collada converter
- Support for OpenIL lib
- Spot, point and directional lights
- Scenegraph
```

## Dir structure

```
- (bin) The binary files
- (doc) The documentation
- (include) The lib header files
- (lib) The static lib
- (media) some data assets to be used with the samples
- (outlib) the third party libraries
- (projects) The visual studio 2005 projects for aika and samples
- (samples) The samples source code
- (source) The lib source code
- (tools) tools from aika engine
- (toolsframework) libraries from aika engine to help on usability
```

## Considerations

- To build aika properly you need to decompress the dependencies libraries on the outlib folder.
- To build and use the collada converter you need to build the fcollada before

## Requirements

- Visual C++ 7/8 or GCC
- Obs. This release was only tested with visual c++ 8 on windows XP.
