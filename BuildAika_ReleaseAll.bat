CALL "C:\Program Files\Microsoft Visual Studio 8\Common7\Tools\vsvars32.bat"

devenv.com projects\vc8\aika_project.sln /build Release
copy outlib\devil1.6.8-rc2\lib\DevIL.dll bin\vc8\release

pause

