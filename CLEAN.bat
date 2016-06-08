REM delete lib files
rd /q /s lib

REM delete bin files
rd /q /s bin

REM delete obj files
rd /q /s projects\vc8\aika\debug
rd /q /s projects\vc8\aika\release
rd /q /s projects\vc8\samples\helloworld\debug
rd /q /s projects\vc8\samples\helloworld\release
rd /q /s projects\vc8\samples\helloworldApp\debug
rd /q /s projects\vc8\samples\helloworldApp\release


REM delete log files
del projects\vc8\aika\assertion.txt
del projects\vc8\aika\memory.txt
del projects\vc8\aika\trace.txt

REM delete vc++ files
del projects\vc8\aika_project.ncb
del projects\vc8\aika_project.suo

REM delete samples
del projects\vc8\samples\samples.ncb
del projects\vc8\samples\samples.suo

REM delete tools
del tools\colladaConverter\colladaconv.suo
del tools\colladaConverter\colladaconv.ncb
rd /q /s tools\colladaConverter\debug
rd /q /s tools\colladaConverter\release

REM delete toolsframework
del toolsframework\ioAkg\ioAkg.ncb
del toolsframework\ioAkg\ioAkg.suo
rd /q /s toolsframework\ioAkg\debug
rd /q /s toolsframework\ioAkg\release

del toolsframework\appFramework\appFramework.ncb
del toolsframework\appFramework\appFramework.suo
rd /q /s toolsframework\appFramework\debug
rd /q /s toolsframework\appFramework\release

REM delete outlib collada
del outlib\FCollada\FCollada.ncb
del outlib\FCollada\FCollada.suo
rd /q /s outlib\FCollada\Output
rd /q /s outlib\FCollada\FColladaTest\Output
rd /q /s outlib\FColladaPlugins\Output
