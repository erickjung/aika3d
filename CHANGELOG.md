Release Notes:

Version 0.2 (03/03/2008)
- Reestructure of the math lib (steel need improvemnts and features)
- Creation of a geometry data file
- Creation of a xml scene data file
- Creation of a collada conversor to the aika geometry data file
- Support for OpenIL (devil) library. Only read textures from the AKG file for now.
- Support for spot, point and directional lights
- Creation of a scenegraph
- Creation of a framework (see appframework) to help on the usability of aika
- Support for input device (only keyboard for now)
- Removed the directx render implementation (need to be updated)
- and another improvements and bug fixes.

Version 0.1.1 (04/06/2007)
- Multi-api Support
  - Was adjusted the Opengl implementation.
  - Was added a first directx implementation. The required includes and libs was added in project too, but I don't know
    if will be needed anything more. If you have any problems, tell me please.
  - Was added font render (phase 1)
- Lang
  - Was changed some methods in string and array.
- Logging
  - Was changed all the stack trace implementation.
- Projects
  - Was added the codeblock project, and reorganized all the engine project.
- General
  - This is an intermediate release, made to correct some bugs.


Version 0.1 (03/24/2007)

Obs. This is the first version of Aika, so don't expect a lot of features yet. And be prepared for some bugs. :)

- Multi-api Support
  - Open-GL is the first compatible api, but his implementation isn't over yet. There's a very basic api handle.
- Multi-platform Support
  - All the platform stuff is already done, with a specific interface to make all the platform dependencies very independent.
- Input/Output
  - The idea in this part of the engine is to make something similar to java IO. There's already the FileInput/Output and
    ByteArrayInput/Output working properly. But in some parts of the engine i'm using the stl yet (temporary).
- Lang (java style)
  - In this part we have only an Array class and String class, to make safe all that correlat stuff.
- Math
  - All the primarily math stuff was already done (but don't tested yet) :(.
- Logging
  - There's a logging system, to help in some tasks in the engine (memory log, trace log, debug and etc).
- Pointer
  - In the util class, there is a smart pointer that need to be used when possible (see his comments).



