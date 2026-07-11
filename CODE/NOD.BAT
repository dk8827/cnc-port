@echo off
pushd
cd ..\run
conquer -CD..\cd2\aud1;..\cd2;..\cd2\install %1 %2 %3 %4 %5
popd
