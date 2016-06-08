CALL "C:\Program Files\Microsoft Visual Studio 8\Common7\Tools\vsvars32.bat"

devenv.com outlib\FCollada\FCollada.sln /build "Release Unicode DLL"
copy "outlib\FCollada\Output\Release Unicode DLL Win32\FColladaU.dll" bin

pause
