@echo off
pushd
cd ..\run
conquer -CD..\cd\aud1;..\cd;..\cd\install %1 %2 %3 %4 %5
popd
